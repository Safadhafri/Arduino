/**
 * 电机控制
 * 
 */

/**        4  3
 *          ++       从上到下排序
 * ---|--       =   {右边enable、N4
 * ---|         =   {N3、N2
 * ---|         =   {N1、左边enable
 * ---|         +lb
 * ---|         +raD
 * ---|--       +rbv
 *         ++
 *        1  2
 */

/**
 * 12v是外接电源，当接通12v外接电源时，5v为输出引脚，可以为arduino主板供电
 * 实际传输给电机的电压会减2v
 */


//#define light 7
//#define lrt
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



void setup(){
    pinMode(13,OUTPUT);//完全停止后提示用
    pinMode(la,OUTPUT);
    pinMode(lb,OUTPUT);
    pinMode(ra,OUTPUT);
    pinMode(rb,OUTPUT);
    pinMode(lr,OUTPUT);
    pinMode(rr,OUTPUT);
    stop();//刚开始是停止
    delay(1000);
}

void loop(){
    //ahead();
    //back();
    turn_left();
    delay(4000);
    turn_right();
    //turn_left_quickly();
    delay(4000);
    //stop_long();
    
    //delay(4000);
    //stop_long();
}

////////////////////////////////////////////////////////////////////////////action1
// /**
//      * 全部停止
//      */
// void stop(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     //while(1){}
// }

// /**
//  * 永远停止，并且13号灯闪烁
//  */
// void stop_long(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     while(1){
//         digitalWrite(13,HIGH);
//         delay(1000);
//         digitalWrite(13,LOW);
//         delay(100);
//         digitalWrite(13,HIGH);
//         delay(100);
//         digitalWrite(13,LOW);
//         delay(100);
//     }
// }
// /**
//  * 向前走，参数为速度
//  */
// void ahead(){
//     //analogWrite(lr,rate);
//     //analogWrite(rr,rate);
//     //digitalWrite(lr,HIGH);
//     //digitalWrite(rr,HIGH);
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
    
// }
// /**
//  * 后退，参数为速度
//  */
// void back(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,HIGH);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,HIGH);
//     //analogWrite(lr,rate);
//     //analogWrite(rr,rate);
// }

// /**
//  * 向左转，原理时差速，在此过程中依然在向前进
//  */
// void turn_left(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
//     //analogWrite(lr,rate);
//     //analogWrite(rr,rate+50);
//     //delay(time);
// }

// /**
//  * 向右转，原理时差速，依然向前进
//  */
// void turn_right(){
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     //analogWrite(lr,rate+50);
//     //analogWrite(rr,rate);
//     //delay(time);
// }
// /**
//  * 急速左转，两轮反向运动
//  * 并且循环，直到OUT3越过黑线
//  */
// void turn_left_quickly(){
//     int temp = 0;
//     while(temp<2){
//         digitalWrite(la,LOW);
//         digitalWrite(lb,HIGH);
//         digitalWrite(ra,HIGH);
//         digitalWrite(rb,LOW);
//         analogWrite(lr,50);
//         analogWrite(rr,50);
//         if(digitalRead(out3)==1 && temp==0){
//             temp = 1;
//         }  
//         if(digitalRead(out3)==0 && temp==1){
//             temp = 2;
//         }
//     }
// }
// /**
//  * 急速右转，说明同上
//  */
// void turn_right_quickly(){
//     int temp = 0;
//     while(temp<2){
//         digitalWrite(la,HIGH);
//         digitalWrite(lb,LOW);
//         digitalWrite(ra,LOW);
//         digitalWrite(rb,HIGH);
//         //analogWrite(lr,50);
//         //analogWrite(rr,50);
//         if(digitalRead(out3)==1 && temp==0){
//             temp = 1;
//         }  
//         if(digitalRead(out3)==0 && temp==1){
//             temp = 2;
//         } 
//     }
    
//     //delay(time);
// }
///////////////////////////////////////////////////////////////////////////////action1


///////////////////////////////////////////////////////////////////////////////action2

// /**
//  * 同action1
//  */
// void stop(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     //while(1){}
// }

// /**
//  * 同action1
//  */
// void stop_long(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     while(1){
//         digitalWrite(13,HIGH);
//         delay(1000);
//         digitalWrite(13,LOW);
//         delay(100);
//         digitalWrite(13,HIGH);
//         delay(100);
//         digitalWrite(13,LOW);
//         delay(100);
//     }
// }

// /**
//  * 同action1
//  */
// void ahead(int rate){
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
//     analogWrite(lr,rate);
//     analogWrite(rr,rate);
// }

// /**
//  * 同action1
//  */
// void back(int rate){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,HIGH);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,HIGH);
//     analogWrite(lr,rate);
//     analogWrite(rr,rate);
// }

