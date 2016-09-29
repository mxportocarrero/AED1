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

Palabra ListaEnlazada::buscar(Palabra d)
{
    NodoLista *p = m_phead;
    while(p)
    {
        if(p->m_dato == d) return p->m_dato;
        p = p->m_pSig;
    }
    Palabra vacia("","");
    return vacia;
}

