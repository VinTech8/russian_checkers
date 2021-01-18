//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSettings *FormSettings;
TColor a,b,c,d;
//---------------------------------------------------------------------------
__fastcall TFormSettings::TFormSettings(TComponent* Owner)
    : TForm(Owner)
{
    a = ColorBox1->Selected;
    b = ColorBox2->Selected;
    c = ColorBox3->Selected;
    d = ColorBox4->Selected;
}
//---------------------------------------------------------------------------
void __fastcall TFormSettings::Button1Click(TObject *Sender)
{
    ShowMessage("»зменени€ вступ€т в силу при создании новой игры!");
    a = ColorBox1->Selected;
    b = ColorBox2->Selected;
    c = ColorBox3->Selected;
    d = ColorBox4->Selected;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormSettings::Button2Click(TObject *Sender)
{
    Close();
    ColorBox1->Selected = a;
    ColorBox2->Selected = b;
    ColorBox3->Selected = c;
    ColorBox4->Selected = d;
}
//---------------------------------------------------------------------------

void __fastcall TFormSettings::Button3Click(TObject *Sender)
{
    ColorBox1->Selected = clCream;
    ColorBox2->Selected = clBlack;
    ColorBox3->Selected = clAqua;
    ColorBox4->Selected = clRed;
}
//---------------------------------------------------------------------------
      
