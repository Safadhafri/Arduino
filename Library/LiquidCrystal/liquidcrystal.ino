
#include <LiquidCrystal.h>  //https://www.arduino.cc/en/Reference/LiquidCrystal

/**
 * rs��LCD��RS�������ӵ������λ��
 * rw��LCD��RW�������ӵ������λ�ã��ӵ�ʱ��ʡ�ԣ�
 * enable��LCD��E�������ӵ������λ��
 * d*��LCD��d*�������ӵ������λ��
 * ��ʹ��4-bitʱ��d0��1��2��3����
 * VSS���ӵ�
 * VDD����Դ����5V
 * A��LED������������ǵýӵ��裩
 * K:LED����Ƹ�������GND
 * V0:������ʾ�Աȶ�
 */

/**
 * һ������16��5
 * 2��  16��
 * 
 * 
 */
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

LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7);
LiquidCrystal lcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7);
LiquidCrystal lcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
int cols = 0;
int rows = 0;
int col = 0;
int row = 0;
String data = "Hello, World.";

void setup(){
    //cols��������rows������
    lcd.begin(cols, rows);

    //�������������Ͻ�
    lcd.clear();

    //���ù��λ�ã���������ͬ��
    lcd.setCursor(col, row);

    //������λ�����Ͻ�
    lcd.home();

    //��ʾ�ַ���data����ʾ������
    //������ʾ���ֽ���
    lcd.write(data);

    //��ӡ���ݣ�dataͬ��
    //BASE����ѡ�������ӡ���֣��˱���Ϊ���ֵĽ���-
    //BASE��ѡֵ��BIN-2��DEC-10��OCT-8��HEX-16
    //�����ֽ���
    lcd.print(data);
    lcd.print(data, BASE);

    //�˽���ࣺhttps://www.arduino.cc/en/Reference/LiquidCrystal
    ...
}

void loop(){
    
}
