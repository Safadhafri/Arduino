

#include <JC_Button.h> //https://github.com/JChristensen/JC_Button

/**
 * pin:̽�����ŵ�λ��
 * ��ѡ�dbTime:����ʱ�䣬Ĭ��Ϊ25ms
 * ��ѡ�puEnable:�Ƿ������ڲ����������裬Ĭ��Ϊture����֮Ϊfalse
 * ��ѡ�invert:�Ǳ�ʾ���߼����𣬷��ʾ���߼����𣿣���Ĭ��Ϊtrue����֮Ϊfalse
 */
Button button(pin, dbTime, puEnable, invert);

/**
 * initialState:��ʼ״̬��Ĭ��Ϊfalse��off��
 */
ToggleButton togbutton(pin, initialState, dbTime, puEnable, invert);



void setup(){
    //��ʼ��
    button.begin();
}

void loop(){
    /**
     * ��¼��ť��״̬
     * �൱���ڴ˴����˸���ǣ���¼״̬
     * ֮��ķ�����Ƶ�������ڴ˺���
     * �˷�����Ҫ��Ƶ��ˢ�£���÷���loop()�ĵ�һ��
     * ����ture/false
     */
    button.read();
    /**
     * �������һ��read()�Ľ��
     * �˷�������ʹ��ť��read()
     */
    button.isPressed();
    button.isReleased();

    /**
     * ��鰴ť��״̬�Ƿ����ı䣬��������read֮���Ƿ�ı�
     */
    button.wasPressed();
    button.wasReleased();

    /**
     * ��ⰴť�Ƿ񱻰�����һ����ʱ�䣬���Ƿ񳤰�
     * ms���趨�İ���ʱ����ֵ����λ����
     * ����true/false
     */
    button.pressedFor(ms);
    button.releasedFor(ms);

    //������һ�θı�״̬��ʱ�䣬����Ϊ��λ��ʱ��������arduino��millis()����
    button.lastChange()

    //�ж�togbutton����һ��read()���Ƿ�ı���״̬
    togbutton.changed();

    //����togbutton����һ��read()����״̬
    togbutton.toggleState()
}



