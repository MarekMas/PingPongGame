object Form1: TForm1
  Left = 139
  Top = 44
  Width = 1201
  Height = 700
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'PingPongByMarekM'
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
  object P2: TShape
    Left = 1044
    Top = 280
    Width = 20
    Height = 120
    Brush.Color = clYellow
    Pen.Width = 2
  end
  object P1: TShape
    Left = 121
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
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Brick2: TShape
    Left = 16
    Top = 160
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Brick3: TShape
    Left = 16
    Top = 280
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Brick4: TShape
    Left = 16
    Top = 408
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Brick5: TShape
    Left = 16
    Top = 536
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
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
    Left = 504
    Top = 312
    Width = 25
    Height = 25
    Brush.Color = clYellow
    Pen.Width = 2
    Shape = stCircle
  end
  object Brick6: TShape
    Left = 1144
    Top = 48
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Brick7: TShape
    Left = 1144
    Top = 168
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Brick8: TShape
    Left = 1144
    Top = 288
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Brick9: TShape
    Left = 1144
    Top = 416
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Brick10: TShape
    Left = 1144
    Top = 544
    Width = 25
    Height = 100
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1185
    Height = 33
    Color = clBackground
    TabOrder = 0
  end
  object TimerBall: TTimer
    Interval = 30
    OnTimer = TimerBallTimer
    Left = 496
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
    Left = 496
    Top = 88
  end
end
