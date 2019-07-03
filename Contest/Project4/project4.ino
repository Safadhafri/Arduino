/**
 * ��Ŀ��LEDө���
 * ��Ŀ״̬�����
 */

/**
 *  1.����-OK
 *  2.LED-OK
 *  3.�����-OK
 */


//���ÿ⣺���̣߳�LED
#include <pt.h>
#include <LED.h>

//����LED
LED led1 = LED(11);
LED led2 = LED(10);
LED led3 = LED(9);
LED led4 = LED(6);
LED led5 = LED(5);

//����5�����߳�
static struct pt pt1,pt2,pt3,pt4,pt5;

//�߳�1
static int protothread1(struct pt *pt){

    //��ʼ����
    PT_BEGIN(pt);

    //���徲̬����
    static long lasttime = 0;
    static int ran = 0;
    while(1) {

        lasttime = millis();
        //�õ��������
        ran = random(100,2001);
        //����˽��̣�ִ����һ������
        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led1.fadeIn(250);
        lasttime = millis();
        ran = random(100,2001);
        PT_WAIT_UNTIL(pt,millis()-lasttime>ran);
        led1.fadeOut(250);

    }
    
    //�رս���
    PT_END(pt);
}

//����2
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
    
    //�رս���
    PT_END(pt);
}

//����3
static int protothread3(struct pt *pt){

    //��ʼ����
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
    
    //�رս���
    PT_END(pt);
}

//����4
static int protothread4(struct pt *pt){

    //��ʼ����
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
    
    //�رս���
    PT_END(pt);
}

//����5
static int protothread5(struct pt *pt){

    //��ʼ����
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
    
    //�رս���
    PT_END(pt);
}



void setup(){
    //��ʼ�����н���
    PT_INIT(&pt1);
    PT_INIT(&pt2);
    PT_INIT(&pt3);
    PT_INIT(&pt4);
    PT_INIT(&pt5);
}

void loop(){
    //��ʼִ�н���
    protothread1(&pt1);
    protothread2(&pt2);
    protothread3(&pt3);
    protothread4(&pt4);
    protothread5(&pt5);
}
