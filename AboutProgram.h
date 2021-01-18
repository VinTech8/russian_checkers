//---------------------------------------------------------------------------

#ifndef AboutProgramH
#define AboutProgramH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormAboutProgram : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
    TImage *Image1;
private:	// User declarations
public:		// User declarations
        __fastcall TFormAboutProgram(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAboutProgram *FormAboutProgram;
//---------------------------------------------------------------------------
#endif
