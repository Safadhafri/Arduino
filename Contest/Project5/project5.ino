/**
 * 项目：寻迹小车
 * 项目状态：进行中
 * 
 */

/**
 * 1.电机驱动--完成
 * 2.转向系统--完成
 * 3.探测模块--完成
 * 4.代码整合--完成
 */

/**
 * 物体数据：
 * 1.底盘距离地面4.5±0.3cm
 * 2.传感器最好离地面1-2cm，且稍微向接线一侧偏移
 */

/**
 * 思路1：让黑线在OUT3、4之间
 * 1.当OUT2-5都为1时：直行
 * 2.当OUT3为0，向左转（中等速度），直到OUT3变为1，再向右转一点，尽量使其与黑线平行
 * 3.当OUT4为0，向右转（中等速度），知道OUT4变为1，再向左转一点，尽量使其与黑线平行
 * 4.当OUT2为0，停下原地向左转，使OUT3变为1再变为1，之后再向左转一点
 * 5.当OUT5为0，停下原地向右转，使OUt4变为1再变为1，之后再向右转一点
 * 6.当OUT2-5都为0时，停止
 * 7.打开电源，延迟3s，之后开始
 */

/**
 * 思路2：让黑线一直处在OUT3下面
 * 1.当OUT3为0时，直行
 * 2.当OUT3变为1时，需要判断车向那个方向偏（第一次无法判断），需要定义变量：偏移状态
 * 3.当OUT2为0时，向左转（中等速度），直到OUT3变为0，同时更新偏移：向左偏
 * 4.当OUT4为0时，向右转（中等速度），直到OUT3变为0，同时更新偏移：向右偏
 * 5.经过3/4步骤后，当OUT3从0变为1时，向偏移状态的反方向旋转，同时反转偏移状态
 * 6.当OUT1为0，停下原地向左转，直到OUT3变为0，同时更新偏移：向左偏
 * 7.当OUT5为0，停下原地向右转，直到OUT3变为0，同时更新偏移：向右偏
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 代码1：思路一
 * 代码状态：废弃，进程库函数有问题，会随机陷在某一个进程中无法自拔。。。
 */
//....
/**
 * 动作1,使黑线在OUT3和OUT4之间
 * 利用多线程
 * 通常线程是前进，强制一定时间后退出
 * 当2、3或4、5变为1后，进入线程3、4
 * 在线程3、4中首先判断是否停止，再转弯（分为大转和小转）
 * 在转弯动作中有时间限制
 * 注意：在每个动作之后都是延续这个动作，没有停止，如果有需要，可以加上
 * 
 * 注意：对于进程的时间管理应该可以用millon()-lasttime<???来进行
 */


/**
 * 代码二：思路2
 * 代码状态：启用
 */

//定义探测模块的引脚位置
#define out1 3
#define out2 12
#define out3 11
#define out4 10
#define out5 9

//定义电机控制模块引脚
#define la 7//N1
#define lb 8//N2

#define ra 4//N3
#define rb 2//N4

#define lr 5//左边速度
#define rr 6//右边速度

//#define defspeed 0//默认速度

/**
 * 判断函数返回值
 */
#define gl 1//go left
#define gr 2//go right
#define ga 0//go ahead
#define st 4//stop
#define glq 5//go left quicklly
#define grq 6//go right quickly

//偏移状态
#define deflection_left 1
#define deflection_right 3

#define dtime 100

//偏移状态
static int deflection = 0;

void setup(){
    
    //探测接口初始化
    pinMode(out2,INPUT);
    pinMode(out3,INPUT);
    pinMode(out4,INPUT);
    pinMode(out5,INPUT);
    Serial.begin(9600);
    //digitalWrite(light,HIGH);
    pinMode(13,OUTPUT);//完全停止后提示用
    //电机接口初始化
    pinMode(la,OUTPUT);
    pinMode(lb,OUTPUT);
    pinMode(ra,OUTPUT);
    pinMode(rb,OUTPUT);

    pinMode(lr,OUTPUT);
    pinMode(rr,OUTPUT);
    //stop();//刚开始是停止
    delay(4000);
}


