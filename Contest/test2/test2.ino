/**
 * �������
 * 
 */

/**        4  3
 *          ++       ���ϵ�������
 * ---|--       =   {�ұ�enable��N4
 * ---|         =   {N3��N2
 * ---|         =   {N1�����enable
 * ---|         +lb
 * ---|         +raD
 * ---|--       +rbv
 *         ++
 *        1  2
 */

/**
 * 12v����ӵ�Դ������ͨ12v��ӵ�Դʱ��5vΪ������ţ�����Ϊarduino���幩��
 * ʵ�ʴ��������ĵ�ѹ���2v
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

#define lr 5//����ٶ�
#define rr 6//�ұ��ٶ�

#define defspeed 0//Ĭ���ٶ�



void setup(){
    pinMode(13,OUTPUT);//��ȫֹͣ����ʾ��
    pinMode(la,OUTPUT);
    pinMode(lb,OUTPUT);
    pinMode(ra,OUTPUT);
    pinMode(rb,OUTPUT);
    pinMode(lr,OUTPUT);
    pinMode(rr,OUTPUT);
    stop();//�տ�ʼ��ֹͣ
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
//      * ȫ��ֹͣ
//      */
// void stop(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     //while(1){}
// }

// /**
//  * ��Զֹͣ������13�ŵ���˸
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
//  * ��ǰ�ߣ�����Ϊ�ٶ�
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
//  * ���ˣ�����Ϊ�ٶ�
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
//  * ����ת��ԭ��ʱ���٣��ڴ˹�������Ȼ����ǰ��
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
//  * ����ת��ԭ��ʱ���٣���Ȼ��ǰ��
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
//  * ������ת�����ַ����˶�
//  * ����ѭ����ֱ��OUT3Խ������
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
//  * ������ת��˵��ͬ��
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
//  * ͬaction1
//  */
// void stop(){
//     digitalWrite(la,LOW);
//     digitalWrite(lb,LOW);
//     digitalWrite(ra,LOW);
//     digitalWrite(rb,LOW);
//     //while(1){}
// }

// /**
//  * ͬaction1
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
//  * ͬaction1
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
//  * ͬaction1
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
//  * ͬaction1
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
//  * ͬaction1
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
//  * ͬaction1
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
//  * ͬaction1
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
 * ����ͬaction1������ѭ��ֱ��OUT3���������
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
 * ͬ��
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