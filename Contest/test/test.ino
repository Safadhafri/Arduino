/**
 * 循迹模块
 * 状态：一厘米是最好的，尽可能低一些，但一定不能接触地面
 * 
 */

/**
 * 当模块检测到遮挡物时会返回1，否则默认返回0
 * 经过测试，和灯光没有关系，尽量让接线的那一侧更低一点，灵敏度会提高
 */

//#define light 7
#define out2 12
#define out3 11
#define out4 10
#define out5 9
#define out1 3


void setup(){
    pinMode(out1,INPUT);
    pinMode(out2,INPUT);
    pinMode(out3,INPUT);
    pinMode(out4,INPUT);
    pinMode(out5,INPUT);
    Serial.begin(9600);
    //digitalWrite(light,HIGH);
}

void loop(){
    Serial.print(digitalRead(out1));
    Serial.print("   ");
    Serial.print(digitalRead(out2));
    Serial.print("   ");
    Serial.print(digitalRead(out3));
    Serial.print("   ");
    Serial.print(digitalRead(out4));
    Serial.print("   ");
    Serial.print(digitalRead(out5));
    Serial.println("   ");
    delay(1000);
}