/**
 * 动作3,使黑线在OUT3下方
 * 利用多线程
 * 用一个deflection变量来说明偏离OUT3时小车的偏转状态
 */
#include <pt.h>

//#define light 7
#define out1 3
#define out2 12
#define out3 11
#define out4 10
#define out5 9

#define la 7//N1
#define lb 8//N2

#define ra 4//N3
#define rb 2//N4

#define lr 5//左边速度
#define rr 6//右边速度

#define ptime 40//进程时间

//#define defspeed 0//默认速度

//偏移状态
#define deflection_left 1
#define deflection_right 2

//声明新线程，可以声明多个线程
/**
 * 进程1：前进
 * 进程2：从中心线偏移
 * 进程3：偏移到OUT2
 * 进程4：偏移到OUT4
 * 进程5：偏移到OUT1
 * 进程6：偏移到OUT5
 */
static struct pt pt1,pt2,pt3,pt4,pt5,pt6;

//偏转状态
static int deflection = 0;

void setup(){
    //pinMode(13,OUTPUT);
    //初始化进程
    PT_INIT(&pt1);
    PT_INIT(&pt2);
    PT_INIT(&pt3);
    PT_INIT(&pt4);
    PT_INIT(&pt5);
    
    PT_INIT(&pt6);
    //pinMode(light,OUTPUT);
    //探测接口初始化
    pinMode(out2,INPUT);
    pinMode(out3,INPUT);
    pinMode(out4,INPUT);
    pinMode(out5,INPUT);
    Serial.begin(9600);
    //digitalWrite(light,HIGH);
    pinMode(13,OUTPUT);//完全停止后提示用
    //电机接口初始化
    pinMode(la,OUTPUT);
    pinMode(lb,OUTPUT);
    pinMode(ra,OUTPUT);
    pinMode(rb,OUTPUT);
    pinMode(lr,OUTPUT);
    pinMode(rr,OUTPUT);
    //stop();//刚开始是停止
    delay(1000);
}

void loop(){
    protothreadName1(&pt1);
    protothreadName2(&pt2);
    protothreadName3(&pt3);
    protothreadName4(&pt4);
    protothreadName5(&pt5);
    protothreadName6(&pt6);
}


void stop(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //while(1){}
}

void stop_long(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    while(1){
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(100);
        digitalWrite(13,HIGH);
        delay(100);
        digitalWrite(13,LOW);
        delay(100);
    }
}

void ahead(){
    digitalWrite(la,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);

    //analogWrite(lr,rate);
    //analogWrite(rr,rate);
}

void back(){
    digitalWrite(la,LOW);
    digitalWrite(lb,HIGH);
    digitalWrite(ra,LOW);
    digitalWrite(rb,HIGH);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate);
}

void turn_left(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate+50);
    //delay(time);
}


void turn_right(){
    digitalWrite(la,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //analogWrite(lr,rate+50);
    //analogWrite(rr,rate);
    //delay(time);
}

/**
 * 大体同action1，但会循环直到OUT3到达黑线上
 */
void turn_left_quickly(){
    int temp = 0;
    while(temp<1){
        digitalWrite(la,LOW);
        digitalWrite(lb,HIGH);
        digitalWrite(ra,HIGH);
        digitalWrite(rb,LOW);
        analogWrite(lr,50);
        analogWrite(rr,50);
        if(digitalRead(out3)==0 && temp==0){
            temp = 1;
        }  
    }
    
}

/**
 * 同上
 */
void turn_right_quickly(){
    int temp = 0;
    while(temp<1){
        digitalWrite(la,HIGH);
        digitalWrite(lb,LOW);
        digitalWrite(ra,LOW);
        digitalWrite(rb,HIGH);
        analogWrite(lr,50);
        analogWrite(rr,50);
        if(digitalRead(out3)==0 && temp==0){
            temp = 1;
        }  
    }
}
/**
 * 前进进程，当OUT3在黑线上方时运行，40ms后会强制退出重新判断
 * 会优先判断是否停止，以下进程都会，故不在说明
 * 并且当偏移被赋值后在此进程中会被反向
 */
static int protothreadName1(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);
    while(1) {
        //coding
        
        PT_WAIT_UNTIL(pt,digitalRead(out3)==0);
        if(digitalRead(out2)==0 && digitalRead(out4)==0 && digitalRead(out3)==0){
            stop_long();
        }
        if(deflection==deflection_left){
            deflection = deflection_right;
        }else if(deflection==deflection_right){
            deflection = deflection_left;
        }
        ahead();
        delay(ptime);
        Serial.println("1");
    }
    
    //关闭进程
    PT_END(pt);
}

/**
 * 偏移转向进程
 * 当OUT3从黑线下离开时开始，会依据偏移状态进行转向
 * 当偏移状态未赋值时无动作
 */
static int protothreadName2(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);

    
    while(1) {
        //coding

        
        PT_WAIT_UNTIL(pt,digitalRead(out3)==1);
        if(deflection==0){

        }else if(deflection==deflection_left){
            //deflection = deflection_right;
            turn_right();
        }else if(deflection==deflection_right){
            //deflection = deflection_left;
            turn_left();
        }
        delay(ptime);
        Serial.println("2");
    }
    
    //关闭进程
    PT_END(pt);
}

/**
 * 左转进程，当黑线到达OUT2时触发，会赋值偏移状态
 */
static int protothreadName3(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);

    
    while(1) {
        //coding

        PT_WAIT_UNTIL(pt,digitalRead(out2)==0);
        if(digitalRead(out2)==0 && digitalRead(out4)==0 && digitalRead(out3)==0){
            stop_long();
        }
        turn_left();
        deflection = deflection_left;
        //turn_left(defspeed,100);
        delay(ptime);
        Serial.println("3");
    }
    
    //关闭进程
    PT_END(pt);
}

/**
 * 右转进程，说明同上
 */
static int protothreadName4(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);

    
    while(1) {
        //coding

        
        PT_WAIT_UNTIL(pt,digitalRead(out4)==0);
        if(digitalRead(out2)==0 && digitalRead(out4)==0 && digitalRead(out3)==0){
            stop_long();
        }
        turn_right();
        deflection = deflection_right;
        delay(ptime);
        Serial.println("4");
    }
    
    //关闭进程
    PT_END(pt);
}

/**
 * 急速左转进程，会赋值偏移状态
 */
static int protothreadName5(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);

    
    while(1) {
        //coding

        
        PT_WAIT_UNTIL(pt,digitalRead(out1)==0);
        if(digitalRead(out2)==0 && digitalRead(out4)==0 && digitalRead(out3)==0){
            stop_long();
        }
        turn_left_quickly();
        deflection = deflection_left;
        delay(ptime);
        Serial.println("5");
    }

    
    //关闭进程
    PT_END(pt);
}


/**
 * 急速右转，说明同上
 */
static int protothreadName6(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);

    
    while(1) {
        //coding

        
        PT_WAIT_UNTIL(pt,digitalRead(out5)==0);
        if(digitalRead(out2)==0 && digitalRead(out4)==0 && digitalRead(out3)==0){
            stop();
        }
        turn_right_quickly();
        deflection = deflection_right;
        delay(ptime);
    }

    
    //关闭进程
    PT_END(pt);
}

