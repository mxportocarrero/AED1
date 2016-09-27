#include "palabra.h"



bool Palabra::operator ==(const Palabra &p1, const Palabra &p2)
{
    return p1.idioma_1 == p2.idioma_1;
}

bool Palabra::operator !=(const Palabra &p1, const Palabra &p2)
{
    return p1.idioma_1 != p2.idioma_1;
}

bool Palabra::operator >(const Palabra &p1, const Palabra &p2)
{
    return p1.idioma_1 > p2.idioma_1;
}

bool Palabra::operator >=(const Palabra &p1, const Palabra &p2)
{
    return p1.idioma_1 >= p2.idioma_1;
}

bool Palabra::operator <(const Palabra &p1, const Palabra &p2)
{
    return p1.idioma_1 < p2.idioma_1;
}

bool Palabra::operator <=(const Palabra &p1, const Palabra &p2)
{
    return p1.idioma_1 <= p2.idioma_1;
}

