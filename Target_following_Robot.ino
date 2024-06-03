#define trigpin 2
#define echopin 3

int m11 = 8;
int m12 = 9;
int m21 = 10;
int m22 = 11;

void setup()
{
 pinMode(m11, OUTPUT);
 pinMode(m12, OUTPUT);
 pinMode(m21, OUTPUT);
 pinMode(m22, OUTPUT);
 pinMode(trigpin, OUTPUT);
 pinMode(echopin, INPUT);
 Serial.begin(9600);
}

void loop()
{
 int duration, distance;
 digitalWrite(trigpin, HIGH);
 delayMicroseconds(1000);
 digitalWrite(trigpin, LOW);
 duration = pulseIn(echopin, HIGH);
 distance = (duration / 2) / 29.1;
 Serial.println(distance);

if (distance >= 30)
{
digitalWrite(m11, LOW);
digitalWrite(m12, LOW);
digitalWrite(m21, LOW);
digitalWrite(m22, LOW);
delay(500);
}
else
{

digitalWrite(m11, HIGH);
digitalWrite(m12, LOW);
digitalWrite(m21, HIGH);
digitalWrite(m22, LOW);
delay(400);

}
}
