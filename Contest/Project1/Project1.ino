/**
 * 项目：从-9、-8数到-1，再从-0.9、0.8到0，再从0、1到20，素数闪三下
 * 项目状态：完成
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
 *    共1   A    F  共2 共3  B   
 *     |    |   |   |   |   |
 *     \\\\\\\\\\\\\\\\\\\\\\\
 *     \\\\\\\\\\\\\\\\\\\\\\\
 *     \\\\.\\\\\.\\\\.\\\\\.\
 *     |    |   |   |   |   |
 *     E    D   DP  C   G  共4  
 */


SevSeg sevseg;

//--int LIGHTVALUE = 90;//光亮，0-100
//--String STRING = "Hello,World!";//显示的字符串
int temp=0;
//--int NUMBER = 0;//显示数字
int NUMBER_TEMP = 0;//延时中间值
int LOCATION = 1;//小数点位数
int speed = 2000;//更新速度
byte HARDWARE = COMMON_CATHODE;//接线模式:COMMON_CATHODE=共阴极/COMMON_ANODE=共阳极。
byte NUMDIGITS = 4;//数码管位数（几个数字）

//               共：1，2，3，4
byte DIGIEPINS[] = {2, 3, 4, 5};//公共引脚连接的引脚位置

//                    A, B, C, D, E,  F,  G,  DP
byte SEGMENTPINS[] = {6, 7, 8, 9, 10, 11, 12, 13};//数码管从A-DP依次连接的引脚位置

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
    sevseg.begin(HARDWARE,NUMDIGITS,DIGIEPINS,SEGMENTPINS);//初始化
}

void loop(){
    step_one();
    step_two();
    step_three();
}

    /**
     * NUMBER是数字，LOCATION是小数点位置（从最右边向左移动位数）
     * 当LOCATION为-1或无时，无小数点
     * 当NUMBER是float类型时，LOCATION是小数点后位数
     * 超出范围显示----
     * 当有true时显示为16进制
     */    
    //--sevseg.setNumber(NUMBER);//无小数点
    //--sevseg.setNumber(NUMBER,LOCATION);//见下文
    //--sevseg.setNumber(NUMBER,LOCATION,true);//16进制


    /**
     * 显示字符，尽可能像
     * 只有数字字符、‘ ’、‘-’、‘.’可以显示                        
     */
    //--sevseg.setChars(STRING);

    /**
     *刷新，必须
     */
    //--sevseg.refreshDisplay();


    /**
     * 闪烁
     */
    //--sevseg.blank();

    /**
     * 光亮调整（-200到200）
     * 尽量再0-100之间
     */
    //--sevseg.setBrightness(LIGHTVALUE);



