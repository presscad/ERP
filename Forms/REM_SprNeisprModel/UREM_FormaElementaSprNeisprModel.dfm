object REM_FormaElementaSprNeisprModel: TREM_FormaElementaSprNeisprModel
  Left = 645
  Top = 0
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1080' '#1084#1086#1076#1077#1083#1077#1081'"'
  ClientHeight = 342
  ClientWidth = 593
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 20
  object Label1: TLabel
    Left = 17
    Top = 47
    Width = 117
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label3: TLabel
    Left = 9
    Top = 144
    Width = 318
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087#1086#1074#1072#1103' '#1085#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' ('#1080#1079' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072'):'
  end
  object Label2: TLabel
    Left = 35
    Top = 111
    Width = 78
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077':'
  end
  object Label4: TLabel
    Left = 55
    Top = 209
    Width = 251
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1052#1086#1076#1077#1083#1100' '#1072#1085#1072#1083#1086#1075' ('#1085#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1080'):'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 142
    Top = 44
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SNEISPMODEL'
    TabOrder = 0
    Width = 408
  end
  object cxButtonOK: TcxButton
    Left = 323
    Top = 284
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonClose: TcxButton
    Left = 439
    Top = 284
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 2
  end
  object NameNeisprcxDBButtonEdit: TcxDBButtonEdit
    Left = 141
    Top = 166
    DataBinding.DataField = 'NAME_REM_SNEISPR'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameNomcxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 409
  end
  object cxButtonDefect: TcxButton
    Left = 200
    Top = 284
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1077#1092#1077#1082#1090#1099
    TabOrder = 4
    OnClick = cxButtonDefectClick
  end
  object DescrcxDBTextEdit: TcxDBTextEdit
    Left = 141
    Top = 108
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DESCR_REM_SNEISPMODEL'
    TabOrder = 5
    Width = 408
  end
  object NameModelNeisprcxDBButtonEdit: TcxDBButtonEdit
    Left = 53
    Top = 236
    DataBinding.DataField = 'NAME_REM_SMODEL'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameModelNeisprcxDBButtonEditPropertiesButtonClick
    TabOrder = 6
    Width = 497
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 240
    Top = 32
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
