//*****************************************************************************/
//	PROJECT:	WIFI_Web_Server
// 	FILE NAME: 	main.c
// 	IDEAS:		Micro WebServer จาก ESP8266 และ Arduino		http://www.ayarafun.com/2014/09/micro-webserver-from-esp8266-and-arduino/
//  
//__________________________________________________________________________________________________________________________________________________
//  Pavlov Evgeniy            Pavlov_en@yahoo.com         	http://mylab.wmsite.ru/moi-razrab/cypress-psoc/
//
// 	DESCRIPTION:  
//	  
//  DEVICES:
//  1. ESP8266 Serial WIFI Wireless TransceiveR Module     	http://www.ebay.com/sch/i.html?_from=R40&_trksid=p4712.m570.l1313.TR0.TRC0.H0.XESP8266&_nkw=ESP8266&_sacat=0 
//  2. CY8CKIT - 030 PSoC3     ( CY8C3866AXI-040  ) 		http://www.cypress.com/?rID=49524
//
//	programms:
//	ESP8266-Config    										https://www.facebook.com/appstack.in.th
//  Hercules SETUP utility by hw-group.com   				http://www.hw-group.com/products/hercules/index_en.html#download
//
//  info:
//	ESP8266 WiFi Module   									http://playground.boxtec.ch/doku.php/wireless/esp8266
//	Forum													http://www.esp8266.com/
//  updating 												http://blog.electrodragon.com/cloud-updating-your-wi07c-esp8266-now/
//***********************************************************************************************************************

#include <device.h>
#include <stdio.h>   				/* sprintf() */
#include "Data_and_Func.h"

#define SSID "carlson" 				// your SSID
#define PASS "scottelise" 			// your password

int i=0;
//------------------

int main()
{ 
int connected=0;	
isr_UART_StartEx(UART_ISR);							// availability flag buffer data RX
CyGlobalIntEnable; 									/* Enable all interrupts by the processor. */
UART_Start();  LCD_Char_Start(); 
 //................................
LCD_Char_Position(0,0);
//UART_PutString("ATE0\r\n");   	CyDelay(1);		//disable echo ( in the new firmware )
UART_PutString("AT+RST\r\n");  	CyDelay(2000);		// Reset and check: whether the module is ready
if (find("ready"))
	{ LCD_Char_PrintString("DEVICE: OK");     }
else{ LCD_Char_PrintString("NO DEVICE!!");}
  // ----------------------try to connect to wifi-----------------------------------------
CyDelay(1000);
   for(i=0;i<5;i++){
		if(connectWiFi(SSID, PASS))
     	{	connected= 1;
      	LCD_Char_Position(0,0); LCD_Char_PrintString("Connected to WiFi...");
      	break;}
   }//................

CyDelay(100);  UART_PutString("AT+CIPMUX=1\r\n"); 		// 
CyDelay(1000); UART_PutString("AT+CIPSERVER=1,80\r\n"); // set the server of port 80  

CyDelay(1000);  UART_PutString("AT+CIFSR\r\n"); 		// Obtain an IP
UART_ClearRxBuffer(); 
CyDelay(5); 											// 
if (find("CIFSR\r\r\n"))
{
 count=0;
	while(Com_Data)
	{
	  ch=UART_ReadRxData();					// deducted symbol
	  buff[count]= ch;	count++;			// add to clipboard
	  Com_Data = UART_GetRxBufferSize();  	// Reset the trigger
	}
}
LCD_Char_Position(1 ,0  );  LCD_Char_PrintString("IP: ");	// derive IP on display
LCD_Char_PrintString(buff);  								

CyDelay(1000);
//-------------------------------------------------------------------------
 while(1)
 {											 
	while(Com_Data)			//We are waiting for client request .....
	{
		ch=UART_ReadRxData();		// deducted symbol
		if (ch == 'G') {			// too lazy to do check on "Get" - as the primary source in wait for the arrival of the symbol 'G'
   			CyDelay(100);			// We wait for the end of the package
			webserver();			// We send a response

    	}
	Com_Data = UART_GetRxBufferSize();  //
	}
 }
}



















