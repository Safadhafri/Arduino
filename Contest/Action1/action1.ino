/**
 * ����1,ʹ������OUT3��OUT4֮��
 * ���ö��߳�
 * ͨ���߳���ǰ����ǿ��һ��ʱ����˳�
 * ��2��3��4��5��Ϊ1�󣬽����߳�3��4
 * ���߳�3��4�������ж��Ƿ�ֹͣ����ת�䣨��Ϊ��ת��Сת��
 * ��ת�䶯������ʱ������
 * ע�⣬��ÿ������֮�����������������û��ֹͣ���������Ҫ�����Լ���
 * 
 * ע�⣺���ڽ��̵�ʱ�����Ӧ�ÿ�����millon()-lasttime<???������
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

#define lr 5//����ٶ�
#define rr 6//�ұ��ٶ�

#define defspeed 0//Ĭ���ٶ�


//�������̣߳�������������߳�
/**
 * ����1��ǰ��
 * ����2������
 * ����3����ת
 * ����4����ת
 * ����5��ֹͣ
 */
static struct pt pt1,pt2,pt3,pt4,pt5;

void setup(){
    //��ʼ������
    PT_INIT(&pt2);
    PT_INIT(&pt3);
    PT_INIT(&pt4);
    PT_INIT(&pt5);
    PT_INIT(&pt1);
    //pinMode(light,OUTPUT);
    //̽��ӿڳ�ʼ��
    pinMode(out2,INPUT);
    pinMode(out3,INPUT);
    pinMode(out4,INPUT);
    pinMode(out5,INPUT);
    //Serial.begin(9600);
    //digitalWrite(light,HIGH);
    pinMode(13,OUTPUT);//��ȫֹͣ����ʾ��
    //����ӿڳ�ʼ��
    pinMode(la,OUTPUT);
    pinMode(lb,OUTPUT);
    pinMode(ra,OUTPUT);
    pinMode(rb,OUTPUT);
    pinMode(lr,OUTPUT);
    pinMode(rr,OUTPUT);
    //stop();//�տ�ʼ��ֹͣ
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
     * ȫ��ֹͣ
     */
void stop(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //while(1){}
}

/**
 * ��Զֹͣ������13�ŵ���˸
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
 * ��ǰ�ߣ�����Ϊ�ٶ�
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
 * ���ˣ�����Ϊ�ٶ�
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
 * ����ת��ԭ��ʱ���٣��ڴ˹�������Ȼ����ǰ��
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
 * ����ת��ԭ��ʱ���٣���Ȼ��ǰ��
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
 * ������ת�����ַ����˶�
 * ����ѭ����ֱ��OUT3Խ������
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
 * ������ת��˵��ͬ��
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
 * ǰ�����̣�����ǿ������40ms���˳�
 */
static int protothreadName1(struct pt *pt){

    //��ʼ����
    PT_BEGIN(pt);

    
    static long lasttime = 0;

    while(1) {
        //coding
        lasttime = millis();
        
        ahead(defspeed);
        delay(40);
        PT_WAIT_UNTIL(pt,millis()-lasttime>100);
    }
    
    //�رս���
    PT_END(pt);
}


// static int protothreadName2(struct pt *pt){

//     //��ʼ����
//     PT_BEGIN(pt);

//     /**
//      * ��Ϊ����������PT_END(pt);����ֹͣ�ˣ�����Ҫ������ѭ����ס
//      * �����Ǳ���ģ�Ҳ���Բ�Ҫ���������߳�ֻ������һ��
//      */
//     while(1) {
//         //coding

//         /**
//          * pt����Ҫ��ͣ���̣߳�condition�Ǽ����̵߳�����
//          */
//         PT_WAIT_UNTIL(pt,condition);
//     }
    
//     //�رս���
//     PT_END(pt);
// }

/**
 * ��ת���̣��������ж��Ƿ�ֹͣ��������ת����С���ȷ���ת��
 */
static int protothreadName3(struct pt *pt){

    //��ʼ����
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
    
    //�رս���
    PT_END(pt);
}

/**
 * ��ת���̣�˵��ͬ��
 */
static int protothreadName4(struct pt *pt){

    //��ʼ����
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
    
    //�رս���
    PT_END(pt);
}


// static int protothreadName5(struct pt *pt){

//     //��ʼ����
//     PT_BEGIN(pt);

//     /**
//      * ��Ϊ����������PT_END(pt);����ֹͣ�ˣ�����Ҫ������ѭ����ס
//      * �����Ǳ���ģ�Ҳ���Բ�Ҫ���������߳�ֻ������һ��
//      */
//     while(1) {
//         //coding

//         /**
//          * pt����Ҫ��ͣ���̣߳�condition�Ǽ����̵߳�����
//          */
//         PT_WAIT_UNTIL(pt,digitalRead(out2)==1 && digitalRead(out3)==1 && digitalRead(out4)==1 && digitalRead(out5)==1);

//     }

    
//     //�رս���
//     PT_END(pt);
// }