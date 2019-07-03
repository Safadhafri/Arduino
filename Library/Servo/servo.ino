
/*
��Servo.h�������ص������
��Servoname.write�е�����Ϊ��Ӧ�Ƕȣ��ҷ�ΧΪ0-180
����Project003�еõ��ɱ仯�ĵ�ѹֵ��0-1023�������Խ����������γ�-
ʵʱ���Ƶĵ������Ҫת����λ
 */

#include <Servo.h>  //https://www.arduino.cc/en/Reference/Servo
/**
 * ���߽�+
 * ��/�ؽӵ�
 * ��/��/�׽�����
 */
Servo servo;

int PIN = 11;//����λ��
int MIN = 544;//servo.attach��Ĭ��ֵ����ѡ
int MAX = 2400;//servo.attach��Ĭ��ֵ����ѡ
int ANGLE = 90;//��ת�Ƕ�
int MS = 1500;//servo.writeMicroseconds��Ĭ��ֵ

void setup(){
    //PIN�����ӵ�����
    servo.attach(PIN);
    //MIN��MAX��ѡ���ֱ�ָ��С�Ƕ�0������Ƕ�180�㣬��΢��Ϊ��λ��Ĭ�Ϸֱ�Ϊ544��2400
    servo.attach(PIN,MIN,MAX);

    //test
    Serial.begin(9600);
}

void loop(){
    //ANGLE����ת�ĽǶȣ��Ƕ�������ھ��Բο�ϵ���ԣ���������ת�ĽǶ�
    //��������ת���ʱ��ANGLE����ת�ٶȣ�90�Ǿ�ֹ��0��180��Ӧ��ͬ����������ת�ٶ�
    servo.write(ANGLE);

    //MS��΢���ƽ������ϴ���Ƕȣ�1500���м䣬1000��2000��������������ֵ
    //�������������servo.write()����һ��
    servo.writeMicroseconds(MS);

    //���ص�ǰ���õ�����ת���Ƕȣ���0-180֮��
    servo.read();

    //�����жϣ�ture��servo�ж�Ӧ�����ţ�false����
    servo.attached();
    
    //ȡ��һ�����ŵ�����
    servo.detach();
}
