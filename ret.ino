int pwm_speedA = 150;
int pwm_speedB = 145;

int count = 0;
int status = 0;

int statusSensor;
int statusSensor1;
int statusSensor2;
int statusSensor3;
int statusSensor4;

int bed;

int IR = 6;
int touch1 = 22;
int touch2 = 24;
int touch3 = 26;
int touch4 = 28;

void setup() {
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(3, OUTPUT);

pinMode(13, INPUT);
pinMode(2, INPUT);
pinMode(4, INPUT);
pinMode(7, INPUT);
pinMode(12, INPUT);

pinMode(IR, INPUT);
pinMode(touch1, INPUT);
pinMode(touch2, INPUT);
pinMode(touch3, INPUT);
pinMode(touch4, INPUT);

Serial.begin(9600);


}
void loop() {
   statusSensor = digitalRead(IR);
   statusSensor1 = digitalRead(touch1);
   statusSensor2 = digitalRead(touch2);
   statusSensor3 = digitalRead(touch3);
   statusSensor4 = digitalRead(touch4);
  
  if(statusSensor1 == HIGH){
     bed = 1;   
  }
  else if(statusSensor2 == HIGH){
    bed = 2;
  }                                                                // take using input or using push button ......
   else if(statusSensor3 == HIGH){
    bed = 3; 
  }
   else if(statusSensor4 == HIGH){
    bed = 4;
  }
    
    lfr();
    if(digitalRead(2) == LOW && digitalRead(7) == LOW && digitalRead(4) == LOW && digitalRead(12) == LOW && digitalRead(13) == LOW){
      count++;
    if(count == 1 && bed  == 1 && status == 0){
        Serial.print(   count);
        stop();
        delay(2000);
        left();
        delay(4000);
       
        bed = 0;
        Serial.print(  "   Bed =  " );
        Serial.print(  bed );
       
        status = 1;
        Serial.print( "   Status =  " );
        Serial.print(     status);
       
        count = 0;
        Serial.print( "   Count =  " );
        Serial.print(  count );

        
  }
   else if(bed == 2 && count == 1 && status == 0){
        Serial.print(    count);
        stop();
        delay(2000);
        right();
        delay(4000);
    
        bed = 0;
        Serial.print(  "   Bed =   " );
        Serial.print(  bed );
    
        status = 2;
        Serial.print( "   Status = " );
        Serial.print(     status);
       
        count = 0;
        Serial.print( "  Count =  " );
        Serial.print(   count  );
    

  }
  else if((bed == 3 || bed == 4) && count == 1){
    Serial.print(    count  );
    stop();
    delay(2000);
    forward();
    delay(3000);
    
  }
  else if(bed == 3 && count == 2 && status == 0){
       Serial.print(   count  );
       stop();
       delay(2000);
       left();
       delay(4000);

       bed = 0;
       Serial.print(  "   Bed =   " );
       Serial.print(  bed );
    
       status = 3;
       Serial.print( "   Status = " );
       Serial.print(     status);
       
       count = 1;
       Serial.print( "  Count =  " );
       Serial.print(   count  );
       
    
  }
    else if(bed == 4 && count == 2 && status == 0){
       Serial.print(   count  );
       stop();
       delay(2000);
       right();
       delay(4000);

       bed = 0;
       Serial.print(  "   Bed =   " );
       Serial.print(  bed );
    
       status = 4;
       Serial.print( "   Status = " );
       Serial.print(     status);
       
       count = 1;
       Serial.print( "  Count =  " );
       Serial.print(   count  );
    
  }

  else if(count == 1 && status == 1){
    Serial.print(  count  );
    stop();
    delay(2000);
    right();
    delay(3000);
  }
  
  else if(count == 1 && status == 2){
    Serial.print(  count  );
    stop();
    delay(2000);
    left();
    delay(3000);
  
  }
  else if(count == 2 && status == 3){
    Serial.print(  count  );
    stop();
    delay(2000);
    right();
    delay(3000);
  
  }
  else if(count == 2 && status == 4){
    Serial.print(  count  );  
    stop();
    delay(2000);
    left();
    delay(3000);
  
  }

  }

   if( statusSensor == 1){        // LOW or HIGH .. has to be changed.....
    Serial.print(" sensor  ...... ");
    stop();
    delay(10000);
    backward();    // need to test thisss ....... 
    delay(3000);
    turn();
    delay(3000); 
    }          
 
}
void forward(){
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  
  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);

  digitalWrite(5, 150);
  digitalWrite(3, 150);
}

void backward(){
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  
  digitalWrite(9, LOW);
  digitalWrite(6, HIGH);

  digitalWrite(5, 150);
  digitalWrite(3, 150);
}

void left(){
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);

  digitalWrite(3,150);
  digitalWrite(5, 150);
}

void right(){
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);

  digitalWrite(3, 150);
  digitalWrite(5, 150);
}

void stop(){
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);

  digitalWrite(5, 0);
  digitalWrite(3, 0);
}
void turn() {
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);

  digitalWrite(3, 100);
  digitalWrite(5, 100);
}

void lfr(){
  if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == LOW && digitalRead(12) == HIGH && digitalRead(13) == HIGH){
  forward();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH && digitalRead(12) == LOW && digitalRead(13) == LOW){
  left();
  }
  else if(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == HIGH){
  right();
  }
  else if(digitalRead(2) == LOW && digitalRead(7) == LOW && digitalRead(4) == LOW && digitalRead(12) == LOW && digitalRead(13) == LOW){
  forward();
  }
 /* else if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == HIGH){
  forward();
  }*/
  else if(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == LOW && digitalRead(12) == HIGH && digitalRead(13) == LOW ){
  right();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == LOW && digitalRead(12) == LOW && digitalRead(13) == HIGH){
  left();
  }
  else if(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == LOW ){
  right();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH && digitalRead(12) == LOW && digitalRead(13) == HIGH){
  left();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == HIGH){
  left();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == LOW && digitalRead(13) == HIGH){
  left();
  }
  

}
