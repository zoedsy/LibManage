    
#include"../include/person.h"
#include"../include/library.h"

// logs = new Logs();
//���幦�ܵȴ�����
using LibSys::library;

Logs* Person::ls = new Logs();
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
              

            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'I':
            if(lib->search(s1,LibSys::library::field::ISBN)){
            
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'A':
             if(lib->search(s1,LibSys::library::field::AUTHOR)){
                
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'P':
            if(lib->search(s1,LibSys::library::field::PRESS)){
               
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;

    }
    system("pause");
    //back admin function menu
    apply1();

    
    
    
    
    
}
void Admin::apply12(){
    //INFORMATION MODIFY
    string _isbn;
    string newname;
    cout<<"the isbn of the book whose name you wanna change:";
    cin>>_isbn;
    cout<<"change the name for the book(new name):";
    cin>>newname;
    lib->changeBookName(*this,_isbn,newname);
    cout<<"successfully change book name!"<<endl;
    //���ع�����ҳ
    system("pause");
    apply1();
    
}
void Admin::apply13(){
    //information insert
    string n;string isbn;string author;string press;int count;string cg;
    cout<<"please input the information of book:(no.,isbn,author,press,count,category):"<<endl;
    cin>>n;cin>>isbn;cin>>author;cin>>press;cin>>count;cin>>cg;
    LibSys::Book b(n,isbn,author,press,count,LibSys::StringToCategory(cg));
    Person::lib->buy(*this,b);
    cout<<"successfully insert book"<<endl;
    system("pause");
    apply1();

}
void Admin::apply14(){
    //information delete
    string n;string isbn;string author;string press;int count;string cg;
    cout<<"please input the information of book to delete:(no.,isbn,author,press,count,category):"<<endl;
    cin>>n;cin>>isbn;cin>>author;cin>>press;cin>>count;cin>>cg;
    LibSys::Book b(n,isbn,author,press,count,LibSys::StringToCategory(cg));
    Person::lib->discard(*this,b);
    cout<<"successfully delete book"<<endl;
    system("pause");
    apply1();


}
void Admin::apply15(){
    //look up borrowlog
    Person::lib->listBorrowTrace();
    system("pause");
    apply1();
}

void Reader::apply21(){
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

            if(Person::lib->search(s1,LibSys::library::field::NAME)){
              

            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'I':
            if(Person::lib->search(s1,LibSys::library::field::ISBN)){
            
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'A':
             if(Person::lib->search(s1,LibSys::library::field::AUTHOR)){
                
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'P':
            if(Person::lib->search(s1,LibSys::library::field::PRESS)){
               
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;

    }
    system("pause");
    //back admin function menu
    apply2();
}
void Reader::apply22(){
    //borrow
    string isbn;
    cout<<"please input the isbn of the book:"<<endl;
    Person::lib->borrow(*this,isbn);
}
void Reader::apply23(){
    //return
    char a;
    string isbn;
    cout<<"Do you wannna return all the books?(Y/N):";
    cin>>a;
    if(a=='Y'){
        Person::lib->retAllBook(*this);
        cout<<"successfully return all the books!"<<endl;
    }else if(a=='N'){
        cout<<"input isbn of the book you wanna return:";
        cin>>isbn;
        Person::lib->ret(*this,isbn);
        cout<<"successfully return  the book!"<<endl;
    }else{
        cout<<"input error!"<<endl;
        apply23();
    }
    
}
void Reader::apply24(){
    //modify personal 
    //nothing
}
void Reader::apply25(){
    //look up borrowlog
    Person::lib->personalBorrowTrace(*this);
    system("pause");
}

void Visitor::apply31(){
    //look up all the information
    Person::lib->list(true);
    system("pause");
    apply3();

}
void Visitor::apply32(){
    //search information
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

            if(Person::lib->search(s1,LibSys::library::field::NAME)){
              

            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'I':
            if(Person::lib->search(s1,LibSys::library::field::ISBN)){
            
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'A':
             if(Person::lib->search(s1,LibSys::library::field::AUTHOR)){
                
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'P':
            if(Person::lib->search(s1,LibSys::library::field::PRESS)){
               
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;

    }
    system("pause");
    //back admin function menu
    apply3();
}



void Admin::apply1()   //����Ա������ҳ
{
    while(1){
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
        system("cls");
        switch(i){
            case 1:
                 //¼����Ϣ�Ľӿ�
                apply11();
                break;
            case 2:
                //�����޸Ľӿ�
                apply12();
                break;
            case 3:
                //���ݲ���ӿ�
                apply13();
                break;
            case 4:
                 //����ɾ���ӿ�
                apply14();
                break;
            case 5:
                //������Ϣ�鿴�ӿ�
                apply15();
                break;
            case 6:
                //last page
                return;
                break;
            default:
                cout<<"input error!"<<endl;
                

        }
    
	    system("pause");
    }
}
void Reader::apply2()   //���߹���
{
    while(1){
        int i;
        cout<<"-----Reader Page-----"<<endl;
        cout<<"1.book search"<<endl;
        cout<<"2.borrow book"<<endl;
        cout<<"3.return book"<<endl;
        cout<<"4.modify personal informatin"<<endl;
        cout<<"5.look up borrowlog"<<endl;
        cout<<"6.back to last page"<<endl;
        cout<<"please input the choice:(1-6)";
        cin>>i;
        system("cls");
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
                return;
                break;
            default:
                cout<<"input error!"<<endl;
                

         }
        system("pause");

    }
    
	
}
void Visitor::apply3()
{   //�ο͹���
    while(1){
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
                return;//?
                //last page
            default:
                cout<<"input error!"<<endl;
                
            
        }
        system("pause");
    }
	
}   