object FormaDocVosvratPost: TFormaDocVosvratPost
  Left = 337
  Top = 139
  Caption = #1042#1086#1079#1074#1088#1072#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091
  ClientHeight = 592
  ClientWidth = 938
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
  object Panel2: TPanel
    Left = 0
    Top = 329
    Width = 7
    Height = 146
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 0
    Top = 475
    Width = 938
    Height = 117
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object ProsmotrLabel: TLabel
      Left = 10
      Top = 69
      Width = 155
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 10
      Top = 97
      Width = 164
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 10
      Top = 12
      Width = 141
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1086#1089#1085#1086#1074#1072#1085#1080#1077':'
    end
    object cxButtonPrint: TcxButton
      Left = 315
      Top = 59
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonDvReg: TcxButton
      Left = 415
      Top = 59
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 514
      Top = 59
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 614
      Top = 59
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 714
      Top = 59
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 4
    end
    object DocOsncxDBButtonEdit: TcxDBButtonEdit
      Left = 174
      Top = 7
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'TDOC_OSN'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
      TabOrder = 5
      Width = 384
    end
  end
  object Panel4: TPanel
    Left = 927
    Top = 329
    Width = 11
    Height = 146
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 4
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 938
    Height = 329
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 29
      Top = 139
      Width = 329
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 678
      Top = 133
      Width = 40
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 15
      Top = 297
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label12: TLabel
      Left = 5
      Top = 81
      Width = 73
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 485
      Top = 41
      Width = 66
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 55
      Top = 203
      Width = 75
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 109
      Top = 269
      Width = 152
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1087#1088#1080#1086#1073#1088#1077#1090#1077#1085#1080#1103':'
    end
    object RTPriceLabel: TLabel
      Left = 514
      Top = 269
      Width = 138
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080':'
    end
    object Label5: TLabel
      Left = 6
      Top = 111
      Width = 35
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1095#1077#1090':'
    end
    object Label4: TLabel
      Left = 10
      Top = 236
      Width = 120
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1079#1086#1087#1086#1083#1091#1095#1072#1090#1077#1083#1100':'
    end
    object Label6: TLabel
      Left = 514
      Top = 236
      Width = 71
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1089#1095'. '#1089#1095#1077#1090':'
    end
    object Label9: TLabel
      Left = 514
      Top = 203
      Width = 71
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1089#1095'. '#1089#1095#1077#1090':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 938
      Height = 33
      Color = clBtnFace
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 14
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonInsert: TToolButton
        Left = 17
        Top = 0
        Action = ActionAddString
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonDelete: TToolButton
        Left = 40
        Top = 0
        Action = ActionDeleteString
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 63
        Top = 0
        Width = 90
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 153
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonExtModule: TToolButton
        Left = 161
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
    object TypePriceComboBox: TcxComboBox
      Left = 286
      Top = 265
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypePriceComboBoxPropertiesChange
      TabOrder = 12
      Width = 217
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 109
      Top = 297
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIMVPO'
      TabOrder = 11
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 460
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 137
      Top = 200
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKLIENT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 10
      Width = 336
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 716
      Top = 137
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      Properties.Kind = ckDateTime
      TabOrder = 7
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 211
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 559
      Top = 137
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      TabOrder = 6
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 120
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 79
      Top = 80
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEFIRM'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 307
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 559
      Top = 41
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMESKLAD'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
      TabOrder = 2
      Width = 283
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 79
      Top = 49
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 307
    end
    object cxLabel1: TcxLabel
      Left = 7
      Top = 48
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object TypeRPriceComboBox: TcxComboBox
      Left = 660
      Top = 265
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypeRPriceComboBoxPropertiesChange
      TabOrder = 13
      Width = 217
    end
    object PosDocPostcxDBDateEdit: TcxDBDateEdit
      Left = 769
      Top = 169
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOCPOST_DVPO'
      Properties.Kind = ckDateTime
      TabOrder = 9
      OnKeyPress = PosDocPostcxDBDateEditKeyPress
      Width = 149
    end
    object NumDocPostcxDBTextEdit: TcxDBTextEdit
      Left = 585
      Top = 169
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOCPOST_DVPO'
      TabOrder = 8
      OnKeyDown = NumDocPostcxDBTextEditKeyDown
      Width = 149
    end
    object cxLabel2: TcxLabel
      Left = 419
      Top = 172
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072' '#8470
    end
    object cxLabel3: TcxLabel
      Left = 742
      Top = 172
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 572
      Top = 72
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SBUSINESS_OPER'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameBusinessOpercxDBButtonEditPropertiesButtonClick
      TabOrder = 3
      Width = 272
    end
    object cxLabel9: TcxLabel
      Left = 448
      Top = 73
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object cxLabel4: TcxLabel
      Left = 514
      Top = 98
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 572
      Top = 97
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SPROJECT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameProjectcxDBButtonEditPropertiesButtonClick
      TabOrder = 4
      Width = 272
    end
    object NameBSchetcxDBButtonEdit: TcxDBButtonEdit
      Left = 75
      Top = 107
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEBSCHET'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameBSchetcxDBButtonEditPropertiesButtonClick
      TabOrder = 20
      Width = 311
    end
    object NameGrPolcxDBButtonEdit: TcxDBButtonEdit
      Left = 137
      Top = 233
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKLIENT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameGrPolcxDBButtonEditPropertiesButtonClick
      TabOrder = 21
      Width = 336
    end
    object NameRaschScetKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 592
      Top = 200
      DataBinding.DataField = 'NAME_RSCHET_KLIENT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameRaschScetKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 22
      Width = 257
    end
    object NameRaschSchetGrpolcxDBButtonEdit: TcxDBButtonEdit
      Left = 592
      Top = 233
      DataBinding.DataField = 'NAME_RSCHET_GRPOL'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameRaschSchetGrpolcxDBButtonEditPropertiesButtonClick
      TabOrder = 23
      Width = 257
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 406
      Top = 137
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 5
      Width = 145
    end
  end
  object cxGrid1: TcxGrid
    Left = 7
    Top = 329
    Width = 920
    Height = 146
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUMVPOT
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1RSUM_DVPOT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Footer = DM.cxStyleFooterSum
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 45
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 242
      end
      object cxGrid1DBTableView1KOLVPOT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOLVPOT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 55
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMEEDPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 63
      end
      object cxGrid1DBTableView1KFVPOT: TcxGridDBColumn
        Caption = #1050
        DataBinding.FieldName = 'KFVPOT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 34
      end
      object cxGrid1DBTableView1PRICEVPOT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICEVPOT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 81
      end
      object cxGrid1DBTableView1SUMVPOT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMVPOT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 80
      end
      object cxGrid1DBTableView1RPRICE_DVPOT: TcxGridDBColumn
        Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072
        DataBinding.FieldName = 'RPRICE_DVPOT'
        Width = 69
      end
      object cxGrid1DBTableView1RSUM_DVPOT: TcxGridDBColumn
        Caption = #1056#1086#1079#1085'. '#1089#1091#1084#1084#1072
        DataBinding.FieldName = 'RSUM_DVPOT'
        Width = 76
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 40
    Top = 104
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionAddString: TAction
      Caption = 'ActionAddString'
      ImageIndex = 0
      ShortCut = 45
      OnExecute = ActionAddStringExecute
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
      ImageIndex = 2
      ShortCut = 46
      OnExecute = ActionDeleteStringExecute
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
    object ActionDvReg: TAction
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      ImageIndex = 56
      OnExecute = ActionDvRegExecute
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 43
      OnExecute = ActionPrintExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 192
    Top = 16
  end
end
