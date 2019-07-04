void setup()
{
  //drive
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);//drive left
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);//drive right
  
  //LED
  pinMode(13, OUTPUT);//LED forward_left
  pinMode(12, OUTPUT);//LED forward_right
  pinMode(7, OUTPUT);//LED backward_left
  pinMode(4, OUTPUT);//LED backward_right
  Serial.begin(9600);
}

int income=0;
digitalWrite(13, LOW);
digitalWrite(12, LOW);
digitalWrite(7, LOW);
digitalWrite(4, LOW);
void loop()
{
  if(Serial.available()>0)
    {
      income=Serial.read();
        
        switch(income)
        {
          case 'f':
              forward();
              break;
            case 'b':
              backward();
              digitalWrite(7, HIGH);digitalWrite(4, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(4, LOW);delay(100); 
              digitalWrite(7, HIGH);digitalWrite(4, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(4, LOW);delay(100); 
              digitalWrite(7, HIGH);digitalWrite(4, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(4, LOW);delay(100); 
              digitalWrite(7, HIGH);digitalWrite(4, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(4, LOW);delay(100); 
              digitalWrite(7, HIGH);digitalWrite(4, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(4, LOW);delay(100); 
              break;
            case 'l':
              left();
              digitalWrite(7, HIGH);digitalWrite(13, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(13, LOW);delay(100); 
              digitalWrite(7, HIGH);digitalWrite(13, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(13, LOW);delay(100); 
            digitalWrite(7, HIGH);digitalWrite(13, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(13, LOW);delay(100); 
              digitalWrite(7, HIGH);digitalWrite(13, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(13, LOW);delay(100); 
              digitalWrite(7, HIGH);digitalWrite(13, HIGH);delay(100);
            digitalWrite(7, LOW);digitalWrite(13, LOW);delay(100); 
              break;
            case 'r':
              right();
                digitalWrite(4, HIGH);digitalWrite(12, HIGH);delay(100);
            digitalWrite(4, LOW);digitalWrite(12, LOW);delay(100);
            digitalWrite(4, HIGH);digitalWrite(12, HIGH);delay(100);
            digitalWrite(4, LOW);digitalWrite(12, LOW);delay(100); 
              digitalWrite(4, HIGH);digitalWrite(12, HIGH);delay(100);
            digitalWrite(4, LOW);digitalWrite(12, LOW);delay(100); 
            digitalWrite(4, HIGH);digitalWrite(12, HIGH);delay(100);
            digitalWrite(4, LOW);digitalWrite(12, LOW);delay(100); 
            digitalWrite(4, HIGH);digitalWrite(12, HIGH);delay(100);
            digitalWrite(4, LOW);digitalWrite(12, LOW);delay(100); 
              break;
            case 's':
              stop();
              digitalWrite(7, HIGH);digitalWrite(4, HIGH);delay(9999);
             
              break;
            default:
              break;
        }
    }
}

void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}

void backward()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}

void left()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}

void right()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}

void stop()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}
