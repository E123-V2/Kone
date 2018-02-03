object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 243
  ClientWidth = 472
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 384
    Top = 8
    Width = 80
    Height = 81
    Shape = stCircle
  end
  object Initialisation: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Initialisation'
    TabOrder = 0
    OnClick = InitialisationClick
  end
  object Message: TEdit
    Left = 168
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Quitter: TButton
    Left = 89
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Quitter'
    TabOrder = 2
    OnClick = QuitterClick
  end
  object Etage3: TEdit
    Left = 399
    Top = 158
    Width = 49
    Height = 21
    Enabled = False
    TabOrder = 3
    Text = 'Etage 3'
  end
  object Etage2: TEdit
    Left = 399
    Top = 131
    Width = 49
    Height = 21
    Enabled = False
    TabOrder = 4
    Text = 'Etage 2'
  end
  object Etage1: TEdit
    Left = 399
    Top = 104
    Width = 49
    Height = 21
    Color = clWhite
    Enabled = False
    TabOrder = 5
    Text = 'Etage 1'
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 32
    Top = 184
  end
end
