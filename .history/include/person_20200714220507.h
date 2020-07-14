#pragma once
#include"..\login\log.h"
#include<map>
class Person{
    public:
         logs logs;
};

class Visitor:public Person{
    protected:
        string account="游客";

};
class Reader:public Person{
    protected:
        string account="游客";
        string password;
        map<string,bool> readlog;
};
class Admin:public Person{
    protected:
        string account;
        string password;
        
};

// logs = new Logs();