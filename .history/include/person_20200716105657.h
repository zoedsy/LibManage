#pragma once
#include"log.h"
#include<map>

// forward declaration
namespace LibSys{
    class library;
}

class Person{
    public:
        static Logs* ls;
        static LibSys::library*lib;

};

class Visitor:public Person{
    protected:
        string account;
    public:
      
        void apply3();
        void apply31();
        void apply32();

};
class Reader:public Person{
    protected:
        string account;
        string password;
        // map<string,bool> readlog; //借阅信息存储的数据结构
    public:
        
        string GetAccount()const noexcept{return account;}
        void apply2();
        void apply21();
        void apply22();
        void apply23();
        void apply24();
        void apply25();

};
class Admin:public Person{
    protected:
        string account;
        string password;
     public:
        string GetAccount()const noexcept{return account;}
     
        void apply1();  
        void apply11();
        void apply12();
        void apply13();
        void apply14();
        void apply15();
};

