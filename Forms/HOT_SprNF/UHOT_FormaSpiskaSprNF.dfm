object HOT_FormaSpiskaSprNF: THOT_FormaSpiskaSprNF
  Left = 392
  Top = 307
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1053#1086#1084#1077#1088#1085#1086#1081' '#1092#1086#1085#1076'"'
  ClientHeight = 518
  ClientWidth = 688
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 688
    Height = 90
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object HintLabel: TLabel
      Left = 10
      Top = 34
      Width = 49
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 688
      Height = 29
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
      object ToolButtonNew: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 90
    Width = 4
    Height = 352
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 688
    Top = 90
    Width = 0
    Height = 352
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object Panel4: TPanel
    Left = 0
    Top = 442
    Width = 688
    Height = 76
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
    object cxButtonClose: TcxButton
      Left = 587
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
  end
  object cxGrid1: TcxGrid
    Left = 4
    Top = 90
    Width = 684
    Height = 352
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnKeyDown = cxGrid1DBTableView1KeyDown
      NavigatorButtons.ConfirmDelete = False
      OnCellDblClick = cxGrid1DBTableView1CellDblClick
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsData.Editing = False
      OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 28
      end
      object cxGrid1DBTableView1NAME_HOT_SOBJECT: TcxGridDBColumn
        Caption = #1054#1073#1098#1077#1082#1090
        DataBinding.FieldName = 'NAME_HOT_SOBJECT'
        Width = 111
      end
      object cxGrid1DBTableView1NAME_HOT_SNF: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_HOT_SNF'
        Width = 117
      end
      object cxGrid1DBTableView1NAME_HOT_SCATNOM: TcxGridDBColumn
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
        DataBinding.FieldName = 'NAME_HOT_SCATNOM'
        Width = 111
      end
      object cxGrid1DBTableView1KOLM_HOT_SNF: TcxGridDBColumn
        Caption = #1052#1077#1089#1090
        DataBinding.FieldName = 'KOLM_HOT_SNF'
        Width = 41
      end
      object cxGrid1DBTableView1POSIN_HOT_SNF: TcxGridDBColumn
        Caption = #1042#1074#1086#1076
        DataBinding.FieldName = 'POSIN_HOT_SNF'
        PropertiesClassName = 'TcxDateEditProperties'
        Width = 73
      end
      object cxGrid1DBTableView1POSOUT_HOT_SNF: TcxGridDBColumn
        Caption = #1042#1099#1074#1086#1076
        DataBinding.FieldName = 'POSOUT_HOT_SNF'
        Width = 73
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
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
  end
end
