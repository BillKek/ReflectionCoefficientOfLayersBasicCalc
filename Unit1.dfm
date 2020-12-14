object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 
    'reflection coefficient calc inspired by y: GetAClass  yyjj7g3Pfy' +
    'w 20201214'
  ClientHeight = 149
  ClientWidth = 797
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  DesignSize = (
    797
    149)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 19
    Width = 28
    Height = 13
    Caption = 'refl_p'
  end
  object Label2: TLabel
    Left = 16
    Top = 59
    Width = 39
    Height = 13
    Caption = 'N layers'
  end
  object Label3: TLabel
    Left = 16
    Top = 91
    Width = 73
    Height = 13
    Caption = 'max reflections'
  end
  object Edit1: TEdit
    Left = 64
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '0.1'
  end
  object Button1: TButton
    Left = 16
    Top = 116
    Width = 75
    Height = 25
    Caption = 'calc'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 216
    Top = 16
    Width = 545
    Height = 113
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object CSpinEdit1: TCSpinEdit
    Left = 120
    Top = 88
    Width = 65
    Height = 22
    Increment = 2
    MaxValue = 7
    MinValue = 3
    TabOrder = 3
    Value = 7
  end
  object CheckBox1: TCheckBox
    Left = 104
    Top = 120
    Width = 97
    Height = 17
    Caption = 'fast/nonbrute'
    Checked = True
    State = cbChecked
    TabOrder = 4
  end
  object CSpinEdit2: TCSpinEdit
    Left = 84
    Top = 53
    Width = 97
    Height = 22
    MaxValue = 40000
    MinValue = 3
    TabOrder = 5
    Value = 50
  end
end
