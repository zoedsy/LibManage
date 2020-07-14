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
    public:
        void apply3();

};
class Reader:public Person{
    protected:
        string account="游客";
        string password;
        map<string,bool> readlog;
    public:
        void apply2();
};
class Admin:public Person{
    protected:
        string account;
        string password;
     public:
        void apply1();   
        
};

// logs = new Logs();
void apply1()   //管理员功能
{
	system("pause");
	exit(0);
}
void apply2()   //读者功能
{
	system("pause");
	exit(0);
}
void apply3()
{   //游客功能
	system("pause");
	exit(0);
}   