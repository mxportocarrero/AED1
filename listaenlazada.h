#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "nodolista.h"

class ListaEnlazada
{
private:
    NodoLista * m_phead;
    NodoLista * m_plast;
public:
    ListaEnlazada()
    {
        m_phead=nullptr;
        m_plast=nullptr;
    }
    void pushBack(Palabra d);
    Palabra buscar(Palabra d);
    bool isEmpty()
    {
        if (m_phead = m_plast = nullptr) return true;
        return false;
    }
    NodoLista * getHead()
    {
        return m_phead;
    }

};

#endif // LISTAENLAZADA_H
