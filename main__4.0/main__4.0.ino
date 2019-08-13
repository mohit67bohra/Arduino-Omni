//Omni direction motor driver
//motor driver 1 front motors


int enA1=5;
int in11= 22;
int in21= 23;
int enB1= 6;
int in31= 24;
int in41= 25;


//motor driver 2 rear motors
int enA2= 7;
int in12= 26;
int in22= 27;
int enB2= 8;
int in32= 28;
int in42= 29;

// motor driver 3 front movement claw

int enA3= 9;
int in13= 30;
int in23= 31;
int enB3= 10;
int in33= 32;
int in43= 33;

// motor driver 4 left right movement claw  && Back Flap

int enA4= 11;
int in14= 34;
int in24= 35;
int enB4= 12;
int in34= 36;
int in44= 37;

// motor driver for U band

int enA5= 13;
int in15= 38;
int in25= 39;

//Transmitter channel defination
  
  int ch1=A0;
  int ch2=A1;
  int ch3=A2;
  int ch4=A3;
  int ch5=A4;
  int ch6=A5;

  int Ch1;
  int Ch2;
  int Ch3;
  int Ch4;
  int Ch5;
  int Ch6;

void setup() {
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  pinMode(ch3, INPUT);
  pinMode(ch4, INPUT);
  pinMode(ch5, INPUT);
  pinMode(ch6, INPUT);

  pinMode(enA1,OUTPUT);
  pinMode(in11,OUTPUT);
  pinMode(in21,OUTPUT);
  pinMode(enB1,OUTPUT);
  pinMode(in31,OUTPUT);
  pinMode(in41,OUTPUT);
  
  pinMode(enA2,OUTPUT);
  pinMode(in12,OUTPUT);
  pinMode(in22,OUTPUT);
  pinMode(enB2,OUTPUT);
  pinMode(in32,OUTPUT);
  pinMode(in42,OUTPUT);

  pinMode(enA3,OUTPUT);
  pinMode(in13,OUTPUT);
  pinMode(in23,OUTPUT);
  pinMode(enB3,OUTPUT);
  pinMode(in33,OUTPUT);
  pinMode(in43,OUTPUT);


  pinMode(enA4,OUTPUT);
  pinMode(in14,OUTPUT);
  pinMode(in24,OUTPUT);
  pinMode(enB4,OUTPUT);
  pinMode(in34,OUTPUT);
  pinMode(in44,OUTPUT);


  pinMode(enA5,OUTPUT);
  pinMode(in15,OUTPUT);
  pinMode(in25,OUTPUT);


}

