#include <Servo.h>
Servo esc_signal1;
Servo esc_signal2;
Servo esc_signal3;
char command;

void setup()
{
  Serial.begin(9600);
  esc_signal1.attach(11);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal1.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);            //ESC initialization delay.

  esc_signal2.attach(10);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal2.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);     

  esc_signal3.attach(9);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal3.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);     
  
}

void loop()
{
while (Serial.available()==0){}

if(Serial.available()>0){
  command=Serial.read();
  }
  
  if(command=='P')
  {
    esc_signal1.write(0);
    esc_signal2.write(120);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    esc_signal3.write(120);
    Serial.println(command);
    delay(15);
  }
  else if(command=='Q')
  {
    esc_signal1.write(120);
    esc_signal2.write(0);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    esc_signal3.write(120);
    Serial.println(command);
    delay(15);
  }
  else if(command=='R')
  {
    esc_signal1.write(120);
    esc_signal2.write(120);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    esc_signal3.write(0);
    Serial.println(command);
    delay(15);
  }
  else if(command=='A')
  {
    esc_signal1.write(0);
    esc_signal2.write(120);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    esc_signal3.write(0);
    Serial.println(command);
    delay(15);
  }
  else if(command=='B')
  {
    esc_signal1.write(0);
    esc_signal2.write(0);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    esc_signal3.write(120);
    Serial.println(command);
    delay(15);
  }
  else if(command=='C')
  {
    esc_signal1.write(120);
    esc_signal2.write(0);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    esc_signal3.write(0);
    Serial.println(command);
    delay(15);
  }
  else if(command=='S')
  {
    esc_signal1.write(0);
    esc_signal2.write(0);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    esc_signal3.write(0);
    Serial.println(command);
    delay(15);
  }

}
