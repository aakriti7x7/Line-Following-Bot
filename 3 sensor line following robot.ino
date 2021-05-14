int R_AC = 2; 		 //motor a = +    //Right Motor  //AntiClock Wise
int R_CW = 3; 		 //motor a = -    //Right Motor  //Clock Wise
int L_AC = 4; 		 //motor b = -    //Left Motor   //AntiClock Wise
int L_CW = 5; 		 //motor b = +    //Left Motor   //Clock Wise
int S_R = 10; 		 //speed of Right Motor
int S_L = 11; 		 //speed of Left Motor
                                   
int RS = A0; 		 //Right Sensor 
int CS = A1; 		 //Centre Sencor 
int LS = A2; 		 //Left Sencor 

void setup() 
{
pinMode(L_AC, OUTPUT);
pinMode(L_CW, OUTPUT);
pinMode(R_AC, OUTPUT);
pinMode(R_CW, OUTPUT);
pinMode(S_L, OUTPUT);
pinMode(S_R, OUTPUT);

pinMode(LS, INPUT);
pinMode(CS, INPUT);
pinMode(RS, INPUT);

analogWrite(S_R, 150);              //speed inversly proportional to accuracy
analogWrite(S_L, 150);              //max speed 225, better to keep it slow
delay(200);
}

void loop()
{  
	if ((digitalRead(LS) == 0)&&(digitalRead(CS) == 1)&&(digitalRead(RS) == 0))          //Forward
	{
		digitalWrite(R_AC, LOW);
		digitalWrite(R_CW, HIGH);
		digitalWrite(L_AC, HIGH);
		digitalWrite(L_CW, LOW); 
	}

	if ((digitalRead(LS) == 1)&&(digitalRead(CS) == 1)&&(digitalRead(RS) == 0))          //Turn Left  //Left Motor stops right one moves clockwise
	                                                                                        
		digitalWrite(R_AC, LOW);
		digitalWrite(R_CW, HIGH);
		digitalWrite(L_AC, LOW);
		digitalWrite(L_CW, LOW);
	}

	if ((digitalRead(LS) == 1)&&(digitalRead(CS) ==0)&&(digitalRead(RS) == 0))           //Turn Left
	{
		digitalWrite(R_AC, LOW);
		digitalWrite(R_CW, HIGH);
		digitalWrite(L_AC, LOW);
		digitalWrite(L_CW, LOW);
	}

	if ((digitalRead(LS) == 0)&&(digitalRead(CS) == 1)&&(digitalRead(RS) == 1))           //Turn Right //Right Motor stops left one moves anti clockwise
	{
		digitalWrite(R_AC, LOW);
		digitalWrite(R_CW, LOW);
		digitalWrite(L_AC, HIGH);
		digitalWrite(L_CW, LOW);
	}

	if ((digitalRead(LS) == 0)&&(digitalRead(CS) == 0)&&(digitalRead(RS) == 1))           //Turn Right
	{
		digitalWrite(R_AC, LOW);
		digitalWrite(R_CW, LOW);
		digitalWrite(L_AC, HIGH);
		digitalWrite(L_CW, LOW);
	}

	if ((digitalRead(LS) == 1)&&(digitalRead(CS) == 1)&&(digitalRead(RS) == 1))           //Stop //both Motor stops
	{
		digitalWrite(R_AC, LOW);
		digitalWrite(R_CW, LOW);
		digitalWrite(L_AC, LOW);
		digitalWrite(L_CW, LOW);
	}
}

