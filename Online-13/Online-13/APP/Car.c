
/*
#include "MOTOR_Interface.h"
#include "DIO_Inteface.h"    
                              

#define  FB PIND3
#define  BB PIND4
#define  RB PIND5
#define  LB PIND6



static void MoveForward(void){
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
	
}

static void MoveBackward(void){
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);
	
}

static void MoveLeft(void){
	MOTOR_CW(M1);
	MOTOR_CCW(M2);
	MOTOR_CW(M3);
	MOTOR_CCW(M4);
	
}
static void MoveRight(void){
	MOTOR_CCW(M1);
	MOTOR_CW(M2);
	MOTOR_CCW(M3);
	MOTOR_CW(M4);
	
}



void CAR_Init(void){
	
	
}


void CAR_Runnable(void){
	if (DIO_ReadPin(FB)==LOW)
	{
		MoveForward();
	}
	
}

*/