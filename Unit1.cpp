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
int wait = 0;
int blindingCount = 1;
TShape *p = NULL;
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
 if(wait > 0) wait --;

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
 if(collision(P1) && wait == 0)
 {
  if((Ball->Top + Ball->Height/2 >= P1->Top) &&
     (Ball->Top + Ball->Height/2 <= P1->Top + P1->Height))
   {
    x = -x;
    if(Ball->Top + Ball->Height/2 <= P1->Top + P1->Height/3)
    {
     P1Top->Visible = false;
    }
    if((Ball->Top + Ball->Height/2 > P1->Top + P1->Height/3) &&
       (Ball->Top + Ball->Height/2 < P1->Top + P1->Height * 2 / 3))
    {
     P1Center->Visible = false;
    }

    if((Ball->Top + Ball->Height/2) >= (P1->Top + P1->Height * 2 / 3) )
    {
     P1Bottom->Visible = false;
    }

   }
   else
   {
    y= -y;
   }
   wait = 50;

 }
 if(collision(P2) && wait == 0)
 {
  if((Ball->Top + Ball->Height/2 > P2->Top) &&
     (Ball->Top + Ball->Height/2 < P2->Top + P2->Height))
   {
    x = -x;
    if(Ball->Top + Ball->Height/2 <= P2->Top + P2->Height/3)
    {
     P2Top->Visible = false;
    }
    if((Ball->Top + Ball->Height/2 > P2->Top + P2->Height/3) &&
       (Ball->Top + Ball->Height/2 < P2->Top + P2->Height * 2 / 3))
    {
     P2Center->Visible = false;
    }

    if((Ball->Top + Ball->Height/2) >= (P2->Top + P2->Height * 2 / 3) )
    {
     P2Bottom->Visible = false;
    }
   }
   else
   {
    y= -y;
   }
   wait = 50;
 }
 
}

//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

    if(Key == 'A')
    {
     TimerP1Up->Enabled = true;
    }
    if(Key == 'Z')
    {
     TimerP1Down->Enabled = true;
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
    if(Key == 'Z')
    {
     TimerP1Down->Enabled = false;
    }
    if(Key == VK_UP)
    {
     TimerP2Up->Enabled = false;
    }
    if(Key == VK_DOWN)
    {
     TimerP2Down->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP1UpTimer(TObject *Sender)
{
 if(P1->Top + P1->Height >= Panel1->Top + Panel1->Height + 40)
 {
  P1->Top -= 10;
  P1Top->Top = P1->Top;
  P1Center->Top = P1Top->Top + P1Top->Height;
  P1Bottom->Top = P1Center->Top + P1Center->Height;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP1DownTimer(TObject *Sender)
{
 if(P1->Top <= Form1->Height -80)
 {
  P1->Top += 10;
  P1Top->Top = P1->Top;
  P1Center->Top = P1Top->Top + P1Top->Height;
  P1Bottom->Top = P1Center->Top + P1Center->Height;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP2UpTimer(TObject *Sender)
{
 if(P2->Top + P2->Height >= Panel1->Top + Panel1->Height + 40)
 {
  P2->Top -= 10;
  P2Top->Top = P2->Top;
  P2Center->Top = P2Top->Top + P2Top->Height;
  P2Bottom->Top = P2Center->Top + P2Center->Height;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP2DownTimer(TObject *Sender)
{
 if(P2->Top <= Form1->Height -80)
 {
  P2->Top += 10;
  P2Top->Top = P2->Top;
  P2Center->Top = P2Top->Top + P2Top->Height;
  P2Bottom->Top = P2Center->Top + P2Center->Height;
 }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::TimerBlindingTimer(TObject *Sender)
{
 if(P1Top->Visible == false && P1Center->Visible == false && P1Bottom->Visible == false)
 {

    if (blindingCount%2 == 0) P1->Brush->Color = clYellow;
    else                      P1->Brush->Color = clRed;
    blindingCount ++;
    if(blindingCount == 13)
    {
     blindingCount = 1;
     P1Top->Visible = true;
     P1Center->Visible = true;
     P1Bottom->Visible = true;
    }
 }

 if(P2Top->Visible == false && P2Center->Visible == false && P2Bottom->Visible == false)
 {

    if (blindingCount%2 == 0) P2->Brush->Color = clYellow;
    else                      P2->Brush->Color = clRed;
    blindingCount ++;
    if(blindingCount == 13)
    {
     blindingCount = 1;
     P2Top->Visible = true;
     P2Center->Visible = true;
     P2Bottom->Visible = true;
    }
 }
}
//---------------------------------------------------------------------------


