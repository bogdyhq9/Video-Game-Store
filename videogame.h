#ifndef VIDEOGAME_H_INCLUDED
#define VIDEOGAME_H_INCLUDED
#include<iostream>
using namespace std;
class VideoGame{
private:
    int cod;
    float pret;
    char* nume;
public:
    VideoGame();
    VideoGame(int c,float p,char* n);
    VideoGame(const VideoGame &v);
    ~VideoGame();
    void setnume(char* n);
    void setpret(float p);
    int getcod();
    float getpret();
    char* getnume();
    VideoGame& operator=(const VideoGame &v);
    friend ostream& operator<<(ostream &os, VideoGame &v);
};

#endif // VIDEOGAME_H_INCLUDED
