object FormaElementaSprAddressNasPunkt: TFormaElementaSprAddressNasPunkt
  Left = 482
  Top = 263
  Caption = #1056#1072#1081#1086#1085
  ClientHeight = 346
  ClientWidth = 466
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
    Left = 10
    Top = 161
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
  object cxButtonOK: TcxButton
    Left = 233
    Top = 242
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
    Left = 332
    Top = 242
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 2
  end
  object cxDBTextEditNAME_SADR_NASPUNKT: TcxDBTextEdit
    Left = 10
    Top = 188
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SADR_NASPUNKT'
    TabOrder = 0
    Width = 415
  end
  object cxDBCheckBoxFL_GOROD_SADR_NASPUNKT: TcxDBCheckBox
    Left = 8
    Top = 130
    Caption = #1075#1086#1088#1086#1076
    DataBinding.DataField = 'FL_GOROD_SADR_NASPUNKT'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 3
    Width = 121
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
