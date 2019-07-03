/**
 * 项目：LED萤火虫
 * 项目状态：完成
 */

/**
 *  1.进程-OK
 *  2.LED-OK
 *  3.随机数-OK
 */


//调用库：多线程，LED
#include <pt.h>
#include <LED.h>

//定义LED
LED led1 = LED(11);
LED led2 = LED(10);
LED led3 = LED(9);
LED led4 = LED(6);
LED led5 = LED(5);

//声明5个新线程
static struct pt pt1,pt2,pt3,pt4,pt5;

//线程1
static int protothread1(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);

    //定义静态变量
    static long lasttime = 0;
    static int ran = 0;
    while(1) {

        lasttime = millis();
        //得到随机周期
        ran = random(100,2001);
        //挂起此进程，执行下一个进程
        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led1.fadeIn(250);
        lasttime = millis();
        ran = random(100,2001);
        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led1.fadeOut(250);

    }
    
    //关闭进程
    PT_END(pt);
}

//进程2
static int protothread2(struct pt *pt){

    PT_BEGIN(pt);
    static long lasttime = 0;
    static int ran = 0;
    while(1) {
        lasttime = millis();
        ran = random(100,2001);
        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led2.fadeIn(250);
        lasttime = millis();
        ran = random(100,2001);

        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led2.fadeOut(250);
    }
    
    //关闭进程
    PT_END(pt);
}

//进程3
static int protothread3(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);
    static long lasttime = 0;
    static int ran = 0;
    while(1) {
        lasttime = millis();
        ran = random(100,2001);
        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led3.fadeIn(250);
        lasttime = millis();
        ran = random(100,2001);

        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led3.fadeOut(250);
    }
    
    //关闭进程
    PT_END(pt);
}

//进程4
static int protothread4(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);
    static long lasttime = 0;
    static int ran = 0;
    while(1) {
        lasttime = millis();
        ran = random(100,2001);
        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led4.fadeIn(250);
        lasttime = millis();
        ran = random(100,2001);

        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led4.fadeOut(250);
    }
    
    //关闭进程
    PT_END(pt);
}

//进程5
static int protothread5(struct pt *pt){

    //开始进程
    PT_BEGIN(pt);
    static long lasttime = 0;
    static int ran = 0;
    while(1) {
        lasttime = millis();
        ran = random(100,2001);
        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led5.fadeIn(250);
        lasttime = millis();
        ran = random(100,2001);

        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led5.fadeOut(250);
    }
    
    //关闭进程
    PT_END(pt);
}



void setup(){
    //初始化所有进程
    PT_INIT(&pt1);
    PT_INIT(&pt2);
    PT_INIT(&pt3);
    PT_INIT(&pt4);
    PT_INIT(&pt5);
}

void loop(){
    //开始执行进程
    protothread1(&pt1);
    protothread2(&pt2);
    protothread3(&pt3);
    protothread4(&pt4);
    protothread5(&pt5);
}
