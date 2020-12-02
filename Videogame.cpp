#include "Videogame.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

Videogame::Videogame() {}
Videogame::Videogame(const std::string &n)
{
    NickName = n;
}

void Videogame::addCivilization(const Civilizacion &c) { civilizaciones.push_back(c); }

void Videogame::insertX(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin() + pos, c);
}
void Videogame::show()
{
    //encabezado
    cout << "El jugador" << NickName << " Posee :" << civilizaciones.size() << " Civilizaciones" << endl;
    ;
    cout << left;
    cout << setw(20) << "Nombre"
         << "||";
    cout << setw(20) << "Posicion X"
         << "||";
    cout << setw(20) << "Posicion Y"
         << "||";
    cout << setw(20) << "Puntuacion"
         << "||" << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout << c << endl;
    }
}

void Videogame::backup()
{
    ofstream archivo("Civilizaciones.txt");
    if (archivo.is_open())
    {

        for (int i = 0; i < civilizaciones.size(); i++)
        {
            Civilizacion &c = civilizaciones[i];
            archivo << c.getNombre() << endl;
            archivo << c.getPosX() << endl;
            archivo << c.getPosY() << endl;
            archivo << c.getPuntuacion() << endl;

            auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
            if (it == civilizaciones.end())
            {
                return;
            }
            else
            {
                it->respaldar_Aldeanos();
            }
        }
    }

    archivo.close();
}

void Videogame::recover()
{
    ifstream archivo("Civilizaciones.txt");
    if (archivo.is_open())
    {
        string temporal;
        int x;

        Civilizacion c;

        while (true)
        {
            getline(archivo, temporal);

            if (archivo.eof())
            {
                break;
            }
            c.setNombre(temporal);

            getline(archivo, temporal);
            x = stoi(temporal); //string a entero
            c.setPosX(x);

            getline(archivo, temporal);
            x = stoi(temporal); //string a entero
            c.setPosY(x);

            getline(archivo, temporal);
            x = stoi(temporal); //string a entero
            c.setPuntuacion(x);

            addCivilization(c);

            auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
            if (it == civilizaciones.end())
            {
                return;
            }
            else
            {
                it->recuperar_Aldeanos();
            }
        }
    }

    archivo.close();
}

void Videogame::erase(size_t p)
{
    civilizaciones.erase(civilizaciones.begin() + p);
}

void Videogame::start(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void Videogame::sortName()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getNombre() < c2.getNombre(); });
}
void Videogame::sortX()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPosX() < c2.getPosX(); });
}
void Videogame::sortY()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPosY() < c2.getPosY(); });
}
void Videogame::sortPunt()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPuntuacion() < c2.getPuntuacion(); });
}

Civilizacion *Videogame::findex(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        //accede a la direccion de memoria y me regresa desreferenciandola
        return &(*it);
    }
}

Civilizacion *Videogame::work(const Civilizacion &c)
{

    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        //accede a la direccion de memoria y me regresa desreferenciandola
        system("CLS");
        //Aqui empieza el menu
        string opc;
        while (true)
        {
            cout << "1) Agregar Aldeanos" << endl;
            cout << "2) Mostrar Aldeanos" << endl;
            cout << "3) borrar" << endl;
            cout << "4) ordenar" << endl;
            cout << "5) buscar" << endl;
            cout << "6) Modificar" << endl;
            cout << "7) Respaldar Aldeanos" << endl;
            cout << "8) Recuperar Aldeanos" << endl;
            cout << "0) Salir" << endl;
            cin >> opc;
            fflush(stdin);

            if (opc == "1")
            {
                Aldeano temp;
                cin >> temp;
                int opc2;
                cout << endl
                     << "1). Insertar al inicio" << endl
                     << "2). Insertar al final";
                cin >> opc2;
                switch (opc2)
                {
                case 1:
                    it->addStart(temp);
                    it->setPuntuacion(it->getPuntuacion() + 100);
                    break;
                case 2:
                    it->addEnd(temp);
                    it->setPuntuacion(it->getPuntuacion() + 100);
                    break;
                default:
                    break;
                }
            }
            else if (opc == "2")
            {
                it->print();
            }
            else if (opc == "3")
            {
                Aldeano temp;
                string name;
                int opc2;
                size_t salute;
                cout << "1). Borrar por Nombre" << endl;
                cout << "2). Borrar por Salud" << endl;
                cout << "3). Borrar por edad" << endl;
                cin >> opc2;
                switch (opc2)
                {
                case 1:

                    cout << "Inserta el nombre a buscar" << endl;
                    cin >> name;
                    it->deleted(name);
                    break;
                case 2:
                    cout << "Inserte la salud minima para los Aldeanos" << endl;
                    cin >> salute;
                    it->deletedHeal(salute);
                    fflush(stdin);
                    break;
                case 3:
                    it->deletedHeal();
                    break;
                default:

                    break;
                }
            }

            else if (opc == "4")
            {
                if (it->contador() == 0)
                {
                    cout << "Sin aldeanos " << endl;
                    break;
                }
                int opc2;
                cout << "1). Ordenar por Nombre" << endl;
                cout << "2). Ordenar por Salud" << endl;
                cout << "3). Ordenar por edad" << endl;
                cin >> opc2;
                switch (opc2)
                {
                case 1:
                    it->sortName();
                    break;
                case 2:
                    it->sortHealth();
                    break;
                case 3:
                    it->sortAge();
                    break;
                default:

                    break;
                }
            }
            else if (opc == "5")
            {
                string temp;
                cout << "Inserte el nombre a buscar" << endl;
                getline(cin, temp);
                it->search(temp);
            }

            else if (opc == "6")
            {
                string temp;
                cout << "Inserte el nombre a Modiicar" << endl;
                getline(cin, temp);
                it->modified(temp);
            }
            else if (opc == "7")
            {
                it->respaldar_Aldeanos();
            }

            else if (opc == "8")
            {
                it->recuperar_Aldeanos();
            }

            else if (opc == "0")
            {
                break;
            }
        }
        //aqui termina

        //it->recuperar_Aldeanos();
    }
}

void Videogame::last()
{
    size_t ultimo = size();
    Civilizacion &c = civilizaciones[ultimo - 1];
    //cout << c << endl;
    c.print();
}
void Videogame::first()
{
    Civilizacion &c = civilizaciones[0];
    //cout << c << endl;
    c.print();
}

size_t Videogame::size() { return civilizaciones.size(); }
