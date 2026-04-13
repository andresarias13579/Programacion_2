
#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

void operator +=(struct Persona &persona, double porc);

// void operator <<(ostream &out,const struct Persona &persona);
ostream &operator <<(ostream &out,const struct Persona &persona);

#endif //SOBRECARGAS_H
