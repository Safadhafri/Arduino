_int pin[3] = {12,11,10};

void setup(){
    pinMode(13,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);
    Serial.begin(9600);
}

void loop(){
    digitalWrite(13,HIGH);
    delay(1000);
    for(int i=0;i<3;++i){
        digitalWrite(pin[i],HIGH);
        Serial.print(digitalRead(pin[0]));
        Serial.print("   ");
        Serial.print(digitalRead(pin[1]));
        Serial.print("   ");
        Serial.print(digitalRead(pin[2]));
        Serial.println(" ");
        delay(100);
    }
    digitalWrite(13,LOW);
    delay(1000);
    for(int i=0;i<3;++i){
        digitalWrite(pin[i],LOW);
        Serial.print(digitalRead(pin[0]));
        Serial.print("   ");
        Serial.print(digitalRead(pin[1]));
        Serial.print("   ");
        Serial.print(digitalRead(pin[2]));
        Serial.println(" ");
        delay(100);
    }
    digitalWrite(13,HIGH);
    delay(2000);
    
}
/*
跑马灯——已测试
三者依次亮，依次灭

 */