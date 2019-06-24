object FormaElementaSprProducerEd: TFormaElementaSprProducerEd
  Left = 645
  Top = 0
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1045#1076#1080#1085#1080#1094#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099' ('#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072')"'
  ClientHeight = 357
  ClientWidth = 614
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
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 30
    Top = 114
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 432
    Top = 18
    Width = 96
    Height = 80
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1087#1077#1088#1077#1089#1095#1077#1090#1072' '#1074' '#1073#1072#1079#1086#1074#1091#1102' '#1077#1076#1080#1085#1080#1094#1091' ('#1091#1084#1085#1086#1078#1077#1085#1080#1077#1084'):'
    WordWrap = True
  end
  object Label3: TLabel
    Left = 63
    Top = 181
    Width = 70
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1064#1090#1088#1080#1093'-'#1082#1086#1076':'
  end
  object Label6: TLabel
    Left = 204
    Top = 41
    Width = 27
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
  end
  object cxButtonOK: TcxButton
    Left = 367
    Top = 287
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 466
    Top = 287
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    Cancel = True
    TabOrder = 5
  end
  object NameEdcxDBTextEdit: TcxDBTextEdit
    Left = 167
    Top = 111
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SPRED'
    TabOrder = 1
    OnKeyDown = NameEdcxDBTextEditKeyDown
    Width = 228
  end
  object KFEdcxDBCalcEdit: TcxDBCalcEdit
    Left = 430
    Top = 81
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'KF_SPRED'
    Properties.AssignedValues.DisplayFormat = True
    Properties.Precision = 15
    TabOrder = 3
    OnKeyDown = KFEdcxDBCalcEditKeyDown
    Width = 142
  end
  object SHcxDBTextEdit: TcxDBTextEdit
    Left = 170
    Top = 174
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'BARCODE_SPRED'
    TabOrder = 2
    OnKeyDown = SHcxDBTextEditKeyDown
    Width = 227
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 245
    Top = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODE_SPRED'
    TabOrder = 0
    OnKeyDown = CodecxDBTextEditKeyDown
    Width = 149
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 40
    Top = 26
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
