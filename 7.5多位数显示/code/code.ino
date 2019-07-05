void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
int count = 0;
int data[4] = {0, 0, 0, 0};
int code[10][4] = {
  {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1},
  {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}
};

void loop()
{
  if(count > 3)
    count = 0;
  for(int j = 0; j < 4; j++)
    digitalWrite(13 - j,HIGH);
  if(Serial.available() > 0)
  {
    digitalWrite(13 - count,LOW);
    data[count] = Serial.read() - 48;
    for(int i = 0; i < 4; i++)
    {
      if(code[data[count]][i] == 0)
        digitalWrite(5 - i,LOW);
      else
        digitalWrite(5 - i,HIGH);
    }
    digitalWrite(13 - count,HIGH);
    count++;
  }
  
}
