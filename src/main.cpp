#include <Arduino.h>
#include <ESP32Servo.h>                        
#include "WiFi.h"

void ProcessBootButton();
void PerformAction1();
void PerformAction2();
void PerformAction3();
void PerformAction4();
void PerformAction5();
void PerformAction6();
void PerformAction7();
void PerformAction8();
void PerformAction9();
void PerformAction10();
void PerformAction11();
void PerformAction12();
void PerformAction13();
void PerformAction14();
void PerformAction15();

Servo handServo;                          
Servo boxServo;


// RTC pins: GPIO2,3,0,1
int switchStatus=0, action=1;
bool bootButtonToggle = false;

const int ledPin = LED_BUILTIN;                    
const int frontSwitchPin = 0;
const int handServoPin = 4;
const int boxServoPin = 3;
const int bootButtonPin = 9;

const int posLidPark = 120;
const int posLidFull = 143;
const int posLidPause = 135;
const int posHandPark = 40;
const int posHandPause = 160;
const int posHandPauseEarly = 150;
const int posHandFull = 175;

void setup()
{
  char string[16];
 
  //sprintf(string, "Start CPU Freq: %i", getCpuFrequencyMhz());
  //Serial.println(string);
  //setCpuFrequencyMhz(240);
  Serial.begin(9600);
  Serial.println("Starting");

  Serial.print("getCpuFrequencyMhz ");
  Serial.println(getCpuFrequencyMhz());

  Serial.print("getXtalFrequencyMhz ");
  Serial.println(getXtalFrequencyMhz());
  
  Serial.print("getApbFrequency ");
  Serial.println(getApbFrequency());

  //Turn off unnecessary stuff
  btStop(); //Bluetooth
  WiFi.mode(WIFI_OFF); // WiFi

  pinMode(frontSwitchPin, INPUT);                  
  pinMode(bootButtonPin, INPUT);

  handServo.attach(handServoPin);              
  boxServo.attach(boxServoPin);
  boxServo.write(posLidPark);
  handServo.write(posHandPark);
}


void loop()
{
  
  ProcessBootButton();

  if (action>15)
  {
    action=1;
  }
  

  switchStatus = digitalRead(frontSwitchPin); 

  if (switchStatus == LOW){                   

    if (action == 1)
    {
      PerformAction1();
      action++;
    }

    else if (action == 2)
    {
      PerformAction2();
      action++;
    }

    else if (action == 3)
    {
      PerformAction3();
      action++;
    }

    else if (action == 4)
    {
      PerformAction4();
      action++;
    }

    else if (action == 5)
    {
      PerformAction5();
      action++;
    }

    else if (action == 6)             
    {
      PerformAction6();
      action++;
    }

    else if (action == 7)
    {
      PerformAction7();
      action++;
    }

    else if (action == 8)
    {
      PerformAction8();
      action++;
    }

    else if (action == 9)
    {
      PerformAction9();
      action++;
    }

    else if (action == 10)
    {
      PerformAction10();
      action++;
    }

    else if (action == 11)
    {
      PerformAction11();
      action++;
    }

    else if (action == 12)
    {
      PerformAction12();
      action++;
    }

    else if (action == 13)
    {
      PerformAction13();
      action++;
    }

    else if (action == 14)
    {
      PerformAction14();
      action++;
    }

    else if (action == 15)
    {
      PerformAction15();
      action++;
    }
  }
}

void ProcessBootButton()
{
  static bool _lastValue = HIGH;
  if (_lastValue==HIGH && digitalRead(bootButtonPin)==LOW) // Boot Button is pulled low when pressed.
  {
    
    if (bootButtonToggle){
      Serial.println("Moving to Full Positions");
      handServo.write(posHandFull);
      boxServo.write(posLidFull);
      bootButtonToggle = false;
    }
    else 
    {
      Serial.println("Moving to Park Positions");
      handServo.write(posHandPark);
      boxServo.write(posLidPark);
      bootButtonToggle = true;
    }
  }
  _lastValue = digitalRead(bootButtonPin);
}

