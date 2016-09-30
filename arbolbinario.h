#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <QStack>
#include "nodoab.h"

template <class T>
class ArbolBinario
{
private:
    NodoAB<T> *m_pRoot;
    QStack<NodoAB<T>*> m_Path;
    NodoAB<T> *m_Current;
public:
    ArbolBinario()
    {
        m_pRoot = m_Current = nullptr;
        m_Path = new QStack<NodoAB<T>*>();
    }
    ~ArbolBinario()
    {
        if (m_pRoot) m_pRoot->KillNodo();
    }
    void begin();
    bool end();
    void operator++();
    bool Find(T d, NodoAB<T> **&p);
    void AddNodo(T d);
};

#endif // ARBOLBINARIO_H
