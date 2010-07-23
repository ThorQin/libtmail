// Contents.h : CContents ������

#pragma once
#include "resource.h"       // ������

#include "tmailx.h"
#include "Content.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CContents

class ATL_NO_VTABLE CContents :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CContents, &CLSID_Contents>,
	public ISupportErrorInfo,
	public IDispatchImpl<IContents, &IID_IContents, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CContents()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CONTENTS)

BEGIN_COM_MAP(CContents)
	COM_INTERFACE_ENTRY(IContents)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(get_item)(LONG index, IContent** pVal);
	STDMETHOD(get_count)(LONG* pVal);
	STDMETHOD(clear)(void);
	STDMETHOD(erase)(LONG index);
	STDMETHOD(get__NewEnum)(IUnknown** pVal);
	STDMETHOD(add)(IContent* content);

	tmail::ContentPtr parent_conent;
};

//OBJECT_ENTRY_AUTO(__uuidof(Contents), CContents)
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(Contents), CContents)