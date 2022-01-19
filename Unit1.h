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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape3;
        TShape *Shape4;
        TShape *Shape5;
        TShape *Shape6;
        TShape *Shape7;
        TShape *Shape8;
        TShape *Shape9;
        TShape *Shape10;
        TShape *Shape11;
        TShape *Shape12;
        TShape *Shape13;
        TShape *Shape14;
        TShape *Shape15;
        TShape *Shape16;
        TShape *Shape17;
        TShape *Shape18;
        TShape *Shape19;
        TShape *Shape20;
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
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerP1UpTimer(TObject *Sender);
        void __fastcall TimerP1DownTimer(TObject *Sender);
        void __fastcall TimerP2UpTimer(TObject *Sender);
        void __fastcall TimerP2DownTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 