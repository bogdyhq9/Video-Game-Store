#include"repo.h"
#include<vector>
#include"videogame.h"
Repo :: Repo()
{
    this->games.reserve(10);
}
void Repo ::adaugare(VideoGame &v)
{
    this->games.push_back(v);
}
Repo :: ~Repo()
{
    this->games.clear();
}
vector<VideoGame> Repo::getall()
{
    return this->games;
}
int Repo ::getsize()
{
    return (int) this->games.size();
}
void Repo::modifica(int i,VideoGame &v)
{
    this->games[i]=v;
}
void Repo :: sterge(int i)
{
    this->games.erase(this->games.begin()+i);
}
