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
#define M_PIN A0//榛戠嚎鎺0;
#define LED D2//鐧界嚎鎺2;
int sT = 280;//绛夊緟LED寮€鍚殑鏃堕棿鏄�280渭s
int dT = 40;//鏁翠釜鑴夊啿鎸佺画鏃堕棿涓�320渭s銆傚洜姝わ紝鎴戜滑杩橀渶鍐嶇瓑寰�40渭s
int sleepTime = 9680;
float vM = 0;//妯℃嫙鍊�
float cV = 0;//鐢靛帇鍊�
float dD = 0;//绮夊皹瀵嗗害

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
    Serial.begin(115200);//鎺ュ彛閫熺巼蹇呴』115200
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
    //得到最小采样（刷新）时间
    double delaytiem = dht.getMinimumSamplingPeriod();

    //返回湿度
    double humidity = dht.getHumidity();

    //返回温度
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