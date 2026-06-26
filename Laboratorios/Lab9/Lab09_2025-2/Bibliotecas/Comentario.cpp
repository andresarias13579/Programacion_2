#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Comentario.h"

Comentario::Comentario() {
}

Comentario::Comentario(const Comentario &com) {
    *this = com;
}

void Comentario::operator=(const Comentario &com) {
    comentario = com.comentario;
    canal = com.canal;
}

string Comentario::get_canal() const {
    return canal;
}

void Comentario::set_canal(const string &canal) {
    this->canal = canal;
}

string Comentario::get_comentario() const {
    return comentario;
}

void Comentario::set_comentario(const string &comentario) {
    this->comentario = comentario;
}

void Comentario::lee(ifstream &arch) {
    getline(arch,canal,',');
    if(arch.eof()) return;
    getline(arch,comentario,'\n');
}

void Comentario::imprime(ofstream &arch) const {
    arch<<comentario<<endl;
}

void operator>>(ifstream &arch, Comentario &com) {
    com.lee(arch);
}
void operator<<(ofstream &arch,const Comentario &com) {
    com.imprime(arch);
}

bool Comentario::operator<(const Comentario &com) {
    return canal < com.canal;
}
