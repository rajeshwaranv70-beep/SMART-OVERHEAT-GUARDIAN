#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pins
int tempPin   = A0;
int ledPin    = 13;
int buzzerPin = 9;
int relayPin  = 7;

float temp;
bool smsSent = false; // GSM SMS control

void setup() {
  pinMode(ledPin,    OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin,  OUTPUT);
  
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.print("Smart Board");
  lcd.setCursor(0, 1);
  lcd.print("System ON!");
  delay(2000);
  lcd.clear();
}

void loop() {
  int value = analogRead(tempPin);
  
  // LM35 conversion
  temp = (value * 5.0 * 100.0) / 1024.0;
  
  Serial.print("Temp: ");
  Serial.println(temp);
  
  // LCD line 1
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C   ");

  if (temp > 70) {
    digitalWrite(ledPin,    HIGH);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(relayPin,  HIGH);
    
    lcd.setCursor(0, 1);
    lcd.print("HIGH TEMP ALERT ");

    if (smsSent == false) {
      Serial.println("================================");
      Serial.println("GSM MODULE TRIGGERED!");
      Serial.println("AT+CMGF=1");
      Serial.println("AT+CMGS=\"+91XXXXXXXXXX\"");
      Serial.println("ALERT: Overheating detected!");
      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.println(" C");
      Serial.println("Relay Tripped - Power Cut!");
      Serial.println("Location: Main Board");
      Serial.println("SMS SENT SUCCESSFULLY!");
      Serial.println("================================");
      smsSent = true;
    }

  } else {
    digitalWrite(ledPin,    LOW);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relayPin,  LOW);
    
    lcd.setCursor(0, 1);
    lcd.print("Temp Normal     ");
    
    smsSent = false;
  }

  delay(1000);
}
