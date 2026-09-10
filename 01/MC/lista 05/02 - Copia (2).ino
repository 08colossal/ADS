int l1 = 11, l2 = 10, l3 = 9, l4 = 6, l5 = 5, l6 = 3;
int pot = A5, estadopot;

void setup()
{
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(pot, INPUT);
}

void loop()
{
  estadopot = analogRead(pot);
  if (estadopot <= 146){
  	analogWrite(l1, LOW);
    analogWrite(l2, LOW);
    analogWrite(l3, LOW);
    analogWrite(l4, LOW);
    analogWrite(l5, LOW);
    analogWrite(l6, LOW);
  }
  else if (estadopot <= 292){
  	analogWrite(l1, HIGH);
    analogWrite(l2, LOW);
    analogWrite(l3, LOW);
    analogWrite(l4, LOW);
    analogWrite(l5, LOW);
    analogWrite(l6, LOW);
  }
  else if (estadopot <= 438){
  	analogWrite(l1, HIGH);
    analogWrite(l2, HIGH);
    analogWrite(l3, LOW);
    analogWrite(l4, LOW);
    analogWrite(l5, LOW);
    analogWrite(l6, LOW);
  }
  else if (estadopot <= 585){
  	analogWrite(l1, HIGH);
    analogWrite(l2, HIGH);
    analogWrite(l3, HIGH);
    analogWrite(l4, LOW);
    analogWrite(l5, LOW);
    analogWrite(l6, LOW);
  }
  else if (estadopot <= 731){
  	analogWrite(l1, HIGH);
    analogWrite(l2, HIGH);
    analogWrite(l3, HIGH);
    analogWrite(l4, HIGH);
    analogWrite(l5, LOW);
    analogWrite(l6, LOW);
  }
  else if (estadopot <= 877){
  	analogWrite(l1, HIGH);
    analogWrite(l2, HIGH);
    analogWrite(l3, HIGH);
    analogWrite(l4, HIGH);
    analogWrite(l5, HIGH);
    analogWrite(l6, LOW);
  }
  else{
  	analogWrite(l1, HIGH);
    analogWrite(l2, HIGH);
    analogWrite(l3, HIGH);
    analogWrite(l4, HIGH);
    analogWrite(l5, HIGH);
    analogWrite(l6, HIGH);
  }
}