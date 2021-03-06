object DMSprPrice: TDMSprPrice
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 345
  Width = 302
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRICE'
      'SET '
      '    IDNOM_PRICE = :IDNOM_PRICE,'
      '    IDTYPE_PRICE = :IDTYPE_PRICE,'
      '    IDED_SPRICE = :IDED_SPRICE,'
      '    ZNACH_PRICE = :ZNACH_PRICE,'
      '    GID_SPRICE = :GID_SPRICE,'
      '    FL_CHANGE_PRICE = :FL_CHANGE_PRICE,'
      '    IDBASE_SPRICE = :IDBASE_SPRICE'
      'WHERE'
      '    ID_PRICE = :OLD_ID_PRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRICE'
      'WHERE'
      '        ID_PRICE = :OLD_ID_PRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRICE('
      '    ID_PRICE,'
      '    IDNOM_PRICE,'
      '    IDTYPE_PRICE,'
      '    IDED_SPRICE,'
      '    ZNACH_PRICE,'
      '    GID_SPRICE,'
      '    FL_CHANGE_PRICE,'
      '    IDBASE_SPRICE'
      ')'
      'VALUES('
      '    :ID_PRICE,'
      '    :IDNOM_PRICE,'
      '    :IDTYPE_PRICE,'
      '    :IDED_SPRICE,'
      '    :ZNACH_PRICE,'
      '    :GID_SPRICE,'
      '    :FL_CHANGE_PRICE,'
      '    :IDBASE_SPRICE'
      ')')
    RefreshSQL.Strings = (
      'select SPRICE.*,  NAME_TPRICE'
      'from '
      '  SPRICE '
      'left outer join STPRICE on IDTYPE_PRICE=ID_TPRICE'
      'where(  '
      '  IDNOM_PRICE=:IDNOM'
      '     ) and (     SPRICE.ID_PRICE = :OLD_ID_PRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select        SPRICE.*,'
      '        NAME_TPRICE'
      'from '
      '  SPRICE '
      'left outer join STPRICE on IDTYPE_PRICE=ID_TPRICE'
      'where '
      '  IDNOM_PRICE=:IDNOM'
      'order by NAME_TPRICE'
      '')
    AutoUpdateOptions.UpdateTableName = 'SPRICE'
    AutoUpdateOptions.KeyFields = 'ID_PRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterInsert = TableAfterInsert
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object TableZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableFL_CHANGE_PRICE: TFIBSmallIntField
      FieldName = 'FL_CHANGE_PRICE'
    end
    object TableID_PRICE: TFIBLargeIntField
      FieldName = 'ID_PRICE'
    end
    object TableIDNOM_PRICE: TFIBLargeIntField
      FieldName = 'IDNOM_PRICE'
    end
    object TableIDTYPE_PRICE: TFIBLargeIntField
      FieldName = 'IDTYPE_PRICE'
    end
    object TableIDED_SPRICE: TFIBLargeIntField
      FieldName = 'IDED_SPRICE'
    end
    object TableGID_SPRICE: TFIBWideStringField
      FieldName = 'GID_SPRICE'
      Size = 10
    end
    object TableIDBASE_SPRICE: TFIBLargeIntField
      FieldName = 'IDBASE_SPRICE'
    end
    object TableNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object TableNAMETPRICE: TStringField
      FieldKind = fkLookup
      FieldName = 'NAMETPRICE'
      LookupDataSet = TPrice
      LookupKeyFields = 'ID_TPRICE'
      LookupResultField = 'NAME_TPRICE'
      KeyFields = 'IDTYPE_PRICE'
      Size = 30
      Lookup = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRICE'
      'SET '
      '    IDNOM_PRICE = :IDNOM_PRICE,'
      '    IDTYPE_PRICE = :IDTYPE_PRICE,'
      '    IDED_SPRICE = :IDED_SPRICE,'
      '    ZNACH_PRICE = :ZNACH_PRICE,'
      '    GID_SPRICE = :GID_SPRICE,'
      '    FL_CHANGE_PRICE = :FL_CHANGE_PRICE,'
      '    IDBASE_SPRICE = :IDBASE_SPRICE'
      'WHERE'
      '    ID_PRICE = :OLD_ID_PRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRICE'
      'WHERE'
      '        ID_PRICE = :OLD_ID_PRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRICE('
      '    ID_PRICE,'
      '    IDNOM_PRICE,'
      '    IDTYPE_PRICE,'
      '    IDED_SPRICE,'
      '    ZNACH_PRICE,'
      '    GID_SPRICE,'
      '    FL_CHANGE_PRICE,'
      '    IDBASE_SPRICE'
      ')'
      'VALUES('
      '    :ID_PRICE,'
      '    :IDNOM_PRICE,'
      '    :IDTYPE_PRICE,'
      '    :IDED_SPRICE,'
      '    :ZNACH_PRICE,'
      '    :GID_SPRICE,'
      '    :FL_CHANGE_PRICE,'
      '    :IDBASE_SPRICE'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  SPRICE'
      'where(  ID_PRICE=:PARAM_ID'
      '     ) and (     SPRICE.ID_PRICE = :OLD_ID_PRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  SPRICE'
      'where ID_PRICE=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRICE'
    AutoUpdateOptions.KeyFields = 'ID_PRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object ElementZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object ElementFL_CHANGE_PRICE: TFIBSmallIntField
      FieldName = 'FL_CHANGE_PRICE'
    end
    object ElementID_PRICE: TFIBBCDField
      FieldName = 'ID_PRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOM_PRICE: TFIBBCDField
      FieldName = 'IDNOM_PRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTYPE_PRICE: TFIBBCDField
      FieldName = 'IDTYPE_PRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDED_SPRICE: TFIBBCDField
      FieldName = 'IDED_SPRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SPRICE: TFIBWideStringField
      FieldName = 'GID_SPRICE'
      Size = 10
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 72
  end
  object TPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select stprice.id_tprice,'
      '       stprice.name_tprice'
      'from STPRICE')
    Transaction = IBTr
    Left = 152
    Top = 136
    poUseLargeIntField = True
    object TPriceID_TPRICE: TFIBLargeIntField
      FieldName = 'ID_TPRICE'
    end
    object TPriceNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 248
    Top = 144
    qoStartTransaction = True
  end
  object SpisokEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select sed.ided,'
      '        sed.nameed,'
      '        sed.kfed'
      'from SED'
      'where IDNOMED=:PARAM_IDNOM')
    Transaction = IBTr
    Left = 184
    Top = 240
    poUseLargeIntField = True
    object SpisokEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object SpisokEdIDED: TFIBLargeIntField
      FieldName = 'IDED'
    end
    object SpisokEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object DataSourceSpisokEd: TDataSource
    DataSet = SpisokEd
    Left = 80
    Top = 240
  end
end
