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
        void apply11();
        void apply12();
        void apply13();
        void apply14();
        void apply15();
         
         
        
};

// logs = new Logs();
//具体功能等待完善
void Admin::apply1()   //管理员功能
{
    int i;
    cout<<"-----管理员界面-----"<<endl;
    cout<<"\t\t1.基本数据录入"<<endl;
    cout<<"\t\t2.基本数据修改"<<endl;
    cout<<"\t\t3.基本数据插入"<<endl;
    cout<<"\t\t4.基本数据删除"<<endl;
    cout<<"\t\t5.查看用户借阅信息"<<endl;
    cout<<"\t\t6.返回上一级"<<endl;
    cout<<"\t\t请输入选项：（1-6）：";
    cin>>i;
    system("cls");//是c这样写吗
    switch(i){
        case 1:
            //录入信息的接口
            break;
        case 2:
            //数据修改接口
            break;
        case 3:
            //数据插入接口
            break;
        case 4:
            //数据删除接口
            break;
        case 5:
            //借阅信息查看接口
            break;
        case 6:

            break;
        default:
            cout<<"选项输入错误!"<<endl;
            apply1();

    }
    
	system("pause");
	exit(0);
}
void Reader::apply2()   //读者功能
{
    int i;
    cout<<"-----读者界面-----"<<endl;
    cout<<"\t\t1.图书查询"<<endl;
    cout<<"\t\t2.基本数据修改"<<endl;
    cout<<"\t\t3.基本数据插入"<<endl;
    cout<<"\t\t4.基本数据删除"<<endl;
    cout<<"\t\t5.查看用户借阅信息"<<endl;
    cout<<"\t\t请输入选项：（1-5）：";
    cin>>i;
    system("cls");//是c这样写吗

	system("pause");
	exit(0);
}
void Visitor::apply3()
{   //游客功能
	system("pause");
	exit(0);
}   
logs* Person::ls = new logs();