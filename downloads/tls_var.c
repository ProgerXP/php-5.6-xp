#include <windows.h>
#include "TLSVar.h"

int tls_init(TLSVar* tls)
{
	if (tls->m_isInitialized)
	{
		return 0;
	}
	tls->m_index = TlsAlloc();
	tls->m_isInitialized = !(tls->m_index == TLS_OUT_OF_INDEXES);
	return tls->m_isInitialized;
}

int tls_finalize(TLSVar* tls)
{
	DWORD index = tls->m_index;
	tls->m_index = 0;
	tls->m_isInitialized = 0;
	return !(TlsFree(index) == 0);
}

int tls_set(TLSVar* tls, LPVOID val)
{
	if (tls->m_index == 0)
	{
		return 0;
	}
	return !(TlsSetValue(tls->m_index, val) == 0);
}

LPVOID tls_get(TLSVar* tls)
{
	if (tls->m_index == 0)
	{
		return NULL;
	}
	return TlsGetValue(tls->m_index);
}

DWORD tls_get_index(TLSVar* tls)
{
	return tls->m_index;
}
