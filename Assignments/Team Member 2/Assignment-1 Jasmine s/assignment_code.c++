void setup()
{
Serial.begin(9600); //initialize serial communication
pinMode(A0, INPUT); //LDR
pinMode(2,INPUT); //PIR sensor
pinMode(A1, INPUT); //Gas sensor
pinMode(13, OUTPUT); //led
pinMode(8, OUTPUT); //buzzer
pinMode(3,OUTPUT); //led
}
void loop()
{
                                      //LDR sensor
int value=analogRead(A0);
if(value>500)
{
digitalWrite(13, HIGH);
Serial.print("BULB ON");
}
else
{
digitalWrite(13, LOW);
Serial.print("BULB OFF");
}
delay(300);
//Gas sensor
int val1=analogRead(A1);
if(val1>250)
{
Serial.print(" || Smoke Detected value=");
Serial.print(val1 );

tone(8,650);
}
else
{
Serial.print(" || No Smoke Detected");
}
delay(300);
noTone(8);
//PIR sensor
int val2=digitalRead(2);
delay(500);
if(val2==1)
{
Serial.println(" || Motion Detected");
}
else
{
Serial.println(" || No Motion Detected");
digitalWrite(3,LOW);
}
}



