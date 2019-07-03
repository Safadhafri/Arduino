int analog = A0;
int input = 0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    input = analogRead(analog);
    //Serial.println(input);
    Serial.println(input*(5.0/1023.0));
    //打印电压值（转换为0-5）
    delay(500);
}
/*
通过模拟输入得到对应的电压值，并打印日志
注意：uno板的输出电压是5V，模拟输入可以检测到0-1023之间的数

 */