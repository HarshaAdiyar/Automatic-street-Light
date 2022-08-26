int ldr;
int ir;
int ir1;
int analog=A0;


void setup() {
  pinMode(2,INPUT); 
  pinMode(A2,INPUT); 
  pinMode(analog,INPUT); 
  Serial.begin(9600);
  Serial.print("ldr value: ");
  pinMode(11,OUTPUT);  
  pinMode(8,OUTPUT);  
}

void loop() { 
  ldr=analogRead(analog);
  Serial.print("ldr value 1: ");  //if it is daytime
  Serial.println(ldr);   
  if(ldr>1000) {   
    Serial.print("ldr value 2: ");  //if it is night-time
    Serial.println(ldr);

    ir=digitalRead(2);
    ir1=analogRead(A2);
    
    Serial.print("ir value 2: ");  //value of ir1 if night
    Serial.println(ir);
    Serial.print("ir value 3: ");  //value of ir2 if night
    Serial.println(ir1);
    if(ir==LOW) {  //if somebody passes ir1
      digitalWrite(11, LOW);
    }
    else if(ir1<=100) {  //if somebody passes ir2
      digitalWrite(11,HIGH);
    }
  }
  else{  //if he/she doesn't pass ir2
      digitalWrite(11, HIGH);
  }
}
