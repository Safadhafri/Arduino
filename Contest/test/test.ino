/**
 * ѭ��ģ��
 * ״̬��һ��������õģ������ܵ�һЩ����һ�����ܽӴ�����
 * 
 */

/**
 * ��ģ���⵽�ڵ���ʱ�᷵��1������Ĭ�Ϸ���0
 * �������ԣ��͵ƹ�û�й�ϵ�������ý��ߵ���һ�����һ�㣬�����Ȼ����
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