void loop(){
    ahead();
    Serial.print(analogRead(lr));
    Serial.println(analogRead(rr));
}

void run(){
    switch (judge()){
    case ga:
        ahead();
        //delay(dtime);
        //stop();
        break;
    case gl:
        turn_left();
        //delay(dtime);
        //stop();
        //delay(dtime);
        break;
    case glq:
        turn_left_quickly();
        //delay(dtime);
        //stop();
        break;
    case gr:
        turn_right();
        ////delay(dtime);
        //stop();
        //delay(dtime);
        break;
    case grq:
        turn_right_quickly();
        //delay(dtime);
        //stop();
        break;
    case st:
        stop_long();
        //delay(dtime);
        //stop();
    default:
        break;
    }
}

/**
 * 判断函数，用于判断小车目前状态，并返回对应的值
 */
int judge(){
    if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==0){
        //优先判断是否停止
        return st;
    }else if(digitalRead(out2)==0){
        deflection = deflection_left;
        //左转
        return gr;
    }else if(digitalRead(out4)==0){
        deflection = deflection_right;
        //右转
        return gl;
    }else if(digitalRead(out1)==0){
        deflection = deflection_left;
        //急速左转
        return grq;
    }else if(digitalRead(out5)==0){
        deflection = deflection_right;
        //急速右转
        return glq;
    }else if(digitalRead(out3)==0){
        //偏移状态反向
        if(deflection==deflection_left){
            deflection = deflection_right;
        }else if(deflection==deflection_right){
            deflection = deflection_left;
        }
        //前进
        return ga;
    }else if(digitalRead(out3)==1){
        if(deflection==0){
            //应该转向，但偏移状态未赋值，故直行
            return ga;
        }else if(deflection==deflection_left){
            //deflection = deflection_right;
            //偏移右转
            return gr;
        }else if(deflection==deflection_right){
            //deflection = deflection_left;
            //偏移左转
            return gl;
        }
    }
}
/**
 * 停止
 */
void stop(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //while(1){}
}

/**
 * 完全停止，并闪烁13号灯提示
 */
void stop_long(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    while(1){
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(100);
        digitalWrite(13,HIGH);
        delay(100);
        digitalWrite(13,LOW);
        delay(100);
    }
}

/**
 * 直行
 */
void ahead(){
    digitalWrite(la,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    analogWrite(lr,400);
    analogWrite(rr,400);
}

/**
 * 后退
 */
void back(){
    digitalWrite(la,LOW);
    digitalWrite(lb,HIGH);
    digitalWrite(ra,LOW);
    digitalWrite(rb,HIGH);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate);
}

/**
 * 左转
 */
void turn_left(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate+50);
    //delay(time);
}

/**
 * 右转
 */
void turn_right(){
    digitalWrite(la,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //analogWrite(lr,rate+50);
    //analogWrite(rr,rate);
    //delay(time);
}

/**
 * 快速左转，直到OUT3再次回到黑线上
 */
void turn_left_quickly(){
    int temp = 0;
    //while(temp<1){
        digitalWrite(la,LOW);
        digitalWrite(lb,HIGH);
        digitalWrite(ra,HIGH);
        digitalWrite(rb,LOW);
        //analogWrite(lr,50);
        //analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
    //}
    
}

/**
 * 快速右转，直到OUT3再次回到黑线上
 */
void turn_right_quickly(){
    int temp = 0;
    //while(temp<1){
        digitalWrite(la,HIGH);
        digitalWrite(lb,LOW);
        digitalWrite(ra,LOW);
        digitalWrite(rb,HIGH);
        //analogWrite(lr,50);
        //analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
    //}
}