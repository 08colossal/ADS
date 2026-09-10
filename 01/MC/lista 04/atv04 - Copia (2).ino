int btn = 13, pvm = 12, pvd = 11;
int vm = 7, am = 6, vd = 5;
bool pedido = false;

void setup()
{
  pinMode(btn, INPUT_PULLUP);
  pinMode(pvm, OUTPUT);
  pinMode(pvd, OUTPUT);
  pinMode(vm, OUTPUT);
  pinMode(am, OUTPUT);
  pinMode(vd, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  
  if (digitalRead(btn) == LOW) {
    pedido = true;
  }

  digitalWrite(vd, HIGH);
  digitalWrite(am, LOW);
  digitalWrite(vm, LOW);
  digitalWrite(pvm, HIGH);
  digitalWrite(pvd, LOW);
  delay(5000);
  
  if (pedido) {
    Serial.print("Clicado");
    digitalWrite(vd, LOW);
    digitalWrite(pvm, HIGH);
    digitalWrite(pvd, LOW);
    digitalWrite(am, HIGH);
    delay(5000);
    digitalWrite(pvd, HIGH);
    digitalWrite(am, LOW);
    digitalWrite(vm, HIGH);
    digitalWrite(pvm, LOW);
    delay(5000);
  }  
}