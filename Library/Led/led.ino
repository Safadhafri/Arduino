

#include <LED.h>    //https://playground.arduino.cc/Code/LED/

/**
 * ע�⣺led��С����ԭ��������ӵ��裡��������
 */

int PIN = 11;//����λ��
int TIME = 1000;//����ʱ��
int TIMES = 1;//����
int VALUE = 255;//����


//�趨ledΪ����PINΪ��������
LED led = LED(PIN);


void setup(){
    
}

void loop(){
    //�ж�led�Ƿ������Ƿ���true������false
    led.getState();

    //����led
    led.on();

    //�ر�led
    led.off();

    //led״̬����
    led.toggle();

    //led��˸
    //TIME�ǳ���ʱ�䣨���룩��TIMES���ڳ���ʱ������˸�Ĵ���
    led.blink(TIME,TIMES);

    //�������ȣ�VALUE������ֵ��0-255��
    led.setValue(VALUE);

    //�𽥱�����TIME�ǳ���ʱ�䣨���룩
    led.fadeIn(TIME);

    //�𽥱䰵��TIME�ǳ���ʱ�䣨���룩
    led.fadeOut(TIME);
}