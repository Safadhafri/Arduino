int analog = A0;
int input = 0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    input = analogRead(analog);
    //Serial.println(input);
    Serial.println(input*(5.0/1023.0));
    //��ӡ��ѹֵ��ת��Ϊ0-5��
    delay(500);
}
/*
ͨ��ģ������õ���Ӧ�ĵ�ѹֵ������ӡ��־
ע�⣺uno��������ѹ��5V��ģ��������Լ�⵽0-1023֮�����

 */