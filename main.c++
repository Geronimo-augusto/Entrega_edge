
#include <Wire.h>
#include <LiquidCrystal.h>
#include <RTClib.h>
#include <DHT.h>

// Definições de pinos
#define DHTPIN 2       // Pino de dados do DHT
#define DHTTYPE DHT22  // Tipo de sensor DHT (DHT11 ou DHT22)
#define PHPIN A0       // Pino analógico para o potenciômetro

// Limites de temperatura e pH
const float tempMin = 20.0;
const float tempMax = 30.0;
const float phMin = 7.0;
const float phMax = 8.5;

// Configuração do LCD
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 10, 6, 5, 4, 3);

// Configuração do RTC
RTC_DS3231 rtc;

// Configuração do sensor DHT

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.print("Inicializando...");

  // Inicialização do monitor serial

  // Inicialização do RTC
  rtc_verifc();

  // Inicialização do sensor DHT
  
  
  // Mensagem inicial
  delay(2000);
  lcd.clear();
  lcd.print("Sistema Pronto");
}

void loop() {
  // Leitura da temperatura e umidade
  float temperatureC = dht.readTemperature();
  
  // Leitura do pH (simulado com um potenciômetro)
  int phValue = analogRead(PHPIN);
  float voltage = phValue * (5.0 / 1024.0);
  float ph = 3.5 * voltage;  // Fórmula de conversão simplificada

  // Verificação de erro de leitura de temperatura
  if (isnan(temperatureC)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Obter a data e hora atual do RTC
  
  
  // Verificação dos limites de temperatura e pH
  if (temperatureC < tempMin || temperatureC > tempMax || ph < phMin || ph > phMax) {
    // Exibir no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alerta!");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.setCursor(11, 1);
    lcd.print("°C");
    lcd.setCursor(8, 0);
    lcd.print("PH: ");
    lcd.print(ph);

    // Registrar no monitor serial
    serial_register(temperatureC,ph);

  } else {
    // Exibir leituras normais no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("PH: ");
    lcd.print(ph);
  }

  // Pequena pausa antes da próxima leitura
  delay(5000);
}

void rtc_verifc() {
    if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}
void serial_register(int temperatureC, int ph){
    DateTime now = rtc.now();
    Serial.print("Alerta - Data/Hora: ");
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print(" - Temp: ");
    Serial.print(temperatureC);
    Serial.print("C, PH: ");
    Serial.println(ph);
}

