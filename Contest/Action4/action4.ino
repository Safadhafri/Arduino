
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

#define defspeed 0//Ĭ���ٶ�
/**
 * �жϺ�������ֵ
 */
#define gl 1
#define gr 2
#define ga 0
#define st 4
#define glq 5
#define grq 6

//ƫ��״̬
#define deflection_left 1
#define deflection_right 3

//ƫ��״̬
static int deflection = 0;

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
        ahead();
        break;
    case gl:
        turn_left();
        break;
    case glq:
        turn_left_quickly();
        break;
    case gr:
        turn_right();
        break;
    case grq:
        turn_right_quickly();
        break;
    case st:
        stop_long();
    default:
        break;
    }
}

int judge(){
    if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==0){
        //�����ж��Ƿ�ֹͣ
        return st;
    }else if(digitalRead(out2)==0){
        deflection = deflection_left;
        //��ת
        return gl;
    }else if(digitalRead(out4)==0){
        deflection = deflection_right;
        //��ת
        return gr;
    }else if(digitalRead(out1)==0){
        deflection = deflection_left;
        //������ת
        return glq;
    }else if(digitalRead(out5)==0){
        deflection = deflection_right;
        //������ת
        return grq;
    }else if(digitalRead(out3)==0){
        //ƫ��״̬����
        if(deflection==deflection_left){
            deflection = deflection_right;
        }else if(deflection==deflection_right){
            deflection = deflection_left;
        }
        //ǰ��
        return ga;
    }else if(digitalRead(out3)==1){
        if(deflection==0){
            //Ӧ��ת�򣬵�ƫ��״̬δ��ֵ����ֱ��
            return ga;
        }else if(deflection==deflection_left){
            //deflection = deflection_right;
            //ƫ����ת
            return gr;
        }else if(deflection==deflection_right){
            //deflection = deflection_left;
            //ƫ����ת
            return gl;
        }
    }
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
        if(digitalRead(out3)==1 && temp==0){
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
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
    }
}