 #include <Servo.h>

Servo servo1, servo2;

int pin1 = 9;
int pin2 = 10;

int servoPositions[2] = {20, 20};
int position =20;
void setup() {
  servo1.attach(pin1);
  servo2.attach(pin2);
  
  Serial.begin(9600);

  servo1.write(servoPositions[0]);
  servo2.write(servoPositions[1]);
  
  Serial.println("Ingresa 1-2 para cerrar cada dedo, 3-4 para abrir cada dedo, 5 para cerrar la mano y 6 para abrir la mano");
}

void loop() {
  if (Serial.available() > 0) {
    int input = Serial.parseInt();

    if (input >= 1 && input <= 2) {
       position = 120;

      if (position >= 0 && position <= 180) {
        servoPositions[input - 1] = position;
        moveFingers(); 
        Serial.print(input);
        Serial.print(" movido a ");
        Serial.println(position);
        Serial.println("Ingresa 1-2 para cerrar cada dedo, 3-4 para abrir cada dedo, 5 para cerrar la mano y 6 para abrir la mano");
      } else {
        Serial.println("Posición no válida, debe ser entre 0 y 180.");
        Serial.println("Ingresa 1-2 para cerrar cada dedo, 3-4 para abrir cada dedo, 5 para cerrar la mano y 6 para abrir la mano");
      }
    }
   
    else if (input == 3 or input == 4) {
       position = 15;

      if (position >= 0 && position <= 180) {
        servoPositions[input - 1] = position;
        moveFingers(); 
        Serial.print("Dedo ");
        Serial.print(input);
        Serial.print(" movido a ");
        Serial.println(position);
        Serial.println("Ingresa 1-2 para controlar cada dedo, o 6 para cerrar la mano");
      } else {
        Serial.println("Posición no válida, debe ser entre 0 y 180.");
        Serial.println("Ingresa 1-2 para cerrar cada dedo, 3-4 para abrir cada dedo, 5 para cerrar la mano y 6 para abrir la mano");
      }
    }

    else if (input == 5) {
      cerrarMano(120);
      Serial.println("Mano Cerrada");
        Serial.println("Ingresa 1-2 para cerrar cada dedo, 3-4 para abrir cada dedo, 5 para cerrar la mano y 6 para abrir la mano");
    }

    else if (input == 6) {
      cerrarMano(10);
      Serial.println("Mano Cerrada");
        Serial.println("Ingresa 1-2 para cerrar cada dedo, 3-4 para abrir cada dedo, 5 para cerrar la mano y 6 para abrir la mano");
    }        
  }
}

// Función para mover los dedos a la posición seleccionada
void moveFingers() {
  servo1.write(servoPositions[0]);
  servo2.write(servoPositions[1]);
}

// Función para cerrar la mano
void cerrarMano(int position) {
  servoPositions[0] = position;
  servoPositions[1] = position;
  moveFingers();
}
