#include "palabra.h"

bool operator==(const Palabra &p1, const Palabra &p2)
{
    return (p1.idioma_1 == p2.idioma_1 || p1.idioma_2 == p2.idioma_2);
}

bool operator !=(const Palabra &p1, const Palabra &p2)
{
    return (p1.idioma_1 != p2.idioma_1);
}

bool operator>(const Palabra &p1, const Palabra &p2)
{
    return (p1.idioma_1 > p2.idioma_1);
}

bool operator<(const Palabra &p1, const Palabra &p2)
{
    return (p1.idioma_1 < p2.idioma_1);
}
