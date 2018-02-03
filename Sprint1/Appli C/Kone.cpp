//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Kone.h"
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
void __fastcall TForm1::InitialisationClick(TObject *Sender)
{
	hcomm=CreateFile("COM1",GENERIC_WRITE|GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_FLAG_OVERLAPPED,NULL);

	if (hcomm==INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,"Impossible d'ouvrir le port COM1", "ATTENTION",MB_ICONSTOP);

		Shape1->Brush->Color=clRed;
	}
	else
	{
		GetCommState(hcomm,&serie);
		serie.BaudRate = 9600;
		serie.ByteSize =8;
		serie.Parity = NOPARITY;
		serie.StopBits = ONESTOPBIT;
		SetCommState(hcomm,&serie);

		Timer1->Enabled=true;

		Shape1->Brush->Color=clLime;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::QuitterClick(TObject *Sender)
{
	CloseHandle(hcomm);

	Timer1->Enabled=false;

	Shape1->Brush->Color=clWhite;
	Etage1->Color=clWhite;
	Etage2->Color=clWhite;
	Etage3->Color=clWhite;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	int taille=2;
	char *chaine ;
	unsigned long pt;

	pt=0;
	chaine=new char[taille+1];
	chaine[0]='\0';

	Message->Text="";
	over.Internal=0;
	over.InternalHigh=0;
	over.Offset=0;
	over.OffsetHigh=0;
	over.Pointer=NULL;
	over.hEvent=NULL;

	ReadFile(hcomm,chaine, taille,&pt, &over);
	PurgeComm(hcomm,PURGE_RXCLEAR);


	if(chaine[1]=='1'){
		Message->Text="Etage 1";
		Etage1->Color=clLime;
		Etage2->Color=clWhite;
		Etage3->Color=clWhite;
	}
	else{
		if(chaine[1]=='2'){
			Message->Text="Etage 2";
			Etage2->Color=clLime;
			Etage1->Color=clWhite;
			Etage3->Color=clWhite;
		}
		else{
			if(chaine[1]=='3'){
				Message->Text="Etage 3";
				Etage3->Color=clLime;
				Etage1->Color=clWhite;
				Etage2->Color=clWhite;
			}
		}
	}
	delete chaine;
}
//---------------------------------------------------------------------------

