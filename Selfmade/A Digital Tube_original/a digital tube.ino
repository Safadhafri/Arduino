#define u_u 2
#define u_l 3
#define u_r 4
#define m 5
#define d_l 6
#define d_d 7
#define d_r 8
#define p 9

/*
                  2
            \\\\\\\\\\\
            \         \
           3\         \4
            \    5    \
            \\\\\\\\\\\
            \         \
           6\         \8
            \    7    \
            \\\\\\\\\\\
                        .9
 */


int number[17][8] = 
{
   //2,3,4,5,6,7,8,9
    {1,1,1,0,1,1,1,0},//0
    {0,0,1,0,0,0,1,0},//1
    {1,0,1,1,1,1,0,0},//2
    {1,0,1,1,0,1,1,0},//3
    {0,1,1,1,0,0,1,0},//4
    {1,1,0,1,0,1,1,0},//5
    {1,1,0,1,1,1,1,0},//6
    {1,0,1,0,0,0,1,0},//7
    {1,1,1,1,1,1,1,0},//8
    {1,1,1,1,0,1,1,0},//9
    {1,1,1,1,1,0,1,1},//A
    {1,1,1,1,1,1,1,1},//B
    {1,1,0,0,1,1,0,1},//C
    {1,1,1,0,1,1,1,1},//D
    {1,1,0,1,1,1,0,1},//E
    {1,1,0,1,1,0,0,1},//F
    {0,1,1,1,0,0,0,1},//.
};

void setup(){
    pinMode(u_u,OUTPUT);
    pinMode(u_l,OUTPUT);
    pinMode(u_r,OUTPUT);
    pinMode(m,OUTPUT);
    pinMode(d_l,OUTPUT);
    pinMode(d_d,OUTPUT);
    pinMode(d_r,OUTPUT);
    pinMode(p,OUTPUT);
    Serial.begin(9600);
}

void loop(){
    for(int i=0;i<17;++i){
        // digitalWrite(u_u,number[i][0]);
        // digitalWrite(u_l,number[i][1]);
        // digitalWrite(u_r,number[i][2]);
        // digitalWrite(m,number[i][3]);
        // digitalWrite(d_l,number[i][4]);
        // digitalWrite(d_d,number[i][5]);
        // digitalWrite(d_r,number[i][6]);
        // digitalWrite(p,number[i][7]);
        // Serial.println(i);
        // delay(1000);
        //ÁíÒ»ÖÖÐ´·¨

        for(int n=0;n<8;++n){
            digitalWrite((n+2),number[i][n]);
            Serial.println(i);
            
        }
        delay(1000);
    }
}