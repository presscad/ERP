object REM_FormaSpiskaSprModelTypRabot: TREM_FormaSpiskaSprModelTypRabot
  Left = 240
  Top = 20
  Caption = #1058#1080#1087#1086#1074#1099#1077' '#1088#1072#1073#1086#1090#1099' '#1084#1086#1076#1077#1083#1080
  ClientHeight = 528
  ClientWidth = 646
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
    Width = 646
    Height = 60
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
      Width = 646
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 9
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 9
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 32
        Top = 0
        Hint = #1048#1079#1084#1077#1085#1080#1090#1100
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 55
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton3: TToolButton
        Left = 78
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButton3'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object LabelNom: TLabel
        Left = 101
        Top = 0
        Width = 206
        Height = 22
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1085#1077#1080#1079#1074#1077#1089#1090#1085#1072'!'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ToolButton2: TToolButton
        Left = 307
        Top = 0
        Width = 6
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton4: TToolButton
        Left = 313
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1088#1090#1099' '#1087#1086' '#1085#1072#1073#1086#1088#1091' '#1080#1079' '#1075#1088#1091#1087#1087#1099
        Caption = 'ToolButton4'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCopy: TToolButton
        Left = 336
        Top = 0
        Hint = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1101#1083#1077#1084#1077#1085#1090#1099' '#1080#1079' '#1076#1088#1091#1075#1086#1081' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        Caption = 'ToolButtonCopy'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 60
    Width = 11
    Height = 403
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
    Left = 0
    Top = 463
    Width = 646
    Height = 65
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonClose: TcxButton
      Left = 538
      Top = 17
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
  object Panel4: TPanel
    Left = 630
    Top = 60
    Width = 16
    Height = 403
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 60
    Width = 619
    Height = 403
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
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1NAME_REM_STYPRABOT: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_REM_STYPRABOT'
        Width = 258
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        Width = 48
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        PropertiesClassName = 'TcxMemoProperties'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 65
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        Width = 234
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 224
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
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 112
    Top = 8
  end
end
