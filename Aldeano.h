#ifndef ALDEANO_H_INCLUDED
#define ALDEANO_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <iomanip>

using namespace std;

class Aldeano
{
private:
    std::string nombre;
    std::string genero;
    int edad;
    int salud;

public:
    Aldeano(/* args */);
    Aldeano(const string &n, const string &g, const int &e, const int s);

    void setNombre(const string &);
    void setGenero(const string &);
    void setEdad(const int &);
    void setSalud(const int &);

    std::string getNombre() const;
    std::string getGenero() const;
    int getEdad() const;
    size_t getSalud() const;

    friend std::ostream &operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(15) << a.nombre << "||";
        out << setw(20) << a.genero << "||";
        out << setw(15) << a.edad << "||";
        out << setw(15) << a.salud << "||";
        return out;
    }
    //ya es costumbre sobrecargar esta madre jajatl
    friend std::istream &operator>>(std::istream &in, Aldeano &a)
    {
        string temp;

        cout << "Nombre: " << endl;
        getline(cin, a.nombre);

        cout << "Genero: " << endl;
        getline(cin, a.genero);

        cout << "Edad:" << endl;
        cin >> a.edad;

        cout << "Salud: " << endl;
        fflush(stdin);
        cin >> a.salud;

        return in;
    }

    bool operator<(const Aldeano &a)
    {
        return nombre < a.getNombre();
    }
    bool operator>(const Aldeano &a)
    {
        return edad > a.getEdad();
    }


};

#endif