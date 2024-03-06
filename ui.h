#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include"service.h"
class UI{
private:
    Service s;
public:
    UI();
    UI(const Service &s);
    ~UI();
    void adaugare();
    void modificare();
    void stergere();
    vector<VideoGame> getall();
    void printmeniu();
    void runmeniu();
    void afisare(vector<VideoGame> v);
    void pretmaimare();
    void intervalpret();
    void cautaredupanume();
};

#endif // UI_H_INCLUDED
