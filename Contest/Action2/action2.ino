/**
 * ����2,ʹ�ý���
 * ����switch�ж�
 * ���������action1һ��
 */
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


/**
 * ��������жϷ���ֵ
 */
#define gl 1
#define gr 2
#define ga 0
#define st 4
#define glq 5
#define grq 6


void setup(){
    //��ʼ������
    // PT_INIT(&pt2);
    // PT_INIT(&pt3);
    // PT_INIT(&pt4);
    // PT_INIT(&pt5);
    // PT_INIT(&pt1);
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
    switch (judge()){
    case ga:
        ahead(defspeed);
        break;
    case gl:
        turn_left(defspeed,100);
        break;
    case glq:
        turn_left_quickly(100);
        break;
    case gr:
        turn_right(defspeed,100);
        break;
    case grq:
        turn_right_quickly(100);
        break;
    case st:
        stop_long();
    default:
        break;
    }
}

int judge(){
    
    if(digitalRead(out2)==1 && digitalRead(out3)==1 && digitalRead(out4)==1 && digitalRead(out5)==1){
        //ֹͣ
        return st;
    }else if(digitalRead(out2)==1 && digitalRead(out3)==0 && digitalRead(out4)==0 && digitalRead(out5)==0){
        //������ת
        return glq;
    }else if(digitalRead(out2)==0 && digitalRead(out3)==1 && digitalRead(out4)==0 && digitalRead(out5)==0){
        //��ת
        return gl;
    }else if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==1 && digitalRead(out5)==0){
        //��ת
        return gr;
    }else if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==0 && digitalRead(out5)==1){
        //������ת
        return grq;
    }else if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==0 && digitalRead(out5)==0){
        //ǰ��
        return ga;
    }
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