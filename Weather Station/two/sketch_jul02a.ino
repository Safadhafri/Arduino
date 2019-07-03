
//#define sensorValue A0
#define LED_R = 11;
#define LED_G = 10;
#define LED_B = 9;
String str;

void setup()
{
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}
  //Serial.begin(9600);}
void loop(){
  int sensorValue = analogRead(A0);
  sensorValue=map(sensorValue,1010,20,0,100);
  //str=String(sensorValue+'%');
  if(sensorValue<33){
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  }else if(sensorValue>66){
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  }else{
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  }
  delay(2000);
}
