#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include"test.h"
#include"ui.h"
using namespace std;

int main()
{
    ifstream login("text");
    ofstream logout("text", ios::app); // Open the file in append mode

    vector<string> v;
    string nume;
    string inputName;
    bool nameFound = false;
    int optiune;
    FileRepo r("videogames");
    Service s(r);
    UI ui(s);
   // ui.runmeniu();

    while (login >> nume)
    {
        v.push_back(nume);
    }

    cout << "Alegeti optiunea(logare(2)/aduagare cont nou(1)) ";
    cin >> optiune;

    if(optiune==2)
    {
        cout<<"Introduceti numele"<<endl;
        cin>>inputName;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==inputName)
            nameFound=true;
    }

    if (nameFound)
    {
        cout << "Autentificare reusita" << endl;
        ui.runmeniu();
    }
    else
    {
        cout<<"Nume gresit "<<endl;
        return 0;
    }
    }
    if(optiune==1)
    {
        cout<<"Introduceti numele"<<endl;
        cin>>inputName;
        logout<<inputName<<endl;
        cout<<"Contul a fost adaugat cu succes"<<endl;
        ui.runmeniu();
    }
    return 0;
}
