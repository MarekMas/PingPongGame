//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include "mmsystem.h"
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x = 0;
int y = 0;
int basicSpeed = 20;
int turboSpeed = 30;
int angle = 4;
int speed = basicSpeed;
int speedP1 = 10, speedP2 = 10;
int wait = 0;
int blindingCount = 1;
int pointsP1 = 0, pointsP2 = 0;
bool serverP1 = true, serverP2 = false;
bool P1PressTurbo = false, P2PressTurbo = false;
bool swapBallColor = false;
bool startGame = false;
bool computerPlayer = false;
int ballYOnP2Line = 340;
int randomValue = 0;
//---------------------------------------------------------------------------
void restartGame()
{
  startGame = true;
  speed = basicSpeed;
  ballYOnP2Line = 340;
  wait = 0;

  Form1->Brick1->Visible = false;
  Form1->Brick2->Visible = false;
  Form1->Brick3->Visible = false;
  Form1->Brick4->Visible = false;
  Form1->Brick5->Visible = false;
  Form1->Brick6->Visible = false;
  Form1->Brick7->Visible = false;
  Form1->Brick8->Visible = false;
  Form1->Brick9->Visible = false;
  Form1->Brick10->Visible = false;
  Form1->P2Top->Visible = true;
  Form1->P2Center->Visible = true;
  Form1->P2Bottom->Visible = true;
  Form1->P1Top->Visible = true;
  Form1->P1Center->Visible = true;
  Form1->P1Bottom->Visible = true;

  pointsP1 = 0;
  pointsP2 = 0;
  Form1->P1->Top = 280;
  Form1->P1Top->Top = Form1->P1->Top;
  Form1->P1Center->Top = Form1->P1Top->Top + Form1->P1Top->Height;
  Form1->P1Bottom->Top = Form1->P1Center->Top + Form1->P1Center->Height;

  Form1->P2->Top = 280;
  Form1->P2Top->Top = Form1->P2->Top;
  Form1->P2Center->Top = Form1->P2Top->Top + Form1->P2Top->Height;
  Form1->P2Bottom->Top = Form1->P2Center->Top + Form1->P2Center->Height;

  if(serverP1)
  {
   Form1->Ball->Left = Form1->P1->Left + Form1->P1->Width;
   Form1->Ball->Top = Form1->P1->Top + Form1->P1->Height/2 - Form1->Ball->Height/2;
  }
  if(serverP2)
  {
   Form1->Ball->Left = Form1->P2->Left - Form1->Ball->Width;
   Form1->Ball->Top = Form1->P2->Top + Form1->P2->Height/2 - Form1->Ball->Height/2;
  }

  Form1->Ball->Visible = true;
  Form1->Label3->Caption = IntToStr(pointsP1) + "  :  " + IntToStr(pointsP2);
}
//---------------------------------------------------------------------------
int getRandomIntiger(int scope)
{
 randomize();
 return  random(scope)+1;
}
//---------------------------------------------------------------------------
int findBallPositionOnP2Line() //oblicz srodek wysokosci pilki gdy znajdzie sie na linii paletki P2
{
 int yEndPosition = 0;
 int YStartPosition = Form1->Ball->Top +  Form1->Ball->Height/2;
 if(x == 0) return 380;
 int numberOfXMovment = (Form1->P2->Left - Form1->Ball->Width - (Form1->P1->Left + Form1->P1->Width))/x;
 int distanseOfY = y * numberOfXMovment;
 yEndPosition = YStartPosition + distanseOfY;


 if(yEndPosition - Form1->Ball->Height/2 <= Form1->Panel1->Top + Form1->Panel1->Height)

 {
  yEndPosition = 2*(Form1->Panel1->Top + Form1->Panel1->Height + Form1->Ball->Height/2) - yEndPosition;

 }
 if(yEndPosition + Form1->Ball->Height/2 >= Form1->Height - 50)
 {
  yEndPosition = 2*(Form1->Height - 50  - Form1->Ball->Height/2) - yEndPosition;
 }
 return yEndPosition;
}
//---------------------------------------------------------------------------

