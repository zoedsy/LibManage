#pragma once
#include"log.h"
#include<map>
class Person{
    public:
        static logs* ls;
};

class Visitor:public Person{
    protected:
        string account="游客";
    public:
        Visitor(){
           //直接进入搜索模块
        }
        void apply3();

};
class Reader:public Person{
    protected:
        string account;
        string password;
        map<string,bool> readlog; //借阅信息存储的数据结构
    public:
        Reader(){
            
        }
        string GetAccount()const noexcept{return account;}
        void apply2();

};
class Admin:public Person{
    protected:
        string account;
        string password;
     public:
        string GetAccount()const noexcept{return account;}
        Admin(){
            //进入登陆后的管理者界面
        }
        void apply1();  
        void apply11();
        void apply12();
        void apply13();
        void apply14();
        void apply15();
         
         
        
};

