#include <RedBot.h>
#include "notes.h"
RedBotMotors motors;
RedBotAccel accelerometer;
#define BUZZ 9
#define BUTTON_PIN 12


#define G5 784
#define A6 1760
#define A_flat_6 1662
#define B6 1976
#define C6 1047
#define F5 698
#define E5 659
#define D5 587
#define G4 392
#define B5 988
#define C5 523
#define C5 523
#define A4 440
#define D4 294
#define D3 147
#define A_flat4 415
#define G3 196
#define F3 175
#define C3 131
#define B3 247
#define B_flat3 233
#define D2 73
#define C2 65
#define E3 165
#define C4 262
#define D_flat4 277
#define F2 87
#define G2 98
#define G_flat3 196
#define E_flat3 156
#define A_flat3 208
#define D_flat3 139
#define G_flat2 93
const int E2 = 82;
#define E_flat2 156
#define B_flat4 466
const int B4 = 493;
const int E4 = 329;
#define A_flat5 831
#define G_flat4 370
#define B_flat4 466
#define D_flat5 466
#define B_flat6 1865
const int D6 = 1175;
#define E_flat4 311
const int F4 = 349;
#define E_flat5 622
#define D_flat6 1109
#define E_flat6 1245
#define G_flat5 740

void one_m(double offset=1,double left=1,double right=1){
  //motors.drive(150);
  motors.rightMotor(150*right);  
  motors.leftMotor(-150*left);
  //delay(2502.15*offset);
  //motors.brake();
}


void turn_r(double offset=1){
  motors.rightMotor(-73);  
  motors.leftMotor(-73);
  //delay(1140.0*offset);
  //motors.brake();
}


void turn_l(double offset=1){
  motors.rightMotor(73);  
  motors.leftMotor(73);
  //delay(1140.0*offset);
  //motors.brake();
}

void run_list(int iterable[][3],double speed,int lengh){
  for(int i = 0;i<lengh;i++){
    if(iterable[i][0]!=0){
      tone(BUZZ,iterable[i][0]);
      if(iterable[i][2]==0){
        one_m();  
      }
      else if(iterable[i][2]==1){
        turn_r();
      }
      else{
        turn_l;
      }
      delay(iterable[i][1]/speed);
      
      
      }
    else{
    noTone(BUZZ);  
    }
  }
  noTone(BUZZ);
  motors.brake();
  
}


void setup() {

int first_part[60][3] = {
                        {G5,83,0},{A6,83,0},{B6,83,0},
                        {C6,250,1},{G5,83,1},{A_flat_6,83,2},
                        {G5,83,2},{F5,250,2},{E5,250,1},
                        {E5,83,0},{F5,83,0},{E5,83,0},
                        {D5,250,1},{0,5,1},{D5,125,1},
                        {G4,125,2},{B5,125,2},{D5,125,1},
                        {G5,250,2},{F5,83,0},{G5,83,0},
                        {F5,83,1},{E5,250,1},{D5,250,1},
                        {E5,125,1},{D5,125,0},{C5,250,0},
                        {B5,125,2},{C5,125,2},{E5,125,2},
                        {G5,125,1},{C6,250,2},{G5,83,2},
                        {A_flat_6,83,1},{G5,83,1},{F5,250,0},
                        {E5,250,2},{0,5,2},{E5,83,2},
                        {F5,83,2},{E5,83,2},{D5,250,2},
                        {0,5,2},{D5,125,2},{G4,125,2},
                        {B5,125,1},{D5,125,1},{G5,250,1},
                        {F5,83,1},{G5,83,1},{F5,83,1},
                        {E5,250,1},{D5,250,1},{C5,250,2},
                        {0,250,2},{C6,250,2},{0,20,2}
                        };

int second[114][3] = {
{C4, 125,0},{D4,125,1},{E_flat4,125,0},
{F4,125,1},{G4,250,2},{C5,250,1},
{0,5,0},{C5,83,2},{D5,83,1},
{C5,83,0},{B4,250,2},{0,5,1},
{B4,125,1},{C5,125,2},{D5,250,1},
{G4,125,1},{A4,125,1},{B4,125,1},
{C5,125,2},{D5,250,2},{E_flat5,250,1},
{D5,83,0},{E_flat5,83,1},{D5,83,2},
{C5,250,1},{0,5,0},{C5,125,2},
{B4,125,2},{C5,250,2},{C4, 125,0},
{D4,125,1},{E_flat4,125,0},{F4,125,1},
{G4,250,1},{C5,250,2},{0,5,0},
{C5,83,1},{D5,83,1},{C5,83,2},
{B4,250,2},{0,5,0},{B4,125,1},
{C5,125},{D5,250},{G4,83},
{A_flat4,83},{G4,83},{G_flat4,125},
{G4,125,1},{A4,250,1},{B4,250,2},
{C5,250,2},{0,250,1},{C6,250,2},
{0,250,2},{C5,125,2},{D5,125,2},
{E_flat5,125,1},{F5,125,1},
{G5,125,0},{A_flat5,125,0},
{A5,125,2},{B5,125,1},{C6,83,2},
{D6,83,1},{C6,83,1},{B5,250,2},
{0,5,1},{B5,125,0},{C6,125,1},
{D6,250,2},{G5,125,2},{A5,125,1},
{B5,125},{C6,125},{D6,125},
{D_flat6,125},{D6,125},{E_flat6,125},
{D6,83},{E_flat6,83},{D6,83},
{C6,250,1},{0,5,0},{C6,125,1},
{B5,125,2},{C6,250,1},
{C5,125,1},{D5,125,2},{E_flat5,125,1},
{F5,125,2},{G5,125,1},{A_flat5,125,2},
{A5,125,2},{B5,125,1},{C6,83,1},
{D6,83,2},{C6,83,0},{B5,250,0},
{0,5,1},{B5,125,1},{C6,125,2},
{D6,250,1},{G5,83,0},{A_flat5,83,0},
{G5,83,2},{G_flat5,125,2},{G5,125,2},
{C6,250,1},{D6,250,1},{E_flat6,250,1},
{E_flat5,125,1},{G5,250,1},{C6,250,1}
};

  while(true){
      accelerometer.read();
    if(accelerometer.x>20000){
      break;
    }
    if(accelerometer.y>20000){
      break;
    }
  }

  float speed=1;
  pinMode(BUZZ, OUTPUT); 
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  run_list(first_part,speed,54);
  run_list(first_part,speed,54);
  run_list(second,speed,114);

}

void loop() {
  // put your main code here, to run repeatedly:

}
