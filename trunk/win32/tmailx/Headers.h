// Headers.h : CHeaders ������

#pragma once
#include "resource.h"       // ������

#include "tmailx.h"
#include "MessageHeader.h"
#include "../../src/content.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CHeaders

class ATL_NO_VTABLE CHeaders :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHeaders, &CLSID_Headers>,
	public ISupportErrorInfo,
	public IDispatchImpl<IHeaders, &IID_IHeaders, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CHeaders()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HEADERS)

BEGIN_COM_MAP(CHeaders)
	COM_INTERFACE_ENTRY(IHeaders)
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

	STDMETHOD(get_item)(BSTR name, IMessageHeader** pVal);
	STDMETHOD(put_item)(BSTR name, BSTR newVal);
	STDMETHOD(get_count)(LONG* pVal);
	STDMETHOD(clear)(void);
	STDMETHOD(erase)(BSTR name);
	STDMETHOD(get__NewEnum)(IUnknown** pVal);
	STDMETHOD(add)(BSTR name, IMessageHeader** pRet);
	STDMETHOD(exist)(BSTR name, VARIANT_BOOL* pVal);

public:
	tmail::ContentPtr content;
};

// OBJECT_ENTRY_AUTO(__uuidof(Headers), CHeaders)
OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(Headers), CHeaders)
