/**
 * ��Ŀ��·�ڽ�ͨ��
 * ��Ŀ״̬�����
 */

/**
 * �ð�ť�䵱��Ӧ����A��ťΪ���ߣ�BΪ����
 * ��4��״̬
 * ���޳�ʱ�����̣����죬����3s----1��A��B��ť��û��=1
 * 
 * ��������ʱ�����̣����죬����3s----1��A���£�Bû��=2
 * 
 * ��������ʱ��1.����-��������-----2��Aû����B����=3
 *            2.���죬����-��������3s----3
 *            3.���죬����----4
 *            4.���̣����죬����3s----1
 * 
 * ��������ʱ��1.���̣����죬����3s-----1��A��B������=4
 *            2.����-��������----2
 *            3.���죬����-��������3s----3
 *            4.���죬���ƣ�ת��1----4
 */

/**
 * ���裺1.״̬��OK
 *      2.�Զ��庯����switch�������ж������������ť�������OK
 *      3.�Ӱ�ť�õ���ϢOK
 *      4.LEDʹ��OK
 */

//���ÿ�
#include <JC_Button.h> //https://github.com/JChristensen/JC_Button
#include <FiniteStateMachine.h>

//��ʼ����ť
Button buttonnorth(3);
Button buttoneast(2);

//�趨״̬
State stepone = State(stepOneBegin,NULL,stepOneExit);
State steptwo = State(stepTwoBegin,NULL,stepTwoExit);
State stepthree = State(stepThreeBegin,NULL,stepThreeExit);
State stepfour = State(stepFourBegin,NULL,stepFourExit);

//��ʼ��״̬��
FSM state = FSM(stepone);

//����Ƶ�����λ��
int nr = 4;
int ng = 5;
int ny_b = 12;
int er = 11;
int eg_b = 10;
int ey = 9;

//�жϰ�ť�������
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

//״̬����
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

//��ʼ����
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
    //��ȡ��ť���
    buttonnorth.read();
    buttoneast.read();
    //״̬�ı�
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
    state.update();//��󶼸���״̬
}