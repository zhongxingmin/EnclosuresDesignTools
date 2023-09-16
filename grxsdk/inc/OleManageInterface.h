#pragma once

class COleClientItem;
class OdDbDatabase;

class OdOleManageInterface
{
public:
  //��ȡָ��Database���ĵ����е�Ole����
	virtual bool getCntrItems(const OdDbDatabase* pDb,bool onlyLink,OdArray<COleClientItem*>& items) = 0;
  virtual void releaseItems() = 0;
};

TOOLKIT_EXPORT OdOleManageInterface* GetOleManage();
void TOOLKIT_EXPORT SetOleManage(OdOleManageInterface*pManageInterface);
