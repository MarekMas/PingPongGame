//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TShape *Brick1;
        TShape *Brick2;
        TShape *Brick3;
        TShape *Brick4;
        TShape *Brick5;
        TShape *P1Top;
        TShape *P1Center;
        TShape *P1Bottom;
        TShape *P2Top;
        TShape *P2Center;
        TShape *P2Bottom;
        TShape *Ball;
        TTimer *TimerBall;
        TShape *P1;
        TShape *P2;
        TTimer *TimerP2Up;
        TTimer *TimerP2Down;
        TTimer *TimerP1Up;
        TTimer *TimerP1Down;
        TTimer *TimerBlinding;
        TShape *Brick6;
        TShape *Brick7;
        TShape *Brick8;
        TShape *Brick9;
        TShape *Brick10;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TShape *WinWindow;
        TStaticText *StaticText1;
        TButton *Button1;
        TButton *Button2;

        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerP1UpTimer(TObject *Sender);
        void __fastcall TimerP1DownTimer(TObject *Sender);
        void __fastcall TimerP2UpTimer(TObject *Sender);
        void __fastcall TimerP2DownTimer(TObject *Sender);
        void __fastcall TimerBlindingTimer(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 