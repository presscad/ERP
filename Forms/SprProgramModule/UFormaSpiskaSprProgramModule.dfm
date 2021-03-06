object FormaSpiskaSprProgramModule: TFormaSpiskaSprProgramModule
  Left = 392
  Top = 307
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1055#1088#1086#1075#1088#1072#1084#1084#1085#1099#1077' '#1084#1086#1076#1091#1083#1080'"'
  ClientHeight = 518
  ClientWidth = 697
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
    Width = 697
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
      Width = 697
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
      object ToolButtonAddAllProgramModule: TToolButton
        Left = 77
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1089#1077' '#1084#1086#1076#1091#1083#1080' '#1074#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082'.'
        Caption = 'ToolButtonAddAllProgramModule'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddAllProgramModuleClick
      end
      object ToolButtonClearSpr: TToolButton
        Left = 100
        Top = 0
        Hint = #1054#1095#1080#1089#1090#1080#1090#1100' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082
        Caption = 'ToolButtonClearSpr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonClearSprClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 90
    Width = 11
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
    Left = 679
    Top = 90
    Width = 18
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
    Width = 697
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
      Top = 27
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 90
    Width = 668
    Height = 352
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyDown = cxGrid1DBTableView1KeyDown
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMSprProgramModule.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 43
      end
      object cxGrid1DBTableView1NAME_PROGRAM_MODULE: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_PROGRAM_MODULE'
        Width = 144
      end
      object cxGrid1DBTableView1GUID_PROGRAM_MODULE: TcxGridDBColumn
        DataBinding.FieldName = 'GUID_PROGRAM_MODULE'
        Width = 142
      end
      object cxGrid1DBTableView1PROGID_PROGRAM_MODULE: TcxGridDBColumn
        Caption = 'ProgId'
        DataBinding.FieldName = 'PROGID_PROGRAM_MODULE'
        Width = 74
      end
      object cxGrid1DBTableView1MODULE_PROGRAM_MODULE: TcxGridDBColumn
        Caption = #1052#1086#1076#1091#1083#1100
        DataBinding.FieldName = 'MODULE_PROGRAM_MODULE'
        Width = 46
      end
      object cxGrid1DBTableView1PATCH_PROGRAM_MODULE: TcxGridDBColumn
        Caption = #1055#1091#1090#1100
        DataBinding.FieldName = 'PATCH_PROGRAM_MODULE'
        Width = 116
      end
      object cxGrid1DBTableView1TYPEMOD_PROGRAM_MODULE: TcxGridDBColumn
        DataBinding.FieldName = 'TYPEMOD_PROGRAM_MODULE'
        PropertiesClassName = 'TcxImageComboBoxProperties'
        Properties.Items = <>
        RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeApplication
        Width = 101
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
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
