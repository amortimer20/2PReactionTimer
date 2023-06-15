unsigned int waitTime;

byte stimLed = 8;
byte greenLed = 12;
byte greenBtn = 13;
byte yellowLed = 3;
byte yellowBtn = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(stimLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenBtn, INPUT);
  pinMode(yellowBtn, INPUT);
}

void loop()
{
  Serial.println("When the LED turns on, push the button!");
  Serial.println("Now, watch the LED. Ready?");
  waitTime = random(2000, 4000);
  delay(waitTime);

  digitalWrite(stimLed, HIGH);

  while (true)
  {
    if (digitalRead(greenBtn) == LOW)
    {
      digitalWrite(greenLed, HIGH);
      Serial.println("Winner is Player green!");
      break;
    }
    else if (digitalRead(yellowBtn) == LOW)
    {
      digitalWrite(yellowLed, HIGH);
      Serial.println("Winner is Player yellow!");
      break;
    }
  }

  

  digitalWrite(stimLed, LOW);
  delay(5000);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}
