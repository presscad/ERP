object HLP_FormaElementaSprImageGrp: THLP_FormaElementaSprImageGrp
  Left = 462
  Top = 235
  Caption = #1043#1088#1091#1087#1087#1072' '#1088#1080#1089#1091#1085#1082#1086#1074
  ClientHeight = 256
  ClientWidth = 493
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 20
    Top = 52
    Width = 152
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099':'
  end
  object IdGnDBText: TDBText
    Left = 30
    Top = 10
    Width = 80
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'ID_ART_IMG_GRP'
  end
  object Label2: TLabel
    Left = 10
    Top = 10
    Width = 16
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID:'
  end
  object Label3: TLabel
    Left = 20
    Top = 121
    Width = 36
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'GUID:'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 76
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_ART_IMG_GRP'
    TabOrder = 0
    Width = 458
  end
  object cxButtonOK: TcxButton
    Left = 265
    Top = 202
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 2
  end
  object cxButtonClose: TcxButton
    Left = 364
    Top = 202
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 3
  end
  object GUIDcxDBTextEdit: TcxDBTextEdit
    Left = 9
    Top = 145
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'GUID_ART_IMG_GRP'
    TabOrder = 1
    OnKeyDown = GUIDcxDBTextEditKeyDown
    Width = 458
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 352
    Top = 8
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
