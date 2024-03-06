#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED
#include"exception.h"
class Validator
{
public:
    Validator(){}
    void valideaza(VideoGame &v)
    {
        if(v.getpret()==0)
            throw MyException("Pretul nu poate fi negativ sau egal cu 0");
        if(v.getcod()==0)
            throw MyException("Codul nu poate fi 0");
        //if(strcmp(v.getnume,"")==0)
            //throw MyException("Numele nu poate fi un string null");
    }
};


#endif // VALIDATOR_H_INCLUDED
