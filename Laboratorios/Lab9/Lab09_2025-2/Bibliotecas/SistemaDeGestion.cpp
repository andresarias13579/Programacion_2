#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iterator>
#include <fstream>

using namespace std;
#include <list>
#include <map>
#include "SistemaDeGestion.h"

void SistemaDeGestion::cargarCategorias(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    Categoria cat;
    while (true) {
        arch>>cat;
        if (arch.eof()) break;
        categorias.push_back(cat);
    }
    categorias.sort();
}

void SistemaDeGestion::cargarComentarios(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    Comentario com;
    while (true) {
        arch>>com;
        if (arch.eof()) break;
        comentarios.push_back(com);
    }
    comentarios.sort();
}

void SistemaDeGestion::cargarEtiquetas(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    Etiqueta eti;
    while (true) {
        arch>>eti;
        if (arch.eof()) break;
        etiquetas[eti.get_codigo()] = eti;
    }
}

void SistemaDeGestion::cargarStreamers(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    Streamer st;
    while (true) {
        arch>>st;
        if (arch.eof()) break;
        streamers.push_back(st);
    }
    streamers.sort();
}

void SistemaDeGestion::completarStreamers() {
    for (Streamer &st : streamers) {

        // Completar categoría
        for (Categoria &cat : categorias) {
            if (cat.get_codigo() == st.get_categoria().get_codigo()) {
                st.set_categoria(cat);
                break;
            }
        }

        // Completar etiquetas
        vector<Etiqueta> vecEtiquetas;
        string cod;

        for (char c : st.get_etiquetas_str()) {
            if (c == '-') {
                vecEtiquetas.push_back(etiquetas[cod]);
                cod.clear();
            }
            else
                cod += c;
        }

        if (!cod.empty())
            vecEtiquetas.push_back(etiquetas[cod]);

        st.set_etiquetas_vector(vecEtiquetas);

        // Completar comentarios
        vector<string> vecComentarios;

        for (Comentario &com : comentarios) {
            if (com.get_canal() == st.get_canal())
                vecComentarios.push_back(com.get_comentario());
        }

        st.set_comentarios(vecComentarios);
    }
}

void SistemaDeGestion::reporteStreamers(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    arch<<setfill('=')<<setw(200)<<"="<<setfill(' ')<<endl;
    arch<<setw(100)<<"REPORTE DE STREAMERS"<<endl;
    arch<<setfill('-')<<setw(200)<<"-"<<setfill(' ')<<endl;
    for (const Streamer &st : streamers) {
        arch<<st;
        arch<<setfill('-')<<setw(200)<<"-"<<setfill(' ')<<endl;
    }
}

void SistemaDeGestion::eliminarStreamers(string idioma) {
    for (list <Streamer>::iterator it = streamers.begin(); it != streamers.end(); ) {
        if (it->get_idioma() == idioma ) it = streamers.erase(it);
        else ++it;
    }
}
