#define siglnal_soil A1

void setup(){
    Serial.begin(9600);
}

void loop(){
    int moisture = map(analogRead(siglnal_soil),0,1023,0,100);
    Serial.println(moisture);
}