/**
 * 动作2,使用进程
 * 利用switch判断
 * 其他事项都和action1一样
 */
#define out2 12
#define out3 11
#define out4 10
#define out5 9

#define la 7//N1
#define lb 8//N2

#define ra 4//N3
#define rb 2//N4

#define lr 5//左边速度
#define rr 6//右边速度

#define defspeed 0//默认速度


/**
 * 定义各个判断返回值
 */
#define gl 1
#define gr 2
#define ga 0
#define st 4
#define glq 5
#define grq 6


void setup(){
    //初始化进程
    // PT_INIT(&pt2);
    // PT_INIT(&pt3);
    // PT_INIT(&pt4);
    // PT_INIT(&pt5);
    // PT_INIT(&pt1);
    //pinMode(light,OUTPUT);
    //探测接口初始化
    pinMode(out2,INPUT);
    pinMode(out3,INPUT);
    pinMode(out4,INPUT);
    pinMode(out5,INPUT);
    //Serial.begin(9600);
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
    switch (judge()){
    case ga:
        ahead(defspeed);
        break;
    case gl:
        turn_left(defspeed,100);
        break;
    case glq:
        turn_left_quickly(100);
        break;
    case gr:
        turn_right(defspeed,100);
        break;
    case grq:
        turn_right_quickly(100);
        break;
    case st:
        stop_long();
    default:
        break;
    }
}

int judge(){
    
    if(digitalRead(out2)==1 && digitalRead(out3)==1 && digitalRead(out4)==1 && digitalRead(out5)==1){
        //停止
        return st;
    }else if(digitalRead(out2)==1 && digitalRead(out3)==0 && digitalRead(out4)==0 && digitalRead(out5)==0){
        //急速左转
        return glq;
    }else if(digitalRead(out2)==0 && digitalRead(out3)==1 && digitalRead(out4)==0 && digitalRead(out5)==0){
        //左转
        return gl;
    }else if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==1 && digitalRead(out5)==0){
        //右转
        return gr;
    }else if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==0 && digitalRead(out5)==1){
        //急速右转
        return grq;
    }else if(digitalRead(out2)==0 && digitalRead(out3)==0 && digitalRead(out4)==0 && digitalRead(out5)==0){
        //前进
        return ga;
    }
}
/**
     * 全部停止
     */
void stop(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //while(1){}
}

/**
 * 永远停止，并且13号灯闪烁
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
 * 向前走，参数为速度
 */
void ahead(){
    //analogWrite(lr,rate);
    //analogWrite(rr,rate);
    //digitalWrite(lr,HIGH);
    //digitalWrite(rr,HIGH);
    digitalWrite(la,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    
}
/**
 * 后退，参数为速度
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
 * 向左转，原理时差速，在此过程中依然在向前进
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
 * 向右转，原理时差速，依然向前进
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
 * 急速左转，两轮反向运动
 * 并且循环，直到OUT3越过黑线
 */
void turn_left_quickly(){
    int temp = 0;
    while(temp<2){
        digitalWrite(la,LOW);
        digitalWrite(lb,HIGH);
        digitalWrite(ra,HIGH);
        digitalWrite(rb,LOW);
        analogWrite(lr,50);
        analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
        if(digitalRead(out3)==0 && temp==1){
            temp = 2;
        }
    }
}
/**
 * 急速右转，说明同上
 */
void turn_right_quickly(){
    int temp = 0;
    while(temp<2){
        digitalWrite(la,HIGH);
        digitalWrite(lb,LOW);
        digitalWrite(ra,LOW);
        digitalWrite(rb,HIGH);
        //analogWrite(lr,50);
        //analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
        if(digitalRead(out3)==0 && temp==1){
            temp = 2;
        } 
    }
    
    //delay(time);
}