//---------------------------------------------------------------------------

#ifndef SettingsH
#define SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSettings : public TForm
{
__published:	// IDE-managed Components
    TColorBox *ColorBox1;
    TColorBox *ColorBox2;
    TLabel *LabelGamer1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TButton *Button1;
    TButton *Button2;
    TLabel *Label4;
    TButton *Button3;
    TLabel *Label8;
    TColorBox *ColorBox3;
    TColorBox *ColorBox4;
    TLabel *Label9;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSettings *FormSettings;
//---------------------------------------------------------------------------
#endif
