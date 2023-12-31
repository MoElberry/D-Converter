#include "StdTypes.h"
#include "DIO_Inteface.h"
#include "MOTOR_Cfg.h"
#include "MOTOR_Interface.h"


void MOTOR_Init(void){
	
	
}


void MOTOR_STOP(MOTOR_type m){
  
  
    DIO_WritePin(MotorPinArr[m][IN1],LOW);
    DIO_WritePin(MotorPinArr[m][IN2],LOW);

/*
	switch(m){
		case M1:
		    DIO_WritePin(M1_IN1,LOW);
		    DIO_WritePin(M1_IN2,LOW);
			break;
    	case M2:
		   	DIO_WritePin(M2_IN1,LOW);
		   	DIO_WritePin(M2_IN2,LOW);
			break;
		case M3:
			DIO_WritePin(M3_IN1,LOW);
			DIO_WritePin(M3_IN2,LOW);
		    break;	
		case M4:
		    DIO_WritePin(M4_IN1,LOW);
		    DIO_WritePin(M4_IN2,LOW);
			break;			   
	}
	*/

}
void MOTOR_CW(MOTOR_type m){

   DIO_WritePin(MotorPinArr[m][IN1],HIGH);
   DIO_WritePin(MotorPinArr[m][IN2],LOW);
  /*
	switch(m){
		case M1:
		        DIO_WritePin(M1_IN1,HIGH);
		        DIO_WritePin(M1_IN2,LOW);
				break;
		case M2:
				DIO_WritePin(M4_IN1,HIGH);
				DIO_WritePin(M2_IN2,LOW);
				break;
		case M3:
				DIO_WritePin(M3_IN1,HIGH);
				DIO_WritePin(M3_IN2,LOW);
				break;
		case M4:
				DIO_WritePin(M4_IN1,HIGH);
				DIO_WritePin(M4_IN2,LOW);
				break;
	}

 */
}
void MOTOR_CCW(MOTOR_type m){

   DIO_WritePin(MotorPinArr[m][IN1],LOW);
   DIO_WritePin(MotorPinArr[m][IN2],HIGH);

/*

	switch(m){
		case M1:
				DIO_WritePin(M1_IN1,LOW);
				DIO_WritePin(M1_IN2,HIGH);
				break;
		case M2:
				DIO_WritePin(M4_IN1,LOW);
				DIO_WritePin(M2_IN2,HIGH);
				break;
		case M3:
				DIO_WritePin(M3_IN1,LOW);
				DIO_WritePin(M3_IN2,HIGH);
				break;
		case M4:
				DIO_WritePin(M4_IN1,LOW);
				DIO_WritePin(M4_IN2,HIGH);
				break;
	}
	*/

}

/*************motor speed****************/

void MOTOR_Seed(MOTOR_type m,u8 speed){
	
	if (speed>MOTOR_MAX_SPEED)
	{
		speed=MOTOR_MAX_SPEED;   
	}
}