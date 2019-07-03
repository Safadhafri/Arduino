/**
 * 项目：电位器控制舵机，按钮控制LCD显示器，按下时华氏温度，否则摄氏温度
 * 项目状态：完成
 */


/**
 * 
 * 步骤：1.LCD显示器，显示指定数据OK
 *      2.电位器和舵机配合OK
 *      3.按钮OK
 *      4.温度传感器OK
 */

#include <LiquidCrystal.h>
#include <DHT.h>
#include <Servo.h>

Servo servo;
DHT dht;
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

const int rs = 12;
const int rw = 11;//待定，通常是接地
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
//设定光标位置
int cols = 0;
int rows = 0;
int col = 0;
int row = 0;
//String data = "Hello, World.";
int change = 0;//判断变量
int delay_time = 1000;//延迟时间

//判断是否按下按钮
void judge(){
    if(analogRead(1)>550){
        change = 1;
    }else{
        change = 0;
    }
}

//进行摄氏度、华氏的转换，默认为摄氏度
double calculate(double temperature){
    if(change==0){
        return temperature;//摄氏温度
    }else{
        return ((temperature*9/5)+32);//华氏温度
    }
}

//初始化
void setup(){
    dht.setup(7);
    //Serial.begin(9600);
    servo.attach(9);
}

void loop(){
    //判断是否按下按钮，改变判断变量
    judge();
    //舵机旋转
    servo.write(map(analogRead(A0),0,1023,0,180));
    //显示温度
    static double temp1;
    double temp = calculate((double)dht.getTemperature());
    lcd.begin(16, 2);
    if(temp>-1000){
        lcd.print(temp);
        temp1 = temp;
        if(change==0){
            lcd.print("`C");//显示不了摄氏度的单位，只能尽可能像了_(:з)∠)_
        }else{
            lcd.print("`F");
        }
        //延迟1s
        delay(delay_time);
    }else{
        lcd.print(temp1);//由于库函数的限制，需要让显示屏在此显示上一次的数据
        if(change==0){
            lcd.print("`C");
        }else{
            lcd.print("`F");
        } 
        delay(delay_time);
    }
}

