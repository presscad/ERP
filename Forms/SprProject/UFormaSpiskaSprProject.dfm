object FormaSpiskaSprProject: TFormaSpiskaSprProject
  Left = 337
  Top = 195
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1055#1088#1086#1077#1082#1090#1099'"'
  ClientHeight = 549
  ClientWidth = 787
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 787
    Height = 73
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object LabelNameGrp: TLabel
      Left = 296
      Top = 56
      Width = 58
      Height = 16
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object HintLabel: TLabel
      Left = 8
      Top = 28
      Width = 44
      Height = 16
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 969
      Height = 26
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNewGrp: TToolButton
        Left = 8
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonNewGrp'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewGrpClick
      end
      object ToolButtonEdiGrp: TToolButton
        Left = 31
        Top = 0
        Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonEdiGrp'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEdiGrpClick
      end
      object ToolButtonDeleteGrp: TToolButton
        Left = 54
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonDeleteGrp'
        ImageIndex = 2
        OnClick = ToolButtonDeleteGrpClick
      end
      object ToolButton2: TToolButton
        Left = 77
        Top = 0
        Width = 84
        Caption = 'ToolButton2'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 161
        Top = 0
        Width = 118
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 279
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1077#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 302
        Top = 0
        Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 325
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButtonUpdate: TToolButton
        Left = 348
        Top = 0
        Caption = 'ToolButtonUpdate'
        ImageIndex = 48
        OnClick = ToolButtonUpdateClick
      end
      object ToolButton4: TToolButton
        Left = 371
        Top = 0
        Width = 35
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonAll: TToolButton
        Left = 406
        Top = 0
        Hint = #1054#1090#1082#1083#1102#1095#1080#1090#1100' '#1080#1077#1088#1072#1088#1093#1080#1102' '#1087#1086' '#1075#1088#1091#1087#1087#1072#1084
        Caption = 'ToolButtonAll'
        ImageIndex = 8
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonAllClick
      end
      object ToolButtonIsmGrp: TToolButton
        Left = 429
        Top = 0
        Hint = #1055#1077#1088#1077#1085#1077#1089#1090#1080' '#1074' '#1076#1088#1091#1075#1091#1102' '#1075#1088#1091#1087#1087#1091
        Caption = 'ToolButtonIsmGrp'
        ImageIndex = 9
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonIsmGrpClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 9
    Height = 430
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 0
    Top = 503
    Width = 787
    Height = 46
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
    TabStop = True
    object cxButtonClose: TcxButton
      Left = 698
      Top = 16
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel4: TPanel
    Left = 779
    Top = 73
    Width = 8
    Height = 430
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
  end
  object Panel5: TPanel
    Left = 269
    Top = 73
    Width = 10
    Height = 430
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 6
  end
  object cxTreeView1: TcxTreeView
    Left = 9
    Top = 73
    Width = 260
    Height = 430
    Align = alLeft
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -15
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = []
    Style.IsFontAssigned = True
    TabOrder = 0
    OnDblClick = cxTreeView1DblClick
    OnKeyDown = cxTreeView1KeyDown
    HideSelection = False
    ReadOnly = True
    RowSelect = True
  end
  object cxGrid1: TcxGrid
    Left = 279
    Top = 73
    Width = 500
    Height = 430
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1CODE_SPROJECT: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_SPROJECT'
        Styles.Header = DM.cxStyleHeaderTable
      end
      object cxGrid1DBTableView1NAME_SPROJECT: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_SPROJECT'
        Styles.Header = DM.cxStyleHeaderTable
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 144
    Top = 88
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
  end
end