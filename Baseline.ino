void setup(){
    pinMode(13,OUTPUT);
}

void loop(){
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
}
/*
ԭʼ����
��1s����0.1s,��0.1s����0.1s
 */