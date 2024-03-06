#include"service.h"
#include"exception.h"
#include"filerepo.h"
#include<string.h>
#include"validator.h"
bool verif(string s)
{
    for(char c: s)
        if(!isdigit(c))
            return false;
    return true;
}
Service :: Service()
{
    this->r=FileRepo();
}
Service :: Service(const FileRepo  &repo)
{
    this->r=repo;
}
Service :: ~Service(){}
void Service :: adaugare(string cod,string pret,char* nume)
{
    int cod1;
    float pret1;
    //strcpy_s(nume1,strlen(nume)+1,nume);
    if(!verif(cod))
        throw MyException("Codul trebuie sa fie numar");
    cod1 = stoi(cod);
    if(!verif(pret))
        throw MyException("Pretul trebuie sa fie numar");
    pret1 = stof(pret);

    VideoGame v(cod1, pret1, nume);
    Validator validator;
    validator.valideaza(v);
    this->r.adaugare(v);
}
void Service :: modifica(string poz,string cod,string pret,char* nume)
{
    int cod1,poz1;
    float pret1;
    if(!verif(poz))
        throw MyException("Pozitia trebuie sa fie numar");
    poz1=stoi(poz);
    //strcpy_s(nume1,strlen(nume)+1,nume);
    if(!verif(cod))
        throw MyException("Codul trebuie sa fie numar");
    cod1 = stoi(cod);
    if(!verif(pret))
        throw MyException("Pretul trebuie sa fie numar");
    pret1 = stof(pret);
    if(poz1<=this->getsize())
    {
        VideoGame v(cod1,pret1,nume);
        this->r.modifica(poz1,v);
    }

}
void Service :: sterge(string poz)
{
    int poz1;
    if(!verif(poz))
        throw MyException("Pozitia trebuie sa fie numar");
    poz1=stoi(poz);
    if(poz1<=this->getsize())
    this->r.sterge(poz1-1);
}
vector<VideoGame> Service ::getall()
{
    return this->r.getall();
}
int Service :: getsize()
{
    return this->r.getsize();
}
vector<VideoGame> Service :: pretmaimare(string p)
{
    float p1;
    if(!verif(p))
        throw MyException("Pretul trebuie sa fie numar");
    p1=stof(p);
    vector<VideoGame> filter;
    vector<VideoGame> jocuri=this->getall();
    for (int i=0;i<this->getsize();i++)
    {
        if(jocuri[i].getpret()>p1)
            filter.push_back(jocuri[i]);
    }
    return filter;
}
vector<VideoGame> Service ::intervalpret(string p1,string p2)
{
    float pret1,pret2;
    if(!verif(p1))
        throw MyException("Primul pret trebuie sa fie numar");
    pret1=stof(p1);
    if(!verif(p2))
        throw MyException("Al doilea pret trebuie sa fie numar");
    pret2=stof(p2);
    if(pret1>pret2)
    {
        float aux;
        aux=pret1;
        pret1=pret2;
        pret2=aux;
    }
    vector<VideoGame> filter;
    vector<VideoGame> jocuri=this->getall();
    for (int i=0;i<this->getsize();i++)
    {
        if(jocuri[i].getpret()>pret1 && jocuri[i].getpret()<pret2)
            filter.push_back(jocuri[i]);
    }
    return filter;
}
VideoGame Service ::cautaredupanume(char * n)
{
    vector<VideoGame> jocuri = this->getall();
    for (int i = 0; i < jocuri.size(); i++)
    {
        if (strcmp(jocuri[i].getnume(), n) == 0)
        {
            return jocuri[i];
        }
    }

    return VideoGame(0, 0, NULL);
}
