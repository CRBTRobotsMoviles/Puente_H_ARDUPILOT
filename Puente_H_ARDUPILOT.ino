float PWME1 = 0;
int PWMS1 = 0;
int IN1M1 = 5;
int IN2M1 = 6;
int ENM1 = 9;
int MAX = 1929;       //CALIBRAR
int INTE1 = 1535;     //CALIBRAR
int INTE2 = 1515;     //CALIBRAR
int MIN = 1165;       //CALIBRAR
int DIF1 = 0;
int DIF2 = 0;

void setup ()
{
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(IN1M1, LOW);
  digitalWrite(IN2M1, LOW);
  DIF1=MAX-INTE1;
  DIF2=INTE2-MIN;
  Serial.begin (9600);
}

void loop ()
{
PWME1 = pulseIn (3, HIGH);
Serial.print ("Valor del pulso: ");
Serial.println (PWME1);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////MOTOR 1
  if (PWME1>INTE1){
    digitalWrite(IN1M1, HIGH); 
    digitalWrite(IN2M1, LOW);
    PWME1=MAX-PWME1;
    PWMS1=map(PWME1,DIF1,0,0,255);
    analogWrite(9,PWMS1);
    Serial.print ("Valor PWM: ");
    Serial.println (PWMS1);
  }
  else if(PWME1>INTE2&&PWME1<INTE1){
    digitalWrite(IN1M1, LOW);
    digitalWrite(IN2M1, LOW);
    PWMS1=0;
    analogWrite(9,PWMS1);
    Serial.print ("Valor PWM: ");
    Serial.println (PWMS1);
  }
  else if(PWME1<INTE2){
    digitalWrite(IN1M1, LOW);
    digitalWrite(IN2M1, HIGH);
    PWME1=INTE2-PWME1;
    PWMS1=map(PWME1,0,DIF2,0,255);
    analogWrite(9,PWMS1);
    Serial.print ("Valor PWM: ");
    Serial.println (PWMS1);
  }
}
