//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x = 8;
int y = 8;
//---------------------------------------------------------------------------
bool collision(TShape *obj)
{
 if((Form1->Ball->Left <= obj->Left + obj->Width) &&
    (Form1->Ball->Left + Form1->Ball->Width >= obj->Left) &&
    (Form1->Ball->Top <= obj->Top + obj->Height) &&
    (Form1->Ball->Top + Form1->Ball->Height >= obj->Top))
 {
  return true;
 }
 else
  return false;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
 Ball->Left += x;
 Ball->Top += y;
 //kolizje ze scianami
 if(Ball->Top <= Panel1->Top + Panel1->Height)
 {
  y = -y;
 }
 if(Ball->Top + Ball->Height >= Form1->Height - 50)
 {
  y = -y;
 }
 // kolizja z paletk¹
 if(collision(P1))
 {
   x = -x;
   y = -y;
 }
 if(collision(P2))
 {
   x = -x;
   y = -y;
 }

}

//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

    if(Key == 'A')
    {
     TimerP1Up->Enabled=true;
    }
    if(Key == 'S')
    {
     TimerP1Down->Enabled= true;
    }
    if(Key == VK_UP)
    {
     TimerP2Up->Enabled=true;
    }
    if(Key == VK_DOWN)
    {
     TimerP2Down->Enabled= true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 'A')
    {
     TimerP1Up->Enabled=false;
    }
    if(Key == 'S')
    {
     TimerP1Down->Enabled= false;
    }
    if(Key == VK_UP)
    {
     TimerP2Up->Enabled=false;
    }
    if(Key == VK_DOWN)
    {
     TimerP2Down->Enabled= false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP1UpTimer(TObject *Sender)
{
  P1->Top -= 10;
  P1Top->Top = P1->Top;
  P1Center->Top = P1Top->Top + P1Top->Height;
  P1Bottom->Top = P1Center->Top + P1Center->Height;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP1DownTimer(TObject *Sender)
{
 P1->Top += 10;
 P1Top->Top = P1->Top;
 P1Center->Top = P1Top->Top + P1Top->Height;
 P1Bottom->Top = P1Center->Top + P1Center->Height;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP2UpTimer(TObject *Sender)
{
 P2->Top -= 10;
 P2Top->Top = P2->Top;
 P2Center->Top = P1Top->Top + P2Top->Height;
 P2Bottom->Top = P2Center->Top + P2Center->Height;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP2DownTimer(TObject *Sender)
{
 P2->Top += 10;
 P2Top->Top = P2->Top;
 P2Center->Top = P2Top->Top + P2Top->Height;
 P2Bottom->Top = P2Center->Top + P2Center->Height;
}
//---------------------------------------------------------------------------

