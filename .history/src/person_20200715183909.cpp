#include"../include/person.h"
// logs = new Logs();
//具体功能等待完善
logs* Person::ls = new logs();
void Admin::apply1()   //管理员功能
{
    int i;
    system("cls");
     cout<<"-----Admin Page-----"<<endl;
    cout<<"1.book search"<<endl;
    cout<<"2.information modify"<<endl;
    cout<<"3.information insert"<<endl;
    cout<<"4.information delete"<<endl;
    cout<<"5.look up borrowlog"<<endl;
    cout<<"6.back to last page"<<endl;
    cout<<"please input the choice:(1-6):";

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
    cout<<"-----Reader Page-----"<<endl;
    cout<<"1.Book Search"<<endl;
    cout<<"2.information modify"<<endl;
    cout<<"3.information insert"<<endl;
    cout<<"4.information delete"<<endl;
    cout<<"5.look up borrowlog"<<endl;
    cout<<"6.back to last page"<<endl;
    cout<<"please input the choice:(1-6)";
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