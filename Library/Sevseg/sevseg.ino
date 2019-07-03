#include <SevSeg.h> //https://github.com/DeanIsMe/SevSeg


/**
 *          A
 *      \\\\\\\\\\
 *     F\\      \\B
 *      \\  G   \\
 *      \\\\\\\\\\
 *     E\\      \\C
 *      \\      \\
 *      \\\\\\\\\\
 *          D       .DP
 */


/**
 *    ��1   A    F  ��2 ��3  B   
 *     |    |   |   |   |   |
 *     \\\\\\\\\\\\\\\\\\\\\\\
 *     \\\\\\\\\\\\\\\\\\\\\\\
 *     \\\\.\\\\\.\\\\.\\\\\.\
 *     |    |   |   |   |   |
 *     E    D   DP  C   G  ��4  
 */


SevSeg sevseg;

int LIGHTVALUE = 90;//������0-100
String STRING = "Hello,World!";//��ʾ���ַ���
int NUMBER = 1000;//��ʾ����
int LOCATION = 1;//С����λ��
byte HARDWARE = COMMON_CATHODE;//����ģʽ:COMMON_CATHODE=������/COMMON_ANODE=��������
byte NUMDIGITS = 4;//�����λ�����������֣�
//               ����1��2��3��4
byte DIGIEPINS[] = {2, 3, 4, 5};//�����������ӵ�����λ��
//                    A, B, C, D, E,  F,  G,  DP
byte SEGMENTPINS[] = {6, 7, 8, 9, 10, 11, 12, 13};//����ܴ�A-DP�������ӵ�����λ��

/**
 * ��Ϊ�˿ⲻ������delay()����ʱ���������������Խ�һ����ʱ����
 * ԭ���ظ����㣬����ʱ�䡣����
 * ע�⣬�ٸ�����ʾʱ����Ҫ���˺�����֣�
 * ���ֻʹ�ô˺������Լ�delay
 */
void write(int number){
    long delay_time = 2000;
    for(int i=0;;i++){
        if(i>=delay_time){
            sevseg.blank();
            return;
        }
        sevseg.setNumber(number);
        sevseg.refreshDisplay();
    }
}

void setup(){
    sevseg.begin(HARDWARE,NUMDIGITS,DIGIEPINS,SEGMENTPINS);//��ʼ��
}

void loop(){
    /**
     * NUMBER�����֣�LOCATION��С����λ�ã������ұ������ƶ�λ����
     * ��LOCATIONΪ-1����ʱ����С����
     * ��NUMBER��float����ʱ��LOCATION��С�����λ��
     * ������Χ��ʾ----
     * ����trueʱ��ʾΪ16����
     */    
    sevseg.setNumber(NUMBER);//��С����
    sevseg.setNumber(NUMBER,LOCATION);//������
    sevseg.setNumber(NUMBER,LOCATION,true);//16����

    /**
     *ˢ�£�����
     */
    sevseg.refreshDisplay();


    /**
     * ��ʾ�ַ�����������
     * ֻ�������ַ����� ������-������.��������ʾ                        
     */
    sevseg.setChars(STRING);

    


    /**
     * �հ�
     */
    sevseg.blank();

    /**
     * ����������-200��200��
     * ������0-100֮��
     */
    sevseg.setBrightness(LIGHTVALUE);

}
