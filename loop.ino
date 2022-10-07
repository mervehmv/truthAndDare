int buzzerPin = 45;
byte buttonPin = A0;


int C = 262;
int D = 294;
int E = 330;
int F = 349;
int G = 392;
int A = 440;
int B = 494;
int C_ = 523;
int notalar[] = {C, D, E, F, G, A, B, C_};
void setup() {
  pinMode(53, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(buttonPin, INPUT);
  //Serial.begin(9600);
  
}

void loop(){ 
  int data  = analogRead(buttonPin);
  
  int c = random(46,54);
  if(data == 0){
    loopx(c);
    data  = analogRead(buttonPin);
  }
  while(data != 0){
    button(c);
    data  = analogRead(buttonPin);
  }
  
}


void loopx(int c) {
 
  for(int speed = 10; speed<= 150 ; speed+=10){
    for(int i = 46; i <= 53;i++){
 
      blink(i);
      tone(buzzerPin, 20000+speed);
      delay(speed);
      noTone(buzzerPin);
      }      
  }
  
  digitalWrite(c, HIGH);
  tone(buzzerPin, 20000);
  delay(200);
  noTone(buzzerPin);
  digitalWrite(c, LOW);
  delay(50);
}


void loopy(){
  int data = analogRead(buttonPin);
  for(int i = 46; i <= 53;i++){
 
      blink(i);
      tone(buzzerPin, 200);
      delay(10);
      noTone(buzzerPin);
      //Serial.print(data);  
      //Serial.println();
      //delay(100);
      data  = analogRead(buttonPin);
      if(data == 0){
        for(int i = 46; i <= 53;i++){
         digitalWrite(i,LOW);
       }
       delay(200);
       //button();
       i=46;
      
      }  
    } 
}
void loopz() {
  int data  = analogRead(buttonPin);
  for(int speed = 10; speed<= 50 ; speed+=5){
    for(int i = 46; i <= 53;i++){
 
      blink(i);
      //tone(buzzerPin, 200+speed);
      delay(speed);
      noTone(buzzerPin);
      Serial.print(data);  
      Serial.println();
      delay(100);
      data  = analogRead(buttonPin);
      if(data == 0){
        for(int i = 46; i <= 53;i++){
         digitalWrite(i,LOW);
       }
       delay(200);
       //button();
       i=46;
       speed = 10;
      }  
    }  
  }
}
void blink(int pinNumber)
{
  
  digitalWrite(pinNumber, HIGH);
  delay(10);
  digitalWrite(pinNumber, LOW);

  
}
void button(int c){
  
  digitalWrite(c, HIGH);
  tone(buzzerPin, 20000);
  delay(200);
  noTone(buzzerPin);
  digitalWrite(c, LOW);
  delay(50);

}
