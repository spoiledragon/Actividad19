#include "Civilizacion.h"
#include <stdio.h>
#include <string>
using namespace std;
Civilizacion::Civilizacion() : puntuacion(0) {}
Civilizacion::Civilizacion(const string &n, const int &x, const int &y, const int &p)
{
    Nombre = n;
    PosX = x;
    PosY = y;
    puntuacion = p;
}

void Civilizacion::setNombre(const string &n) { Nombre = n; }
void Civilizacion::setPosX(const int &x) { PosX = x; }
void Civilizacion::setPosY(const int &y) { PosY = y; }
void Civilizacion::setPuntuacion(const int &p) { puntuacion = p; }

void Civilizacion::addEnd(const Aldeano &a)
{
    Aldeanos.push_back(a);
}
void Civilizacion::addStart(const Aldeano &a)
{
    Aldeanos.push_front(a);
}

string Civilizacion::getNombre() { return Nombre; }
int Civilizacion::getPosX() { return PosX; }
int Civilizacion::getPosY() { return PosY; }
int Civilizacion::getPuntuacion() { return puntuacion; }

//acrividad 18
void Civilizacion::print()
{
    if(Aldeanos.size()==0){
        cout<<"Sin aldeanos Agregados"<<endl;
        return;
    }
    cout << left;
    cout << setw(15) << "Nombre"
         << "||";
    cout << setw(20) << "Pos X"
         << "||";
    cout << setw(15) << "Pos Y"
         << "||";
    cout << setw(15) << "Puntuacion"
         << "||" << endl;

    cout << setw(15) << getNombre() << "||";
    cout << setw(20) << getPosX() << "||";
    cout << setw(15) << getPosY() << "||";
    cout << setw(15) << getPuntuacion() << "||" << endl;
    for (int i = 0; i < 73; i++)
    {
        printf("%c", 203);
    }
    cout << endl;
    cout << setw(15) << "Nombre"
         << "||";
    cout << setw(20) << "Raza"
         << "||";
    cout << setw(15) << "Edad"
         << "||";
    cout << setw(15) << "Salud"
         << "||" << endl;

    for (auto it = Aldeanos.begin(); it != Aldeanos.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;
}

void Civilizacion::deleted(const string &b)
{
    for (auto it = Aldeanos.begin(); it != Aldeanos.end(); it++)
    {
        Aldeano &a = *it;
        if (b == a.getNombre())
        {
            Aldeanos.erase(it);
            return;
        }
    }
    cout << "No se encontro tu Elemento intenta con otro" << endl;
}

void Civilizacion::deletedHeal(const size_t &s)
{
    Aldeanos.remove_if([s](const Aldeano &a) { return a.getSalud() <= s; });
}

void Civilizacion::deletedHeal()
{
    Aldeanos.remove_if([](const Aldeano &a) { return a.getEdad() >= 60; });
}

bool comparatorAge(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getEdad() > a2.getEdad();
}
bool comparatorHealth(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getSalud() > a2.getSalud();
}
void Civilizacion::sortName()
{
    Aldeanos.sort();
}
void Civilizacion::sortAge()
{
    Aldeanos.sort(comparatorAge);
}
void Civilizacion::sortHealth()
{
    Aldeanos.sort(comparatorHealth);
}

void Civilizacion::search(const string &s)
{
    for (auto it = Aldeanos.begin(); it != Aldeanos.end(); it++)
    {
        Aldeano &a = *it;
        if (s == a.getNombre())
        {
            cout << a << endl;
            return;
        }
    }
    cout << "No se encontro tu Elemento intenta con otro" << endl;
}

void Civilizacion::modified(const string &s)
{
    for (auto it = Aldeanos.begin(); it != Aldeanos.end(); it++)
    {
        Aldeano &a = *it;
        if (s == a.getNombre())
        {
            cout << *it;
            int opc2;
            string temp;
            int tempo;
            while (true)
            {
                cout << endl;
                cout << "1). Modificar el Nombre" << endl;
                cout << "2). Modificar el Genero" << endl;
                cout << "3). Modificar la Edad" << endl;
                cout << "4). Modificar la Salud" << endl;
                cout << "5). Salir" << endl;
                cin >> opc2;
                switch (opc2)
                {
                case 1:
                    cout << "Inserte el nuevo Nombre" << endl;
                    fflush(stdin);
                    getline(cin, temp);
                    it->setNombre(temp);
                    break;
                case 2:
                    cout << "Inserte el nuevo Genero" << endl;
                    fflush(stdin);
                    getline(cin, temp);
                    it->setGenero(temp);
                    break;
                case 3:
                    cout << "Inserte la Nueva Edad" << endl;
                    fflush(stdin);
                    cin >> tempo;
                    it->setEdad(tempo);
                    break;
                case 4:
                    cout << "Inserte la Nueva Salud" << endl;
                    fflush(stdin);
                    cin >> tempo;
                    it->setSalud(tempo);
                    break;
                case 5:
                    return;
                    break;
                default:
                    cout << "opcion invalida";
                    break;
                }
            }

            return;
        }
    }
    cout << "No se encontro tu Elemento intenta con otro" << endl;
}

void Civilizacion::respaldar_Aldeanos()
{
    ofstream aldeanos(getNombre() + ".txt");

    for (auto it = Aldeanos.begin(); it != Aldeanos.end(); ++it)
    {
        Aldeano &aldeano = *it;
        aldeanos << aldeano.getNombre() << endl;
        aldeanos << aldeano.getEdad() << endl;
        aldeanos << aldeano.getGenero() << endl;
        aldeanos << aldeano.getSalud() << endl;
    }
    aldeanos.close();
}
void Civilizacion::recuperar_Aldeanos()
{
    ifstream archivo(getNombre() + ".txt");
    if (archivo.is_open())
    {
        string temporal;
        Aldeano c;

        while (true)
        {
            getline(archivo, temporal);

            if (archivo.eof())
            {
                break;
            }
            c.setNombre(temporal);

            getline(archivo,temporal);
            c.setEdad(stoi(temporal));

            getline(archivo, temporal);
            c.setGenero(temporal);

            getline(archivo, temporal);
            c.setSalud(stoi(temporal));

            addEnd(c);
        }
    }

    archivo.close();
}

size_t Civilizacion::contador(){
    return Aldeanos.size();
}
