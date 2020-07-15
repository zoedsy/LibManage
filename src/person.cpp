#include"../include/person.h"
// logs = new Logs();
//具体功能等待完善
logs* Person::ls = new logs();

void Admin::apply11(){

}
void Admin::apply12(){
    
}
void Admin::apply13(){
    
}
void Admin::apply14(){
    
}
void Admin::apply15(){
    
}

void Reader::apply21(){

}
void Reader::apply22(){
    
}
void Reader::apply23(){
    
}
void Reader::apply24(){
    
}
void Reader::apply25(){
    
}

void Visitor::apply31(){

}
void Visitor::apply32(){
    
}



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
            apply11();
            break;
        case 2:
            //数据修改接口
            apply12();
            break;
        case 3:
            //数据插入接口
            apply13();
            break;
        case 4:
            //数据删除接口
            apply14();
            break;
        case 5:
            //借阅信息查看接口
            apply15();
            break;
        case 6:
            //last page
            break;
        default:
            cout<<"input error!"<<endl;
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
      switch(i){
        case 1:
        
            apply21();
            break;
        case 2:
        
            apply22();
            break;
        case 3:
            
            apply23();
            break;
        case 4:
        
            apply24();
            break;
        case 5:
        
            apply25();
            break;
        case 6:
            // secondPage(2);
            break;
        default:
            cout<<"input error!"<<endl;
            apply2();

}
	system("pause");
	exit(0);
}
void Visitor::apply3()
{   //游客功能
    int i;
    cout<<"-----Visitor-----"<<endl;
    cout<<"1.look up the information of all books"<<endl;
    cout<<"2.search the information of the book"<<endl;
    cout<<"3.back to last page"<<endl;
    cout<<"please input the choice(1-3):"<<endl;
    cin>>i;
    switch(i){
        case 1:
            apply31();
            break;
        case 2:
            apply32();
            break;
        case 3:
            //last page
        default:
            cout<<"input error!"<<endl;
            apply3();
        
    }
	system("pause");
	exit(0);
}   