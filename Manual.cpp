//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Manual.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormManual *FormManual;
//---------------------------------------------------------------------------
__fastcall TFormManual::TFormManual(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormManual::FormCreate(TObject *Sender)
{
    RichEdit1->Lines->LoadFromFile("help/how_to_play.rtf");    
}
//---------------------------------------------------------------------------