// /**
//  * 同action1
//  */
// void turn_left(int rate,int time){
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
//     analogWrite(lr,rate);
//     analogWrite(rr,rate+50);
//     delay(time);
// }

// /**
//  * 同action1
//  */
// void turn_right(int rate,int time){
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
//     analogWrite(lr,rate+50);
//     analogWrite(rr,rate);
//     delay(time);
// }

// /**
//  * 同action1
//  */

// void turn_left_quickly(){
//     int temp = 0;
//     while(temp<2){
//         digitalWrite(la,LOW);
//         digitalWrite(lb,HIGH);
//         digitalWrite(ra,HIGH);
//         digitalWrite(rb,LOW);
//         analogWrite(lr,50);
//         analogWrite(rr,50);
//         if(digitalRead(out3)==1 && temp==0){
//             temp = 1;
//         }  
//         if(digitalRead(out3)==0 && temp==1){
//             temp = 2;
//         }
//     }
// }

// /**
//  * 同action1
//  */
// void turn_right_quickly(){
//     int temp = 0;
//     while(temp<2){
//         digitalWrite(la,HIGH);
//         digitalWrite(lb,LOW);
//         digitalWrite(ra,LOW);
//         digitalWrite(rb,HIGH);
//         analogWrite(lr,50);
//         analogWrite(rr,50);
//         if(digitalRead(out3)==1 && temp==0){
//             temp = 1;
//         }  
//         if(digitalRead(out3)==0 && temp==1){
//             temp = 2;
//         } 
//     }
    
//     //delay(time);
// }
//////////////////////////////////////////////////////////////////////////////////////////////////action2

//////////////////////////////////////////////////////////////////////////////////////actino3

void stop(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,LOW);
    digitalWrite(rb,LOW);
    //while(1){}
}

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

void ahead(){
    digitalWrite(la,HIGH);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate);
}

void back(){
    digitalWrite(la,LOW);
    digitalWrite(lb,HIGH);
    digitalWrite(ra,LOW);
    digitalWrite(rb,HIGH);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate);
}

void turn_left(){
    digitalWrite(la,LOW);
    digitalWrite(lb,LOW);
    digitalWrite(ra,HIGH);
    digitalWrite(rb,LOW);
    //analogWrite(lr,rate);
    //analogWrite(rr,rate+50);
    //delay(time);
}


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
 * 大体同action1，但会循环直到OUT3到达黑线上
 */
void turn_left_quickly(){
    int temp = 0;
    while(temp<1){
        digitalWrite(la,LOW);
        digitalWrite(lb,HIGH);
        digitalWrite(ra,HIGH);
        digitalWrite(rb,LOW);
        analogWrite(lr,50);
        analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
    }
    
}

/**
 * 同上
 */
void turn_right_quickly(){
    int temp = 0;
    while(temp<1){
        digitalWrite(la,HIGH);
        digitalWrite(lb,LOW);
        digitalWrite(ra,LOW);
        digitalWrite(rb,HIGH);
        analogWrite(lr,50);
        analogWrite(rr,50);
        if(digitalRead(out3)==1 && temp==0){
            temp = 1;
        }  
    }
}
///////////////////////////////////////////////////////////////////////////////////////////actino3

/////////////////////////////////////////////////////////////////////////////////////////////action4

// void stop(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     //while(1){}
// }

// void stop_long(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     while(1){
//         digitalWrite(13,HIGH);
//         delay(1000);
//         digitalWrite(13,LOW);
//         delay(100);
//         digitalWrite(13,HIGH);
//         delay(100);
//         digitalWrite(13,LOW);
//         delay(100);
//     }
// }

// void ahead(int rate){
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
//     analogWrite(lr,rate);
//     analogWrite(rr,rate);
// }

// void back(int rate){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,HIGH);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,HIGH);
//     analogWrite(lr,rate);
//     analogWrite(rr,rate);
// }

// void turn_left(int rate,int time){
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
//     analogWrite(lr,rate);
//     analogWrite(rr,rate+50);
//     delay(time);
// }


// void turn_right(int rate,int time){
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
//     analogWrite(lr,rate+50);
//     analogWrite(rr,rate);
//     delay(time);
// }

// void turn_left_quickly(int time){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,HIGH);
//     digitalWrite(ra,HIGH);
//     digitalWrite(rb,LOW);
//     analogWrite(lr,50);
//     analogWrite(rr,50);
//     delay(time);
// }

// void turn_right_quickly(int time){
//     digitalWrite(la,HIGH);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,HIGH);
//     analogWrite(lr,50);
//     analogWrite(rr,50);
//     delay(time);
// }
///////////////////////////////////////////////////////////////////////////////////////action4