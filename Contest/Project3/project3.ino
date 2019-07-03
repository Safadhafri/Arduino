/**
 * 项目：路口交通灯
 * 项目状态：完成
 */

/**
 * 用按钮充当感应器，A按钮为北边，B为东边
 * 共4种状态
 * 当无车时：北绿，东红，持续3s----1，A、B按钮都没按=1
 * 
 * 当北来车时：北绿，东红，持续3s----1，A按下，B没按=2
 * 
 * 当东来车时：1.北黄-蓝，东红-----2，A没按，B按下=3
 *            2.北红，东绿-蓝，持续3s----3
 *            3.北红，东黄----4
 *            4.北绿，东红，持续3s----1
 * 
 * 当都来车时：1.北绿，东红，持续3s-----1，A、B都按下=4
 *            2.北黄-蓝，东红----2
 *            3.北红，东绿-蓝，持续3s----3
 *            4.北红，东黄，转到1----4
 */

/**
 * 步骤：1.状态机OK
 *      2.自定义函数：switch函数，判断来车情况、按钮情况反馈OK
 *      3.从按钮得到信息OK
 *      4.LED使用OK
 */

//调用库
#include <JC_Button.h> //https://github.com/JChristensen/JC_Button
#include <FiniteStateMachine.h>

//初始化按钮
Button buttonnorth(3);
Button buttoneast(2);

//设定状态
State stepone = State(stepOneBegin,NULL,stepOneExit);
State steptwo = State(stepTwoBegin,NULL,stepTwoExit);
State stepthree = State(stepThreeBegin,NULL,stepThreeExit);
State stepfour = State(stepFourBegin,NULL,stepFourExit);

//初始化状态机
FSM state = FSM(stepone);

//定义灯的引脚位置
int nr = 4;
int ng = 5;
int ny_b = 12;
int er = 11;
int eg_b = 10;
int ey = 9;

//判断按钮按下情况
int condition(){
    if(buttonnorth.isReleased()==false && buttoneast.isReleased()==false){
        //Serial.println(1);
        return 1;
    }else if(buttonnorth.isReleased()==true && buttoneast.isReleased()==false){
        return 2;
        //Serial.println(2);
    }else if(buttonnorth.isReleased()==false && buttoneast.isReleased()==true){
        return 3;
        //Serial.println(3);
    }else if(buttonnorth.isReleased()==true && buttoneast.isReleased()==true){
        return 4;
        //Serial.println(4);
    }
}

//状态函数
void stepOneBegin(){
    digitalWrite(ng,HIGH);
    digitalWrite(er,HIGH);
    delay(3000);
}

void stepOneExit(){
    digitalWrite(ng,LOW);
    digitalWrite(er,LOW);
}

void stepTwoBegin(){
    digitalWrite(ny_b,HIGH);
    digitalWrite(er,HIGH);
    delay(3000);
}

void stepTwoExit(){
    digitalWrite(ny_b,LOW);
    digitalWrite(er,LOW);
}

void stepThreeBegin(){
    digitalWrite(nr,HIGH);
    digitalWrite(eg_b,HIGH);
    delay(3000);
}

void stepThreeExit(){
    digitalWrite(nr,LOW);
    digitalWrite(eg_b,LOW);
}

void stepFourBegin(){
    digitalWrite(nr,HIGH);
    digitalWrite(ey,HIGH);
    delay(3000);
}

void stepFourExit(){
    digitalWrite(nr,LOW);
    digitalWrite(ey,LOW);
}

//初始函数
void setup(){
    buttonnorth.begin();
    buttoneast.begin();
    Serial.begin(9600);
    pinMode(nr,OUTPUT);
    pinMode(ng,OUTPUT);
    pinMode(ny_b,OUTPUT);
    pinMode(er,OUTPUT);
    pinMode(eg_b,OUTPUT);
    pinMode(ey,OUTPUT);
    state.immediateTransitionTo(stepone);
}


void loop(){
    //读取按钮情况
    buttonnorth.read();
    buttoneast.read();
    //状态改变
    switch (condition()){
        case 1 :
        state.transitionTo(stepone);
        break;

        case 2 :
        state.transitionTo(stepone);
        break;

        case 3 :
        state.transitionTo(steptwo);
        state.update();
        state.transitionTo(stepthree);
        state.update();
        //delay(3000);
        state.transitionTo(stepfour);
        state.update();
        state.transitionTo(stepone);
        state.update();
        //delay(3000);
        state.transitionTo(stepone);
        break;

        case 4 :
        delay(3000);
        state.transitionTo(steptwo);
        state.update();
        state.transitionTo(stepthree);
        state.update();
        //delay(3000);
        state.transitionTo(stepfour);
        state.update();
        state.transitionTo(stepone);
    }
    state.update();//最后都更新状态
}