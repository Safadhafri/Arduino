

/**
 * 154-31
 */
#include "DHT.h"//https://github.com/adafruit/DHT-sensor-library

#define DHTPIN 2 

#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

//dht.begin();//put this in setup()

// void temperature(){
//     float humidity = dht.readHumidity();
//     // 读取摄氏温度，默认
//     float temperature = dht.readTemperature();

//     float fahrenheit = dht.readTemperature(true);

//     // 检查是否错误，并重启
//     if (isnan(humidity) || isnan(temperature) || isnan(fahrenheit)) {
//       Serial.println(F("Failed to read from DHT sensor!"));
//       return;
//     }

//     // 以华氏温度为单位计算热指数，默认
//     float hif = dht.computeHeatIndex(fahrenheit, humidity);
//     // 以摄氏温度计算热指数
//     float hic = dht.computeHeatIndex(temperature, humidity, false);

    
//     Serial.print(F("Humidity: "));
//     Serial.print(humidity);
//     Serial.print(F("%  Temperature: "));
//     Serial.print(temperature);
//     Serial.print(F("°C "));
//     Serial.print(fahrenheit);
//     Serial.print(F("°F  Heat index: "));
//     Serial.print(hic);
//     Serial.print(F("°C    "));
//     Serial.print(hif);
//     Serial.println(F("°F"));
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup(){
    Serial.begin(9600);
    dht.begin();
}

void loop(){
    float humidity = dht.readHumidity();
    // 读取摄氏温度，默认
    float temperature = dht.readTemperature();

    float fahrenheit = dht.readTemperature(true);

    // 检查是否错误，并重启
    if (isnan(humidity) || isnan(temperature) || isnan(fahrenheit)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    // 以华氏温度为单位计算热指数，默认
    float hif = dht.computeHeatIndex(fahrenheit, humidity);
    // 以摄氏温度计算热指数
    float hic = dht.computeHeatIndex(temperature, humidity, false);

    
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F("%  Temperature: "));
    Serial.print(temperature);
    Serial.print(F("°C "));
    Serial.print(fahrenheit);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C    "));
    Serial.print(hif);
    Serial.println(F("°F"));
}
