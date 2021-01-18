//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainWindow.h"
#include "Settings.h"
#include "AboutProgram.h"
#include "Manual.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
TImage *selectChecker(NULL), *past(NULL), *next(NULL), *check(NULL);
TImage *multiBeat(NULL);
TImage *BoardKeyGo[32], *BoardSquare[32];
bool flag = false;
int keyboard = 0;
int step = 0, index1 = 0, index2 = 0;

//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
    : TForm(Owner)
{
    BoardKeyGo[0] = (TImage*)B8;
    BoardKeyGo[1] = (TImage*)D8;
    BoardKeyGo[2] = (TImage*)F8;
    BoardKeyGo[3] = (TImage*)H8;
    BoardKeyGo[4] = (TImage*)A7;
    BoardKeyGo[5] = (TImage*)C7;
    BoardKeyGo[6] = (TImage*)E7;
    BoardKeyGo[7] = (TImage*)G7;
    BoardKeyGo[8] = (TImage*)B6;
    BoardKeyGo[9] = (TImage*)D6;
    BoardKeyGo[10] = (TImage*)F6;
    BoardKeyGo[11] = (TImage*)H6;
    BoardKeyGo[12] = (TImage*)A5;
    BoardKeyGo[13] = (TImage*)C5;
    BoardKeyGo[14] = (TImage*)E5;
    BoardKeyGo[15] = (TImage*)G5;
    BoardKeyGo[16] = (TImage*)B4;
    BoardKeyGo[17] = (TImage*)D4;
    BoardKeyGo[18] = (TImage*)F4;
    BoardKeyGo[19] = (TImage*)H4;
    BoardKeyGo[20] = (TImage*)A3;
    BoardKeyGo[21] = (TImage*)C3;
    BoardKeyGo[22] = (TImage*)E3;
    BoardKeyGo[23] = (TImage*)G3;
    BoardKeyGo[24] = (TImage*)B2;
    BoardKeyGo[25] = (TImage*)D2;
    BoardKeyGo[26] = (TImage*)F2;
    BoardKeyGo[27] = (TImage*)H2;
    BoardKeyGo[28] = (TImage*)A1;
    BoardKeyGo[29] = (TImage*)C1;
    BoardKeyGo[30] = (TImage*)E1;
    BoardKeyGo[31] = (TImage*)G1;

    BoardSquare[0] = (TImage*)A8;
    BoardSquare[1] = (TImage*)C8;
    BoardSquare[2] = (TImage*)E8;
    BoardSquare[3] = (TImage*)G8;
    BoardSquare[4] = (TImage*)B7;
    BoardSquare[5] = (TImage*)D7;
    BoardSquare[6] = (TImage*)F7;
    BoardSquare[7] = (TImage*)H7;
    BoardSquare[8] = (TImage*)A6;
    BoardSquare[9] = (TImage*)C6;
    BoardSquare[10] = (TImage*)E6;
    BoardSquare[11] = (TImage*)G6;
    BoardSquare[12] = (TImage*)B5;
    BoardSquare[13] = (TImage*)D5;
    BoardSquare[14] = (TImage*)F5;
    BoardSquare[15] = (TImage*)H5;
    BoardSquare[16] = (TImage*)A4;
    BoardSquare[17] = (TImage*)C4;
    BoardSquare[18] = (TImage*)E4;
    BoardSquare[19] = (TImage*)G4;
    BoardSquare[20] = (TImage*)B3;
    BoardSquare[21] = (TImage*)D3;
    BoardSquare[22] = (TImage*)F3;
    BoardSquare[23] = (TImage*)H3;
    BoardSquare[24] = (TImage*)A2;
    BoardSquare[25] = (TImage*)C2;
    BoardSquare[26] = (TImage*)E2;
    BoardSquare[27] = (TImage*)G2;
    BoardSquare[28] = (TImage*)B1;
    BoardSquare[29] = (TImage*)D1;
    BoardSquare[30] = (TImage*)F1;
    BoardSquare[31] = (TImage*)H1;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCreate(TObject *Sender)
{
    //загрузка изображений
    CleanBoard();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::CleanBoard()
{
    int n = 8;
    for(int i = 0; i < 32; i++)
    {
        if(FileExists("textures/SquareMoneyGreen.bmp") != true)
        {
            ShowMessage("Отсутствует изображение основного поля!\ntextures/SquareMoneyGreen.bmp");
            break;
        }
        if(FileExists("textures/SquareWhite.bmp") != true)
        {
            ShowMessage("Отсутствует изображение вторичного поля!\ntextures/SquareWhite.bmp");
            break;
        }
        if(i % 2 == 0 && i < n)
        {
            BoardSquare[i]->Picture->LoadFromFile("textures/SquareWhite.bmp");
            BoardKeyGo[i]->Picture->LoadFromFile("textures/SquareMoneyGreen.bmp");
        }
        else if(i % 2 != 0 && i < n)
        {
            BoardSquare[i]->Picture->LoadFromFile("textures/SquareWhite.bmp");
            BoardKeyGo[i]->Picture->LoadFromFile("textures/SquareMoneyGreen.bmp");
        }
        if(i == 7 || i == 15 || i == 23)
            n += 8;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::CanvasChecker(TObject *Sender, int colorChecker)
{
    if(selectChecker != NULL)
    {
        CancelCanvasEllipse(selectChecker);
    }
    selectChecker = (TImage*)Sender;
    selectChecker->Canvas->Pen->Width = 3;
    selectChecker->Canvas->Pen->Color = clMoneyGreen;
    selectChecker->Canvas->Brush->Style = bsSolid;
    if(colorChecker == 1)
        selectChecker->Canvas->Brush->Color = FormSettings->ColorBox1->Selected;
    else if(colorChecker == 2)
        selectChecker->Canvas->Brush->Color = FormSettings->ColorBox2->Selected;
    else if(colorChecker == 3)
        selectChecker->Canvas->Brush->Color = clMoneyGreen;
    selectChecker->Canvas->Ellipse(4,4,46,46);
    if(flag != true)
        selectChecker = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::CanvasEllipse(TObject *Sender)
{
    selectChecker->Canvas->Pen->Width = 3;
    selectChecker->Canvas->Pen->Color = FormSettings->ColorBox3->Selected;
    if(past != NULL)
    {
        selectChecker->Canvas->Pen->Color = FormSettings->ColorBox4->Selected;
    }
    selectChecker->Canvas->Brush->Style = bsClear;
    selectChecker->Canvas->Ellipse(4,4,46,46);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::CanvasEllipseKing(TObject *Sender)
{
    if(selectChecker != check || flag == true)
    {
    int n = 0;
    for(n = 0; n < 4; n++)
    {
        if(selectChecker == BoardKeyGo[n])
            flag = true;
    }
    for(n = 31; n > 27; n--)
    {
        if(selectChecker == BoardKeyGo[n])
            flag = true;
    }
    if(flag == true)
    {
        TPoint points[7];
        points[0] = Point(15,30);
        points[1] = Point(12,18);
        points[2] = Point(21,24);
        points[3] = Point(25,13);
        points[4] = Point(29,24);
        points[5] = Point(38,18);
        points[6] = Point(35,30);
        selectChecker->Canvas->Pen->Width = 2;
        selectChecker->Canvas->Pen->Color = clOlive;
        selectChecker->Canvas->Brush->Color = clYellow;
        selectChecker->Canvas->Brush->Style = bsSolid;
        selectChecker->Canvas->Polygon(points,6);
        flag = false;
    }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::CancelCanvasEllipse(TObject *Sender)
{
    selectChecker->Canvas->Pen->Width = 3;
    selectChecker->Canvas->Pen->Color = clMoneyGreen;
    selectChecker->Canvas->Brush->Style = bsClear;
    selectChecker->Canvas->Ellipse(4,4,46,46);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::SquareClick(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    if(Button == mbLeft)
    {
        SelectedChecker((TImage*)Sender);
    }
    else if(Button == mbMiddle && selectChecker != NULL && Sender == selectChecker)
    {
        CancelSelectedChecker(selectChecker);
        selectChecker = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::SelectedChecker(TObject *Sender)
{
    if(selectChecker == NULL && keyboard == 0)
    {
        selectChecker = (TImage*)Sender;
        check = selectChecker;
        CanvasEllipse(selectChecker);
        StatusBar1->Panels->Items[1]->Text = "Ход: Игрок №1";
    }
    else if(selectChecker != NULL && keyboard == 0)
    {
        CancelCanvasEllipse(selectChecker);
        MoveMouse((TImage*)Sender);
        selectChecker = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::CancelSelectedChecker(TObject *Sender)
{
    CancelCanvasEllipse(selectChecker);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::MoveMouse(TObject *Sender)
{
    if(selectChecker != NULL && keyboard == 0)
    {
        past = selectChecker;
        next = (TImage*)Sender;
        if(ButtonNote->Enabled == false && past != next && multiBeat != past)
        {
            if(past->Left == next->Left-50 || past->Left == next->Left+50)
                ListBox1->Items->Strings[index1] = IntToStr(index1+1) + "." + past->Name + "-" + next->Name;
            else
                ListBox1->Items->Strings[index1] = IntToStr(index1+1) + "." + past->Name + ":" + next->Name;
            index1 += 1;
        }
        else if(ButtonNote->Enabled == false && past != next && multiBeat == past)
        {
            if(index1-1 > -1)
                ListBox1->Items->Strings[index1-1] = ListBox1->Items->Strings[index1-1] + ":" + next->Name;
        }
        next->Picture->Bitmap->Assign(past->Picture->Bitmap);
        CanvasChecker(past,3);
        multiBeat = next;
        selectChecker = next;
        CanvasEllipseKing(selectChecker);
        past = NULL;
        StatusBar1->Panels->Items[0]->Text = "Партия не сохранена!";
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::MoveKeyboard(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_SHIFT && index1 > 0)
    {
        if(selectChecker != NULL)
        {
            CancelCanvasEllipse(selectChecker);
        }
        selectChecker = BoardKeyGo[0];
        past = NULL;
        multiBeat = NULL;
        CanvasEllipse(selectChecker);
        keyboard = 1;
        step = 0;
        StatusBar1->Panels->Items[0]->Text = "Партия не сохранена!";
        StatusBar1->Panels->Items[1]->Text = "Ход: Игрок №2";
    }
    else if(keyboard == 1 && Key == VK_RETURN && selectChecker != NULL)
    {
        past = selectChecker;
        check = selectChecker;
        CanvasEllipse(selectChecker);
    }
    else if(keyboard == 1 && Key == VK_SPACE && past != NULL)
    {
        next = selectChecker;
        next->Picture->Bitmap->Assign(past->Picture->Bitmap);
        if(ButtonNote->Enabled == false && past != next && multiBeat != past)
        {
            if(past->Left == next->Left-50 || past->Left == next->Left+50)
                ListBox2->Items->Strings[index2] = IntToStr(index2+1) + "." + past->Name + "-" + next->Name;
            else
                ListBox2->Items->Strings[index2] = IntToStr(index2+1) + "." + past->Name + ":" + next->Name;
            index2 += 1;
        }
        else if(ButtonNote->Enabled == false && past != next && multiBeat == past)
        {
            if(index2-1 > -1)
                ListBox2->Items->Strings[index2-1] = ListBox2->Items->Strings[index2-1] + ":" + next->Name;
        }
        CanvasChecker(past,3);
        multiBeat = next;
        selectChecker = next;
        CanvasEllipseKing(selectChecker);
        check = NULL;
        past = NULL;
        CanvasEllipse(selectChecker);
    }
    else if(keyboard == 1 && Key == VK_CONTROL)
    {
        CancelCanvasEllipse(selectChecker);
        selectChecker = NULL;
        multiBeat = NULL;
        keyboard = 0;
        StatusBar1->Panels->Items[1]->Text = "Ход: Игрок №1";
    }
    else if(keyboard == 1)
    {
    if(Key == VK_UP && step > 3)
    {
        if(selectChecker != NULL)
        {
            CancelCanvasEllipse(selectChecker);
        }
        step -= 4;
        selectChecker = BoardKeyGo[step];
        CanvasEllipse(selectChecker);
    }
    else if(Key == VK_DOWN && step < 28)
    {
        if(selectChecker != NULL)
        {
            CancelCanvasEllipse(selectChecker);
        }
        step += 4;
        selectChecker = BoardKeyGo[step];
        CanvasEllipse(selectChecker);
    }
    else if(Key == VK_LEFT && step > 0)
    {
        if(selectChecker != NULL)
        {
            CancelCanvasEllipse(selectChecker);
        }
        step -= 1;
        selectChecker = BoardKeyGo[step];
        CanvasEllipse(selectChecker);
    }
    else if(Key == VK_RIGHT && step < 31)
    {
        if(selectChecker != NULL)
        {
            CancelCanvasEllipse(selectChecker);
        }
        step += 1;
        selectChecker = BoardKeyGo[step];
        CanvasEllipse(selectChecker);
    }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::NoteParty(TObject *Sender)
{
    keyboard = 0;
    StatusBar1->Panels->Items[1]->Text = "Ход:";
    ResetBoard(0);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::NewGameClick(TObject *Sender)
{
    ButtonNote->Enabled = false;
    ResetBoard(0);
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::CleanBoardClick(TObject *Sender)
{
    ButtonNote->Enabled = true;
    keyboard = 0;
    index1 = 0, index2 = 0;
    multiBeat = NULL;
    StatusBar1->Panels->Items[0]->Text = "Партия не сохранена!";
    StatusBar1->Panels->Items[1]->Text = "Ход:";
    for(int i = ListBox1->Items->Count; i > -1; i--)
    {
        ListBox1->Items->Delete(i);
    }
    for(int i = ListBox2->Items->Count; i > -1; i--)
    {
        ListBox2->Items->Delete(i);
    }
    CleanBoard();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ResetBoard(int colorChecker)
{
     keyboard = 0;
     index1 = 0, index2 = 0;
     multiBeat = NULL;
     StatusBar1->Panels->Items[0]->Text = "Партия не сохранена!";
     StatusBar1->Panels->Items[1]->Text = "Ход:";
     for(int i = ListBox1->Items->Count; i > -1; i--)
     {
         ListBox1->Items->Delete(i);
     }
     for(int i = ListBox2->Items->Count; i > -1; i--)
     {
         ListBox2->Items->Delete(i);
     }
     for(int i = 0; i < 8; i++)
     {
          if(FileExists("textures/SquareMoneyGreen.bmp") != true)
          {
              ShowMessage("Отсутствует изображение основного поля!\ntextures/SquareMoneyGreen.bmp");
              break;
          }
          if(FileExists("textures/SquareWhite.bmp") != true)
          {
              ShowMessage("Отсутствует изображение вторичного поля!\ntextures/SquareWhite.bmp");
              break;
          }
          for(int j = 0; j < 4; j++)
          {
               if(i == 0)
                {
                        switch(j)
                        {
                                case 0: CanvasChecker(A1,1); break;
                                case 1: CanvasChecker(C1,1); break;
                                case 2: CanvasChecker(E1,1); break;
                                case 3: CanvasChecker(G1,1); break;
                        }
                }
                else if(i == 1)
                {
                        switch(j)
                        {
                                case 0: CanvasChecker(B2,1); break;
                                case 1: CanvasChecker(D2,1); break;
                                case 2: CanvasChecker(F2,1); break;
                                case 3: CanvasChecker(H2,1); break;
                        }
                }
                else if(i == 2)
                {
                        switch(j)
                        {
                                case 0: CanvasChecker(A3,1); break;
                                case 1: CanvasChecker(C3,1); break;
                                case 2: CanvasChecker(E3,1); break;
                                case 3: CanvasChecker(G3,1); break;
                        }
                }
                else if(i == 3)
                {
                        switch(j)
                        {
                                case 0: CanvasChecker(B4,3); break;
                                case 1: CanvasChecker(D4,3); break;
                                case 2: CanvasChecker(F4,3); break;
                                case 3: CanvasChecker(H4,3); break;
                        }
                }
                else if(i == 4)
                {
                        switch(j)
                        {
                                case 0: CanvasChecker(A5,3); break;
                                case 1: CanvasChecker(C5,3); break;
                                case 2: CanvasChecker(E5,3); break;
                                case 3: CanvasChecker(G5,3); break;
                        }
                }
                else if(i == 5)
                {
                        switch(j)
                        {
                                case 0: CanvasChecker(B6,2); break;
                                case 1: CanvasChecker(D6,2); break;
                                case 2: CanvasChecker(F6,2); break;
                                case 3: CanvasChecker(H6,2); break;
                        }
                }
                else if(i == 6)
                {
                        switch(j)
                        {
                                case 0: CanvasChecker(A7,2); break;
                                case 1: CanvasChecker(C7,2); break;
                                case 2: CanvasChecker(E7,2); break;
                                case 3: CanvasChecker(G7,2); break;
                        }
                }
                else if(i == 7)
                {
                        switch(j)
                        {
                                case 0: CanvasChecker(B8,2); break;
                                case 1: CanvasChecker(D8,2); break;
                                case 2: CanvasChecker(F8,2); break;
                                case 3: CanvasChecker(H8,2); break;
                        }
                }
          }
     }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_SaveGameClick(TObject *Sender)
{
    if(index1 > 0 && index1 - index2 < 2)
    {
    int f; // дескриптор файла
    f = FileCreate("save.txt");

    if(f != -1)
    {
        // сохранить таблицу в файле
        AnsiString st = "";
        st = "Игрок №1   Игрок №2\r\n";
        FileWrite(f,st.c_str(),st.Length());
        for(int i = 0; i < index1; i++)
        {
            if(index1 == index2)
                st = ListBox1->Items->Strings[i] + "     " + ListBox2->Items->Strings[i] + "\r\n";
            else if(index1 > index2)
            {
                if(i == index1 - 1)
                    st = ListBox1->Items->Strings[i] + "\r\n";
                else
                    st = ListBox1->Items->Strings[i] + "     " + ListBox2->Items->Strings[i] + "\r\n";
            }
            FileWrite(f,st.c_str(),st.Length());
        }
        FileClose(f);
        StatusBar1->Panels->Items[0]->Text = "Партия сохранена";
    }
    else
        // ошибка доступа к файлу
        ShowMessage("Ошибка доступа к файлу");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_SettingsClick(TObject *Sender)
{
    FormSettings->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_ManualClick(TObject *Sender)
{
    FormManual->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_AboutProgramClick(TObject *Sender)
{
    FormAboutProgram->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_AddSimple1Click(TObject *Sender)
{
    if(selectChecker != NULL && keyboard == 0)
    {
        CanvasChecker(selectChecker,1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_AddSimple2Click(TObject *Sender)
{
    if(selectChecker != NULL && keyboard == 0)
    {
        CanvasChecker(selectChecker,2);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_AddKing1Click(TObject *Sender)
{
    if(selectChecker != NULL && keyboard == 0)
    {
        flag = true;
        CanvasChecker(selectChecker,1);
        CanvasEllipseKing(selectChecker);
        selectChecker = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_AddKing2Click(TObject *Sender)
{
    if(selectChecker != NULL && keyboard == 0)
    {
        flag = true;
        CanvasChecker(selectChecker,2);
        CanvasEllipseKing(selectChecker);
        selectChecker = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::N_DeleteClick(TObject *Sender)
{
    if(selectChecker != NULL && keyboard == 0)
        CanvasChecker(selectChecker,3);
    selectChecker = NULL;
    multiBeat = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonDeleteClick(TObject *Sender)
{
    if(index1 > index2 && index1 > 0)
    {
        ListBox1->Items->Delete(index1-1);
        index1 -= 1;
    }
    else if(index2 == index1 && index2 > 0)
    {
        ListBox2->Items->Delete(index2-1);
        index2 -= 1;
    }
    multiBeat = NULL;
    ButtonDelete->Enabled = false;
    ButtonDelete->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonNoteClick(TObject *Sender)
{
    ButtonNote->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ListBox1Click(TObject *Sender)
{
    ListBox1->Enabled = false;
    ListBox1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ListBox2Click(TObject *Sender)
{
    ListBox2->Enabled = false;
    ListBox2->Enabled = true;
}
//---------------------------------------------------------------------------

