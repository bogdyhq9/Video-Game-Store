#ifndef FILEREPO_H_INCLUDED
#define FILEREPO_H_INCLUDED
#include"repo.h"
#include<string.h>
#include<fstream>
using namespace std;
class FileRepo: public Repo{
private:
    char numefisier[20];
public:
    FileRepo() : Repo()
    {
        strcpy(this->numefisier,"");
        // numefisier = new char[1];
        //numefisier[0] = '\0';
    }
    FileRepo(char* fisier):Repo()
    {
        strcpy(this->numefisier,fisier);
        //this->numefisier=new char[strlen(fisier)+1];
        //strcpy_s(this->numefisier,strlen(fisier)+1,fisier);
    }
    ~FileRepo(){
        //if(this->numefisier)
        //{
           // delete[] this->numefisier;
           // this->numefisier=nullptr;
        //}
    }
    void scrie()
    {
        ofstream g(this->numefisier);
        vector<VideoGame>jocuri;
        jocuri=this->getall();
        for(int i=0;i<this->getsize();i++)
            g<<jocuri[i].getcod()<<" "<<jocuri[i].getpret()<<" "<<jocuri[i].getnume()<<endl;
        g.close();
    }
    void citeste()
    {
        ifstream f(this->numefisier);
        char nume[30];
        char* n;
        float pret;
        int cod;
        while(f>>cod)
        {
            f>>pret;
            f>>nume;
            n= new char[strlen(nume)+1];
            strcpy_s(n,strlen(nume)+1,nume);
            VideoGame v(cod,pret,n);
            this->adaugare(v);
            delete[] n;
        }
        f.close();
    }

};



#endif // FILEREPO_H_INCLUDED
