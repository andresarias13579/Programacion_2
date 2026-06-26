//
// Created by Andres on 25/06/2026.
//

#ifndef LISTA_CON_PLANTILLAS_PLNODO_H
#define LISTA_CON_PLANTILLAS_PLNODO_H
template <typename T> class PlLista;

template <typename T>
class PlNodo {
private:
    T dato;
    PlNodo<T> *siguiente;
    friend class PlLista<T>;
public:
    PlNodo();
    void inicializa();
};

template <typename T>
PlNodo<T>::PlNodo() {
    inicializa();
}
template <typename T>
void PlNodo<T>::inicializa() {
    siguiente = nullptr;
}

#endif //LISTA_CON_PLANTILLAS_PLNODO_H
