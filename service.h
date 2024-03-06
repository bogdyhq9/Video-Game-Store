#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
//#include"repo.h"
#include"filerepo.h"
class Service{
private:
    FileRepo r;
public:
    Service();
    Service(const FileRepo &r);
    ~Service();
    void scrie()
    {
        this->r.scrie();
    }
    void citeste()
    {
        this->r.citeste();
    }
    void adaugare(string cod,string pret,char* nume);
    void modifica(string poz,string cod,string pret,char* nume);
    void sterge(string poz);
    vector<VideoGame> getall();
    int getsize();
    vector<VideoGame> pretmaimare(string p);
    vector<VideoGame> intervalpret(string p1,string p2);
    VideoGame cautaredupanume(char *n);

};


#endif // SERVICE_H_INCLUDED