void showWinBox(AnsiString winner)
{
  Form1->StaticText1->Caption = winner + "  WON";
  Form1->WinWindow->Visible = true;
  Form1->StaticText1->Visible = true;
  Form1->Button1->Visible = true;
  Form1->Button2->Visible = true;
  Form1->Button3->Visible = true;
  sndPlaySound("snd/win.wav",SND_ASYNC);
  Form1->Ball->Visible = false;

  startGame = false;
}
//---------------------------------------------------------------------------

void showLevelBox()
{
  Form1->StaticText1->Caption = "Computer Level";
  Form1->WinWindow->Visible = true;
  Form1->StaticText1->Visible = true;
  Form1->Button4->Visible = true;
  Form1->Button5->Visible = true;
  Form1->Button6->Visible = true;
  Form1->Ball->Visible = false;

  startGame = false;
}
//---------------------------------------------------------------------------
void hideBox()
{
  Form1->WinWindow->Visible = false;
  Form1->StaticText1->Visible = false;
  Form1->Button1->Visible = false;
  Form1->Button2->Visible = false;
  Form1->Button3->Visible = false;
  Form1->Button4->Visible = false;
  Form1->Button5->Visible = false;
  Form1->Button6->Visible = false;

}
void changeX()
{
 double outcome, speedD = speed , yD = y;
 if(speed > y) outcome = sqrt(pow(speedD,2.0) - pow(yD,2.0));
 if(x > 0)                      x = - outcome;
 else                           x = outcome;
 if (serverP1)                  x = outcome;
 if (serverP2)                  x = -outcome;
}
//---------------------------------------------------------------------------
bool collision(TShape *obj)
{
 if((Form1->Ball->Left <= obj->Left + obj->Width) &&
    (Form1->Ball->Left + Form1->Ball->Width >= obj->Left) &&
    (Form1->Ball->Top + Form1->Ball->Height/2 <= obj->Top + obj->Height) &&
    (Form1->Ball->Top + Form1->Ball->Height/2 >= obj->Top))
 {

 speed = basicSpeed;
 sndPlaySound("snd/ballpickup.wav",SND_ASYNC);

  return true;
 }
 else
  return false;
}
//---------------------------------------------------------------------------
void showNewBrick(int paddleNumber)
{
 if(paddleNumber == 1)
 {
  if(Form1->Brick1->Visible == false) Form1->Brick1->Visible = true;
  else if(Form1->Brick5->Visible == false) Form1->Brick5->Visible = true;
  else if(Form1->Brick2->Visible == false) Form1->Brick2->Visible = true;
  else if(Form1->Brick4->Visible == false) Form1->Brick4->Visible = true;
  else if(Form1->Brick3->Visible == false) Form1->Brick3->Visible = true;
 }
if(paddleNumber == 2)
 {
  if(Form1->Brick6->Visible == false) Form1->Brick6->Visible = true;
  else if(Form1->Brick10->Visible == false) Form1->Brick10->Visible = true;
  else if(Form1->Brick7->Visible == false) Form1->Brick7->Visible = true;
  else if(Form1->Brick9->Visible == false) Form1->Brick9->Visible = true;
  else if(Form1->Brick8->Visible == false) Form1->Brick8->Visible = true;
 }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
 if(wait > 0) wait --;

 if(startGame)
 {
  Ball->Left += x;
  Ball->Top += y;
 }
 //kolizje ze scianami
 if(Ball->Top <= Panel1->Top + Panel1->Height && y<0)        y = -y;
 if(Ball->Top + Ball->Height >= Form1->Height - 50 && y>0)   y = -y;

 // kolizja z paletk¹ P1
 if(collision(P1) && wait == 0)
 {
    if(P1PressTurbo)
    {
     speed = turboSpeed;
     sndPlaySound("snd/turbopickup.wav",SND_ASYNC);
    }
    else
    {
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

    if(TimerP1Up->Enabled)             y -= angle + angle/2;
    else if(TimerP1Down->Enabled)      y += angle + angle/2;
    else if(y > 0)                     y = angle + angle/2;
    else if(y < 0)                     y = -angle + angle/2;

   wait = 25;

   if(y>(3*angle)) y -= angle;
   if(y<(3*-angle)) y += angle;
   changeX();
   ballYOnP2Line = findBallPositionOnP2Line();
 }
  // kolizja z paletk¹ P2
 if(collision(P2) && wait == 0)
 {
    randomValue = getRandomIntiger(3);

    if(P2PressTurbo || (computerPlayer == true && randomValue == 2))
    {
     speed = turboSpeed;
     sndPlaySound("snd/turbopickup.wav",SND_ASYNC);
    }
    else
    {
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
    randomValue = getRandomIntiger(4);
    if(TimerP2Up->Enabled || randomValue == 1)          y -= angle + angle/2;
    else if(TimerP2Down->Enabled || randomValue == 2)   y += angle + angle/2;
    else if(y > 0 || randomValue == 3)                  y = angle + angle/2;
    else if(y < 0 || randomValue == 4)                  y = -angle + angle/2;


   wait = 25;

   if(y>(3*angle)) y -= angle;
   if(y<(3*-angle)) y += angle;
   changeX();
 }
 //przegrana P1
 if(Ball->Left < P1->Left - 120)
 {
  TimerBall->Enabled = false;
  serverP1 = true;
  pointsP2++;
  Ball->Left = P1->Left + P1->Width;
  Ball->Top = P1->Top + P1->Height/2 - Ball->Height/2;
  Ball->Brush->Color = clYellow;
  Label3->Caption = IntToStr(pointsP1) + "  :  " + IntToStr(pointsP2);
  sndPlaySound("snd/getpoints.wav",SND_ASYNC);
  }
  //przegrana P2
 if(Ball->Left > P2->Left + 120)
 {
  TimerBall->Enabled = false;
  serverP2 = true;
  pointsP1++;
  Ball->Left = P2->Left - Ball->Width;
  Ball->Top = P2->Top + P2->Height/2 - Ball->Height/2;
  Ball->Brush->Color = clYellow;
  Label3->Caption = IntToStr(pointsP1) + "  :  " + IntToStr(pointsP2);
  sndPlaySound("snd/getpoints.wav",SND_ASYNC);
 }
 //wygrana P1
 if(pointsP1 == 2)
 {
    showWinBox("Player 1");
 }
 //wygrana P2
 if(pointsP2 == 2)
 {
    if(computerPlayer)   showWinBox("Computer");
    else                 showWinBox("Player 2");
 }
 // kolizja z ceglami
 if(collision(Brick1) && Brick1->Visible)
 {
   x = -x;
   Brick1->Visible = false;
 }

 if(collision(Brick2) && Brick2->Visible)
 {
   x = -x;
   Brick2->Visible = false;
 }

 if(collision(Brick3) && Brick3->Visible)
 {
   x = -x;
   Brick3->Visible = false;
 }

 if(collision(Brick4) && Brick4->Visible)
 {
   x = -x;
   Brick4->Visible = false;
 }

 if(collision(Brick5) && Brick5->Visible)
 {
   x = -x;
   Brick5->Visible = false;
 }

 if(collision(Brick6) && Brick6->Visible)
 {
   x = -x;
   Brick6->Visible = false;
 }

 if(collision(Brick7) && Brick7->Visible)
 {
   x = -x;
   Brick7->Visible = false;
 }

 if(collision(Brick8) && Brick8->Visible)
 {
   x = -x;
   Brick8->Visible = false;
 }

 if(collision(Brick9) && Brick9->Visible)
 {
   x = -x;
   Brick9->Visible = false;
 }

 if(collision(Brick10) && Brick10->Visible)
 {
   x = -x;
   Brick10->Visible = false;
 }
}

//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if(startGame)
 {
    if(Key == 'A')
    {
     TimerP1Up->Enabled = true;
    }
    if(Key == 'Z')
    {
     TimerP1Down->Enabled = true;
    }
    if(Key == VK_UP && computerPlayer == false)
    {
     TimerP2Up->Enabled=true;
    }
    if(Key == VK_DOWN && !computerPlayer)
    {
     TimerP2Down->Enabled = true;
    }
    if(Key == 'X')
     {
      if(serverP1 == true)
      {
       speed = basicSpeed;
       if(TimerP1Up->Enabled)               y = -angle;
       else if(TimerP1Down->Enabled)        y = angle;
       else                                 y = 0;
       changeX();
       TimerBall->Enabled = true;
       serverP1 = false;
       ballYOnP2Line = findBallPositionOnP2Line();
      }
      else
      {
       P1->Brush->Color = clRed;
       P1->BringToFront();
       P1PressTurbo = true;
      }

     }

    if(Key == VK_LEFT && !computerPlayer)
     {
      if(serverP2 == true)
      {
       if(TimerP2Up->Enabled)               y = -angle;
       else if(TimerP2Down->Enabled)        y = angle;
       else                                 y = 0;
       changeX();
       TimerBall->Enabled = true;
       serverP2 = false;
      }
      else
      {
       P2->Brush->Color = clRed;
       P2->BringToFront();
       P2PressTurbo = true;
      }
     }
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
    if(Key == VK_UP && !computerPlayer)
    {
     TimerP2Up->Enabled = false;
    }
    if(Key == VK_DOWN&& !computerPlayer)
    {
     TimerP2Down->Enabled = false;
    }
    if(Key == 'X')
    {
     P1->Brush->Color = clYellow;
     P1->SendToBack();
     P1PressTurbo = false;
    }
    if(Key == VK_LEFT && !computerPlayer)
    {
     P2->Brush->Color = clYellow;
     P2->SendToBack();
     P2PressTurbo = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP1UpTimer(TObject *Sender)
{

 if(P1->Top >= Panel1->Top + Panel1->Height)
 {
  P1->Top -= 10;
  P1Top->Top = P1->Top;
  P1Center->Top = P1Top->Top + P1Top->Height;
  P1Bottom->Top = P1Center->Top + P1Center->Height;
 }
 if(serverP1)
 {
  Ball->Left = P1->Left + P1->Width;
  Ball->Top = P1->Top + P1->Height/2 - Ball->Height/2;
  P1Top->Top = P1->Top;
  P1Center->Top = P1Top->Top + P1Top->Height;
  P1Bottom->Top = P1Center->Top + P1Center->Height;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP1DownTimer(TObject *Sender)
{

 if(P1->Top + P1->Height <= Form1->Height -50)
 {
  P1->Top += speedP1;
  P1Top->Top = P1->Top;
  P1Center->Top = P1Top->Top + P1Top->Height;
  P1Bottom->Top = P1Center->Top + P1Center->Height;
 }
 if(serverP1)
 {
  Ball->Left = P1->Left + P1->Width;
  Ball->Top = P1->Top + P1->Height/2 - Ball->Height/2;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP2UpTimer(TObject *Sender)
{

 if(P2->Top >= Panel1->Top + Panel1->Height)
 {
  P2->Top -= speedP2;
  P2Top->Top = P2->Top;
  P2Center->Top = P2Top->Top + P2Top->Height;
  P2Bottom->Top = P2Center->Top + P2Center->Height;
 }
 if(serverP2)
 {
  Ball->Left = P2->Left - Ball->Width;
  Ball->Top = P2->Top + P2->Height/2 - Ball->Height/2;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerP2DownTimer(TObject *Sender)
{

 if(P2->Top + P2->Height <= Form1->Height -50)
 {
  P2->Top += speedP2;
  P2Top->Top = P2->Top;
  P2Center->Top = P2Top->Top + P2Top->Height;
  P2Bottom->Top = P2Center->Top + P2Center->Height;
 }
  if(serverP2)
 {
  Ball->Left = P2->Left - Ball->Width;
  Ball->Top = P2->Top + P2->Height/2 - Ball->Height/2;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBlindingTimer(TObject *Sender)
{
 if(P1Top->Visible == false && P1Center->Visible == false && P1Bottom->Visible == false)
 {
    if(blindingCount == 1)
    {
     showNewBrick(1);
     sndPlaySound("snd/newbrick.wav",SND_ASYNC);
    }
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
    if(blindingCount == 1)
    {
     showNewBrick(2);
     sndPlaySound("snd/newbrick.wav",SND_ASYNC);
    }
    if (blindingCount%2 == 0) P2->Brush->Color = clYellow;
    else                      P2->Brush->Color = clGreen;
    blindingCount ++;
    if(blindingCount == 13)
    {
     blindingCount = 1;
     P2Top->Visible = true;
     P2Center->Visible = true;
     P2Bottom->Visible = true;
    }
 }
 if(speed == turboSpeed)
 {
   if(swapBallColor)
   {
    Ball->Brush->Color = clRed;
    swapBallColor = false;
   }
   else
   {
    Ball->Brush->Color = clYellow;
    swapBallColor = true;
   }
 }
 else
 {
  Ball->Brush->Color = clYellow;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
 hideBox();
 computerPlayer = true;
 Label2->Caption = "Computer";
 showLevelBox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 hideBox();
 computerPlayer = false;
 Label2->Caption = "Player 2";
 speedP2 = 10;
 basicSpeed =20;
 turboSpeed =30;
 angle = 4;
 TimerP2Up->Enabled = false;
 TimerP2Down->Enabled = false;
 restartGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 speedP2 = 5;
 basicSpeed =15;
 turboSpeed =20;
 angle = 3;
 hideBox();
 restartGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 speedP2 = 8;
 basicSpeed =20;
 turboSpeed =30;
  angle = 4;
 hideBox();
 restartGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 speedP2 = 12;
 basicSpeed =25;
 turboSpeed =38;
 angle = 5;
 hideBox();
 restartGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AITimerTimer(TObject *Sender)
{
     if(startGame && computerPlayer)
     {
      if(serverP2 == true)
      {
       speed = basicSpeed;
       Application->ProcessMessages();       Sleep(1000);
       randomValue = getRandomIntiger(3);
       switch(randomValue)
       {
       case 1:
             y = -angle;
       break;
       case 2:
            y =  angle;
       break;
       case 3:
            y = 0;
       break;
       }
       changeX();
       TimerBall->Enabled = true;
       serverP2 = false;
       ballYOnP2Line = (Form1->Height -50 + Panel1->Height)/2;
      }

      if(ballYOnP2Line > P2->Top + P2->Height *2/3)
      {
         TimerP2Up->Enabled = false;
         TimerP2Down->Enabled = true;
      }
      else if(ballYOnP2Line < P2->Top + P2->Height/3)
      {
         TimerP2Up->Enabled = true;
         TimerP2Down->Enabled = false;
      }
      else
      {
         TimerP2Up->Enabled = false;
         TimerP2Down->Enabled = false;
      }
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 ShowMessage("Sterowanie paletk¹: Gracz1  A,S; Gracz 2 Strza³ki góra,dó³. Serwowanie/Mocne uderzenie: Gracz 1 klawisz X; Gracz 2 strza³ka w lewo. Aby zmieni k¹t odbicia pi³ki trzeba miec wcisniety kawisz ruchu w trakcie odbicia. Powodzenia :)");
}
//---------------------------------------------------------------------------

