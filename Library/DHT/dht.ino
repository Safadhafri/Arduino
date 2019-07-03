/**
 *      '-'
 *    \\------����
 *    \\('+')
 *    \\------������û��ʶ��
 *    \\
 *    \\------��Ϣ
 *      'S'
 */

/**
 * ע�⣺�ź�����Ӧ�ý���digital���ϣ�����anolog���ϣ���
 * �Ѿ�������оƬ�ϵ����ֲ���Ҫ�ӵ���
 */

// Written by ladyada, public domain
// Amendde by fewoot

#include "DHT.h"//https://github.com/adafruit/DHT-sensor-library

#define DHTPIN 2     // �ź�����λ��

// �л���Ӧ���ͺ�
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// ��һ��10K�ĵ���

//ʵ��������
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    //Serial.println(F("DHTxx test!"));

    dht.begin();
}

void loop() {
    
    // 250�����ȡһ��
    // ���������ʵ����2s�ӳ�
    float humidity = dht.readHumidity();
    // ��ȡ�����¶ȣ�Ĭ��
    float temperature = dht.readTemperature();
    // ��ȡ�����¶�
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

}