void PerformAction1()
{
  Serial.println("Action 1");
  Serial.println("Open Lid to Full");            
  for (int i = posLidPark; i <= posLidFull; i++)
  {
    boxServo.write(i);
    delay(20);
  }
  Serial.println("Hand to Pause");  
  for (int i = posHandPark; i <= posHandPause; i++)
  {
    handServo.write(i);
    delay(20);
  }
  delay(1000);
  Serial.println("Hand to Full");  
  handServo.write(posHandFull);
  delay(200);
  Serial.println("Hand to Park");  
  for (int i = posHandFull; i >=posHandPark; i--)
  {
    handServo.write(i);
    delay(20);
  }
  Serial.println("Lid to Park");  
  for (int i = posLidFull; i >= posLidPark; i--)
  {
    boxServo.write(i);
    delay(20);
  }
}

void PerformAction2()
{
  Serial.println("Action 2");         
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(550);
  handServo.write(posHandFull);
  delay(550);
  handServo.write(posHandPark);
  delay(550);
  boxServo.write(posLidPark);
  delay(1500);
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(3000);
  boxServo.write(posLidPark);
}

void PerformAction3()
{
  Serial.println("Action 3");         
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(1000);
  boxServo.write(posLidPark);
  delay(2000);
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  handServo.write(posHandFull);
  delay(550);
  handServo.write(posHandPark);
  delay(500);
  boxServo.write(posLidPark);
}

void PerformAction4()
{
  Serial.println("Action 4");         
  for (int i = posLidPark; i <= posLidFull; i++)
  {
    boxServo.write(i);
    delay(20);
  }
  for (int i = posHandPark; i <= posHandPause; i++)
  {
    handServo.write(i);
    delay(20);
  }
  delay(2000);
  handServo.write(posHandFull);
  delay(200);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);
}

void PerformAction5()
{
  Serial.println("Action 5");     
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(2000);
  handServo.write(posHandPause);
  delay(550);
  handServo.write(posHandPauseEarly);
  delay(200);
  handServo.write(posHandPause);
  delay(200);
  handServo.write(posHandPauseEarly);
  delay(200);
  handServo.write(posHandPause);
  delay(200);
  handServo.write(posHandPauseEarly);
  delay(200);
  handServo.write(posHandPause);
  delay(200);
  handServo.write(posHandPauseEarly);
  delay(200);
  handServo.write(posHandPause);
  delay(200);
  handServo.write(posHandPauseEarly);
  delay(200);
  handServo.write(posHandPause);
  delay(2000);
  handServo.write(posHandFull);
  delay(400);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);
}

 void PerformAction6()
 {
  Serial.println("Action 6");      
  for (int i = posLidPark; i < posLidFull; i++)
  {
    boxServo.write(i);
    delay(20);
  }
  delay(1000);
  for (int i = 0; i < 12; i++)
  {
    for (int j = posLidPark; j <= posLidFull; j++){
      boxServo.write(j);
      delay(6);
    }
    delay(200);
  }
  for (int i = posHandPark; i <= posHandPause; i++)
  {
    handServo.write(i);
    delay(30);
  }
  handServo.write(posHandFull);
  delay(400);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);
  delay(1500);
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(3000);
  boxServo.write(posLidPark);
}

void PerformAction7()
{
  Serial.println("Action 7");      
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(400);
  handServo.write(posHandFull);
  delay(1000);
  for (int i = 0; i < 6; i++)
  {
    for (int j = posLidPark; j <= posLidFull; j++){
      boxServo.write(j);
      delay(6);
    }
    delay(200);
  }
  delay(500);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);
}

void PerformAction8()
{
  Serial.println("Action 8");    
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  handServo.write(posHandFull);
  delay(2000);
  for (int i = 0; i < 7; i++)
  {
    handServo.write(posHandPause);
    delay(100);
    handServo.write(posHandPauseEarly);
    delay(100);
  }
  delay(500);
  handServo.write(posHandPark);
  delay(1000);
  boxServo.write(posLidPark);
}

