#ifndef PALABRALISTA_H
#define PALABRALISTA_H

#include <string>
#include "palabra.h"
using std::string;

class PalabraLista: public Palabra
{
private:
    PalabraLista * m_pSig;
public:
    PalabraLista(string a, string b)
    {
        idioma_1 = a;
        idioma_2 = b;
        m_pSig = nullptr;
    }
};

#endif // PALABRALISTA_H
