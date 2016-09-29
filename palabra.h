#ifndef PALABRA_H
#define PALABRA_H

#include <string>
using std::string;
class Palabra
{
protected:
    string idioma_1, idioma_2;
public:
    Palabra ()
    {
        idioma_1 = "";
        idioma_2 = "";
    }
    Palabra (string a, string b)
    {
        idioma_1 = a;
        idioma_2 = b;
    }
    friend bool operator == (const Palabra &p1,const Palabra &p2);
    friend bool operator != (const Palabra &p1,const Palabra &p2);
    friend bool operator > (const Palabra &p1,const Palabra &p2);
    friend bool operator < (const Palabra &p1,const Palabra &p2);
    string getString()
    {
        return idioma_1;
    }
    string getString2()
    {
        return idioma_2;
    }
};

#endif // PALABRA_H
