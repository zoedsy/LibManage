#include"../include/person.h"
#include"../include/library.h"

// logs = new Logs();
//具体功能等待完善
using LibSys::library;

logs* Person::ls = new logs();
library* Person::lib = new library();
void Admin::apply11(){
    //search
    string s1;
    char c;
    system("cls");
    cout<<"how do you want to search the"
    <<"book(N(NAME),I(ISBN),A(AUTHOR),P(PRESS)):"<<endl;
    cin>>c;
    cout<<"input the keyword:"<<endl;
    cin>>s1;
    
    switch(c){
        case 'N':

            if(lib->search(s1,LibSys::library::field::NAME)){
                //if you wannna borrow the book
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'I':
            if(lib->search(s1,LibSys::library::field::ISBN)){
                //if you wannna borrow the book
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'A':
             if(lib->search(s1,LibSys::library::field::AUTHOR)){
                //if you wannna borrow the book
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'P':
            if(lib->search(s1,LibSys::library::field::PRESS)){
                //if you wannna borrow the book
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;

    }
  

    
    
    
    
    
}
void Admin::apply12(){
    //INFORMATION MODIFY

    
}
void Admin::apply13(){
    //information insert
    string _isbn;
    string newname;
    cout<<"the isbn of the book whose name you wanna change:";
    cin>>_isbn;
    cout<<"change the name for the book(new name):";
    cin>>newname
    LibSys::changeBookName(*this,_isbn,,newname);

}
void Admin::apply14(){
    //information delete
}
void Admin::apply15(){
    //look up borrowlog
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