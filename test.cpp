#include"videogame.h"
#include"repo.h"
#include"service.h"
#include"filerepo.h"
#include<assert.h>
#include<string.h>
void testVideoGame()
{
    VideoGame v(1,289.5,"GTA V");
    assert(v.getcod()==1);
    assert(v.getpret()==289.5);
    assert(strcmp(v.getnume(),"GTA V")==0);
    v.setnume("League of Legends");
    v.setpret(0);
    assert(v.getpret()==0);
    assert(strcmp(v.getnume(),"League of Legends")==0);
    VideoGame v1(v);
    assert(v1.getpret()==0);
    assert(strcmp(v1.getnume(),"League of Legends")==0);
}
void testRepo()
{
    Repo r;
    VideoGame v(1,289.5,"GTA V");
    VideoGame v1(2,200.1,"Far Cry");
    VideoGame v2(3,40,"Overcooked");
    r.adaugare(v);
    r.adaugare(v1);
    //cout<<r.getsize();
    assert(r.getsize()==2);
    r.modifica(1,v2);
    vector<VideoGame> games;
    games=r.getall();
    assert(games[1].getpret()==40);
    r.sterge(1);
    assert(r.getsize()==1);
}
void testService()
{
    FileRepo r;
    VideoGame v(1,289.5,"GTA V");
    VideoGame v1(2,200.1,"Far Cry");
    VideoGame v2(3,40,"Overcooked");
    Service s(r);
   // s.adaugare(v);
    //s.adaugare(v1);
    //assert (s.getsize()==2);
    //s.sterge(0);
    //assert(s.getsize()==1);
}
void test_pretmaimare()
{
    FileRepo r;
    VideoGame v(1,289.5,"GTA V");
    VideoGame v1(2,200.1,"Far Cry");
    VideoGame v2(3,40,"Overcooked");
    Service s(r);
//    s.adaugare(v);
  //  s.adaugare(v1);
    //s.adaugare(v2);
    vector<VideoGame> rez;
    //rez=s.pretmaimare(150);
    assert(rez.size()==2);
}
void testFileRepo(){
    FileRepo fr("testfile");
    fr.citeste();
    //cout<<fr.getsize();
    assert(fr.getsize()==1);
}
void testFileReposciere()
{
    FileRepo fr("testfile1");
    VideoGame v(1,289.5,"GTA V");
    VideoGame v1(2,200.1,"Far Cry");
    fr.adaugare(v);
    fr.adaugare(v1);
    fr.scrie();
}
void testIntervalPret()
{
    FileRepo r;
    Service service(r);
    VideoGame v1(1, 50,"GameA");
    VideoGame v2(2, 70,"GameB");
    VideoGame v3(3, 30,"GameC");
    VideoGame v4(4, 90,"GameD");
    VideoGame v5(5, 40,"GameE");

   // service.adaugare(v1);
    //service.adaugare(v2);
    //service.adaugare(v3);
    //service.adaugare(v4);
    //service.adaugare(v5);

    //vector<VideoGame> result1 = service.intervalpret(20, 60);
//    assert(result1.size() == 3);
    //assert(result1[0].getcod() == 1);
   // assert(result1[1].getcod() == 3);
    //assert(result1[2].getcod() == 5);

    // Test case 2: p1 = 70, p2 = 100
   // vector<VideoGame> result2 = service.intervalpret(70, 100);
    //assert(result2.size() == 1);
    //assert(result2[0].getcod() == 4);
}
void testCautare()
{
    FileRepo r;
    Service service(r);
    VideoGame v1(1, 50,"GameA");
    VideoGame v2(2, 70,"GameB");
    VideoGame v3(3, 30,"GameC");
    VideoGame v4(4, 90,"GameD");
    VideoGame v5(5, 40,"GameE");
    //service.adaugare(v1);
    //service.adaugare(v2);
    //service.adaugare(v3);
    //service.adaugare(v4);
    //service.adaugare(v5);
    VideoGame v=service.cautaredupanume("GameA");
    assert(v.getpret()==50);
}
