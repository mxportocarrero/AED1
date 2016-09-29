#include "listaenlazada.h"


void ListaEnlazada::pushBack(Palabra d)
{
    NodoLista *p = new NodoLista(d);
    if(!m_phead)
    {
        m_phead = p;
        m_plast = p;
    }
    else {
        m_plast->m_pSig = p;
        m_plast = p;
    }
}

bool ListaEnlazada::buscar(Palabra d)
{
    NodoLista *p = m_phead;
    while(p)
    {
        if(p->m_dato == d) return true;
        p = p->m_pSig;
    }
    return false;
}

