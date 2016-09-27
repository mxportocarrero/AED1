#ifndef PALABRA_H
#define PALABRA_H

#include <string>
using std::string;
class Palabra
{
protected:
    string idioma_1, idioma_2;
public:
    friend bool operator == (const Palabra &p1,const Palabra &p2);
    friend bool operator != (const Palabra &p1,const Palabra &p2);
    friend bool operator > (const Palabra &p1,const Palabra &p2);
    friend bool operator >= (const Palabra &p1,const Palabra &p2);
    friend bool operator < (const Palabra &p1,const Palabra &p2);
    friend bool operator <= (const Palabra &p1,const Palabra &p2);
};

#endif // PALABRA_H
