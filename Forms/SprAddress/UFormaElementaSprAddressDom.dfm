object FormaElementaSprAddressDom: TFormaElementaSprAddressDom
  Left = 482
  Top = 263
  Caption = #1044#1086#1084
  ClientHeight = 370
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 18
    Top = 233
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 190
    Top = 9
    Width = 27
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
  end
  object DBTextID_SADR_REGION: TDBText
    Left = 225
    Top = 9
    Width = 200
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'ID_SADR_REGION'
  end
  object DBTextCODE_SADR_REGION: TDBText
    Left = 225
    Top = 38
    Width = 200
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'CODE_SADR_REGION'
  end
  object DBTextNAME_SADR_REGION: TDBText
    Left = 225
    Top = 67
    Width = 200
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'NAME_SADR_REGION'
  end
  object DBTextNAME_SADR_RAYON: TDBText
    Left = 225
    Top = 96
    Width = 200
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'NAME_SADR_RAYON'
  end
  object DBTextNAME_SADR_NASPUNKT: TDBText
    Left = 209
    Top = 125
    Width = 200
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'NAME_SADR_NASPUNKT'
  end
  object DBTextPOSTCODE_SADR_STREET: TDBText
    Left = 209
    Top = 165
    Width = 200
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'POSTCODE_SADR_STREET'
  end
  object DBTextNAME_SADR_STREET: TDBText
    Left = 209
    Top = 205
    Width = 200
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'NAME_SADR_STREET'
  end
  object cxButtonOK: TcxButton
    Left = 241
    Top = 314
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonClose: TcxButton
    Left = 340
    Top = 314
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 2
  end
  object cxDBTextEditNAME_SADR_DOM: TcxDBTextEdit
    Left = 280
    Top = 252
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SADR_DOM'
    TabOrder = 0
    Width = 129
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 80
    Top = 24
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
