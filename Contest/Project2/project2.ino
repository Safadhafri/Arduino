/**
 * ��Ŀ����λ�����ƶ������ť����LCD��ʾ��������ʱ�����¶ȣ����������¶�
 * ��Ŀ״̬�����
 */


/**
 * 
 * ���裺1.LCD��ʾ������ʾָ������OK
 *      2.��λ���Ͷ�����OK
 *      3.��ťOK
 *      4.�¶ȴ�����OK
 */

#include <LiquidCrystal.h>
#include <DHT.h>
#include <Servo.h>

Servo servo;
DHT dht;
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

const int rs = 12;
const int rw = 11;//������ͨ���ǽӵ�
const int enable = 11;
const int d7 = 2;
const int d6 = 3;
const int d5 = 4;
const int d4 = 5;
const int d3 = 6;
const int d2 = 7;
const int d1 = 8;
const int d0 = 9;


//--LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7);
//--LiquidCrystal lcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7);
//--LiquidCrystal lcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
//�趨���λ��
int cols = 0;
int rows = 0;
int col = 0;
int row = 0;
//String data = "Hello, World.";
int change = 0;//�жϱ���
int delay_time = 1000;//�ӳ�ʱ��

//�ж��Ƿ��°�ť
void judge(){
    if(analogRead(1)>550){
        change = 1;
    }else{
        change = 0;
    }
}

//�������϶ȡ����ϵ�ת����Ĭ��Ϊ���϶�
double calculate(double temperature){
    if(change==0){
        return temperature;//�����¶�
    }else{
        return ((temperature*9/5)+32);//�����¶�
    }
}

//��ʼ��
void setup(){
    dht.setup(7);
    //Serial.begin(9600);
    servo.attach(9);
}

void loop(){
    //�ж��Ƿ��°�ť���ı��жϱ���
    judge();
    //�����ת
    servo.write(map(analogRead(A0),0,1023,0,180));
    //��ʾ�¶�
    static double temp1;
    double temp = calculate((double)dht.getTemperature());
    lcd.begin(16, 2);
    if(temp>-1000){
        lcd.print(temp);
        temp1 = temp;
        if(change==0){
            lcd.print("`C");//��ʾ�������϶ȵĵ�λ��ֻ�ܾ���������_(:��)��)_
        }else{
            lcd.print("`F");
        }
        //�ӳ�1s
        delay(delay_time);
    }else{
        lcd.print(temp1);//���ڿ⺯�������ƣ���Ҫ����ʾ���ڴ���ʾ��һ�ε�����
        if(change==0){
            lcd.print("`C");
        }else{
            lcd.print("`F");
        } 
        delay(delay_time);
    }
}

