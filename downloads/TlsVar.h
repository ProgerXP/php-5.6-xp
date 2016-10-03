#pragma once

typedef struct TLSVar
{
	int	m_isInitialized;
	DWORD	m_index;
} TLSVar;

int tls_init(TLSVar* tls);
int tls_finalize(TLSVar* tls);
int tls_set(TLSVar* tls, LPVOID val);
LPVOID tls_get(TLSVar* tls);
DWORD tls_get_index(TLSVar* tls);
