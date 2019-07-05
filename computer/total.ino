/**
 * ����Ŀ�
 */
//#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <DHT.h>    //https://github.com/markruys/arduino-DHT

/**
 * ��½����
 */
#define WLAN_SSID    "dudududu"   //wifi�˺�
#define WLAN_PASS   "qazmlpwsxnko"      //wifi����
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883   // use 8883 for SSL
#define AIO_USERNAME    "shendu"  //�˻�����
#define AIO_KEY         "862f6d912d894503b543339f8f002b96"  //KEY

/**
 * ��������
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
 * �������úͱ�������
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
   * ���ӷ���
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
   * ��ȡ������Ϣ
   */
  float value1=smell();
  if (! smell.publish(value1++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  /**
   * ��ȡ����ʪ��
   */
  int value2=soil();
  if (! soil.publish(value2++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  /**
   * ��ȡ����ʪ��
   */
  double value3=humidity(); 
  if (! humidity.publish(value3++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  /**
   * ��ȡ�¶�
   */
  double value4=temperature(); 
  if (! temperature.publish(value4++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  /**
   * ��ȡˮλ��Ϣ
   */
  long value5=water();
  if (! water.publish(value5++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
}
/**
 * ����
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
 * �����Ǹ���ģ��Ŀ��ƺͶ�������
 */
/**
 * smell sensor
 */
float smell(){
    if(digitalRead(MD==HIGH))//监测到则弢�关信号端为高电平，低电平信号灯亮
    {
        Serial.print("There is something smell bad...");
        Serial.print("Value:");
        Serial.println(analogRead(K));//打印模拟倄1�71ￄ1�77
    }
    else
    {
        Serial.println("Nothing");
    }
    digitalWrite(LED,LOW); //弢�启内部LED
    delayMicroseconds(sT); // 弢�启LED后的280us的等待时闄1�71ￄ1�77
    vM=analogRead(K); // 读取模拟倄1�71ￄ1�77
    delayMicroseconds(dT); // 40us等待时间
    digitalWrite(LED,HIGH); // 关闭LED
    delayMicroseconds(sleepTime);
    // 0 - 5V mapped to 0 - 1023 integer values
    // recover voltage
    cV = vM * (5.0 / 1024.0); //将模拟��转换为电压倄1�71ￄ1�77
    dD = 0.17 * cV - 0.1; //将电压��转换为粉尘密度输出单位
    Serial.print("Raw Signal Value＄1�7 ");
    Serial.print(vM);
    Serial.print(" - Voltage: ");
    Serial.print(cV);
    Serial.print("- Dust Density:");
    Serial.println(dD); //朢�终浓度��，输出单位＄1�71ￄ1�77 毫克/立方籄1�71ￄ1�77
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
    //�õ���С������ˢ�£�ʱ��
    double delaytiem = dht.getMinimumSamplingPeriod();

    //����ʪ��
    double humidity = dht.getHumidity();
    return humidity;
}

/**
 * temperature
 */
double temperature(){
    //�õ���С������ˢ�£�ʱ��
    double delaytiem = dht.getMinimumSamplingPeriod();
    //�����¶�
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
  uint8_t retries = 3;  //重试三次
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