void PerformAction9()
{
  Serial.println("Action 9");      
  for (int i = posLidPark; i <= posLidPause; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(2000);
  boxServo.write(posLidFull);
  for (int i = posHandPark; i <=posHandPause; i++)
  {
    handServo.write(i);
    delay(40);
  }
  delay(500);
  handServo.write(posHandFull);
  delay(200);
  for (int i = posHandFull; i >=posHandPark; i--)
  {
    handServo.write(i);
    delay(40);
  }
  boxServo.write(posLidPark);
  delay(2000);
  boxServo.write(posLidPause);
  delay(3000);
  boxServo.write(posLidPark);
}


void PerformAction10()
{
  Serial.println("Action 10");      
  for (int i = posLidPark; i <= posLidPause; i++)
  {
    boxServo.write(i);
    delay(100);
  }
  delay(1000);
  for (int i = 0; i < 10; i++)
  {
    for (int j = posLidPark; j <= posLidPause; j++){
      boxServo.write(j);
      delay(6);
  }
    delay(100);
  }
  boxServo.write(posLidFull);
  delay(100);
  handServo.write(posHandFull);
  delay(650);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);
}

void PerformAction11()
{
  Serial.println("Action 11");     
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  handServo.write(posHandFull);
  delay(2000);
  for (int i = 0; i < 3; i++)
  {
    handServo.write(posHandPause);
    delay(200);
    handServo.write(posHandPauseEarly);
    delay(200);
  }
  delay(1500);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);
  delay(1500);
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  handServo.write(posHandFull);
  delay(3000);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);
}

void PerformAction12()
{
  Serial.println("Action 12");    
  for (int i = posLidPark; i <= posLidFull; i++)
  {
    boxServo.write(i);
    delay(50);
  }
  delay(1000);
  for (int i = posHandPark; i <= posHandFull; i++)
  {
    handServo.write(i);
    delay(50);
  }
  delay(2000);
  handServo.write(posHandFull);
  delay(200);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);
}

void PerformAction13()
{
  Serial.println("Action 13");     
  for (int i = posLidPark; i <= posLidFull; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(2000);
  for (int i = posHandPark; i <= posHandPauseEarly; i++)
  {
    handServo.write(i);
    delay(40);
  }
  for (int i = 0; i < 3; i++)
  {
    handServo.write(posHandPause);
    delay(200);
    handServo.write(posHandPauseEarly);
    delay(800);
  }
  handServo.write(posHandFull);
  delay(2000);
  handServo.write(posHandPark);
  delay(500);
  boxServo.write(posLidPark);
}

void PerformAction14()
{
  Serial.println("Action 14");     
  for (int i = posLidPark; i <= posLidPause; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(4000);
  boxServo.write(posLidFull);
  handServo.write(posHandFull);
  delay(1000);
  handServo.write(posHandPark);
  delay(500);
  boxServo.write(posLidPause);
  delay(4000);
  boxServo.write(posLidPark);
}

void PerformAction15()
{
  Serial.println("Action 15");   
  for (int i = posLidPark; i <= posLidPause; i++){
    boxServo.write(i);
    delay(6);
  }
  delay(1000);
  for (int i = 0; i < 3; i++)
  {      
    for (int j = posLidPark; j <= posLidPause; j++){
      boxServo.write(j);
      delay(50);
    }
    for (int j = posLidPause; j >= posLidPark; j--)
    {
      boxServo.write(j);
      delay(50);
    }
  }
  for (int j = posLidPark; j <= posLidFull; j++){
    boxServo.write(j);
    delay(50);
  }
  for (int i = posHandPark; i <= posHandPause; i++)
  {
    handServo.write(i);
    delay(40);
  }
  delay(1000);
  handServo.write(posHandFull);
  delay(400);
  handServo.write(posHandPark);
  delay(400);
  boxServo.write(posLidPark);

}
