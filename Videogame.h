#ifndef VIDEOGAME_H_INCLUDED
#define VIDEOGAME_H_INCLUDED
#include "Civilizacion.h"
#include <iostream>
#include <vector>
using namespace std;
class Videogame
{
private:
    std::string NickName;
    std::vector<Civilizacion> civilizaciones;

public:
    Videogame();
    Videogame(const std::string &);

    void show();
    void addCivilization(const Civilizacion &c);

    void backup();
    void recover();
    void insertX(const Civilizacion &c, size_t p);
    void start(const Civilizacion &c, size_t n);
    void erase(size_t x);
    void sortName();
    void sortX();
    void sortY();
    void sortPunt();
    void last();
    void first();
    size_t size();

    Civilizacion *work(const Civilizacion &);
    Civilizacion *findex(const Civilizacion &);
    
    friend Videogame &operator<<(Videogame &vid, const Civilizacion &c)
    {
        vid.addCivilization(c);
        return vid;
    }
};

#endif