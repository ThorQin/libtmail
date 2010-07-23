// Mail.h : CMail ������

#pragma once
#include "resource.h"       // ������

#include "tmailx.h"
#include "Content.h"
#include "../../src/mail.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CMail

class ATL_NO_VTABLE CMail : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMail, &CLSID_Mail>,
	public ISupportErrorInfo,
	public IDispatchImpl<IMail, &IID_IMail, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMail()//: _unknown(0)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MAIL)


BEGIN_COM_MAP(CMail)
	COM_INTERFACE_ENTRY(IMail)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
//	COM_INTERFACE_ENTRY_AGGREGATE(__uuidof(IContent), _unknown)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		mail = tmail::MailPtr(new tmail::Mail());
		//CComObject<CContent>* content;
		//HRESULT hr = CComObject<CContent>::CreateInstance(&content);
		//if (FAILED(hr))
		//	return hr;
		//content->content = mail;
		//hr = content->QueryInterface(&_unknown);
		//if (FAILED(hr))
		//{
		//	delete content;
		//	return hr;
		//}
		return S_OK;
	}

	void FinalRelease()
	{
		//_unknown->Release();
	}

public:

	STDMETHOD(get_from)(BSTR* pVal);
	STDMETHOD(put_from)(BSTR newVal);

public:
	tmail::MailPtr mail;

	//IUnknown* _unknown;
	STDMETHOD(get_to)(BSTR* pVal);
	STDMETHOD(put_to)(BSTR newVal);
	STDMETHOD(get_cc)(BSTR* pVal);
	STDMETHOD(put_cc)(BSTR newVal);
	STDMETHOD(get_bcc)(BSTR* pVal);
	STDMETHOD(put_bcc)(BSTR newVal);
	STDMETHOD(get_subject)(BSTR* pVal);
	STDMETHOD(put_subject)(BSTR newVal);
	STDMETHOD(get_content)(IContent** pVal);
	STDMETHOD(get_date)(DATE* pVal);
	STDMETHOD(put_date)(DATE newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(Mail), CMail)
