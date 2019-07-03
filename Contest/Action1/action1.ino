/**
 * 动作1,使黑线在OUT3和OUT4之间
 * 利用多线程
 * 通常线程是前进，强制一定时间后退出
 * 当2、3或4、5变为1后，进入线程3、4
 * 在线程3、4中首先判断是否停止，再转弯（分为大转和小转）
 * 在转弯动作中有时间限制
 * 注意，在每个动作之后都是延续这个动作，没有停止，如果有需要，可以加上
 * 
 * 注意：对于进程的时间管理应该可以用millon()-lasttime<???来进行
 */
#include <pt.h>

//#define light 7
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

#define defspeed 0//默认速度


//声明新线程，可以声明多个线程
/**
 * 进程1：前进
 * 进程2：后退
 * 进程3：左转
 * 进程4：右转
 * 进程5：停止
 */
static struct pt pt1,pt2,pt3,pt4,pt5;

void setup(){
    //初始化进程
    PT_INIT(&pt2);
    PT_INIT(&pt3);
    PT_INIT(&pt4);
    PT_INIT(&pt5);
    PT_INIT(&pt1);
    //pinMode(light,OUTPUT);
    //探测接口初始化
    pinMode(out2,INPUT);
    pinMode(out3,INPUT);
    pinMode(out4,INPUT);
    pinMode(out5,INPUT);
    //Serial.begin(9600);
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
    delay(4000);
}

void loop(){
    protothreadName1(&pt1);
    //protothreadName2(&pt2);
    protothreadName3(&pt3);
    protothreadName4(&pt4);
    //protothreadName5(&pt5);
}
/**
     * 全部停止
     */
void stop(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //while(1){}
}

/**
 * 永远停止，并且13号灯闪烁
 */
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
/**
 * 向前走，参数为速度
 */
void ahead(){
    //analogWrite(lr,rate);
    //analogWrite(rr,rate);
    //digitalWrite(lr,HIGH);
    //digitalWrite(rr,HIGH);
    digitalWrite(la,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    
}
/**
 * 后退，参数为速度
 */
void back(){
    digitalWrite(la,LOW);
    digitalWrite(lb,HIGH);
    digitalWrite(ra,LOW);
    digitalWrite(rb,HIGH);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate);
}

/**
 * 向左转，原理时差速，在此过程中依然在向前进
 */
void turn_left(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate+50);
    //delay(time);
}

/**
 * 向右转，原理时差速，依然向前进
 */
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
 * 急速左转，两轮反向运动
 * 并且循环，直到OUT3越过黑线
 */
void turn_left_quickly(){
    int temp = 0;
    while(temp<2){
        digitalWrite(la,LOW);
        digitalWrite(lb,HIGH);
        digitalWrite(ra,HIGH);
        digitalWrite(rb,LOW);
        analogWrite(lr,50);
        analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
        if(digitalRead(out3)==0 && temp==1){
            temp = 2;
        }
    }
}
/**
 * 急速右转，说明同上
 */
void turn_right_quickly(){
    int temp = 0;
    while(temp<2){
        digitalWrite(la,HIGH);
        digitalWrite(lb,LOW);
        digitalWrite(ra,LOW);
        digitalWrite(rb,HIGH);
        //analogWrite(lr,50);
        //analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
        if(digitalRead(out3)==0 && temp==1){
            temp = 2;
        } 
    }
    
    //delay(time);
}
/**
 * 前进进程，并且强制运行40ms后退出
 */
static int protothreadName1(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);

    
    static long lasttime = 0;

    while(1) {
        //coding
        lasttime = millis();
        
        ahead(defspeed);
        delay(40);
        PT_WAIT_UNTIL(pt,millis()-lasttime>100);
    }
    
    //关闭进程
    PT_END(pt);
}


// static int protothreadName2(struct pt *pt){

//     //开始进程
//     PT_BEGIN(pt);

//     /**
//      * 因为进程碰到“PT_END(pt);”就停止了，所以要用无限循环框住
//      * 但不是必须的，也可以不要，但那样线程只能运行一次
//      */
//     while(1) {
//         //coding

//         /**
//          * pt是需要暂停的线程，condition是继续线程的条件
//          */
//         PT_WAIT_UNTIL(pt,condition);
//     }
    
//     //关闭进程
//     PT_END(pt);
// }

/**
 * 左转进程，会率先判断是否停止，在慢速转弯后会小幅度反向转弯
 */
static int protothreadName3(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);

    
    while(1) {
        //coding

        
        

        PT_WAIT_UNTIL(pt,digitalRead(out3)==1 || digitalRead(out2)==1);
        if(digitalRead(out2)==1 && digitalRead(out3)==1 && digitalRead(out4)==1 && digitalRead(out5)==1){
            stop_long();
        }else if(digitalRead(out3)==1){
            turn_left(defspeed,100);
            turn_right(defspeed,50);
        }else if(digitalRead(out2)==1){
            turn_left_quickly();
        }
        //turn_left(defspeed,100);
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

        
        PT_WAIT_UNTIL(pt,digitalRead(out4)==1 || digitalRead(out5)==1);
        if(digitalRead(out2)==1 && digitalRead(out3)==1 && digitalRead(out4)==1 && digitalRead(out5)==1){
            stop_long();
        }else if(digitalRead(out4)==1){
            //PT_WAIT_UNTIL(pt,condition);
            turn_right(defspeed,100);
            turn_left(defspeed,50);
        }else if(digitalRead(out5)==1){
            turn_right_quickly();
        }
        
    }
    
    //关闭进程
    PT_END(pt);
}


// static int protothreadName5(struct pt *pt){

//     //开始进程
//     PT_BEGIN(pt);

//     /**
//      * 因为进程碰到“PT_END(pt);”就停止了，所以要用无限循环框住
//      * 但不是必须的，也可以不要，但那样线程只能运行一次
//      */
//     while(1) {
//         //coding

//         /**
//          * pt是需要暂停的线程，condition是继续线程的条件
//          */
//         PT_WAIT_UNTIL(pt,digitalRead(out2)==1 && digitalRead(out3)==1 && digitalRead(out4)==1 && digitalRead(out5)==1);

//     }

    
//     //关闭进程
//     PT_END(pt);
// }