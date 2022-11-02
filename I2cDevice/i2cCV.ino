#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;//object  for current sesnor

#define LED_Pin  8
#define OLED_RESET 4


Adafruit_SSD1306 display(OLED_RESET);

void setup() {

  pinMode(LED_Pin, OUTPUT);
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  ina219.begin();
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  ina219.setCalibration_16V_400mA();

  // initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.display();
  
}

void loop() {
  
  digitalWrite(LED_Pin, HIGH); 
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;
  int averagecurrent =0;

  //shuntvoltage = ina219.getShuntVoltage_mV();
   //power_mW = ina219.getPower_mW();
  
  busvoltage = ina219.getBusVoltage_V();
  loadvoltage = busvoltage + (shuntvoltage / 1000);

  for (int i=0; i<10; i++){
  averagecurrent = averagecurrent + ina219.getCurrent_mA();
  }
  current_mA = averagecurrent/10;
  // show data on OLED
  display.clearDisplay();
  
  display.setCursor(0, 0);
  display.print("Bus V:"); 
  display.print(busvoltage); 
  display.print(" V");

  display.setCursor(0, 10);
  display.print("Load V:"); 
  display.print(loadvoltage); 
  display.print(" V");

  display.setCursor(0, 20);
  display.print("Current:"); 
  display.print(current_mA); 
  display.println(" mA");
 
 display.display();

 delay(1000);

}
