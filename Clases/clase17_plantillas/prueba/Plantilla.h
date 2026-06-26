//
// Created by Andres on 25/06/2026.
//

#ifndef PRUEBA_PLANTILLA_H
#define PRUEBA_PLANTILLA_H
#include <iostream>

template <typename T>
class Plantilla {
private:
    T dato;
public:
    T get_dato() const;
    void set_dato(const T &dato);
    void leeDato();
    void imprimirDato();
};

template<typename T>
T Plantilla<T>::get_dato() const {
    return dato;
}

template<typename T>
void Plantilla<T>::set_dato(const T &dato) {
    this->dato = dato;
}

template<typename T>
void Plantilla<T>::leeDato() {
    cin >> dato;
}

template<typename T>
void Plantilla<T>::imprimirDato() {
    cout << dato;
    cout<<endl;
}

#endif //PRUEBA_PLANTILLA_H
