const int r = 6, g = 5, b = 3;
int R = 0, G = 0, B = 0;
void setup()
{
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop()
{
  //GB
  for (G = 0; G <= 255; G += 5){
  	analogWrite(g, G);
    delay(100);
  }
  
  for (B = 0; B <= 255; B += 5){
	  analogWrite(b, B);
    delay(100);
  }
  
  analogWrite(r, 0);
  analogWrite(g, 0);
  analogWrite(b, 0);
  
  
  //RG
  for (R = 0; R <= 255; R += 5){
   	analogWrite(r, R); 
    delay(100);
  }
  
  for (G = 0; G <= 255; G += 5){
  	analogWrite(g, G);
    delay(100);
  }
  
  analogWrite(r, 0);
  analogWrite(g, 0);
  analogWrite(b, 0);
  
  //RBG
  for (R = 0; R <= 255; R += 5){
   	analogWrite(r, R); 
    delay(100);
  }
  
  for (B = 0; B <= 255; B += 5){
	  analogWrite(b, B);
    delay(100);
  }
  
  
  for (G = 0; G <= 255; G += 5){
  	analogWrite(g, G);
    delay(100);
  }
  analogWrite(r, 0);
  analogWrite(g, 0);
  analogWrite(b, 0);
}
