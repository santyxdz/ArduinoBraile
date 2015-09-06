#include <stdio.h>
#include <math.h>
#include <LiquidCrystal.h>
#define sw1 PINC,0
#define PORTA,0

LiquidCrystal lcd(48,49,45,44,43,42);

void setup(){
  DDRL = B01111111;
  DDRA = B;
  pinMode(47,OUTPUT);
  digitalWrite(47,0);
  lcd.begin(16,2);
}

void loop(){
  
  lcd.setCursor(0,0);
  
  if(bitRead(PINC,0)==HIGH&&bitRead(PINC,1)==HIGH){
    bitSet(PORTA,0);
  }else{
    bitClear(PORTA,0);
  }
  bin_dec()
  lcd.print("A Dos: ");
  lcd.print(255-var+1);
}

int dec_bin(int num){
    int rem, i=1, binary=0;
    while (num!=0)
    {
        rem=num%2;
        num/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}

int bin_dec(int num){
    int decimal=0, i=0, rem;
    while (num!=0)
    {
        rem = num%10;
        num/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}
char toBraile(int num){
    switch (num){
    case 000001:
        return 'a';
    case 000011:
        return 'b';
    case 001001:
        return 'c';
    case 011001:
        return 'd';
    case 010001:
        return 'e';
    case 001011:
        return 'f';
    case 011011:
        return 'g';
    case 010011:
        return 'h';
    case 001010:
        return 'i';
    case 011010:
        return 'j';
    case 000101:
        return 'k';
    case 000111:
        return 'l';
    case 001101:
        return 'm';
    case 011101:
        return 'n';
    case 010101:
        return 'o';
    case 001111:
        return 'p';
    case 011111:
        return 'q';
    case 010111:
        return 'r';
    case 001110:
        return 's';
    case 011110:
        return 't';
    case 100101:
        return 'u';
    case 100111:
        return 'v';
    case 101101:
        return 'x';
    case 111101:
        return 'y';
    case 110101:
        return 'z';
    case 110111:
        return 'á';
    case 101110:
        return 'é';
    case 001100:
        return 'í';
    case 101100:
        return 'ó';
    case 111110:
        return 'ú';
    case 110011:
        return 'ü';
    case 111011:
        return 'ñ';
    case 111010:
        return 'w';
    case 101111:
        return '&';
    case 000100:
        return '.';
    case 111100:
        return "#";//Prefijo numerico
    case 101000:
        return 'A';
    case 000010:
        return ',';
    case 100010:
        return '¿';
    case 000110:
        return ';';
    case 010110:
        return '¡';
    case 100110:
        return '"';
    case 011100:
        return '(';
    case 011100:
        return ')';
    case 100100:
        return '-';
    case 010100:
        return '*';
    default:
        return 0;
        
    }
    return 0;
}
char toBraileNum(int num){
  switch (num){
    case 000001:
        return '1';
    case 000011:
        return '2';
    case 001001:
        return '3';
    case 011001:
        return '4';
    case 010001:
        return '5';
    case 001011:
        return '6';
    case 011011:
        return '7';
    case 010011:
        return '8';
    case 001010:
        return '9';
    case 011010:
        return '0';
    default: 
        return 0;
}


int main(int argc, char const *argv[])
{
	int braile;
	scanf ("%i",braile);
	printf ("%c \n",toBraile(braile));
	return 0;
}
