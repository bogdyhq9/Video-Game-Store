#include<iostream>
#include<string.h>
#include <limits>
#include"ui.h"
#include"exception.h"
using namespace std;
UI ::UI()
{
    this->s=Service();
}
UI ::UI(const Service &service)
{
    this->s=service;
}
UI ::~UI(){}
void UI ::adaugare()
{
    try{
        string cod;
        string pret;
        char nume[30];
        char* t;
        cout << "Introduceti jocul (cod, pret, nume):" << endl;
        cin >> cod >> pret >> nume;

        t = new char[strlen(nume) + 1];
        strcpy_s(t, strlen(nume) + 1, nume);

        this->s.adaugare(cod, pret, t);

        delete[] t;
    }
    catch(MyException exc)
    {
        cout<<exc.GetText()<<endl;
    }
    catch(...)
    {
        cout<<"other exception"<<endl;
    }

}
void UI ::stergere()
{
    try{
     string poz;
    cout<<"Dati pozitia jocului pe care doriti sa-l stergeti"<<endl;
    cin>>poz;
    //if(poz<=this->s.getsize())
        this->s.sterge(poz);
    }
    catch(MyException exc)
    {
        cout<<exc.GetText()<<endl;
    }
    catch(...)
    {
        cout<<"other exception"<<endl;
    }
}
void UI:: modificare()
{
try{
    string pos,cod;
    string pret;
    char nume[30];
    char* t;
    cout<<"Dati pozitia jocului pe care doriti sa-l modificati ";
    cin>>pos;
    //if(pos>(this->s.getsize()))
        //cout<<"Pozitia invalida"<<endl;
        cout<<"Adaugati noul joc(cod,pret,nume) ";
        cin>>cod>>pret>>nume;
        t = new char[strlen(nume) + 1];
        strcpy_s(t, strlen(nume) + 1, nume);
        //VideoGame v(cod,pret,t);
        s.modifica(pos,cod,pret,t);
        delete[] t;
}
catch(MyException exc)
    {
        cout<<exc.GetText()<<endl;
    }
    catch(...)
    {
        cout<<"other exception"<<endl;
    }
}
void UI:: afisare(vector<VideoGame> v)
{
    vector<VideoGame>:: iterator it=v.begin();
    while(it!=v.end())
    {
        cout<<*it;
        it++;
    }
}
void UI:: pretmaimare()
{
    try{
    string p;
    vector<VideoGame> jocuri;
    cout<<"Dati pretul pentru a afisa jocurile cu pret mai mare"<<endl;
    cin>>p;
    jocuri=this->s.pretmaimare(p);
    this->afisare(jocuri);
    }
    catch(MyException exc)
    {
        cout<<exc.GetText()<<endl;
    }
    catch(...)
    {
        cout<<"other exception"<<endl;
    }

}
void UI::intervalpret()
{
    try{
    string p1,p2;
    vector<VideoGame> jocuri;
    cout<<"Dati intervalul de pret"<<endl;
    cin>>p1>>p2;
    jocuri=this->s.intervalpret(p1,p2);
    this->afisare(jocuri);
    }
    catch(MyException exc)
    {
        cout<<exc.GetText()<<endl;
    }
    catch(...)
    {
        cout<<"other exception"<<endl;
    }

}
void UI::cautaredupanume()
{
    char n[30];
    cout << "Dati numele jocului pe care il cautati: ";
    cin >> n;

    VideoGame v = this->s.cautaredupanume(n);

    if(v.getcod() == 0)
    {
        cout << "Jocul cautat nu exista" << endl;
    }
    else
    {
        cout << v;
    }
}
void UI:: printmeniu()
	{
	    cout << endl << "1. Adauga joc" << endl;
	    cout<<"2. Modifica joc"<<endl;
	    cout<<"3. Sterge joc(pozitie)"<<endl;
        cout << "4. Afisare jocuri" << endl;
        cout<<"5. Afisarea jocurilor cu un pret mai mare decat cel dat"<<endl;
        cout<<"6. Afisarea jocurilor dintr-un interval de pret"<<endl;
        cout<<"7. Cautarea unui joc dupa nume"<<endl;
	}
void UI::runmeniu()
{
    this->s.citeste();
    int optiune;
        while (true)
{
            printmeniu();
            cout << "Selectati optiunea: ";
            cin >> optiune;
            if (optiune == 1)
                {
                    this->adaugare();
                }
            else if (optiune == 3)
                {
                    this->stergere();
                }
            else if (optiune == 2)
                {
                    this->modificare();
                }
            else if (optiune == 4)
                {
                    vector<VideoGame> v = this->s.getall();
                    this->afisare(v);
                }
            else if (optiune == 5)
                {
                    this->pretmaimare();
                }
            else if (optiune == 6)
                {
                    this->intervalpret();
                }
            else if (optiune == 7)
                {
                    this->cautaredupanume();
                }
            else{
                break;
            }
}
this->s.scrie();
}
