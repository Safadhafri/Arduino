

void setup(){
    pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
    Serial.begin(9600);
}

void loop(){
    analogWrite(6,255);
    analogWrite(5,255);
    Serial.print(analogRead(6));
    Serial.print("   ");
    Serial.println(analogRead(5));
}
