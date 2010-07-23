// Content.h : CContent ������

#pragma once
#include "resource.h"       // ������

#include "tmailx.h"
#include "../../src/content.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CContent

class ATL_NO_VTABLE CContent :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CContent, &CLSID_Content>,
	public ISupportErrorInfo,
	public IDispatchImpl<IContent, &IID_IContent, &LIBID_TMail, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CContent()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CONTENT)


BEGIN_COM_MAP(CContent)
	COM_INTERFACE_ENTRY(IContent)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		content = tmail::ContentPtr(new tmail::Content);
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(parse)(SAFEARRAY* data, VARIANT_BOOL only_headers);
	STDMETHOD(save)(BSTR filename);
	STDMETHOD(load)(BSTR filename, VARIANT_BOOL only_header);
	STDMETHOD(setBodyText)(BSTR text);
	STDMETHOD(loadBody)(BSTR filename);
	STDMETHOD(get_headers)(IHeaders** pVal);
	STDMETHOD(get_body)(SAFEARRAY** pVal);
	STDMETHOD(put_body)(SAFEARRAY* newVal);
	STDMETHOD(getBodyText)(BSTR* pVal);
	STDMETHOD(saveBody)(BSTR filename);
	STDMETHOD(get_multiparts)(IContents** pVal);
	STDMETHOD(createAlternativeBody)(BSTR text, BSTR html, VARIANT attachments);
	STDMETHOD(createTextBody)(BSTR text, VARIANT attachments);
	STDMETHOD(createHtmlBody)(BSTR html, VARIANT attachments);
	STDMETHOD(createRelatedBody)(BSTR html, VARIANT pictures, 
		VARIANT attachments, VARIANT_BOOL use_cid);

	STDMETHOD(createAlternativeBodyF)(BSTR textFile, BSTR html, VARIANT attachments);
	STDMETHOD(createTextBodyF)(BSTR textFile, VARIANT attachments);
	STDMETHOD(createHtmlBodyF)(BSTR htmlFile, VARIANT attachments);
	STDMETHOD(createRelatedBodyF)(BSTR htmlFile, VARIANT pictures, 
		VARIANT attachments, VARIANT_BOOL use_cid);

public:
	tmail::ContentPtr content;
	
	STDMETHOD(generateId)(void);
	STDMETHOD(get_contentType)(BSTR* pVal);
	STDMETHOD(get_filename)(BSTR* pVal);
	STDMETHOD(get_extname)(BSTR* pVal);
};

OBJECT_ENTRY_AUTO(__uuidof(Content), CContent)
