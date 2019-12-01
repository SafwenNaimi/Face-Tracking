#include<Servo.h>

Servo servoVer; //Vertical Servo
Servo servoHor; //Horizontal Servo

int x;
int y;

int prevX;
int prevY;

void setup()
{
  Serial.begin(9600);
  servoVer.attach(5); //Attach Vertical Servo to Pin 5
  servoHor.attach(6); //Attach Horizontal Servo to Pin 6
  servoVer.write(90);
  servoHor.write(90);
}

void Pos_x()

  {
    int servoX = map(x, 600, 0, 20, 179);
    

    servoX = min(servoX, 179);
    servoX = max(servoX, 20);
   
    
    servoHor.write(servoX);
   
  }

void Pos_y()
{
 
    int servoY = map(y, 450, 0, 179, 20);

    
    servoY = min(servoY, 179);
    servoY = max(servoY, 20);
    
    
    servoVer.write(servoY);
}

/*void Pos()
{    int servoX = map(x, 600, 0, 20, 179);

  int servoY = map(y, 450, 0, 179, 20);

    servoX = min(servoX, 179);
    servoX = max(servoX, 20);
   
    
    servoY = min(servoY, 179);
    servoY = max(servoY, 20);
    
        servoHor.write(servoX);

    servoVer.write(servoY);
}*/




/*void loop()
{
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'X')
    {if(Serial.read() == 'Y')
      {x = Serial.parseInt();
      y = Serial.parseInt();}
     {Pos();}

      
      
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}}*/

/*void loop()
{
  if(Serial.available() > 0)
  {
   if (Serial.read()=='X')
   {
    x=Serial.parseInt();
    Pos_x();
   
     (Serial.read()=='Y');
    
      y=Serial.parseInt();
      Pos_y();
    
    
      
      
    
    }
    }
}*/
  /*
void loop()
{
  if(Serial.available() > 0){
    z=Serial.read();
    for(int i=1;i<4;i++){
      x=x+z[i];
      y=y+z[i+11];
    }
       x=Serial.parseInt();
       y=Serial.parseInt(); 
       pos_x;
       pos_y
  }
char x[]="";
char y[]="";
    }
*/  


char input="";

void loop()
{
  if(Serial.available() > 0)
  {input = Serial.read();
    if(input == 'X')
    {
      x=Serial.parseInt();
      Pos_x();
        
    }
    if (input=='Y')
    {
      y=Serial.parseInt();
      Pos_y();
    }
    input = ""; 
 
      
    }
    while(Serial.available() > 0)
    {
      Serial.read();
    }
}
/*
char input = "";
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()){ //checks if any data is in the serial buffer
  input = Serial.read(); //reads the data into a variable
  if(input == 'U'){
   servoVer.write(y+1);    //adjusts the servo angle according to the input
   y += 1;               //updates the value of the angle
  }
  else if(input == 'D'){ 
   servoVer.write(y-1);
   y -= 1;
  }
  else{
   servoVer.write(y);
  } 
  if(input == 'L'){
  servoHor.write(x-1);
  x -= 1;
  } else if(input == 'R'){
  servoHor.write(x+1);
  x += 1;
  }
  else{
  servoHor.write(x);
  }
  input = "";           //clears the variable
 }
 //process keeps repeating!! :)
}*/
