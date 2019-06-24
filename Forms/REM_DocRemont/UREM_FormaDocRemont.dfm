object REM_FormaDocRemont: TREM_FormaDocRemont
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1084#1086#1085#1090' '#1087#1086' '#1079#1072#1103#1074#1082#1077'"'
  ClientHeight = 547
  ClientWidth = 811
  Color = clBtnFace
  Constraints.MinWidth = 689
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 469
    Width = 811
    Height = 78
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 16
      Top = 8
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'FNAME_USER'
      DataSource = REM_DMDocRemont.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 16
      Top = 24
      Width = 111
      Height = 16
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBTextSUM_REM_GALLDOC: TDBText
      Left = 598
      Top = 15
      Width = 181
      Height = 16
      AutoSize = True
      DataField = 'SUM_REM_GALLDOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonPrint: TcxButton
      Left = 187
      Top = 40
      Width = 75
      Height = 25
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 268
      Top = 40
      Width = 75
      Height = 25
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 349
      Top = 40
      Width = 75
      Height = 25
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 430
      Top = 40
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 511
      Top = 40
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 248
    Width = 0
    Height = 221
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 810
    Top = 248
    Width = 1
    Height = 221
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 811
    Height = 248
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 52
      Top = 119
      Width = 211
      Height = 24
      Caption = #1056#1077#1084#1086#1085#1090' '#1087#1086' '#1079#1072#1103#1074#1082#1077'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 362
      Top = 115
      Width = 32
      Height = 26
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 20
      Top = 225
      Width = 66
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label5: TLabel
      Left = 23
      Top = 56
      Width = 40
      Height = 13
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 392
      Top = 35
      Width = 34
      Height = 13
      Caption = #1057#1082#1083#1072#1076':'
    end
    object RTPriceLabel: TLabel
      Left = 363
      Top = 202
      Width = 106
      Height = 13
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080':'
    end
    object Label4: TLabel
      Left = 28
      Top = 168
      Width = 39
      Height = 13
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object Label7: TLabel
      Left = 28
      Top = 200
      Width = 40
      Height = 13
      Caption = #1047#1072#1103#1074#1082#1072':'
    end
    object Label8: TLabel
      Left = 424
      Top = 178
      Width = 11
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #8470
    end
    object Label9: TLabel
      Left = 544
      Top = 178
      Width = 11
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1086#1090
    end
    object Label10: TLabel
      Left = 548
      Top = 150
      Width = 17
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = '1'#8470
    end
    object Label11: TLabel
      Left = 548
      Top = 163
      Width = 17
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = '2'#8470
    end
    object Label12: TLabel
      Left = 404
      Top = 55
      Width = 22
      Height = 13
      Caption = #1058#1080#1087':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 811
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 6
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
        Width = 171
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 234
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 242
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateCheck: TToolButton
        Left = 265
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1063#1077#1082' '#1050#1050#1052
        Caption = 'ToolButtonCreateCheck'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateCheckClick
      end
      object ToolButtonCreateRealRozn: TToolButton
        Left = 288
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1088#1086#1079#1085'."'
        Caption = 'ToolButtonCreateRealRozn'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateRealRoznClick
      end
      object ToolButtonCreateReal: TToolButton
        Left = 311
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103'"'
        Caption = 'ToolButtonCreateReal'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateRealClick
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 100
      Top = 222
      DataBinding.DataField = 'PRIM_REM_DREMONT'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDoc
      TabOrder = 5
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 496
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 269
      Top = 123
      DataBinding.DataField = 'NUM_REM_GALLDOC'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      TabOrder = 3
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 81
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 398
      Top = 123
      DataBinding.DataField = 'POS_REM_GALLDOC'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Kind = ckDateTime
      Properties.OnChange = PosDoccxDBDateEditPropertiesChange
      TabOrder = 4
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 159
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 79
      Top = 53
      DataBinding.DataField = 'NAMEFIRM'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = False
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 274
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 80
      Top = 31
      DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = False
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 273
    end
    object cxLabel1: TcxLabel
      Left = 16
      Top = 32
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 432
      Top = 31
      DataBinding.DataField = 'NAMESKLAD'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
      TabOrder = 2
      Width = 249
    end
    object TypePricecxDBLookupComboBox: TcxDBLookupComboBox
      Left = 482
      Top = 200
      DataBinding.DataField = 'IDTPRICE_REM_DREMONT'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDoc
      Properties.ImmediatePost = True
      Properties.KeyFieldNames = 'ID_TPRICE'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_TPRICE'
        end>
      Properties.ListSource = DMSprTypePrice.DataSourceTable
      TabOrder = 8
      Width = 175
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 84
      Top = 165
      DataBinding.DataField = 'NAMEKLIENT'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 9
      Width = 273
    end
    object NameZcxDBButtonEdit: TcxDBButtonEdit
      Left = 84
      Top = 195
      DataBinding.DataField = 'NAME_REM_Z'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDoc
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameZcxDBButtonEditPropertiesButtonClick
      TabOrder = 10
      Width = 273
    end
    object NameKlientcxDBLabel: TcxDBLabel
      Left = 375
      Top = 149
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'KLIENT_NAME_REM_Z'
      Height = 17
      Width = 164
    end
    object ModelcxDBLabel: TcxDBLabel
      Left = 377
      Top = 162
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'MODEL_REM_Z'
      Height = 17
      Width = 155
    end
    object PosZcxDBLabel: TcxDBLabel
      Left = 570
      Top = 176
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'POS_REM_Z'
      Height = 17
      Width = 98
    end
    object NumZcxDBLabel: TcxDBLabel
      Left = 440
      Top = 177
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'NUM_REM_Z'
      Height = 17
      Width = 99
    end
    object SerNumcxDBLabel: TcxDBLabel
      Left = 570
      Top = 149
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'SERNUM_REM_Z'
      Height = 17
      Width = 98
    end
    object SerNum2cxDBLabel: TcxDBLabel
      Left = 570
      Top = 162
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'SERNUM2_REM_Z'
      Height = 17
      Width = 98
    end
    object TypeRemontcxDBImageComboBox: TcxDBImageComboBox
      Left = 432
      Top = 53
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeRemont
      DataBinding.DataField = 'TYPE_REMONT_REM_DREMONT'
      Properties.Items = <>
      TabOrder = 17
      Width = 249
    end
    object cxLabel9: TcxLabel
      Left = 359
      Top = 77
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 460
      Top = 76
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
      TabOrder = 19
      Width = 221
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 460
      Top = 97
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
      TabOrder = 20
      Width = 221
    end
    object cxLabel4: TcxLabel
      Left = 413
      Top = 98
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 248
    Width = 810
    Height = 221
    Align = alClient
    TabOrder = 4
    object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBBandedTableView1SUM_REM_DREMONTT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      OptionsView.HeaderAutoHeight = True
      OptionsView.RowSeparatorColor = clWindowText
      OptionsView.RowSeparatorWidth = 2
      Bands = <
        item
          Styles.Header = DM.cxStyleHeaderTable
        end>
      object cxGrid1DBBandedTableView1RECNO: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 20
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1DVREG_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = #1044#1074' '#1088#1077#1075
        DataBinding.FieldName = 'DVREG_REM_DREMONTT'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Styles.Header = DM.cxStyleHeaderTable
        Width = 20
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_TYPE_NOM_LOOCUP: TcxGridDBBandedColumn
        Caption = #1058#1080#1087' '#1085#1086#1084'.'
        DataBinding.FieldName = 'NAME_TYPE_NOM_LOOCUP'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 62
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1CODENOM: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 52
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1ARTNOM: TcxGridDBBandedColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 74
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAMENOM: TcxGridDBBandedColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 168
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAMEED: TcxGridDBBandedColumn
        Caption = #1045#1076'.'
        DataBinding.FieldName = 'NAMEED'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAMEEDPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 68
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1KF_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KF_REM_DREMONTT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 36
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1KOL_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_REM_DREMONTT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 70
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1PRICE_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_REM_DREMONTT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 86
        Position.BandIndex = 0
        Position.ColIndex = 9
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1SUM_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_DREMONTT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 67
        Position.BandIndex = 0
        Position.ColIndex = 10
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDHW_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = 'ID'
        DataBinding.FieldName = 'IDHW_REM_DREMONTT'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1CODE_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SHARDWARE'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 82
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1NAME_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077', '#1073#1083#1086#1082', '#1076#1077#1090#1072#1083#1100' ('#1085#1086#1074#1072#1103')'
        DataBinding.FieldName = 'NAME_REM_SHARDWARE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SHARDWAREPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 176
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1SERNUM_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 86
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1IDHWOLD_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = 'ID'
        DataBinding.FieldName = 'IDHWOLD_REM_DREMONTT'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 73
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1OLD_CODE_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'OLD_CODE_REM_SHARDWARE'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 70
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1OLD_NAME_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077', '#1073#1083#1086#1082' ('#1089#1090#1072#1088#1099#1081')'
        DataBinding.FieldName = 'OLD_NAME_REM_SHARDWARE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1OLD_NAME_REM_SHARDWAREPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 153
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1OLD_SERNUM_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'OLD_SERNUM_REM_SHARDWARE'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 73
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1IDHW_DONOR_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = 'ID'
        DataBinding.FieldName = 'IDHW_DONOR_REM_DREMONTT'
        Styles.Content = DM.cxStyleclMoneyGreen
        Styles.Header = DM.cxStyleHeaderTable
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1DONOR_CODE_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'DONOR_CODE_REM_SHARDWARE'
        Styles.Content = DM.cxStyleclMoneyGreen
        Styles.Header = DM.cxStyleHeaderTable
        Width = 82
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1DONOR_NAME_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1044#1086#1085#1086#1088
        DataBinding.FieldName = 'DONOR_NAME_REM_SHARDWARE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1DONOR_NAME_REM_SHARDWAREPropertiesButtonClick
        Styles.Content = DM.cxStyleclMoneyGreen
        Styles.Header = DM.cxStyleHeaderTable
        Width = 176
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1DONOR_SERNUM_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'DONOR_SERNUM_REM_SHARDWARE'
        Styles.Content = DM.cxStyleclMoneyGreen
        Styles.Header = DM.cxStyleHeaderTable
        Width = 86
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1NAME_REM_STYPUSLOV: TcxGridDBBandedColumn
        Caption = #1058#1080#1087#1086#1074#1086#1081' '#1091#1079#1077#1083
        DataBinding.FieldName = 'NAME_REM_STYPUSLOV'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_STYPUSLOVPropertiesButtonClick
        Styles.Content = DM.cxStyleclMoneyGreen
        Styles.Header = DM.cxStyleHeaderTable
        Width = 143
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1DESCR_REM_DREMONTT: TcxGridDBBandedColumn
        Caption = #1054#1087#1080#1089#1072#1085#1080#1077
        DataBinding.FieldName = 'DESCR_REM_DREMONTT'
        Styles.Content = DM.cxStyleclMoneyGreen
        Styles.Header = DM.cxStyleHeaderTable
        Width = 226
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1NAME_SMHRAN: TcxGridDBBandedColumn
        Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085'.'
        DataBinding.FieldName = 'NAME_SMHRAN'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_SMHRANPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 73
        Position.BandIndex = 0
        Position.ColIndex = 11
        Position.RowIndex = 0
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBBandedTableView1
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
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 400
    Top = 24
  end
end
