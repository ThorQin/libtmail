// Options.h : COptions ������

#pragma once
#include "resource.h"       // ������

#include "tmailx.h"
#include <vector>
#include <string>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// COptions

class ATL_NO_VTABLE COptions :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COptions, &CLSID_Options>,
	public ISupportErrorInfo,
	public IDispatchImpl<IOptions, &IID_IOptions, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	COptions()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_OPTIONS)


BEGIN_COM_MAP(COptions)
	COM_INTERFACE_ENTRY(IOptions)
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

	STDMETHOD(get_item)(LONG index, BSTR* pVal);
	STDMETHOD(get_count)(LONG* pVal);

	std::vector<std::wstring> strings;
};

OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(Options), COptions)