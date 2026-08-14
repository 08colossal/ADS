const int id1 = 11, id2 = 10, id3 = 9;
const int led = 8;
int etapa = 0;

void setup(){
	pinMode(id1, INPUT);
	pinMode(id2, INPUT);
  	pinMode(id3, INPUT);
  	pinMode(led, OUTPUT);
}


void loop(){
	int aceso1 = digitalRead(id1);
  	int aceso2 = digitalRead(id2);
  	int aceso3 = digitalRead(id3);
  
  if (aceso1 == 1 && aceso2 == 0 && aceso3 == 0){
  	etapa = 1; 
  } 
  else if (aceso1 == 0 && aceso2 == 1 && aceso3 == 0){
  	digitalWrite(led, HIGH);
    delay(2000); 
  } 
  else if (aceso1 == 0 && aceso2 == 0 && aceso3 == 1){
  	digitalWrite(led, HIGH);
    delay(2000); 
  } 
  else if (aceso1 == 0 && aceso2 == 1 && aceso3 == 1){
  	digitalWrite(led, HIGH);
    delay(2000); 
  } 
  
  
  if (etapa == 1){
    if(aceso3 == 1 && aceso2 == 0){
    	etapa = 2;
    }
    else if(aceso3 == 0 && aceso2 == 1){
    	digitalWrite(led, HIGH);
      	delay(2000);
    }
    
  }
  
  if (etapa == 2){
    if (aceso2 == 1){
      etapa = 3; 
    }
  }
  
  if (etapa == 3){
  	digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    etapa = 0;
   }
  
  if (aceso1 == 0 || aceso2 == 0 || aceso3 == 0){
    digitalWrite(led, LOW); 
  }
}
