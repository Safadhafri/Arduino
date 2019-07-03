/**
 * ��Ŀ����-9��-8����-1���ٴ�-0.9��0.8��0���ٴ�0��1��20������������
 * ��Ŀ״̬�����
 */

#include <SevSeg.h>//https://github.com/DeanIsMe/SevSeg


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

//--int LIGHTVALUE = 90;//������0-100
//--String STRING = "Hello,World!";//��ʾ���ַ���
int temp=0;
//--int NUMBER = 0;//��ʾ����
int NUMBER_TEMP = 0;//��ʱ�м�ֵ
int LOCATION = 1;//С����λ��
int speed = 2000;//�����ٶ�
byte HARDWARE = COMMON_CATHODE;//����ģʽ:COMMON_CATHODE=������/COMMON_ANODE=��������
byte NUMDIGITS = 4;//�����λ�����������֣�

//               ����1��2��3��4
byte DIGIEPINS[] = {2, 3, 4, 5};//�����������ӵ�����λ��

//                    A, B, C, D, E,  F,  G,  DP
byte SEGMENTPINS[] = {6, 7, 8, 9, 10, 11, 12, 13};//����ܴ�A-DP�������ӵ�����λ��

void step_one(){
    int NUMBER = -9;
    for(;;){
        NUMBER_TEMP++;
        if(NUMBER_TEMP==speed){
            NUMBER_TEMP = 0;
            NUMBER++;
        }

        sevseg.setNumber(NUMBER);
        sevseg.refreshDisplay();
        if(NUMBER>=0){
            return;
        }
    }
}

void step_two(){
    float NUMBER = -0.9;
    for(;;){
        NUMBER_TEMP++;
        if(NUMBER_TEMP==speed){
            NUMBER_TEMP = 0;
            NUMBER += 0.1;
        }

        sevseg.setNumber(NUMBER,LOCATION);
        sevseg.refreshDisplay();

        if(NUMBER>0){
            return;
        }
    }
}

void step_three(){
    int NUMBER = 0;
    for(;;){
        NUMBER_TEMP++;
        if(NUMBER_TEMP==speed){
            NUMBER_TEMP = 0;
            NUMBER += 1;
        }
        switch(NUMBER){
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
            step_four(NUMBER);
            step_four(NUMBER);
            step_four(NUMBER);
            NUMBER++;
            break;
            default:
            break;
        }

        sevseg.setNumber(NUMBER);
        sevseg.refreshDisplay();

        if(NUMBER>20){
            return;
        }
    }
}

void step_four(int number){
    long temp = 0;
    //NUMBER = 2;
    for(;;){
        //static long temp = 0;
        temp++;
        if(temp>1000){
            sevseg.blank();
            delay(500);
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
    step_one();
    step_two();
    step_three();
}

    /**
     * NUMBER�����֣�LOCATION��С����λ�ã������ұ������ƶ�λ����
     * ��LOCATIONΪ-1����ʱ����С����
     * ��NUMBER��float����ʱ��LOCATION��С�����λ��
     * ������Χ��ʾ----
     * ����trueʱ��ʾΪ16����
     */    
    //--sevseg.setNumber(NUMBER);//��С����
    //--sevseg.setNumber(NUMBER,LOCATION);//������
    //--sevseg.setNumber(NUMBER,LOCATION,true);//16����


    /**
     * ��ʾ�ַ�����������
     * ֻ�������ַ����� ������-������.��������ʾ                        
     */
    //--sevseg.setChars(STRING);

    /**
     *ˢ�£�����
     */
    //--sevseg.refreshDisplay();


    /**
     * ��˸
     */
    //--sevseg.blank();

    /**
     * ����������-200��200��
     * ������0-100֮��
     */
    //--sevseg.setBrightness(LIGHTVALUE);



