/**
 * ��Ŀ��Ѱ��С��
 * ��Ŀ״̬��������
 * 
 */

/**
 * 1.�������--���
 * 2.ת��ϵͳ--���
 * 3.̽��ģ��--���
 * 4.��������--���
 */

/**
 * �������ݣ�
 * 1.���̾������4.5��0.3cm
 * 2.��������������1-2cm������΢�����һ��ƫ��
 */

/**
 * ˼·1���ú�����OUT3��4֮��
 * 1.��OUT2-5��Ϊ1ʱ��ֱ��
 * 2.��OUT3Ϊ0������ת���е��ٶȣ���ֱ��OUT3��Ϊ1��������תһ�㣬����ʹ�������ƽ��
 * 3.��OUT4Ϊ0������ת���е��ٶȣ���֪��OUT4��Ϊ1��������תһ�㣬����ʹ�������ƽ��
 * 4.��OUT2Ϊ0��ͣ��ԭ������ת��ʹOUT3��Ϊ1�ٱ�Ϊ1��֮��������תһ��
 * 5.��OUT5Ϊ0��ͣ��ԭ������ת��ʹOUt4��Ϊ1�ٱ�Ϊ1��֮��������תһ��
 * 6.��OUT2-5��Ϊ0ʱ��ֹͣ
 * 7.�򿪵�Դ���ӳ�3s��֮��ʼ
 */

/**
 * ˼·2���ú���һֱ����OUT3����
 * 1.��OUT3Ϊ0ʱ��ֱ��
 * 2.��OUT3��Ϊ1ʱ����Ҫ�жϳ����Ǹ�����ƫ����һ���޷��жϣ�����Ҫ���������ƫ��״̬
 * 3.��OUT2Ϊ0ʱ������ת���е��ٶȣ���ֱ��OUT3��Ϊ0��ͬʱ����ƫ�ƣ�����ƫ
 * 4.��OUT4Ϊ0ʱ������ת���е��ٶȣ���ֱ��OUT3��Ϊ0��ͬʱ����ƫ�ƣ�����ƫ
 * 5.����3/4����󣬵�OUT3��0��Ϊ1ʱ����ƫ��״̬�ķ�������ת��ͬʱ��תƫ��״̬
 * 6.��OUT1Ϊ0��ͣ��ԭ������ת��ֱ��OUT3��Ϊ0��ͬʱ����ƫ�ƣ�����ƫ
 * 7.��OUT5Ϊ0��ͣ��ԭ������ת��ֱ��OUT3��Ϊ0��ͬʱ����ƫ�ƣ�����ƫ
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * ����1��˼·һ
 * ����״̬�����������̿⺯�������⣬���������ĳһ���������޷��԰Ρ�����
 */
//....
/**
 * ����1,ʹ������OUT3��OUT4֮��
 * ���ö��߳�
 * ͨ���߳���ǰ����ǿ��һ��ʱ����˳�
 * ��2��3��4��5��Ϊ1�󣬽����߳�3��4
 * ���߳�3��4�������ж��Ƿ�ֹͣ����ת�䣨��Ϊ��ת��Сת��
 * ��ת�䶯������ʱ������
 * ע�⣺��ÿ������֮�����������������û��ֹͣ���������Ҫ�����Լ���
 * 
 * ע�⣺���ڽ��̵�ʱ�����Ӧ�ÿ�����millon()-lasttime<???������
 */


/**
 * �������˼·2
 * ����״̬������
 */

//����̽��ģ�������λ��
#define out1 3
#define out2 12
#define out3 11
#define out4 10
#define out5 9

//����������ģ������
#define la 7//N1
#define lb 8//N2

#define ra 4//N3
#define rb 2//N4

#define lr 5//����ٶ�
#define rr 6//�ұ��ٶ�

//#define defspeed 0//Ĭ���ٶ�

/**
 * �жϺ�������ֵ
 */
#define gl 1//go left
#define gr 2//go right
#define ga 0//go ahead
#define st 4//stop
#define glq 5//go left quicklly
#define grq 6//go right quickly

//ƫ��״̬
#define deflection_left 1
#define deflection_right 3

#define dtime 100

//ƫ��״̬
static int deflection = 0;

void setup(){
    
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
    delay(4000);
}


void loop(){
    ahead();
    Serial.print(analogRead(lr));
    Serial.println(analogRead(rr));
}

void run(){
    switch (judge()){
    case ga:
        ahead();
        //delay(dtime);
        //stop();
        break;
    case gl:
        turn_left();
        //delay(dtime);
        //stop();
        //delay(dtime);
        break;
    case glq:
        turn_left_quickly();
        //delay(dtime);
        //stop();
        break;
    case gr:
        turn_right();
        ////delay(dtime);
        //stop();
        //delay(dtime);
        break;
    case grq:
        turn_right_quickly();
        //delay(dtime);
        //stop();
        break;
    case st:
        stop_long();
        //delay(dtime);
        //stop();
    default:
        break;
    }
}

/**
 * �жϺ����������ж�С��Ŀǰ״̬�������ض�Ӧ��ֵ
 */
int judge(){
    if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==0){
        //�����ж��Ƿ�ֹͣ
        return st;
    }else if(digitalRead(out2)==0){
        deflection = deflection_left;
        //��ת
        return gr;
    }else if(digitalRead(out4)==0){
        deflection = deflection_right;
        //��ת
        return gl;
    }else if(digitalRead(out1)==0){
        deflection = deflection_left;
        //������ת
        return grq;
    }else if(digitalRead(out5)==0){
        deflection = deflection_right;
        //������ת
        return glq;
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
/**
 * ֹͣ
 */
void stop(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //while(1){}
}

/**
 * ��ȫֹͣ������˸13�ŵ���ʾ
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
 * ֱ��
 */
void ahead(){
    digitalWrite(la,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    analogWrite(lr,400);
    analogWrite(rr,400);
}

/**
 * ����
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
 * ��ת
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
 * ��ת
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
 * ������ת��ֱ��OUT3�ٴλص�������
 */
void turn_left_quickly(){
    int temp = 0;
    //while(temp<1){
        digitalWrite(la,LOW);
        digitalWrite(lb,HIGH);
        digitalWrite(ra,HIGH);
        digitalWrite(rb,LOW);
        //analogWrite(lr,50);
        //analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
    //}
    
}

/**
 * ������ת��ֱ��OUT3�ٴλص�������
 */
void turn_right_quickly(){
    int temp = 0;
    //while(temp<1){
        digitalWrite(la,HIGH);
        digitalWrite(lb,LOW);
        digitalWrite(ra,LOW);
        digitalWrite(rb,HIGH);
        //analogWrite(lr,50);
        //analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
    //}
}