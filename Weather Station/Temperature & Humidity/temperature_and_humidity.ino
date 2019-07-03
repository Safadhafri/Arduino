

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
//     // ��ȡ�����¶ȣ�Ĭ��
//     float temperature = dht.readTemperature();

//     float fahrenheit = dht.readTemperature(true);

//     // ����Ƿ���󣬲�����
//     if (isnan(humidity) || isnan(temperature) || isnan(fahrenheit)) {
//       Serial.println(F("Failed to read from DHT sensor!"));
//       return;
//     }

//     // �Ի����¶�Ϊ��λ������ָ����Ĭ��
//     float hif = dht.computeHeatIndex(fahrenheit, humidity);
//     // �������¶ȼ�����ָ��
//     float hic = dht.computeHeatIndex(temperature, humidity, false);

    
//     Serial.print(F("Humidity: "));
//     Serial.print(humidity);
//     Serial.print(F("%  Temperature: "));
//     Serial.print(temperature);
//     Serial.print(F("��C "));
//     Serial.print(fahrenheit);
//     Serial.print(F("��F  Heat index: "));
//     Serial.print(hic);
//     Serial.print(F("��C    "));
//     Serial.print(hif);
//     Serial.println(F("��F"));
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup(){
    Serial.begin(9600);
    dht.begin();
}

void loop(){
    float humidity = dht.readHumidity();
    // ��ȡ�����¶ȣ�Ĭ��
    float temperature = dht.readTemperature();

    float fahrenheit = dht.readTemperature(true);

    // ����Ƿ���󣬲�����
    if (isnan(humidity) || isnan(temperature) || isnan(fahrenheit)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    // �Ի����¶�Ϊ��λ������ָ����Ĭ��
    float hif = dht.computeHeatIndex(fahrenheit, humidity);
    // �������¶ȼ�����ָ��
    float hic = dht.computeHeatIndex(temperature, humidity, false);

    
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F("%  Temperature: "));
    Serial.print(temperature);
    Serial.print(F("��C "));
    Serial.print(fahrenheit);
    Serial.print(F("��F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("��C    "));
    Serial.print(hif);
    Serial.println(F("��F"));
}
