#include <project.h>
//#include <stdio.h>   /* sprintf() */

uint8 Com_Data;         // data in RX
char InString[128];

char8 ch;       /* Data received from the Serial port */
uint8 count = 0u;
   // uint8 pos = 0u;
char buff[128];			// buffer of RX
	
CY_ISR_PROTO(UART_ISR);
CY_ISR(UART_ISR) 
	{ Com_Data=1; } 

//***********************************************************************//	
uint16  findUntil(char *target, char *terminate)				// from SoftwareSerial.h  (arduino)
{
uint8 targetLen = strlen(target); 								// Длина искомого фрагмента
uint8 index = 0;  												// maximum target string length is 255 bytes
uint8 termIndex = 0;											// позиция 
uint8 termLen = (terminate == NULL ? 0 : strlen(terminate));	// длина признака  конца строки
char c;															// текущий символ
	while( (c = UART_GetChar()) != 0)									// читаем UART    
	{  // это элемент[index] искомой строки?  
      if( c == target[index]){  if(++index >= targetLen){  return 1; }}	// return true если все элементы строки найдены    if all chars in the target match
      else  index = 0;   //..........................    				// не тот фрагмент - обнуляемся 

	  if(termLen > 0 && c == terminate[termIndex]) 						// найден элемент[index] признака конца строки
			{ if(++termIndex >= termLen)  return 2;   }		 			// конц строки найден, искомый фрагмент - нет
      else     termIndex = 0;	 										//не конец строки  - обнуляемся 							
    }
    return 0;	// буфер данных пуст
}
//**********************************************************************

uint16  find(char *target)				 
{
uint8 targetLen = strlen(target); 								// Длина искомого фрагмента
uint8 index = 0;  												// maximum target string length is 255 bytes
//uint8 termIndex = 0;											// позиция 
//uint8 termLen = (terminate == NULL ? 0 : strlen(terminate));	// длина признака  конца строки
char c;															// текущий символ
while( (c = UART_GetChar()) != 0)									// читаем UART    
	{  // это элемент[index] искомой строки?  
      if( c == target[index]){  if(++index >= targetLen){return 1; }}	// return true если все элементы строки найдены    if all chars in the target match
      else  index = 0;   //..........................     				// не тот фрагмент - обнуляемся 
    }
    return 0;	// буфер данных пуст
}

//***********************************************************************
int connectWiFi(char *SSID, char *PASS)
{
char sendString[32];
sprintf(sendString,"AT+CWJAP=\"%s\",\"%s\"\r\n",SSID, PASS);	
UART_PutString("AT+CWMODE=1\r");   	CyDelay(10);
UART_PutString(sendString); 	CyDelay(2000);
if(find("OK\r\n")) return 1;
else return 0;
}

//***********************  отправка  ответа  ******************************************
void http(char *output) 		 
{
 char sendString[32];
 uint16 len=0;
 len=strlen(output)	;	
 sprintf(sendString,"AT+CIPSEND=0,%d\r\n",len);		//  
 UART_PutString(sendString); CyDelay(10);			// Для простоты: вместо ожидания символа '>' просто выдержим паузу
 UART_PutString(output);  
}

//********************  формируем ответ  **********************************************
void webserver(void) {
  static uint16 test;		// счетчик автообновлений странички     // HTML-Шпаргалка:        http://ruseller.com/htmlshpora.php?id=52
  char sendString[1000];	// не менее длины сообщения				// таблица основных тегов http://ru.html.net/tutorials/html/lesson8.php
																	// Основы HTML            http://html-exp.narod.ru/base.htm 
sprintf(sendString,"<title>ESP8266 Webserver</title>"				// HTTP/1.0 200 OK\r\n......??????????????????????????????
	"<meta http-equiv='refresh' content='1' >" 						// To make the page reload or refresh itself (sec)
	"<body bgcolor='FFFFD6'>"										// цвет фона документа
	"<H3>Micro Site Web Server</H3>"								// заголовок
	"<span style='color:#0000FF'>\r\n"								// поменяем цвет текста
	"<p>reloads = %d</p>\r\n",test);								// счетчик автообновлений
	test++;															// 
http(sendString);													// страница готова, отправляем
 CyDelay(100);
UART_PutString("AT+CIPCLOSE=0\r");   	//CyDelay(500);
}





