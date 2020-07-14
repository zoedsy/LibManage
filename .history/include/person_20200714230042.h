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
        string account="游客";
        string password;
        map<string,bool> readlog; //借阅信息存储的数据结构
    public:
        Reader(){
            //进入登陆后的读者界面
        }
        void apply2();
};
class Admin:public Person{
    protected:
        string account;
        string password;
     public:
        Admin(){
            //进入登陆后的管理者界面
        }
        void apply1();   
        
};

// logs = new Logs();
//具体功能等待完善
void Admin::apply1()   //管理员功能
{
	system("pause");
	exit(0);
}
void Reader::apply2()   //读者功能
{
	system("pause");
	exit(0);
}
void Visitor::apply3()
{   //游客功能
	system("pause");
	exit(0);
}   
logs* Person::ls = new logs();