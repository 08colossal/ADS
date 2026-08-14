const int sw1 = 13, sw2 = 12, led1 = 11, led2 = 10;

void setup()
{
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}
int antes = -1, agora = -1;
void loop()
{
  if(digitalRead(sw1) == 1 && digitalRead(sw2) == 0){
  	digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    agora =1;
    if(agora != antes){
      Serial.println("Interruptor 1, led VERDE");
    }
  }
  
  
  if(digitalRead(sw1) == 0 && digitalRead(sw2) == 1){
  	digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    agora = 2;
    if(agora != antes){
      Serial.println("Interruptor 2, led VERMELHO");
    }
  }
  
  if(digitalRead(sw2) == 1 && digitalRead(sw1) == 1){
  	digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
     agora = 3;
    if(agora != antes){
      Serial.println("Interruptores 1 e 2, led VERMELHO");
    }
  }
  
  if(digitalRead(sw1) == 0 && digitalRead(sw2) == 0){
   	digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    agora = 0;
  }
  antes = agora;
}