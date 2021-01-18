//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainWindow.cpp", FormMain);
USEFORM("AboutProgram.cpp", FormAboutProgram);
USEFORM("Manual.cpp", FormManual);
USEFORM("Settings.cpp", FormSettings);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TFormMain), &FormMain);
         Application->CreateForm(__classid(TFormAboutProgram), &FormAboutProgram);
         Application->CreateForm(__classid(TFormManual), &FormManual);
         Application->CreateForm(__classid(TFormSettings), &FormSettings);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
             Application->ShowException(&exception);
         }
    }
    return 0;
}
//---------------------------------------------------------------------------
