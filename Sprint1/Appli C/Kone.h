//---------------------------------------------------------------------------

#ifndef KoneH
#define KoneH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *Initialisation;
	TEdit *Message;
	TButton *Quitter;
	TShape *Shape1;
	TEdit *Etage3;
	TEdit *Etage2;
	TEdit *Etage1;
	TTimer *Timer1;
	void __fastcall InitialisationClick(TObject *Sender);
	void __fastcall QuitterClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// Déclarations utilisateur
public:		// Déclarations utilisateur
	HANDLE hcomm;
	DCB serie;
	OVERLAPPED over;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
