#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED
#include "exception"
#include<string.h>


class MyException{
private:
  char text[50];
public:
  MyException(){
  strcpy(this->text,"");
  }
  MyException(char* s){
  strcpy(this->text,s);
  }
  char* GetText(){
    return this->text;
  }
};

#endif // EXCEPTION_H_INCLUDED
