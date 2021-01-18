//---------------------------------------------------------------------------

#ifndef ManualH
#define ManualH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormManual : public TForm
{
__published:	// IDE-managed Components
    TRichEdit *RichEdit1;
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormManual(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormManual *FormManual;
//---------------------------------------------------------------------------
#endif
