

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"


#include "DIO_Inteface.h"
#include "MOTOR_Interface.h"
#include "KeyPad_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Cfg.h"
#include "ADC_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"





typedef enum{
	NO_VALUE,
	HEX_TO_DEC,
	HEX_TO_BIN,
	HEX_TO_HEX,
	DEC_TO_HEX,
	DEC_TO_BIN,
	DEC_TO_DEC,
	BIN_TO_DEC,
	BIN_TO_BIN,
	BIN_TO_HEX
	
	}convert_type;
	
	
	typedef enum{
		BIN,
		DEC,
		HEX
		
	}flag_type;
	
	
	int main(void)
	{
		  DIO_Init();
		  MOTOR_Init();
		  LCD_Init();
		  KEYPAD_Init();
	
		 convert_type  state=NO_VALUE;
		 flag_type  FlagType=DEC;
		 flag_type  FlagType2=DEC;
		 u8 num;
		 u8 k=NO_KEY;
		 u8 init_flag=0;
		 u8 flag_state1=0;
		 u8 flag_state2=0;
	
		 u8 str[8]={0};
		 u8 i=0,c=2;
		 u8 HexToDec[8]={0};
		 u8 j =0;
         u8 index_bin=10;
		while (1)
		{  
		  
		   // Welcome Message
	if (init_flag==0)
	{
		LCD_GoTo(0,5);
		LCD_WriteString("HELLO");
		LCD_GoTo(1,0);
		LCD_WriteString("Converter ELBERY..");
		_delay_ms(2000);
		
		LCD_GoTo(0,0);
		LCD_WriteString("Convert from ");
		LCD_GoTo(1,0);
		LCD_WriteString("1:D   2:B    3:H");
		
		init_flag=1;
		flag_state1=0;
	}
	    /*************************** state 1    and clear ****************/
	if ((init_flag==1)&&(flag_state1==0))
	{
		
		 k=KEYPAD_GetKey();
		 
		 if (k!=NO_KEY){
			 
			   // clear screen
			   if (k=='C')
			   {
				   
				 	LCD_ClearPosition(0,0,15);
				 	LCD_ClearPosition(1,0,15);
				   LCD_GoTo(0,0);
				   init_flag=0;
				   flag_state1=0;
				   flag_state2=0;
				   index_bin=10;
				   str[8]=0;
					   i=0;
			   }
			   
			   /************state one ***************/
			   	if (k=='1')
			   	{
				   	LCD_GoTo(0,0);
				   	LCD_WriteString("Convert D to ");
				   	LCD_GoTo(1,0);
				   	LCD_WriteString("1:D   2:B    3:H");
				   flag_state1=1;
				   	FlagType=DEC;
			   	}else if (k=='2')
			   	{
				   	LCD_GoTo(0,0);
				   	LCD_WriteString("Convert B to ");
				   	LCD_GoTo(1,0);
				   	LCD_WriteString("1:D   2:B    3:H");
				    flag_state1=1;
				    FlagType=BIN;
			   	}else if (k=='3')
			   	{
				   	LCD_GoTo(0,0);
				   	LCD_WriteString("Convert H to ");
				   	LCD_GoTo(1,0);
				   	LCD_WriteString("1:D   2:B    3:H");
				   	 flag_state1=1;
				    FlagType=HEX;
			   	}
			 
		 }
	//	flag_state1=1;       //Not to enter here again
	
	}
	   
	////////////////////////////////////////////////////////////
	
	/*************************** state 2   and clear ****************/
	if ((flag_state1==1)&&(flag_state2==0))
	{
		k=KEYPAD_GetKey();
		if (k!=NO_KEY){
			// clear screen
			 if (k=='C')
			 {
				 
					LCD_ClearPosition(0,0,15);
					LCD_ClearPosition(1,0,15);
				 LCD_GoTo(0,0);
				 init_flag=0;
				 flag_state1=0;
				 flag_state2=0;
				 index_bin=10;
				 str[8]=0;
					 i=0;
			 }
			
			/************state two ***************/
			if (k=='1')
			{
				flag_state2=1; 
				 FlagType2=DEC;
				switch(FlagType){
					case DEC:
					   LCD_ClearPosition(0,0,13);
					   state=DEC_TO_DEC;
					  
					   LCD_GoTo(0,0);
					   LCD_WriteString("DEC TO DEC ");
					   _delay_ms(500);
					   
					   LCD_ClearPosition(0,0,13);
					   LCD_GoTo(0,0);
					   LCD_WriteString("D: ");
					   LCD_ClearPosition(1,0,16);
					   LCD_GoTo(1,0);
					   LCD_WriteString("D: ");
					   break;
			       case BIN:
				        LCD_ClearPosition(0,0,13);
				        state=BIN_TO_DEC;
						
						LCD_GoTo(0,0);
						LCD_WriteString("BIN TO DEC ");
						_delay_ms(500);
						LCD_ClearPosition(0,0,13);
					    LCD_GoTo(0,0);
				   	    LCD_WriteString("B: ");
					    LCD_ClearPosition(1,0,16);
						LCD_GoTo(1,0);
						LCD_WriteString("D: ");
						break;
				   case HEX:
				        LCD_ClearPosition(0,0,13);
				        state=HEX_TO_DEC;
					
						LCD_GoTo(0,0);
						LCD_WriteString("HEX TO DEC ");
						_delay_ms(500);
						LCD_ClearPosition(0,0,13);
						LCD_GoTo(0,0);
						LCD_WriteString("H: ");
						LCD_ClearPosition(1,0,16);
						LCD_GoTo(1,0);
						LCD_WriteString("D: ");
						break;
						
				}
			}else if (k=='2')
			{
				flag_state2=1; 
				 FlagType2=BIN;
				switch(FlagType){
					case DEC:
					LCD_ClearPosition(0,0,13);
					state=DEC_TO_BIN;
					LCD_GoTo(0,0);
					LCD_WriteString("DEC TO BIN ");
					_delay_ms(500);
					LCD_ClearPosition(0,0,13);
					LCD_GoTo(0,0);
					LCD_WriteString("D: ");
					LCD_ClearPosition(1,0,16);
					LCD_GoTo(1,0);
					LCD_WriteString("B: ");
					break;
					case BIN:
					LCD_ClearPosition(0,0,13);
					state=BIN_TO_BIN;
					LCD_GoTo(0,0);
					LCD_WriteString("BIN TO BIN ");
					_delay_ms(500);
					LCD_ClearPosition(0,0,13);
					LCD_GoTo(0,0);
					LCD_WriteString("B: ");
					LCD_ClearPosition(1,0,16);
					LCD_GoTo(1,0);
					LCD_WriteString("B: ");
					break;
					case HEX:
					LCD_ClearPosition(0,0,13);
					state=HEX_TO_BIN;
					LCD_GoTo(0,0);
					LCD_WriteString("HEX TO BIN ");
					_delay_ms(500);
					LCD_ClearPosition(0,0,13);
					LCD_GoTo(0,0);
					LCD_WriteString("H: ");
					LCD_ClearPosition(1,0,16);
					LCD_GoTo(1,0);
					LCD_WriteString("B: ");
					break;
				}
				
			}else if (k=='3')
			{
				flag_state2=1;
				 FlagType2=HEX; 
				switch(FlagType){
					case DEC:
					LCD_ClearPosition(0,0,13);
					state=DEC_TO_HEX;
					LCD_GoTo(0,0);
					LCD_WriteString("DEC TO HEX ");
					_delay_ms(500);
					LCD_ClearPosition(0,0,13);
					LCD_GoTo(0,0);
					LCD_WriteString("D: ");
					LCD_ClearPosition(1,0,16);
					LCD_GoTo(1,0);
					LCD_WriteString("H: ");
					break;
					case BIN:
					LCD_ClearPosition(0,0,13);
					state=BIN_TO_HEX;
					LCD_GoTo(0,0);
					LCD_WriteString("BIN TO HEX ");
					_delay_ms(500);
					LCD_ClearPosition(0,0,13);
					LCD_GoTo(0,0);
					LCD_WriteString("B: ");
					LCD_ClearPosition(1,0,16);
					LCD_GoTo(1,0);
					LCD_WriteString("H: ");
					break;
					case HEX:
					state=HEX_TO_HEX;
					LCD_ClearPosition(0,0,13);
					LCD_GoTo(0,0);
					LCD_WriteString("HEX TO HEX ");
					_delay_ms(500);
				    LCD_ClearPosition(0,0,13);
				    LCD_GoTo(0,0);
				    LCD_WriteString("H: ");
				    LCD_ClearPosition(1,0,16);
					LCD_GoTo(1,0);
					LCD_WriteString("H: ");
					break;
				}
				
			}
			
		}
	
		
	}
		
	/**********************************************************main app*******************************/
		
	if (flag_state2==1)
	{
		k=KEYPAD_GetKey();
		// clear screen
		if (k=='C')
		{
			
			LCD_ClearPosition(0,0,15);
			LCD_ClearPosition(1,0,15);
			LCD_GoTo(0,0);
			init_flag=0;
			flag_state1=0;
			flag_state2=0;
			index_bin=10;
			str[8]=0;
			c=2;
			i=0;
		}
		if (k!=NO_KEY){
			 
			switch(FlagType){
						 c=2;
					case DEC:
				             
							  if(k>='0'&&k<='9')
							  {
								  LCD_GoTo(0,c);
								  c++;
								  LCD_WriteChar(k);
								  num=num*10+(k-'0');
							  }
							  break;
				   case HEX:
				           
							if(k>='0'&&k<='9')
							{ 
								HexToDec[j]=k;
								j++;
								LCD_GoTo(0,c);
								c++;
								LCD_WriteChar(k);
					
							}else if (k=='/')    // A
							{
								k='A';
								HexToDec[j]=k;
								j++;
								LCD_GoTo(0,c);
								c++;
								LCD_WriteChar(k);
						
						   }else if (k=='*')    // B
						   {
								k='B';
								HexToDec[j]=k;
								j++;
								LCD_GoTo(0,c);
								 c++;
								LCD_WriteChar(k);
						
						   }else if (k=='-')    // E
						   {
							   k='E';
							   HexToDec[j]=k;
							   j++;
							   LCD_GoTo(0,c);
							   c++;
							   LCD_WriteChar(k);
					   
						   }
						   else if (k=='+')    // F
						   {
								k='F';
								HexToDec[j]=k;
								j++;
								LCD_GoTo(0,c);
								c++;
								LCD_WriteChar(k);
					   
							}
					
							num=LCD_StrHexToDec(HexToDec);
							break;
				   case BIN:
                           				
							if(k>='0'&&k<='1')
							{
								str[i]=k;
								i++;
								LCD_GoTo(0,index_bin);
								index_bin--;
								if (index_bin==2)
								{
									index_bin=10;
								}
								LCD_WriteChar(k);
							}
							break;
			  }
			// 
			if (k=='=')
			{    
				 index_bin=10;
			    c=1;
				switch( FlagType2){
								
						case DEC:
					    LCD_GoTo(1,c);
								switch(FlagType)
								{
									
									case DEC:
										state=DEC_TO_DEC;
							
										LCD_WriteNumber(num);
										c++;
										break;
									case HEX:
										state=HEX_TO_DEC;
										 num=LCD_StrHexToDec(HexToDec);          
							
										LCD_WriteNumber(num);
										c++;
										break;
									case BIN:
										state=BIN_TO_DEC;
										num=0;
			     						num=LCD_BinaryToDec(str);           
							
										LCD_WriteNumber(num);
							
										c++;
										break;
								}
								num=0;
								break;
						case HEX:
								LCD_GoTo(1,c);
								switch(FlagType)
								{
									
									case DEC:
										state=DEC_TO_HEX;
										LCD_WriteHex(num);
										c++;
										break;
						
									case HEX:
										state=HEX_TO_HEX;
										LCD_WriteHex(num);
										c++;
										break;
									case BIN:
										state=BIN_TO_HEX;
										num=LCD_BinaryToDec(str); 
										LCD_WriteHex(num); 
				
										i=0;
										c++;
										break;
								}
								num=0;
								break;
						case BIN:
								LCD_GoTo(1,c);
								switch(FlagType)
								{
									
									case DEC:
										state=DEC_TO_BIN;
			    						LCD_DecToBinary(num);
										c++;
										break;
									case HEX:
										state=HEX_TO_BIN;
										 num=LCD_StrHexToDec(HexToDec);
										 LCD_DecToBinary(num);
				
										c++;
										break;
									case BIN:
										state=BIN_TO_BIN;
										LCD_WriteString(str);				
										c++;
										break;
								}
								num=0;
								break;
								
					}
					 
					
				}
			
			}
		 
	     }
		

	
        }
		   
		
	}

	

	
	
	
	
	
	
	
	
	/////////////////////////////////////////////////////////////////////////////
	
	/*
void Converter_Init(void)
{
	convert_type  state=NO_VALUE;
	flag_type  FlagType=DEC;
	u8 num;
	u8 k;
	u8 init_flag=0;
	u8 flag_state1=0;
	u8 flag_state2=0;
	u8  flag_D=0;
	u8  flag_B=0;
	u8  flag_H=0;
	
	
	// Welcome Message
	if (init_flag==0)
	{
		LCD_GoTo(0,5);
		LCD_WriteString("HELLO");
		LCD_GoTo(1,0);
		LCD_WriteString("Converter ELBERY..");
		_delay_ms(2000);
		
		LCD_GoTo(0,0);
		LCD_WriteString("Convert from ");
		LCD_GoTo(1,0);
		LCD_WriteString("1:D   2:B    3:H");
		
		init_flag=1;
		flag_state1=0;
	}
	    // state 1    and clear 
	if ((init_flag==1)&&(flag_state1==0))
	{
		 k=KEYPAD_GetKey();
		 if (k!=NO_KEY){
			   // clear screen
			   if (k=='C')
			   {
				   LCD_ClearPosition(0,0,15);
				   LCD_ClearPosition(1,0,15);
				   LCD_GoTo(0,0);
				   init_flag=0;
				   flag_state1=0;
				   flag_state2=0;
			   }
			   
			   //state one 
			   	if (k=='1')
			   	{
				   	LCD_GoTo(0,0);
				   	LCD_WriteString("Convert D to ");
				   	LCD_GoTo(1,0);
				   	LCD_WriteString("1:D   2:B    3:H");
				   
				   	FlagType=DEC;
			   	}else if (k=='2')
			   	{
				   	LCD_GoTo(0,0);
				   	LCD_WriteString("Convert B to ");
				   	LCD_GoTo(1,0);
				   	LCD_WriteString("1:D   2:B    3:H");
				   
				    FlagType=BIN;
			   	}else if (k=='3')
			   	{
				   	LCD_GoTo(0,0);
				   	LCD_WriteString("Convert H to ");
				   	LCD_GoTo(1,0);
				   	LCD_WriteString("1:D   2:B    3:H");
				   	
				    FlagType=HEX;
			   	}
			 
		 }
		flag_state1=1;       //Not to enter here again
	}
	   
	////////////////////////////////////////////////////////////
	
	// state 2   and clear /
	if ((flag_state1==1)&&(flag_state2==0))
	{
		k=KEYPAD_GetKey();
		if (k!=NO_KEY){
			// clear screen
			if (k=='C')
			{
				LCD_ClearPosition(0,0,15);
				LCD_ClearPosition(1,0,15);
				LCD_GoTo(0,0);
				init_flag=0;
				flag_state1=0;
				flag_state2=0;
			}
			
			//state two /
			if (k=='1')
			{
				switch(FlagType){
					case DEC:
					   state=DEC_TO_DEC;
					   LCD_GoTo(0,0);
					   LCD_WriteString("DEC TO DEC ");
					   _delay_ms(500);
					   LCD_GoTo(0,0);
					   LCD_WriteString("            ");
					   LCD_GoTo(0,0);
					   LCD_WriteString("D: ");
					   LCD_GoTo(1,0);
					   LCD_WriteString("D: ");
					   break;
			       case BIN:
				        state=BIN_TO_DEC;
						LCD_GoTo(0,0);
						LCD_WriteString("BIN TO DEC ");
						_delay_ms(500);
						LCD_GoTo(0,0);
						LCD_WriteString("            ");
						LCD_GoTo(0,0);
						LCD_WriteString("B: ");
						LCD_GoTo(1,0);
						LCD_WriteString("D: ");
						break;
				   case HEX:
				        state=HEX_TO_DEC;
						LCD_GoTo(0,0);
						LCD_WriteString("HEX TO DEC ");
						_delay_ms(500);
						LCD_GoTo(0,0);
						LCD_WriteString("            ");
						LCD_GoTo(0,0);
						LCD_WriteString("H: ");
						LCD_GoTo(1,0);
						LCD_WriteString("D: ");
						break;
				}
			}else if (k=='2')
			{
				switch(FlagType){
					case DEC:
					state=DEC_TO_BIN;
					LCD_GoTo(0,0);
					LCD_WriteString("DEC TO BIN ");
					_delay_ms(500);
					LCD_GoTo(0,0);
					LCD_WriteString("            ");
					LCD_GoTo(0,0);
					LCD_WriteString("D: ");
					LCD_GoTo(1,0);
					LCD_WriteString("B: ");
					break;
					case BIN:
					state=BIN_TO_BIN;
					LCD_GoTo(0,0);
					LCD_WriteString("BIN TO BIN ");
					_delay_ms(500);
					LCD_GoTo(0,0);
					LCD_WriteString("            ");
					LCD_GoTo(0,0);
					LCD_WriteString("B: ");
					LCD_GoTo(1,0);
					LCD_WriteString("B: ");
					break;
					case HEX:
					state=HEX_TO_BIN;
					LCD_GoTo(0,0);
					LCD_WriteString("HEX TO BIN ");
					_delay_ms(500);
					LCD_GoTo(0,0);
					LCD_WriteString("            ");
					LCD_GoTo(0,0);
					LCD_WriteString("H: ");
					LCD_GoTo(1,0);
					LCD_WriteString("B: ");
					break;
				}
				
			}else if (k=='3')
			{
				switch(FlagType){
					case DEC:
					state=DEC_TO_HEX;
					LCD_GoTo(0,0);
					LCD_WriteString("DEC TO HEX ");
					_delay_ms(500);
					LCD_GoTo(0,0);
					LCD_WriteString("            ");
					LCD_GoTo(0,0);
					LCD_WriteString("D: ");
					LCD_GoTo(1,0);
					LCD_WriteString("H: ");
					break;
					case BIN:
					state=BIN_TO_HEX;
					LCD_GoTo(0,0);
					LCD_WriteString("BIN TO HEX ");
					_delay_ms(500);
					LCD_GoTo(0,0);
					LCD_WriteString("            ");
					LCD_GoTo(0,0);
					LCD_WriteString("B: ");
					LCD_GoTo(1,0);
					LCD_WriteString("H: ");
					break;
					case HEX:
					state=HEX_TO_HEX;
					LCD_GoTo(0,0);
					LCD_WriteString("HEX TO HEX ");
					_delay_ms(500);
					LCD_GoTo(0,0);
					LCD_WriteString("            ");
					LCD_GoTo(0,0);
					LCD_WriteString("H: ");
					LCD_GoTo(1,0);
					LCD_WriteString("H: ");
					break;
				}
				
			}
			
		}
		flag_state2=1;   //Not to enter here again
		
	}
		
		
	if (flag_state2==1)
	{
		k=KEYPAD_GetKey();
		if (k!=NO_KEY){
			
			switch(state){
				
			}
			
		
	}
		

	
   }

 }

*/	