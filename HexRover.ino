#include <Servo.h>
Servo kist;
Servo lokot;
Servo plecho;
Servo core;


#define speedL A0
#define speedR A1


int posPlech;  //состояние плеча при исходном   состоянии
int posLok;    //состояние локтя при исходном   состоянии
int posKist;   //состояние плеча при исходном   состоянии
int posKist1;  //состояние локтя при неисходном состоянии
int poscore;

int motorLplus = 2;
int motorRplus = 3;
int motorLmin = 4;
int motorRmin = 5;
const int speedL = 85;
const int speedR = 85;
float bluetooth ;

void setup() {
  analogWrite(A0, speedL);
  analogWrite(A1, speedR);
  Serial.begin(9600);
  kist.attach(8);
  lokot.attach(9);
  plecho.attach(10);
  core.attach(11);

}
void loop() {
  if (Serial.available()) {
    bluetooth = Serial.read();
    if (bluetooth == 'F') {
      digitalWrite(motorLplus, HIGH);
      digitalWrite(motorLmin , LOW);
      digitalWrite(motorRplus, HIGH);
      digitalWrite(motorRmin , LOW);
      delay(15);
    }
    if (bluetooth == 'B') {
      digitalWrite(motorLplus, LOW);
      digitalWrite(motorLmin , HIGH);
      digitalWrite(motorRplus, LOW);
      digitalWrite(motorRmin , HIGH);
      delay(15);
    } if (bluetooth == 'L') {
      digitalWrite(motorLplus, LOW);
      digitalWrite(motorLmin , HIGH);
      digitalWrite(motorRplus, HIGH);
      digitalWrite(motorRmin , LOW);
      delay(15);
    } if (bluetooth == 'R') {
      digitalWrite(motorLplus, HIGH);
      digitalWrite(motorLmin , LOW);
      digitalWrite(motorRplus, LOW);
      digitalWrite(motorRmin , HIGH);
      delay(15);

    } if (bluetooth == 'W') {
      if (kist.read() == posKist) {
        kist.write(posKist1);
      }
      kist.write(posKist);
      delay(15);


    } if (bluetooth == 'W') {
      poscore = core.read();
      if (poscore >= 1) {
        core.write(poscore - 1);
        delay(15);
      }

    } if (bluetooth == 'W') {
      if (poscore x<= 179) {
        core.write(poscore + 1);
        delay(15);
      }

    }
    if (bluetooth == 'W') {
      if (posLok <= 44) {
        lokot.write(posLok + 1);
        delay(15);
      }

    }
    if (bluetooth == 'W') {
      if (posLok >= 1) {
        lokot.write(posLok - 1);
        delay(15);
      }
      if (bluetooth == 'W') {
        if (posPlech >= 1) {
          plecho.write(posPlech - 1);
          delay(15);
        }
        if (bluetooth == 'W') {
          if (posPlech <= 44) {
            plecho.write(posPlech + 1);
            delay(15);
          }

        }
      }
    }
  }
