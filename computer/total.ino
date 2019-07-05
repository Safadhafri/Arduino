/**
 * 所需的库
 */
//#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <DHT.h>    //https://github.com/markruys/arduino-DHT

/**
 * 登陆设置
 */
#define WLAN_SSID    "dudududu"   //wifi账号
#define WLAN_PASS   "qazmlpwsxnko"      //wifi密码
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883   // use 8883 for SSL
#define AIO_USERNAME    "shendu"  //账户名称
#define AIO_KEY         "862f6d912d894503b543339f8f002b96"  //KEY

/**
 * 网络设置
 */
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish humidity= Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/humidity");
Adafruit_MQTT_Publish temperature= Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temperature");
Adafruit_MQTT_Publish water= Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/water");
Adafruit_MQTT_Publish smell = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/smell");
Adafruit_MQTT_Publish soil = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/soil");
void MQTT_connect();
uint32_t x=0;

/**
 * 参数设置和变量定义
 */
#define K A0
#define data D5
#define LED_R  D1
#define LED_G  D3
#define LED_B  D4
String str;
#define MD D0
#define LED D2
int sT = 280;
int dT = 40;
int sleepTime = 9680;
float vM = 0;
float cV = 0;
float dD = 0;


void setup(){
  /**
   * light
   */
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  /**
   * smell sensor
   */
  pinMode(K,INPUT);
  pinMode(MD,INPUT);
  pinMode(LED,OUTPUT);
  /**
   * soil moisture
   */
  Serial.begin(9600);
  /**
   * temperature
   */
  dht.setup(PIN);
  /**
   * 连接反馈
   */
  Serial.println(F("Adafruit MQTT demo"));
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
}


void loop(){
  MQTT_connect();
  light();
  //smell();
  //soil();
  //water();
  //temperature();
  /**
   * 读取空气信息
   */
  float value1=smell();
  if (! smell.publish(value1++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  /**
   * 读取土壤湿度
   */
  int value2=soil();
  if (! soil.publish(value2++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  /**
   * 读取空气湿度
   */
  double value3=humidity(); 
  if (! humidity.publish(value3++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  /**
   * 读取温度
   */
  double value4=temperature(); 
  if (! temperature.publish(value4++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  /**
   * 读取水位信息
   */
  long value5=water();
  if (! water.publish(value5++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
}
/**
 * 闪灯
 */
void light(){
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * 以下是各个模块的控制和读数函数
 */
/**
 * smell sensor
 */
float smell(){
    if(digitalRead(MD==HIGH))//鐩戞祴鍒板垯寮拷鍏充俊鍙风涓洪珮鐢靛钩锛屼綆鐢靛钩淇″彿鐏寒
    {
        Serial.print("There is something smell bad...");
        Serial.print("Value:");
        Serial.println(analogRead(K));//鎵撳嵃妯℃嫙鍊�1锟�7
    }
    else
    {
        Serial.println("Nothing");
    }
    digitalWrite(LED,LOW); //寮拷鍚唴閮↙ED
    delayMicroseconds(sT); // 寮拷鍚疞ED鍚庣殑280us鐨勭瓑寰呮椂闂�1锟�7
    vM=analogRead(K); // 璇诲彇妯℃嫙鍊�1锟�7
    delayMicroseconds(dT); // 40us绛夊緟鏃堕棿
    digitalWrite(LED,HIGH); // 鍏抽棴LED
    delayMicroseconds(sleepTime);
    // 0 - 5V mapped to 0 - 1023 integer values
    // recover voltage
    cV = vM * (5.0 / 1024.0); //灏嗘ā鎷燂拷锟借浆鎹负鐢靛帇鍊�1锟�7
    dD = 0.17 * cV - 0.1; //灏嗙數鍘嬶拷锟借浆鎹负绮夊皹瀵嗗害杈撳嚭鍗曚綅
    Serial.print("Raw Signal Value锛� ");
    Serial.print(vM);
    Serial.print(" - Voltage: ");
    Serial.print(cV);
    Serial.print("- Dust Density:");
    Serial.println(dD); //鏈拷缁堟祿搴︼拷锟斤紝杈撳嚭鍗曚綅锛�1锟�7 姣厠/绔嬫柟绫�1锟�7
    delay(1000);
    return (float(vM/1024)-0.0356)*120000*0.035);
}

/**
 * soil moisture
 */
int soil(){
    int moisture = map(analogRead(K),0,1023,0,100);
    Serial.println(moisture);
    return moisture;
}

/*
 * humidity
 */
double humidity(){
    //锟矫碉拷锟斤拷小锟斤拷锟斤拷锟斤拷刷锟铰ｏ拷时锟斤拷
    double delaytiem = dht.getMinimumSamplingPeriod();

    //锟斤拷锟斤拷湿锟斤拷
    double humidity = dht.getHumidity();
    return humidity;
}

/**
 * temperature
 */
double temperature(){
    //锟矫碉拷锟斤拷小锟斤拷锟斤拷锟斤拷刷锟铰ｏ拷时锟斤拷
    double delaytiem = dht.getMinimumSamplingPeriod();
    //锟斤拷锟斤拷锟铰讹拷
    double temperature = dht.getTemperature();
    return temperature;
}

/**
 * water
 */
long water(){
    long value = analogRead(K); //Read data from analog pin and store it to value variable
  if (value<=480){ 
    Serial.println("Water level: 0mm - Empty!"); 
  }
  else if (value>480 && value<=530){ 
    Serial.println("Water level: 0mm to 5mm"); 
  }
  else if (value>530 && value<=615){ 
    Serial.println("Water level: 5mm to 10mm"); 
  }
  else if (value>615 && value<=660){ 
    Serial.println("Water level: 10mm to 15mm"); 
  } 
  else if (value>660 && value<=680){ 
    Serial.println("Water level: 15mm to 20mm"); 
  }
  else if (value>680 && value<=690){ 
    Serial.println("Water level: 20mm to 25mm"); 
  }
  else if (value>690 && value<=700){ 
    Serial.println("Water level: 25mm to 30mm"); 
  }
  else if (value>700 && value<=705){ 
    Serial.println("Water level: 30mm to 35mm"); 
  }
  else if (value>705){ 
    Serial.println("Water level: 35mm to 40mm"); 
  }
  
  delay(1000); // Check for new value every 5 sec
 return value;
}

/**
 * Connect
 */
void MQTT_connect() {
  int8_t ret;
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;  //閲嶈瘯涓夋
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}

