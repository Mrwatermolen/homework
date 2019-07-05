void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

int data = 0;
int code[10][4] = {
  {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1},
  {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}
};

void loop()
{
  if(Serial.available() > 0)
  {
    data = Serial.read() - 48;
    for(int i = 0; i < 4; i++)
    {
      if(code[data][i] == 0)
        digitalWrite(5 - i,LOW);
      else
        digitalWrite(5 - i,HIGH);
    }
  }
  
}
