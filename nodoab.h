#ifndef NODOAB_H
#define NODOAB_H

template <class T>
class NodoAB
{
public:
    T m_Dato;
    NodoAB<T> *m_pSon[2];
public:
    NodoAB(T d)
    {
        m_Dato = d;
        m_pSon[0] = m_pSon[1] = nullptr;
    }
    void KillNodo()
    {
        if (m_pSon[0]) m_pSon[0]->KillNodo();
        if (m_pSon[1]) m_pSon[1]->KillNodo();
        delete this;
    }
};

#endif // NODOAB_H
