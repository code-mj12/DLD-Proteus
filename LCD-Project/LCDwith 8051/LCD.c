
#include<reg51.h>

//Function declarations
void cct_init(void);
void delay(int);
void lcdinit(void);
void writecmd(int);
void writedata(char);
void ReturnHome(void);

//*******************
//Pin description
/*
P2 is data bus
P1.0 is RS
P1.1 is E
*/
//********************

// Defines Pins
sbit RS = P1^0;
sbit E  = P1^1;

// ***********************************************************
// Main program
//
void main(void)
{
   cct_init();                                     //Make all ports zero

   lcdinit();                                      //Initilize LCD

   writecmd(0x81);
   writedata('A');                                 //write
   writedata('l');                                 //write
   writedata('I');                                 //write
   writedata(' ');                                 //write
   writedata(' ');                                 //write
   writedata(' ');                                 //write
   writedata('S');                                 //write
   writedata('U');                                 //write
   writedata('B');                                 //write
   writedata('H');                                 //write
   writedata('A');                                 //write
   writedata('N');                                 //write
   writedata(' ');
	
   writecmd(0xc0);

   writedata('M');                                 //write
   writedata('A');                                 //write
   writedata('J');                                 //write
   writedata('I');                                 //write
   writedata('D');                                 //write
   writedata(' ');                                 //write
   writedata('A');                                 //write
   writedata('H');                                 //write
   writedata('M');                                 //write
   writedata('A');                                 //write
   writedata('D');                                 //write
   writedata(' ');                                 //write

   ReturnHome();                                   //Return to 0 position

	while(1)
	{
	}

}


void cct_init(void)
{
P0 = 0x00;   //not used 
P1 = 0x00;   //not used 
P2 = 0x00;   //used as data port
P3 = 0x00;   //used for generating E and RS
}

void delay(int a)
{
   int i;
   for(i=0;i<a;i++);   //null statement
}

void writedata(char t)
{
   RS = 1;             // => RS = 1
   P2 = t;             //Data transfer
   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}


void writecmd(int z)
{
   RS = 0;             // => RS = 0
   P2 = z;             //Data transfer
   E  = 1;             // => E = 1
   delay(150);
   E  = 0;             // => E = 0
   delay(150);
}

void lcdinit(void)
{
  ///////////// Reset process from datasheet /////////
     delay(15000);
   writecmd(0x30);
     delay(4500);
   writecmd(0x30);
     delay(300);
   writecmd(0x30);
     delay(650);
  /////////////////////////////////////////////////////
   writecmd(0x38);    //function set
   writecmd(0x0c);    //display on,cursor off,blink off
   writecmd(0x01);    //clear display
   writecmd(0x06);    //entry mode, set increment
   
}

void ReturnHome(void)     //Return to 0 location
{
  writecmd(0x02);
    delay(1500);
}