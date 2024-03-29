const int s0=8;
const int s1=0;
const int s2=12;
const int s3=11;
const int out=10;
int redLed=2;
int greenLed=3;
int blueLed=4;
int red=0;
int green=0;
int blue=0;
void setup(){
  Serial.begin(9600);
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
}
void loop(){
  color();
  Serial.print("R Intensity");
  Serial.print(red,DEC);
  Serial.print("G Intensity");
  Serial.print(green,DEC);
  Serial.print("B Intensity");
  Serial.print(blue,DEC);
  
  if(red<blue && red<green){
    Serial.println("-(Red Colour)");
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
  }
  
  else if(blue<red && blue<green){
    Serial.println("-(Blue Colour)");
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,HIGH);
  }
  
  else if(red<blue && red<green){
    Serial.println("-(Green Colour)");
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,LOW);
  }
  
  else{
    Serial.println();
  }
  delay(300);
  
}

void color(){
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  red=pulseIn(out,digitalRead(out)==HIGH?LOW:HIGH);
  digitalWrite(s3,HIGH);
  blue=pulseIn(out,digitalRead(out)==HIGH?LOW:HIGH);
  digitalWrite(s2,HIGH);
  green=pulseIn(out,digitalRead(out)==HIGH?LOW:HIGH);
}

    
    

