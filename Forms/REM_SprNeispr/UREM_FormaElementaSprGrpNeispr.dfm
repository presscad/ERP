object REM_FormaElementaSprGrpNeispr: TREM_FormaElementaSprGrpNeispr
  Left = 462
  Top = 235
  Caption = #1043#1088#1091#1087#1087#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 211
  ClientWidth = 485
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 20
  object Label1: TLabel
    Left = 23
    Top = 38
    Width = 173
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099':'
  end
  object IdGnDBText: TDBText
    Left = 30
    Top = 10
    Width = 81
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'ID_REM_SGRPNEISPR'
    DataSource = REM_DMSprGrpNeispr.DataSourceElement
  end
  object Label2: TLabel
    Left = 10
    Top = 10
    Width = 21
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID:'
  end
  object Label3: TLabel
    Left = 23
    Top = 102
    Width = 239
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099' (English):'
  end
  object cxButtonOK: TcxButton
    Left = 269
    Top = 170
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 370
    Top = 170
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 1
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 23
    Top = 66
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SGRPNEISPR'
    DataBinding.DataSource = REM_DMSprGrpNeispr.DataSourceElement
    TabOrder = 2
    Width = 441
  end
  object NameEngcxDBTextEdit: TcxDBTextEdit
    Left = 23
    Top = 122
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_ENG_REM_SGRPNEISPR'
    DataBinding.DataSource = REM_DMSprGrpNeispr.DataSourceElement
    TabOrder = 3
    Width = 441
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
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