void loop() {

Ch1=(pulseIn(ch1,HIGH));
Ch2=(pulseIn(ch2,HIGH));
Ch3=(pulseIn(ch3,HIGH));
Ch4=(pulseIn(ch4,HIGH));
Ch5=(pulseIn(ch5,HIGH));
Ch6=(pulseIn(ch6,HIGH));

Serial.println(Ch1);
Serial.println(Ch2);
Serial.println(Ch3);
Serial.println(Ch4);
Serial.println(Ch5);
Serial.println(Ch6);

  //STOP
          if(Ch1>1450 && Ch1<1550 && Ch2>1450 && Ch2<1550 && Ch6<1100 ){
          digitalWrite(enA1, 0);
          digitalWrite(in11, LOW);                                     
          digitalWrite(in21, LOW);
          digitalWrite(enB1, 0);
          digitalWrite(in31, LOW);                                     
          digitalWrite(in41, LOW);
          digitalWrite(enA2, 0);
          digitalWrite(in12, LOW);                                     
          digitalWrite(in22, LOW);
          digitalWrite(enB2, 0); 
          digitalWrite(in32, LOW);                                     
          digitalWrite(in42, LOW);
          Serial.println("stop");
    }

  //Front
          if(Ch2 > 1550 && Ch2 < 2000 && Ch1>1450 && Ch1<1550 && Ch6<1100 ){
          int control=map(Ch2,1550,2000,0,255);
          analogWrite(enA1, control);
          digitalWrite(in11, HIGH);                                     
          digitalWrite(in21, LOW);
          analogWrite(enB1, control);
          digitalWrite(in31, HIGH);                                     
          digitalWrite(in41, LOW);
          analogWrite(enA2, control);
          digitalWrite(in12, HIGH);                                     
          digitalWrite(in22, LOW);
          analogWrite(enB2, control); 
          digitalWrite(in32, HIGH);                                     
          digitalWrite(in42, LOW);
          Serial.println("forward");
       }

 //Backward
          if(Ch2 < 1450 && Ch2 > 1000 && Ch1>1450 && Ch1<1550 && Ch6<1100){
          int control=map(Ch2,1450,1000,0,255);
           analogWrite(enA1, control);
          digitalWrite(in11, LOW);                                     
          digitalWrite(in21, HIGH);
          analogWrite(enB1, control);
          digitalWrite(in31, LOW);                                     
          digitalWrite(in41, HIGH);
          analogWrite(enA2, control);
          digitalWrite(in12, LOW);                                     
          digitalWrite(in22, HIGH);
          analogWrite(enB2, control); 
          digitalWrite(in32, LOW);                                     
          digitalWrite(in42, HIGH);
           Serial.println("backward");
          }


//Perpendicular right

          if(Ch1 > 1550 && Ch1 < 2000 && Ch2>1450 && Ch2<1550 && Ch6<1100 ){
           int control=map(Ch1,1550,2000,0,255);
           analogWrite(enA1, control);
          digitalWrite(in11, LOW);                                     
          digitalWrite(in21, HIGH);
          analogWrite(enB1, control);
          digitalWrite(in31, HIGH);                                     
          digitalWrite(in41, LOW);
          analogWrite(enA2, control);
          digitalWrite(in12, LOW);                                     
          digitalWrite(in22, HIGH);
          analogWrite(enB2, control); 
          digitalWrite(in32, HIGH);                                     
          digitalWrite(in42, LOW);
          Serial.println("right");      
          }
          
//pERPENDICULAR LEFT
           if(Ch1 < 1450 && Ch1 > 1000 && Ch2>1450 && Ch2<1550 && Ch6<1100 ){
           int control=map(Ch1,1450,1000,0,255);
            analogWrite(enA1, control);
          digitalWrite(in11, HIGH);                                     
          digitalWrite(in21, LOW);
          analogWrite(enB1, control);
          digitalWrite(in31, LOW);                                     
          digitalWrite(in41, HIGH);
          analogWrite(enA2, control);
          digitalWrite(in12, HIGH);                                     
          digitalWrite(in22, LOW);
          analogWrite(enB2, control); 
          digitalWrite(in32, LOW);                                     
          digitalWrite(in42, HIGH);
          Serial.println("left"); 
           }

   
 // EXACT 45 DEGREE 
          if(Ch1 > 1550 && Ch1 < 2000 && Ch2 > 1550 && Ch2 < 2000 && Ch6<1100){
            int cnt1=map(Ch1,1550,2000,0,255);
            int cnt2=map(Ch2,1550,2000,0,255);
            int control=(cnt1+cnt2)/2;
           analogWrite(enA1, 0);
          digitalWrite(in11, LOW);                                     
          digitalWrite(in21, LOW);
          analogWrite(enB1, control);
          digitalWrite(in31, HIGH);                                     
          digitalWrite(in41, LOW);
          analogWrite(enA2, 0);
          digitalWrite(in12, LOW);                                     
          digitalWrite(in22, LOW);
          analogWrite(enB2, control); 
          digitalWrite(in32, HIGH);                                     
          digitalWrite(in42, LOW);
          Serial.println("45 Degree");
          }

                    
 //EXACT 135 DEGREE
          if(Ch1 < 1450 && Ch1 > 1000 && Ch2 > 1550 && Ch2 < 2000 && Ch6<1100){
            int cnt1=map(Ch1,1450,1000,0,255);
            int cnt2=map(Ch2,1550,2000,0,255);
            int control=(cnt1+cnt2)/2;
          analogWrite(enA1, control);
          digitalWrite(in11, HIGH);                                     
          digitalWrite(in21, LOW);
          analogWrite(enB1, 0);
          digitalWrite(in31, LOW);                                     
          digitalWrite(in41, LOW);
          analogWrite(enA2, control);
          digitalWrite(in12, HIGH);                                     
          digitalWrite(in22, LOW);
          analogWrite(enB2, 0); 
          digitalWrite(in32, LOW);                                     
          digitalWrite(in42, LOW);
          Serial.println("135 Degree");
          }
          
 //EXACT 225 DEGREE 
          if(Ch1 < 1450 && Ch1 > 1000 && Ch2 < 1450 && Ch2 > 1000 && Ch6<1100){
          int cnt1=map(Ch1,1450,1000,0,255);
            int cnt2=map(Ch2,1450,1000,0,255);
            int control=(cnt1+cnt2)/2;
          analogWrite(enA1, 0);
          digitalWrite(in11, LOW);                                     
          digitalWrite(in21, LOW);
          analogWrite(enB1, control);
          digitalWrite(in31, LOW);                                     
          digitalWrite(in41, HIGH);
          analogWrite(enA2, 0);
          digitalWrite(in12, LOW);                                     
          digitalWrite(in22, LOW);
          analogWrite(enB2, control); 
          digitalWrite(in32, LOW);                                     
          digitalWrite(in42, HIGH);
          Serial.println("225 Degree");
          }
          
// EXACT 315 DEGREE 
          if(Ch1 > 1550 && Ch1 < 2000 && Ch2 < 1450 && Ch2 > 1000 && Ch6<1100){
          int cnt1=map(Ch1,1550,2000,0,255);
            int cnt2=map(Ch2,1450,1000,0,255);
            int control=(cnt1+cnt2)/2;
          analogWrite(enA1, control);
          digitalWrite(in11, LOW);                                     
          digitalWrite(in21, HIGH);
          analogWrite(enB1, 0);
          digitalWrite(in31, LOW);                                     
          digitalWrite(in41, LOW);
          analogWrite(enA2, control);
          digitalWrite(in12, LOW);                                     
          digitalWrite(in22, HIGH);
          analogWrite(enB2, 0); 
          digitalWrite(in32, LOW);                                     
          digitalWrite(in42, LOW);
          Serial.println("315 Degree");
            }
            
// CLOCKWISE DIRECTION
          if(Ch5 > 1700 && Ch6 < 1100){
    int control=map(Ch5,1700,2000,0,255);
          analogWrite(enA1, control);
          digitalWrite(in11, LOW);                                     
          digitalWrite(in21, HIGH);
          analogWrite(enB1, control);
          digitalWrite(in31, HIGH);                                     
          digitalWrite(in41, LOW);
          analogWrite(enA2, control);
          digitalWrite(in12, HIGH);                                     
          digitalWrite(in22, LOW);
          analogWrite(enB2, control); 
          digitalWrite(in32, LOW);                                     
          digitalWrite(in42, HIGH);
  //        delayMicroseconds(1000);
          Serial.println("CLOCKWISE");
          }

          
//cOUNTER CLOCKWISE DIRECTION
            if(Ch5 < 1100 && Ch6 < 1100){
    int control=map(Ch5,1100,990,0,255);
            analogWrite(enA1, control);
          digitalWrite(in11, HIGH);                                     
          digitalWrite(in21, LOW);
          analogWrite(enB1, control);
          digitalWrite(in31, LOW);                                     
          digitalWrite(in41, HIGH);
          analogWrite(enA2, control);
          digitalWrite(in12, LOW);                                     
          digitalWrite(in22, HIGH);
          analogWrite(enB2, control); 
          digitalWrite(in32, HIGH);                                     
          digitalWrite(in42, LOW);
//          delayMicroseconds(1000);
          Serial.println("ANTICLOCKWISE");
            }

// Stop Position Claw Motion
       if(Ch3 > 1200 && Ch3 < 1700 && Ch4 > 1200 && Ch4 < 1700 && Ch6 < 1100){
        
          analogWrite(enA3, 0);
          digitalWrite(in13, LOW);                                     
          digitalWrite(in23, LOW);
          analogWrite(enB3, 0);
          digitalWrite(in33, LOW);                                     
          digitalWrite(in43, LOW);
          analogWrite(enA4, 0);
          digitalWrite(in14, LOW);                                     
          digitalWrite(in24, LOW);
//          delayMicroseconds(1000);
          Serial.println("Claw Stop");
            
}

  // Front Motion of the Claw
       if(Ch3 > 1700 && Ch3 < 2000 && Ch4 > 1200 && Ch4 < 1700 && Ch6 < 1100) {
          int control = map (Ch3,1700,2000,0,255);
          analogWrite(enA3, control);
          digitalWrite(in13, LOW);                                     
          digitalWrite(in23, HIGH);
          analogWrite(enB3, control);
          digitalWrite(in33, LOW);                                     
          digitalWrite(in43, HIGH);
          analogWrite(enA4, 0);
          digitalWrite(in14, LOW);                                     
          digitalWrite(in24, LOW);
          Serial.println("Claw Forward");
      

}
//Claw BAckward motion
       if(Ch3 > 1000 && Ch3 < 1200 && Ch4 > 1200 && Ch4 < 1700 && Ch6 < 1100) {
          int control = map (Ch3,1200,1000,0,255);
          analogWrite(enA3, control);
          digitalWrite(in13, HIGH);                                     
          digitalWrite(in23, LOW);
          analogWrite(enB3, control);
          digitalWrite(in33, HIGH);                                     
          digitalWrite(in43, LOW);
          analogWrite(enA4, 0);
          digitalWrite(in14, LOW);                                     
          digitalWrite(in24, LOW);
          Serial.println("Claw Backward");
      

}

//claw left motion
       if(Ch3 > 1200 && Ch3 < 1700 && Ch4 > 1000 && Ch4 < 1200 && Ch6 < 1100) {
          int control = map (Ch4,1200,1000,0,255);
          analogWrite(enA3, 0);
          digitalWrite(in13, LOW);                                     
          digitalWrite(in23, LOW);
          analogWrite(enB3, 0);
          digitalWrite(in33, LOW);                                     
          digitalWrite(in43, LOW);
          analogWrite(enA4, control);
          digitalWrite(in14, LOW);                                     
          digitalWrite(in24, HIGH);
//          delayMicroseconds(1000);
          Serial.println("Claw left");
      
}
//claw right motion
       if(Ch3 > 1200 && Ch3 < 1700 && Ch4 > 1700 && Ch4 < 2000 && Ch6 < 1100) {
          int control = map (Ch4,1700,2000,0,255);
          analogWrite(enA3, 0);
          digitalWrite(in13, LOW);                                     
          digitalWrite(in23, LOW);
          analogWrite(enB3, 0);
          digitalWrite(in33, LOW);                                     
          digitalWrite(in43, LOW);
          analogWrite(enA4, control);
          digitalWrite(in14, HIGH);                                     
          digitalWrite(in24, LOW);
//          delayMicroseconds(1000);
          Serial.println("Claw left");
     
}
//Right Claw STOP movement 
  if( Ch2 > 1450 && Ch2 < 1550 && Ch6>1800){
            
             analogWrite(enA3, 0);
          digitalWrite(in13, LOW);                                     
          digitalWrite(in23, LOW);
  }
// Right Claw Front Movement
  if( Ch2 > 1550 && Ch2 < 2000 && Ch6>1800){
              int control = map(Ch2,1550,2000,0,255);
           analogWrite(enA3, control);
          digitalWrite(in13, LOW);                                     
          digitalWrite(in23, HIGH);
  }

  // Right Claw Backward Movement
  if( Ch2 < 1450 && Ch2 >1000 && Ch6>1800){
              int control = map(Ch2,1450,1000,0,255);
              analogWrite(enA3, control);
          digitalWrite(in13, HIGH);                                     
          digitalWrite(in23, LOW);

  }
//LEFT Claw STOP movement 
  if( Ch3 > 1400 && Ch3 < 1550 && Ch6>1800){
           analogWrite(enB3, 0);
          digitalWrite(in33, LOW);                                     
          digitalWrite(in43, LOW);

  }
  // LEFT Claw Front Movement
  if( Ch3 > 1550 && Ch3 < 2000 && Ch6>1800){
         int control = map(Ch3,1550,2000,0,255);
           analogWrite(enB3, control);
          digitalWrite(in33, LOW);                                     
          digitalWrite(in43, HIGH);
  }

  // LEFT Claw Backward Movement
  if( Ch3 < 1400 && Ch3 > 1000 && Ch6>1800){
        int control = map(Ch3,1400,1000,0,255);
              analogWrite(enB3, control);
          digitalWrite(in33, HIGH);                                     
          digitalWrite(in43, LOW);

  }
//RIGHT LEFT  Claw STOP movement 
  if( Ch4 > 1450 && Ch4 < 1550 && Ch6>1800){
           analogWrite(enA4, 0);
          digitalWrite(in14, LOW);                                     
          digitalWrite(in24, LOW);
  }
//RIGHT LEFT  Claw Left movement 
  if( Ch4 > 1550 && Ch4<2000 && Ch6>1800){
          int control = map(Ch4,1550,2000,0,255);
           analogWrite(enA4, control);
          digitalWrite(in14, HIGH);                                     
          digitalWrite(in24, LOW);
  }
//RIGHT LEFT  Claw RIGHT movement 
  if( Ch4 < 1450 && Ch4 > 1000 && Ch6>1800){
            int control = map(Ch4,1450,1000,0,255);
           analogWrite(enA4, control);
          digitalWrite(in14, LOW);                                     
          digitalWrite(in24, HIGH);
  }
  


// Back flap stop

      if(Ch5 > 1100 && Ch5 < 1800 && Ch6 > 1800) {
                
          analogWrite(enB4, 0);
          digitalWrite(in34, LOW);                                     
          digitalWrite(in44, LOW);      
       Serial.println("Back flap stop");
      }      
// Back Flap Open 
      if(Ch5 > 1800 && Ch6 > 1800) {
          
          int control(Ch5,1800,2000,0,255);
          analogWrite(enB4, control);
          digitalWrite(in34, HIGH);                                     
          digitalWrite(in44, LOW);      
        Serial.println("Back flap Open");
        }
// Back Flap Close 
      if(Ch5 < 1100 && Ch6 > 1800) {
          
          int control(Ch5,1100,1000,0,255);
          analogWrite(enB4, control);
          digitalWrite(in34, LOW);                                     
          digitalWrite(in44, HIGH);      
        Serial.println("Back flap Close");
        }
//U BAND STOP
      if(Ch1 > 1200 && Ch1 < 1700 && Ch6 > 1800) {
          
          analogWrite(enA5, 0);
          digitalWrite(in15, LOW);                                     
          digitalWrite(in25, LOW);      
        Serial.println("U BAND STOP");
        }
//U BAND DOWN
      if(Ch1 < 1200 && Ch6 > 1800) {
          
          int control(Ch1,1200,1000,0,255);
          analogWrite(enA5, control);
          digitalWrite(in15, HIGH);                                     
          digitalWrite(in25, LOW);      
        Serial.println("U BAND DOWN");
        }
//U BAND UP
      if( Ch1 > 1700 && Ch6 > 1800) {
          
          int control(Ch1,1700,2000,0,255);
          analogWrite(enA5, control);
          digitalWrite(in15, LOW);                                     
          digitalWrite(in25, HIGH);      
        Serial.println("U BAND UP");
        }
}