// while(1)
// {																			//  AT+CIPSTART="TCP","188.226.224.148",80;\r\n
//		// test_Write(Com_Data); CyDelay(100);
//	 while(Com_Data)
//	//if(Com_Data)
//	{
//		CyDelay(100);
//		 ch=UART_ReadRxData();	// вычитываем символ
//		if (ch == 'G') {			// лень делать проверку  findUntil("Get", "OK\r\n") 
//	 	//if (find("GE")){
//			
//			//CyDelay(100);
//			//UART_ClearRxBuffer(); 	
//			webserver();
//    	 	 CyDelay(500);
//    	}
//	//UART_ClearRxBuffer();  //
//	//Com_Data=0;
//	}
// }
//}







////UART_PutString("AT+CIPSTART=\"TCP\",\"188.226.224.148\",80;\r\n"); 		// 184.106.153.149   AT+CIPSTART="TCP","184.106.153.149",80;\r\n   
//UART_PutString("AT+CIPSTART=\"TCP\",\"192.168.0.37\",8001;\r\n");		// AT+CIPSTART="TCP","192.168.0.37",8001;\r\n
//	CyDelay(1000);	
//UART_PutString("AT+CIPSEND=5\r\n");CyDelay(1);	
//UART_PutString("12345\r\n");
//	CyDelay(5000);	
	




	
//if(c) 	// Indicates that data byte is received.
// {
//
//if (findUntil("+IPD,", "OK\r\n"))	
//	{
////CyDelay(50);		
//UART_PutString("AT+CIPSEND=\r"); //5,12345\r\n
//	}	
//
//	while(Com_Data)
//{
//	ch=UART_ReadRxData();	// вычитываем символ
//	buff[count]= ch;	count++;	// добавляем в буфер
//	Com_Data = UART_GetRxBufferSize();  //
//}
//LCD_Char_Position(0 ,0  );  LCD_Char_PrintString(buff);
//memset(buff,'\0',128);  count=0;	
//
//
//
//CyDelay(200);
// 
// }




//UART_PutString("AT+CWMODE=3\r\n"); 
//CyDelay(100);
//UART_PutString("AT+CIPMUX=1\r\n"); 
//CyDelay(100);
//UART_PutString("AT+CWSAP=\"myhome\",\"44448888\",11,3\r\n"); 
//CyDelay(100);
//UART_PutString("AT+CIPSERVER=1,8002\r\n"); 
//CyDelay(3500);
//UART_PutString("AT+CIPMUX=0\r\n"); 
//CyDelay(100);
	
	//UART_PutString("AT+CWMODE?\r\n");


//
//
//
//Com_Data = UART_GetRxBufferSize();
//
//while(Com_Data)
//{
//	ch=UART_ReadRxData();				// вычитываем символ
//	buff[count]= ch;	count++;		// добавляем в буфер
//	Com_Data = UART_GetRxBufferSize();  // Reset the trigger
//}
//LCD_Char_Position(0 ,0  );  LCD_Char_PrintString(buff);
//memset(buff,'\0',128);  count=0;
////...............
//UART_PutString("AT+CIPSERVER=1,8002\r\n"); 
//CyDelay(10);
//findUntil("no ", "OK\r\n");	
//Com_Data = UART_GetRxBufferSize();
//
//while(Com_Data)
//{
//	ch=UART_ReadRxData();				// вычитываем символ
//	buff[count]= ch;	count++;		// добавляем в буфер
//	Com_Data = UART_GetRxBufferSize();  // 
//}
//LCD_Char_Position(1 ,0  );  LCD_Char_PrintString(buff);
//memset(buff,'\0',128);  count=0;	
//	




//    while(1)
//    {
//        /* Check the UART status */
//        ch = UART_GetChar();
//
//        /* If byte received */
//        if(ch > 0)
//        {
//            count++;        
//            /* If the count value reaches the count 16 start from first location */
//            if(count % 16 == 0u) 
//            {
//                pos = 0u; /* resets the count value */
//                /* Display will be cleared when reached count value 16 */
//                LCD_Char_WriteControl(LCD_Char_CLEAR_DISPLAY); 
//            }
//
//            LCD_Char_Position(0u, pos++);
//            LCD_Char_PutChar(ch);         /* Print the received character */
//
//            LCD_Char_Position(1u, 0u);
//            LCD_Char_PrintInt8(count);    /* Prints the count in the LCD */
//        }
//    
//	CyDelay(50);
//	}



/* [] END OF FILE */
