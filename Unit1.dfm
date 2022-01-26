object Form1: TForm1
  Left = 240
  Top = 64
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  Caption = 'PingPongByMarekM'
  ClientHeight = 642
  ClientWidth = 1180
  Color = clSkyBlue
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object P1: TShape
    Left = 121
    Top = 280
    Width = 20
    Height = 120
    Brush.Color = clYellow
    Pen.Width = 2
  end
  object P2: TShape
    Left = 1044
    Top = 280
    Width = 20
    Height = 120
    Brush.Color = clYellow
    Pen.Width = 2
  end
  object Brick1: TShape
    Left = 16
    Top = 40
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object Brick2: TShape
    Left = 16
    Top = 160
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object Brick3: TShape
    Left = 16
    Top = 280
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object Brick4: TShape
    Left = 16
    Top = 408
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object Brick5: TShape
    Left = 16
    Top = 536
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object P1Top: TShape
    Left = 121
    Top = 280
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P1Center: TShape
    Left = 121
    Top = 320
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P1Bottom: TShape
    Left = 121
    Top = 360
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P2Top: TShape
    Left = 1044
    Top = 280
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P2Center: TShape
    Left = 1044
    Top = 320
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P2Bottom: TShape
    Left = 1044
    Top = 360
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object Ball: TShape
    Left = 140
    Top = 328
    Width = 25
    Height = 25
    Brush.Color = clYellow
    Pen.Width = 2
    Shape = stCircle
  end
  object Brick6: TShape
    Left = 1144
    Top = 40
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object Brick7: TShape
    Left = 1144
    Top = 160
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object Brick8: TShape
    Left = 1144
    Top = 280
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object Brick9: TShape
    Left = 1144
    Top = 408
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object Brick10: TShape
    Left = 1144
    Top = 536
    Width = 25
    Height = 100
    Brush.Color = clGreen
    Pen.Width = 2
    Shape = stRoundRect
    Visible = False
  end
  object WinWindow: TShape
    Left = 376
    Top = 224
    Width = 425
    Height = 177
    Brush.Color = clBlack
    Pen.Color = clMaroon
    Pen.Width = 3
    Shape = stRoundRect
    Visible = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1185
    Height = 33
    Color = clBackground
    TabOrder = 0
    object Label1: TLabel
      Left = 104
      Top = 5
      Width = 77
      Height = 27
      Alignment = taCenter
      Caption = 'Player 1'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clYellow
      Font.Height = -19
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 1016
      Top = 5
      Width = 77
      Height = 27
      Alignment = taCenter
      Caption = 'Player 2'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clYellow
      Font.Height = -19
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 560
      Top = 5
      Width = 64
      Height = 27
      Alignment = taCenter
      Caption = '0  :  0'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clYellow
      Font.Height = -19
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object StaticText1: TStaticText
    Left = 376
    Top = 248
    Width = 425
    Height = 48
    Alignment = taCenter
    AutoSize = False
    BiDiMode = bdLeftToRight
    Caption = 'StaticText1'
    Color = clMaroon
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clYellow
    Font.Height = -31
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentColor = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 1
    Visible = False
  end
  object Button1: TButton
    Left = 416
    Top = 312
    Width = 129
    Height = 65
    Cursor = crHandPoint
    Caption = 'New Game'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    Visible = False
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 632
    Top = 312
    Width = 129
    Height = 65
    Cursor = crHandPoint
    Caption = 'Quit'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    Visible = False
    OnClick = Button2Click
  end
  object TimerBall: TTimer
    Enabled = False
    Interval = 20
    OnTimer = TimerBallTimer
    Left = 576
    Top = 48
  end
  object TimerP2Up: TTimer
    Enabled = False
    Interval = 20
    OnTimer = TimerP2UpTimer
    Left = 1040
    Top = 56
  end
  object TimerP2Down: TTimer
    Enabled = False
    Interval = 20
    OnTimer = TimerP2DownTimer
    Left = 1040
    Top = 96
  end
  object TimerP1Up: TTimer
    Enabled = False
    Interval = 20
    OnTimer = TimerP1UpTimer
    Left = 128
    Top = 56
  end
  object TimerP1Down: TTimer
    Enabled = False
    Interval = 20
    OnTimer = TimerP1DownTimer
    Left = 128
    Top = 96
  end
  object TimerBlinding: TTimer
    Interval = 100
    OnTimer = TimerBlindingTimer
    Left = 576
    Top = 88
  end
  object TimerAI: TTimer
    Interval = 20
    OnTimer = TimerAITimer
    Left = 976
    Top = 80
  end
end
