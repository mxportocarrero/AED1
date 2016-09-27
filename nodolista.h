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
        m_dato.idioma_1 = d.idioma_1;
        m_dato.idioma_2 = d.idioma_2;
    }

    NodoLista(string a, string b)
    {
        m_dato.idioma_1 = a;
        m_dato.idioma_2 = b;
    }
};

#endif // NODOLISTA_H
