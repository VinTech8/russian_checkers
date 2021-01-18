//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
    TImage *A8;
    TImage *B8;
    TImage *C8;
    TImage *D8;
    TImage *E8;
    TImage *F8;
    TImage *G8;
    TImage *H8;
    TImage *A7;
    TImage *B7;
    TImage *C7;
    TImage *D7;
    TImage *E7;
    TImage *F7;
    TImage *G7;
    TImage *H7;
    TImage *A6;
    TImage *B6;
    TImage *C6;
    TImage *D6;
    TImage *E6;
    TImage *F6;
    TImage *G6;
    TImage *H6;
    TImage *A5;
    TImage *B5;
    TImage *C5;
    TImage *D5;
    TImage *E5;
    TImage *F5;
    TImage *G5;
    TImage *H5;
    TImage *A4;
    TImage *B4;
    TImage *C4;
    TImage *D4;
    TImage *E4;
    TImage *F4;
    TImage *G4;
    TImage *H4;
    TImage *A3;
    TImage *B3;
    TImage *C3;
    TImage *D3;
    TImage *E3;
    TImage *F3;
    TImage *G3;
    TImage *H3;
    TImage *A2;
    TImage *B2;
    TImage *C2;
    TImage *D2;
    TImage *E2;
    TImage *F2;
    TImage *G2;
    TImage *H2;
    TImage *A1;
    TImage *B1;
    TImage *C1;
    TImage *D1;
    TImage *E1;
    TImage *F1;
    TImage *G1;
    TImage *H1;
        TMainMenu *MainMenu1;
    TMenuItem *N_Game;
    TMenuItem *N_Settings;
    TMenuItem *N_Help;
        TMenuItem *N4;
    TMenuItem *N_SaveGame;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N_Manual;
        TMenuItem *N10;
        TMenuItem *N_AboutProgram;
    TStatusBar *StatusBar1;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TPanel *Panel4;
    TPanel *Panel5;
    TPanel *Panel6;
    TPanel *Panel7;
    TPanel *Panel8;
    TPanel *Panel9;
    TPanel *Panel10;
    TPanel *Panel11;
    TPanel *Panel12;
    TPanel *Panel13;
    TPanel *Panel14;
    TPanel *Panel15;
    TPanel *Panel16;
    TPanel *Panel17;
    TLabel *LabelGamer1;
    TPopupMenu *PopupMenu1;
    TMenuItem *N1;
    TMenuItem *N_Delete;
    TMenuItem *N11;
    TMenuItem *N_AddSimple1;
    TMenuItem *N_AddSimple2;
    TListBox *ListBox1;
    TLabel *Label1;
    TLabel *Label2;
    TMenuItem *N2;
    TMenuItem *N12;
    TMenuItem *N21;
    TMenuItem *N3;
    TListBox *ListBox2;
    TButton *ButtonNote;
    TButton *ButtonDelete;
    TSaveDialog *SaveDialog1;
    void __fastcall NewGameClick(TObject *Sender);
    void __fastcall CleanBoardClick(TObject *Sender);
    void __fastcall SquareClick(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall SelectedChecker(TObject *Sender);
    void __fastcall CancelSelectedChecker(TObject *Sender);
    void __fastcall N_ManualClick(TObject *Sender);
    void __fastcall N_AboutProgramClick(TObject *Sender);
    void __fastcall ExitClick(TObject *Sender);
    void __fastcall MoveKeyboard(TObject *Sender, WORD &Key,
      TShiftState Shift);
    void __fastcall N_SettingsClick(TObject *Sender);
    void __fastcall N_AddSimple1Click(TObject *Sender);
    void __fastcall N_AddSimple2Click(TObject *Sender);
    void __fastcall N_AddKing1Click(TObject *Sender);
    void __fastcall N_AddKing2Click(TObject *Sender);
    void __fastcall N_DeleteClick(TObject *Sender);
    void __fastcall N_SaveGameClick(TObject *Sender);
    void __fastcall ButtonDeleteClick(TObject *Sender);
    void __fastcall ButtonNoteClick(TObject *Sender);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall ListBox2Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormMain(TComponent* Owner);
    void __fastcall CleanBoard();
    void __fastcall ResetBoard(int colorChecker);
    void __fastcall CanvasBoard(TObject *Sender, int colorSquare);
    void __fastcall CanvasChecker(TObject *Sender, int colorChecker);
    void __fastcall CanvasEllipse(TObject *Sender);
    void __fastcall CanvasEllipseKing(TObject *Sender);
    void __fastcall CancelCanvasEllipse(TObject *Sender);
    void __fastcall MoveMouse(TObject *Sender);
    void __fastcall NoteParty(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
