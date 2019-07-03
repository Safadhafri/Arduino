/**
 * ����3,ʹ������OUT3�·�
 * ���ö��߳�
 * ��һ��deflection������˵��ƫ��OUT3ʱС����ƫת״̬
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

#define lr 5//����ٶ�
#define rr 6//�ұ��ٶ�

#define ptime 40//����ʱ��

//#define defspeed 0//Ĭ���ٶ�

//ƫ��״̬
#define deflection_left 1
#define deflection_right 2

//�������̣߳�������������߳�
/**
 * ����1��ǰ��
 * ����2����������ƫ��
 * ����3��ƫ�Ƶ�OUT2
 * ����4��ƫ�Ƶ�OUT4
 * ����5��ƫ�Ƶ�OUT1
 * ����6��ƫ�Ƶ�OUT5
 */
static struct pt pt1,pt2,pt3,pt4,pt5,pt6;

//ƫת״̬
static int deflection = 0;

void setup(){
    //pinMode(13,OUTPUT);
    //��ʼ������
    PT_INIT(&pt1);
    PT_INIT(&pt2);
    PT_INIT(&pt3);
    PT_INIT(&pt4);
    PT_INIT(&pt5);
    
    PT_INIT(&pt6);
    //pinMode(light,OUTPUT);
    //̽��ӿڳ�ʼ��
    pinMode(out2,INPUT);
    pinMode(out3,INPUT);
    pinMode(out4,INPUT);
    pinMode(out5,INPUT);
    Serial.begin(9600);
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
 * ����ͬaction1������ѭ��ֱ��OUT3���������
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
 * ͬ��
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
 * ǰ�����̣���OUT3�ں����Ϸ�ʱ���У�40ms���ǿ���˳������ж�
 * �������ж��Ƿ�ֹͣ�����½��̶��ᣬ�ʲ���˵��
 * ���ҵ�ƫ�Ʊ���ֵ���ڴ˽����лᱻ����
 */
static int protothreadName1(struct pt *pt){

    //��ʼ����
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
    
    //�رս���
    PT_END(pt);
}

/**
 * ƫ��ת�����
 * ��OUT3�Ӻ������뿪ʱ��ʼ��������ƫ��״̬����ת��
 * ��ƫ��״̬δ��ֵʱ�޶���
 */
static int protothreadName2(struct pt *pt){

    //��ʼ����
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
    
    //�رս���
    PT_END(pt);
}

/**
 * ��ת���̣������ߵ���OUT2ʱ�������ḳֵƫ��״̬
 */
static int protothreadName3(struct pt *pt){

    //��ʼ����
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

        
        PT_WAIT_UNTIL(pt,digitalRead(out4)==0);
        if(digitalRead(out2)==0 && digitalRead(out4)==0 && digitalRead(out3)==0){
            stop_long();
        }
        turn_right();
        deflection = deflection_right;
        delay(ptime);
        Serial.println("4");
    }
    
    //�رս���
    PT_END(pt);
}

/**
 * ������ת���̣��ḳֵƫ��״̬
 */
static int protothreadName5(struct pt *pt){

    //��ʼ����
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

    
    //�رս���
    PT_END(pt);
}


/**
 * ������ת��˵��ͬ��
 */
static int protothreadName6(struct pt *pt){

    //��ʼ����
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

    
    //�رս���
    PT_END(pt);
}

