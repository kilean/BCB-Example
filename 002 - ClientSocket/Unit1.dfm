object Form1: TForm1
  Left = 207
  Top = 127
  Width = 275
  Height = 388
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 10
    Height = 13
    Caption = 'IP'
  end
  object Label2: TLabel
    Left = 16
    Top = 40
    Width = 19
    Height = 13
    Caption = 'Port'
  end
  object Edit1: TEdit
    Left = 40
    Top = 13
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '127.0.0.1'
  end
  object Edit2: TEdit
    Left = 40
    Top = 38
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '18888'
  end
  object Button1: TButton
    Left = 168
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Connect'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 168
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Disconnect'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 168
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Test'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 128
    Width = 233
    Height = 209
    ScrollBars = ssBoth
    TabOrder = 5
  end
  object Edit3: TEdit
    Left = 8
    Top = 72
    Width = 233
    Height = 21
    TabOrder = 6
    Text = 'Test'
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 24
    Top = 144
  end
end
