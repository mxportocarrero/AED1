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
    bool buscar(Palabra d);
};

#endif // LISTAENLAZADA_H
