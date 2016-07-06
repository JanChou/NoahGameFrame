// -------------------------------------------------------------------------
//    @FileName      :   NFCPotionConsumeProcessModule.h
//    @Author           :   LvSheng.Huang
//    @Date             :   2013-10-02
//    @Module           :   NFCPotionConsumeProcessModule
//    @Desc             :   �������ѻ�����--ʹ����Ʒ����ü��ܻ��ߵ���
//                                  --������ѧϰ����,���������Ʒ,BUFF��õ�BUFF,������ʹ�ü���
// -------------------------------------------------------------------------

#ifndef NFC_CARDITEMCONSUME_PROCESS_MODULE_H
#define NFC_CARDITEMCONSUME_PROCESS_MODULE_H

#include <iostream>
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIPackModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFIItemCardConsumeProcessModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIItemModule.h"
#include "NFComm/NFPluginModule/NFIHeroModule.h"

class NFCItemCardConsumeProcessModule
    : public NFIItemCardConsumeProcessModule
{

public:
    NFCItemCardConsumeProcessModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();
    virtual bool AfterInit();

	//��Ʒʹ���Ƿ�Ϸ�
	virtual int ConsumeLegal(const NFGUID& self, const std::string& strItemID, const NFIDataList& targetID);

	//�Ϸ�,����,��ô��������[���ĺ�,nItemRowID�Ѿ��Ҳ����ˣ���Ϊ���ܱ������]
	virtual int ConsumeProcess(const NFGUID& self, const std::string& strItemID, const NFIDataList& targetID);

private:
    NFIKernelModule* m_pKernelModule;
    NFILogModule* m_pLogModule;
    NFIPackModule* m_pPackModule;
	NFIElementModule* m_pElementModule;
	NFIItemModule* m_pItemModule;
	NFIHeroModule* m_pHeroModule;
};

#endif