#define MA A0
#define MD D0
#define M_PIN A0//黑线接A0;
#define LED D2//白线接D2;
int sT = 280;//等待LED弢�启的时间昄1�7280μs
int dT = 40;//整个脉冲持续时间丄1�7320μs。因此，我们还需再等径1�740μs
int sleepTime = 9680;
float vM = 0;//模拟倄1�7
float cV = 0;//电压倄1�7
float dD = 0;//粉尘密度

/*GND负极接地，VCC正极5V＄1�7
 *预热20s
 */
void setup(){
  Serial.begin(115200);//接口速率必须115200
  pinMode(MA,INPUT);
  pinMode(MD,INPUT);
  pinMode(LED,OUTPUT);
}
void loop(){
  if(digitalRead(MD==HIGH))//监测到则弢�关信号端为高电平，低电平信号灯亮
  {
    Serial.print("There is something smell bad...");
    Serial.print("Value:");
    Serial.println(analogRead(MA));//打印模拟倄1�7
  }
  else
  {
    Serial.println("Nothing");
  }
  digitalWrite(LED,LOW); //弢�启内部LED
  delayMicroseconds(sT); // 弢�启LED后的280us的等待时闄1�7
  vM=analogRead(M_PIN); // 读取模拟倄1�7
  delayMicroseconds(dT); // 40us等待时间
  digitalWrite(LED,HIGH); // 关闭LED
  delayMicroseconds(sleepTime);
  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage
  cV = vM * (5.0 / 1024.0); //将模拟��转换为电压倄1�7
  dD = 0.17 * cV - 0.1; //将电压��转换为粉尘密度输出单位
  Serial.print("Raw Signal Value ＄1�70-1023）： ");
  Serial.print(vM);
  Serial.print(" - Voltage＄1�7 ");
  Serial.print(cV);
  Serial.print("- Dust Density＄1�7");
  Serial.println(dD); //朢�终浓度��，输出单位＄1�7 毫克/立方籄1�7
  delay(1000);
}

