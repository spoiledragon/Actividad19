#include "Aldeano.h"
using namespace std;
Aldeano::Aldeano() {}

Aldeano::Aldeano(const string &n, const string &g, const int &e, const int s)
{
    nombre = n;
    genero = g;
    edad = e;
    salud = s;
}
//setters
void Aldeano::setNombre(const string &s) { nombre = s; }
void Aldeano::setGenero(const string &s) { genero = s; }
void Aldeano::setEdad(const int &i) { edad = i; }
void Aldeano::setSalud(const int &i) { salud = i; }

//Getters
string Aldeano::getNombre() const { return nombre; }
string Aldeano::getGenero() const { return genero; }
int Aldeano::getEdad() const { return edad; }
size_t Aldeano::getSalud() const { return salud; }

