int bt1 = 13;
int zero = 10, um = 8, dois = 6;
int clicks =-1;

int antes1 = LOW;


void setup()
{
  pinMode(bt1, INPUT);
  pinMode(zero, OUTPUT);
  pinMode(um, OUTPUT);
  pinMode(dois, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int atual1 = digitalRead(bt1);

  // ligar leds
  if (clicks == 0){
 	digitalWrite(zero, 0);
    digitalWrite(um, 0);
    digitalWrite(dois, 0);
  }
  
  if (clicks == 1){
 	digitalWrite(zero, 0);
    digitalWrite(um, 0);
    digitalWrite(dois, 1);
  }
  if (clicks == 2){
 	digitalWrite(zero, 0);
    digitalWrite(um, 1);
    digitalWrite(dois, 0);
  }
  if (clicks == 3){
 	digitalWrite(zero, 0);
    digitalWrite(um, 1);
    digitalWrite(dois, 1);
  }
  if (clicks == 4){
 	digitalWrite(zero, 1);
    digitalWrite(um, 0);
    digitalWrite(dois, 0);
  }
   if (clicks == 5){
 	digitalWrite(zero, 1);
    digitalWrite(um, 0);
    digitalWrite(dois, 1);
  }
  if (clicks == 6){
 	digitalWrite(zero, 1);
    digitalWrite(um, 1);
    digitalWrite(dois, 0);
  }
   if (clicks == 7){
 	digitalWrite(zero, 1);
    digitalWrite(um, 1);
    digitalWrite(dois, 1);
    clicks = -1;
  }
   //zerar:
  	if (clicks == 8){
 	digitalWrite(zero, 0);
    digitalWrite(um, 0);
    digitalWrite(dois, 0);
    }
  
    // click ++
  if (antes1 == LOW && atual1 == HIGH ) {
    clicks++;
    Serial.println(clicks);
  }  
	
  
  antes1 = atual1; //high vira low e vice versa pro loop funcionar
 
}