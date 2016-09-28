#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "palabra.h"
#include <string>
using std::string;

class NodoLista
{
public:
    Palabra m_dato;
    NodoLista * m_pSig;
public:
    NodoLista(Palabra d)
    {
        m_dato = d;
    }

    NodoLista(string a, string b)
    {
        Palabra p(a,b);
        m_dato = p;
    }
};

#endif // NODOLISTA_H
