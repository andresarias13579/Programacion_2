#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
#include <vector>
#include "Categoria.h"
#include "Etiqueta.h"
#include "Streamer.h"

Streamer::Streamer() {
}

Streamer::Streamer(const Streamer &st) {
    *this = st;
}
void Streamer::operator=(const Streamer &st) {
    canal = st.canal;
    fecha = st.fecha;
    categoria = st.categoria;
    etiquetasStr = st.etiquetasStr;
    etiquetasVector = st.etiquetasVector;
    idioma = st.idioma;
    comentarios = st.comentarios;
}

string Streamer::get_canal() const {
    return canal;
}

void Streamer::set_canal(const string &canal) {
    this->canal = canal;
}

int Streamer::get_fecha() const {
    return fecha;
}

void Streamer::set_fecha(const int fecha) {
    this->fecha = fecha;
}

Categoria Streamer::get_categoria() const {
    return categoria;
}

void Streamer::set_categoria(const Categoria &categoria) {
    this->categoria = categoria;
}

string Streamer::get_etiquetas_str() const {
    return etiquetasStr;
}

void Streamer::set_etiquetas_str(const string &etiquetas_str) {
    etiquetasStr = etiquetas_str;
}

vector<Etiqueta> Streamer::get_etiquetas_vector() const {
    return etiquetasVector;
}

void Streamer::set_etiquetas_vector(const vector<Etiqueta> &etiquetas_vector) {
    etiquetasVector = etiquetas_vector;
}

string Streamer::get_idioma() const {
    return idioma;
}

void Streamer::set_idioma(const string &idioma) {
    this->idioma = idioma;
}

vector<string> Streamer::get_comentarios() const {
    return comentarios;
}

void Streamer::set_comentarios(const vector<string> &comentarios) {
    this->comentarios = comentarios;
}

void Streamer::lee(ifstream &arch) {
    getline(arch, canal,',');
    if (arch.eof()) return;
    int dd, mm,aa;
    char c;
    arch >> dd>>c >> mm>>c >> aa>>c;
    fecha = aa*10000 + mm*100 + dd;
    string catego;
    getline(arch, catego,',');
    categoria.set_codigo(catego);
    getline(arch,etiquetasStr,',');
    getline(arch,idioma,'\n');
}

void Streamer::imprimir(ofstream &arch) const {
    arch<<"CANAL: "<<canal<<endl;
    arch<<"FECHA: "<<fecha<<endl;
    arch<<"LENGUAJE: "<<idioma<<endl;
    categoria.imprime(arch);
    arch<<"ETIQUETAS STR: "<<etiquetasStr<<endl;
    arch<<"ETIQUETAS:"<<endl;
    int i=1;
    for (Etiqueta e : etiquetasVector) {
        arch<<i<<")";
        e.imprime(arch);
        i++;
    }
    arch<<"COMENTARIOS:"<<endl;
    int j=1;
    for (string c : comentarios) {
        arch<<j<<")";
        arch<<c<<endl;
        j++;
    }
}

void operator>>(ifstream &arch, Streamer &st) {
    st.lee(arch);
}

void operator<<(ofstream &arch, const Streamer &st) {
    st.imprimir(arch);
}

bool Streamer::operator<(const Streamer &st) {
    return categoria.get_codigo() < st.categoria.get_codigo() or
        (categoria.get_codigo() == st.categoria.get_codigo() and  fecha < st.fecha);
}
