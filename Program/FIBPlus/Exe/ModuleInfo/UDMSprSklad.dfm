object DMSprSklad: TDMSprSklad
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 231
  Width = 363
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select  * from SSKLAD')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 16
    object TableTSKLAD: TFIBIntegerField
      FieldName = 'TSKLAD'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
      RoundByScale = True
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object TableMOLSKLAD: TFIBWideStringField
      FieldName = 'MOLSKLAD'
    end
    object TableADRSKLAD: TFIBWideStringField
      FieldName = 'ADRSKLAD'
      Size = 100
    end
    object TableGID_SSKLAD: TFIBWideStringField
      FieldName = 'GID_SSKLAD'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSKLAD'
      'SET '
      '    NAMESKLAD = :NAMESKLAD,'
      '    MOLSKLAD = :MOLSKLAD,'
      '    ADRSKLAD = :ADRSKLAD,'
      '    TSKLAD = :TSKLAD,'
      '    GID_SSKLAD = :GID_SSKLAD,'
      '    IDBASE_SSKLAD = :IDBASE_SSKLAD,'
      '    DBLUCHETALLNOM_SSKLAD = :DBLUCHETALLNOM_SSKLAD,'
      '    DBLUCHET_SSKLAD = :DBLUCHET_SSKLAD,'
      '    PREFIKS_NUM_SSKLAD = :PREFIKS_NUM_SSKLAD'
      'WHERE'
      '    IDSKLAD = :OLD_IDSKLAD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSKLAD'
      'WHERE'
      '        IDSKLAD = :OLD_IDSKLAD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSKLAD('
      '    IDSKLAD,'
      '    NAMESKLAD,'
      '    MOLSKLAD,'
      '    ADRSKLAD,'
      '    TSKLAD,'
      '    GID_SSKLAD,'
      '    IDBASE_SSKLAD,'
      '    DBLUCHETALLNOM_SSKLAD,'
      '    DBLUCHET_SSKLAD,'
      '    PREFIKS_NUM_SSKLAD'
      ')'
      'VALUES('
      '    :IDSKLAD,'
      '    :NAMESKLAD,'
      '    :MOLSKLAD,'
      '    :ADRSKLAD,'
      '    :TSKLAD,'
      '    :GID_SSKLAD,'
      '    :IDBASE_SSKLAD,'
      '    :DBLUCHETALLNOM_SSKLAD,'
      '    :DBLUCHET_SSKLAD,'
      '    :PREFIKS_NUM_SSKLAD'
      ')')
    RefreshSQL.Strings = (
      'select * from SSKLAD where(  IDSKLAD=:ID'
      '     ) and (     SSKLAD.IDSKLAD = :OLD_IDSKLAD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SSKLAD where IDSKLAD=:ID')
    AutoUpdateOptions.UpdateTableName = 'SSKLAD'
    AutoUpdateOptions.KeyFields = 'IDSKLAD'
    AutoUpdateOptions.GeneratorName = 'GEN_SSKLAD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementTSKLAD: TFIBIntegerField
      FieldName = 'TSKLAD'
    end
    object ElementIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object ElementMOLSKLAD: TFIBWideStringField
      FieldName = 'MOLSKLAD'
    end
    object ElementADRSKLAD: TFIBWideStringField
      FieldName = 'ADRSKLAD'
      Size = 200
    end
    object ElementGID_SSKLAD: TFIBWideStringField
      FieldName = 'GID_SSKLAD'
      Size = 10
    end
    object ElementDBLUCHETALLNOM_SSKLAD: TFIBSmallIntField
      FieldName = 'DBLUCHETALLNOM_SSKLAD'
    end
    object ElementDBLUCHET_SSKLAD: TFIBSmallIntField
      FieldName = 'DBLUCHET_SSKLAD'
    end
    object ElementPREFIKS_NUM_SSKLAD: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_SSKLAD'
      Size = 3
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
    Left = 264
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
    Left = 264
    Top = 96
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 160
    qoStartTransaction = True
  end
end
