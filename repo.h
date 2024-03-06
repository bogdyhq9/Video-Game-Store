#ifndef REPO_H_INCLUDED
#define REPO_H_INCLUDED
#include <vector>
#include"videogame.h"
#include<iostream>
using namespace std;
class Repo{
private:
    vector<VideoGame>games;
public:
    Repo();
    ~Repo();
    void adaugare(VideoGame &v);
    void modifica(int poz,VideoGame &v);
    vector<VideoGame> getall();
    void sterge(int poz);
    int getsize();

};


#endif // REPO_H_INCLUDED
