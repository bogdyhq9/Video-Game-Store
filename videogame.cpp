#include"videogame.h"
#include<string.h>
#include<iostream>
using namespace std;
VideoGame :: VideoGame()
{
    this->cod=0;
    this->pret=0;
    this->nume=nullptr;
}
VideoGame :: VideoGame(int c,float p, char* n)
{
    this->cod=c;
    this->pret=p;
    this->nume=new char[strlen(n)+1];
    strcpy_s(this->nume,strlen(n)+1,n);
}
VideoGame ::VideoGame(const VideoGame &v)
{
    this->cod=v.cod;
    this->pret=v.pret;
    this->nume=new char[strlen(v.nume)+1];
    strcpy_s(this->nume,strlen(v.nume)+1,v.nume);
}
VideoGame::~VideoGame()
{
    if(this->nume)
    {
        delete[] this->nume;
        this->nume=nullptr;
    }
}
void VideoGame :: setpret(float p)
{
    this->pret=p;
}
void VideoGame :: setnume(char *n)
{
    if(this->nume)
        delete[] this->nume;
    this->nume = new char[strlen(n)+1];
    strcpy_s(this->nume,strlen(n)+1,n);
}
int VideoGame :: getcod()
{
    return this-> cod;
}
float VideoGame :: getpret()
{
    return this->pret;
}
char * VideoGame :: getnume()
{
    return this->nume;
}
VideoGame& VideoGame:: operator=(const VideoGame &v)
{
    this->setnume(v.nume);
    this->setpret(v.pret);
    this->cod=v.cod;
}
ostream& operator<<(ostream &os,VideoGame &v)
{
    cout<<"Cod "<<v.cod<<" Pret "<<v.pret<<" Nume "<<v.nume<<endl;
    return os;
}
