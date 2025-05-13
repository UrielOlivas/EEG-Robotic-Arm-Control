#include <Servo.h>

Servo servo1, servo2, servo3, servo4, servo5;
int pin1 = 9;
int pin2 = 10;
int pin3 = 11;
int pin4 = 12;
int pin5 = 13;

int Pos_abierta[5] = {10, 10, 10, 160, 160};
int Pos_cerrada[5] = {160, 160, 160, 10, 10};

void setup() {

  servo1.attach(pin1);
  servo2.attach(pin2);
  servo3.attach(pin3);
  servo4.attach(pin4);
  servo5.attach(pin5);

  servo1.write(Pos_abierta[0]);
  servo2.write(Pos_abierta[1]);
  servo3.write(Pos_abierta[2]);
  servo4.write(Pos_abierta[3]);
  servo5.write(Pos_abierta[4]);

  Serial.begin(9600);
  Serial.println("Ingresa 1-5 para cerrar cada dedo, 11-55 para abrir cada dedo");
}

void loop() {
  if (Serial.available() > 0) {
    int input = Serial.parseInt();

    if (input == 1) {
    servo1.write(Pos_cerrada[0]);
  }
   else if (input == 11){
    servo1.write(Pos_abierta[0]);
   }
   else if (input == 2) {
    servo2.write(Pos_cerrada[1]);
  }
   else if (input == 22){
    servo2.write(Pos_abierta[1]);
   }
   else if (input == 3) {
    servo3.write(Pos_cerrada[2]);
  }
   else if (input == 33){
    servo3.write(Pos_abierta[2]);
   }
   else if (input == 4) {
    servo4.write(Pos_cerrada[3]);
  }
   else if (input == 44){
    servo4.write(Pos_abierta[3]);
   }
   else if (input == 5) {
    servo5.write(Pos_cerrada[4]);
  }
   else if (input == 55){
    servo5.write(Pos_abierta[4]);
   }
   else if (input == 6) {
    servo1.write(Pos_cerrada[0]);
    servo2.write(Pos_cerrada[1]);
    servo3.write(Pos_cerrada[2]);
    servo4.write(Pos_cerrada[3]);
    servo5.write(Pos_cerrada[4]);
  }
   else if (input == 7){
    servo1.write(Pos_abierta[0]);
    servo2.write(Pos_abierta[1]);
    servo3.write(Pos_abierta[2]);
    servo4.write(Pos_abierta[3]);
    servo5.write(Pos_abierta[4]);    
   }
}
}
