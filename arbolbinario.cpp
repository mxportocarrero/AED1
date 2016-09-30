#include "arbolbinario.h"

template <class T>
void ArbolBinario<T>::begin()
{
    NodoAB<T> *q = m_pRoot;
    while(q->m_pSon[0])
    {
        m_Path.push(q);
        q = q->m_pSon[0];
    }
    m_Current = q;
}

template <class T>
bool ArbolBinario<T>::end()
{
    if (m_Current == nullptr) return true;
    return false;
}

template <class T>
void ArbolBinario<T>::operator++()
{
    NodoAB<T> *q = m_Current;
    if (q->m_pSon[1])
    {
        q = q->m_pSon[1];
        while (q->m_pSon[0])
        {
            m_Path.push(q);
            q = q->m_pSon[0];
        }
    }
    else
    {
        NodoAB<T> *p = m_Path.pop();
        while (!m_Path.empty() && q == p->m_pSon[1])
        {
            q = p;
            p = m_Path.pop();
        }
        q = p;
    }
    m_Current = q;
}

template <class T>
bool ArbolBinario<T>::Find(T d, NodoAB<T> **&p)
{
    p = &m_pRoot;
    while (*p)
    {
        if ((*p)->m_Dato == d) return true;
        p = &((*p)->m_pSon[(*p)->m_Dato < d]);
    }
}

template <class T>
void ArbolBinario<T>::AddNodo(T d)
{
    NodoAB<T> **q;
    if (Find(d, q)) return;
    *q = new NodoAB<T>(d);
}
