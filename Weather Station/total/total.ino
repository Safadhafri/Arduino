/**
 * light
 */
//#define sensorValue A0
#define data D5
#define LED_R = D1
#define LED_G = D3
#define LED_B = D4
String str;

/**
 * smell sensor
 */
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

/**
 * soil moisture
 */
#define siglnal_soil A0

/**
 * temperature
 */


#include "DHT.h"    //https://github.com/markruys/arduino-DHT
DHT dht;
#define PIN A0

/**
 * water
 */
#define signal A0

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
    Serial.begin(115200);//接口速率必须115200
    pinMode(MA,INPUT);
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
}

void loop(){

}
/**
 * light
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

/**
 * smell sensor
 */

void smell(){
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

/**
 * soil moisture
 */

void soil(){
    int moisture = map(analogRead(siglnal_soil),0,1023,0,100);
    Serial.println(moisture);
}

/**
 * temperature
 */

void temperature(){
    //�õ���С������ˢ�£�ʱ��
    double delaytiem = dht.getMinimumSamplingPeriod();

    //����ʪ��
    double humidity = dht.getHumidity();

    //�����¶�
    double temperature = dht.getTemperature();
}

/**
 * water
 */
void water(){
    long value = analogRead(signal); //Read data from analog pin and store it to value variable

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
	
	//delay(1000); // Check for new value every 5 sec
}