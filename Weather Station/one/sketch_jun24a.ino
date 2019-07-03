#define MA A0
#define MD D0
#define M_PIN A0//榛戠嚎鎺0;
#define LED D2//鐧界嚎鎺2;
int sT = 280;//绛夊緟LED寮€鍚殑鏃堕棿鏄�280渭s
int dT = 40;//鏁翠釜鑴夊啿鎸佺画鏃堕棿涓�320渭s銆傚洜姝わ紝鎴戜滑杩橀渶鍐嶇瓑寰�40渭s
int sleepTime = 9680;
float vM = 0;//妯℃嫙鍊�
float cV = 0;//鐢靛帇鍊�
float dD = 0;//绮夊皹瀵嗗害

/*GND璐熸瀬鎺ュ湴锛孷CC姝ｆ瀬5V锛�
 *棰勭儹20s
 */
void setup(){
  Serial.begin(115200);//鎺ュ彛閫熺巼蹇呴』115200
  pinMode(MA,INPUT);
  pinMode(MD,INPUT);
  pinMode(LED,OUTPUT);
}
void loop(){
  if(digitalRead(MD==HIGH))//鐩戞祴鍒板垯寮€鍏充俊鍙风涓洪珮鐢靛钩锛屼綆鐢靛钩淇″彿鐏寒
  {
    Serial.print("There is something smell bad...");
    Serial.print("Value:");
    Serial.println(analogRead(MA));//鎵撳嵃妯℃嫙鍊�
  }
  else
  {
    Serial.println("Nothing");
  }
  digitalWrite(LED,LOW); //寮€鍚唴閮↙ED
  delayMicroseconds(sT); // 寮€鍚疞ED鍚庣殑280us鐨勭瓑寰呮椂闂�
  vM=analogRead(M_PIN); // 璇诲彇妯℃嫙鍊�
  delayMicroseconds(dT); // 40us绛夊緟鏃堕棿
  digitalWrite(LED,HIGH); // 鍏抽棴LED
  delayMicroseconds(sleepTime);
  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage
  cV = vM * (5.0 / 1024.0); //灏嗘ā鎷熷€艰浆鎹负鐢靛帇鍊�
  dD = 0.17 * cV - 0.1; //灏嗙數鍘嬪€艰浆鎹负绮夊皹瀵嗗害杈撳嚭鍗曚綅
  Serial.print("Raw Signal Value 锛�0-1023锛夛細 ");
  Serial.print(vM);
  Serial.print(" - Voltage锛� ");
  Serial.print(cV);
  Serial.print("- Dust Density锛�");
  Serial.println(dD); //鏈€缁堟祿搴﹀€硷紝杈撳嚭鍗曚綅锛� 姣厠/绔嬫柟绫�
  delay(1000);
}

