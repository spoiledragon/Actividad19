#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <istream>
#include <list>
#include "Aldeano.h"

using namespace std;
class Civilizacion
{
private:
    std::string Nombre;
    int PosX;
    int PosY;
    int puntuacion;
    list<Aldeano> Aldeanos;

public:
    Civilizacion();
    Civilizacion(const std::string &, const int &, const int &, const int &);

    void setNombre(const std::string &);
    void setPosY(const int &);
    void setPosX(const int &);
    void setPuntuacion(const int &);
    //añadir
    void addEnd(const Aldeano &a);
    void addStart(const Aldeano &a);

    void print();
    //borrar por edad en especifico o general
    void deleted(const string &b);
    void deletedHeal(const size_t &s);
    void deletedHeal();

    //organizar
    void sortName();
    void sortAge();
    void sortHealth();
    void modified(const string& s);

    //buscar
    void search(const string& s);

    std::string getNombre();
    int getPosX();
    int getPosY();
    int getPuntuacion();

    void respaldar_Aldeanos();
    void recuperar_Aldeanos();

    size_t contador();
    

    friend std::istream &operator>>(std::istream &in, Civilizacion &c)
    {
        string temp;

        cout << "Nombre: " << endl;
        getline(cin, c.Nombre);

        cout << "Posicion X : " << endl;
        cin >> c.PosX;

        cout << "Posicion Y" << endl;
        cin >> c.PosY;

        cout << "Puntuacion: " << endl;
        fflush(stdin);
        cin >> c.puntuacion;
        return in;
    }
        friend std::ostream &operator<<(std::ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(20) << c.Nombre << "||";
        out << setw(20) << c.PosX << "||";
        out << setw(20) << c.PosY << "||";
        out << setw(20) << c.puntuacion << "||";
        return out;
    }

    bool operator==(const Civilizacion &c)
    {
        return Nombre == c.Nombre;
    }
    bool operator==(const Civilizacion &c) const
    {
        return Nombre == c.Nombre;
    }

    Civilizacion& operator =(const Civilizacion c1){
        
    }


};

#endif