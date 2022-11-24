//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
byte Mayor(Cardinal n){      // n =1234 de entrada
byte s;
if(n < 10){ //caso base
	s = n;  //tienes los numeros 1, 2, 3, 4, 5, 6, 7, 8, 9 "un digito"
}else{      //caso general
	byte otro = n % 10;  //aqui en la ultima iteracion quedo en 12
	s = Mayor(n / 10); //
	if (s > otro)  // s = 1 y otro = 2  en la primera comparacion
		s = s;
	else
		s = otro;
}
return s;     //la salida
}
byte sumaPar(Cardinal n){
byte s;
if(n < 10){
	if(n % 2 == 0){
		s = n;
	}else
		s = 0;
}else{
	s = sumaPar(n / 10);
	byte u = n % 10;
	if (u % 2 == 0){
	s = s + u;
	}
}
return s;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Edit2->Text = sumaPar(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
