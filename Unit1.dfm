object Form1: TForm1
  Left = 251
  Top = 31
  Width = 1200
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
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 16
    Top = 32
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape2: TShape
    Left = 16
    Top = 96
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape3: TShape
    Left = 16
    Top = 160
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape4: TShape
    Left = 16
    Top = 224
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape5: TShape
    Left = 16
    Top = 288
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape6: TShape
    Left = 16
    Top = 352
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape7: TShape
    Left = 16
    Top = 416
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape8: TShape
    Left = 16
    Top = 480
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape9: TShape
    Left = 16
    Top = 544
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape10: TShape
    Left = 16
    Top = 608
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape11: TShape
    Left = 1144
    Top = 32
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape12: TShape
    Left = 1144
    Top = 96
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape13: TShape
    Left = 1144
    Top = 160
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape14: TShape
    Left = 1144
    Top = 224
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape15: TShape
    Left = 1144
    Top = 288
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape16: TShape
    Left = 1144
    Top = 352
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape17: TShape
    Left = 1144
    Top = 416
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape18: TShape
    Left = 1144
    Top = 480
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape19: TShape
    Left = 1144
    Top = 544
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object Shape20: TShape
    Left = 1144
    Top = 603
    Width = 25
    Height = 50
    Brush.Color = clRed
    Pen.Width = 2
    Shape = stRoundRect
  end
  object P1Top: TShape
    Left = 125
    Top = 280
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P1Center: TShape
    Left = 125
    Top = 320
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P1Bottom: TShape
    Left = 125
    Top = 360
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P2Top: TShape
    Left = 1048
    Top = 280
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P2Center: TShape
    Left = 1048
    Top = 320
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object P2Bottom: TShape
    Left = 1048
    Top = 360
    Width = 20
    Height = 40
    Brush.Color = clGreen
    Pen.Width = 2
  end
  object Ball: TShape
    Left = 144
    Top = 328
    Width = 25
    Height = 25
    Brush.Color = clYellow
    Pen.Width = 2
    Shape = stCircle
  end
  object Shape21: TShape
    Left = 125
    Top = 280
    Width = 20
    Height = 120
    Pen.Width = 2
    Visible = False
  end
  object Shape22: TShape
    Left = 1048
    Top = 280
    Width = 20
    Height = 120
    Pen.Width = 2
    Visible = False
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
    Left = 376
    Top = 48
  end
end
