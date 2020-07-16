/*
 * @Author: DuShiyi
 * @Date: 2020-07-15 17:56:32
 * @LastEditTime: 2020-07-16 18:42:49
 * @LastEditors: Please set LastEditors
 * @Description: about person(admin ,visitor,reader)
 * @FilePath: \LibManage\src\person.cpp
 */    
#include"../include/person.h"
#include"../include/library.h"

// logs = new Logs();
//具体功能等待完善
using LibSys::library;

// Logs* Person::ls = new Logs();
// library* Person::lib = new library();
/*==============================================================================
|函 数 名|:apply11
|功能描述|:管理员登陆后的search界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Admin::apply11(){
    //search
    LibSys::library* lib1= LibSys::library::getLibrary();
    string s1;
    char c;
    system("cls");
    cout<<"您希望通过哪种方式来搜索书籍，"<<endl;
    cout<<"书名请输入‘N’,ISBN请输入‘I’,作者名请输入‘A’,出版社名请输入‘P’:";
    cin>>c;
    cout<<"请输入其关键词:";
    cin>>s1;
    
    switch(c){
        case 'N':

            if(lib1->search(s1,LibSys::library::field::NAME)){
              

            }else{
                cout<<"未找到相应书籍"<<endl;
            }
            break;
        case 'I':
            if(lib1->search(s1,LibSys::library::field::ISBN)){
            
            }else{
                cout<<"未找到相应书籍"<<endl;
            }
            break;
        case 'A':
             if(lib1->search(s1,LibSys::library::field::AUTHOR)){
                
            }else{
                cout<<"未找到相应书籍"<<endl;
            }
            break;
        case 'P':
            if(lib1->search(s1,LibSys::library::field::PRESS)){
               
            }else{
                cout<<"未找到相应书籍"<<endl;
            }
            break;

    }
    system("pause");
    //back admin function menu
    apply1();    
}
/*==============================================================================
|函 数 名|:apply12
|功能描述|:管理员登陆后的修改书籍数据界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Admin::apply12(){
    //INFORMATION MODIFY
    LibSys::library* lib1= LibSys::library::getLibrary();
    string _isbn;
    string newname;
    cout<<"";
    cin>>_isbn;
    cout<<"change the name for the book(new name):";
    cin>>newname;
    lib1->changeBookName(*this,_isbn,newname);
    cout<<"successfully change book name!"<<endl;
    //返回功能主页
    system("pause");
    apply1();
    
}

/*==============================================================================
|函 数 名|:apply13
|功能描述|:管理员登陆后的插入书籍信息的界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Admin::apply13(){
    //information insert
    LibSys::library* lib1= LibSys::library::getLibrary();
    string n;string isbn;string author;string press;int count;string cg;
    cout<<"please input the information of book:(no.,isbn,author,press,count,category):"<<endl;
    cin>>n;cin>>isbn;cin>>author;cin>>press;cin>>count;cin>>cg;
    LibSys::Book b(n,isbn,author,press,count,LibSys::StringToCategory(cg));
    lib1->buy(*this,b);
    cout<<"successfully insert book"<<endl;
    system("pause");
    apply1();

}
/*==============================================================================
|函 数 名|:apply14
|功能描述|:管理员登陆后的书籍信息删除界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Admin::apply14(){
    //information delete
    LibSys::library* lib1= LibSys::library::getLibrary();
    string n;string isbn;string author;string press;int count;string cg;
    cout<<"please input the information of book to delete:(no.,isbn,author,press,count,category):"<<endl;
    cin>>n;cin>>isbn;cin>>author;cin>>press;cin>>count;cin>>cg;
    LibSys::Book b(n,isbn,author,press,count,LibSys::StringToCategory(cg));
    lib1->discard(*this,b);
    cout<<"successfully delete book"<<endl;
    system("pause");
    apply1();


}
/*==============================================================================
|函 数 名|:apply11
|功能描述|:管理员登陆后的search界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Admin::apply15(){
    //look up borrowlog
    LibSys::library* lib1= LibSys::library::getLibrary();
    lib1->listBorrowTrace();
    system("pause");
    apply1();
}

/*==============================================================================
|函 数 名|:apply21
|功能描述|：读者登陆后的search界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Reader::apply21(){
    //search
    LibSys::library* lib1= LibSys::library::getLibrary();
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

            if(lib1->search(s1,LibSys::library::field::NAME)){
              

            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'I':
            if(lib1->search(s1,LibSys::library::field::ISBN)){
            
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'A':
             if(lib1->search(s1,LibSys::library::field::AUTHOR)){
                
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'P':
            if(lib1->search(s1,LibSys::library::field::PRESS)){
               
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;

    }
    system("pause");
    //back admin function menu
    apply2();
}
/*==============================================================================
|函 数 名|:apply22
|功能描述|:读者登陆后的借阅界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Reader::apply22(){
    //borrow
    LibSys::library* lib1= LibSys::library::getLibrary();
    string isbn;
    cout<<"please input the isbn of the book:"<<endl;
    cin>>isbn;
    lib1->borrow(*this,isbn);
}
/*==============================================================================
|函 数 名|:apply11
|功能描述|:读者登陆后的归还界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Reader::apply23(){
    //return
    LibSys::library* lib1= LibSys::library::getLibrary();
    char a;
    string isbn;
    cout<<"Do you wannna return all the books?(Y/N):";
    cin>>a;
    if(a=='Y'){
        lib1->retAllBook(*this);
        // cout<<"successfully return all the books!"<<endl;
    }else if(a=='N'){
        cout<<"input isbn of the book you wanna return:";
        cin>>isbn;
        lib1->ret(*this,isbn);
        // cout<<"successfully return  the book!"<<endl;
    }else{
        cout<<"input error!"<<endl;
        apply23();
    }
    
}


/*==============================================================================
|函 数 名|:apply25
|功能描述|:读者登陆后的查阅个人借书信息的界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Reader::apply25(){
    //look up borrowlog
    LibSys::library* lib1= LibSys::library::getLibrary();
    lib1->personalBorrowTrace(*this);
    system("pause");
}
/*==============================================================================
|函 数 名|:apply31
|功能描述|:游客查阅所有书籍信息的界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Visitor::apply31(){
    //look up all the information
    LibSys::library* lib1= LibSys::library::getLibrary();
    lib1->list(true);
    system("pause");
    apply3();

}
/*==============================================================================
|函 数 名|:apply32
|功能描述|:游客搜索书籍信息的界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Visitor::apply32(){
    //search information
    LibSys::library* lib1= LibSys::library::getLibrary();
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

            if(lib1->search(s1,LibSys::library::field::NAME)){
              

            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'I':
            if(lib1->search(s1,LibSys::library::field::ISBN)){
            
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'A':
             if(lib1->search(s1,LibSys::library::field::AUTHOR)){
                
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;
        case 'P':
            if(lib1->search(s1,LibSys::library::field::PRESS)){
               
            }else{
                cout<<"can not find the book"<<endl;
            }
            break;

    }
    system("pause");
    //back admin function menu
    apply3();
}

/*==============================================================================
|函 数 名|:apply1
|功能描述|:管理员登陆后功能选项界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Admin::apply1()  
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
                return;
                break;
            default:
                cout<<"input error!"<<endl;
                

        }
    
	    system("pause");
    }
}
/*==============================================================================
|函 数 名|:apply2
|功能描述|:读者登陆后功能界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Reader::apply2()   //读者功能
{
    while(1){
        int i;
        system("cls");
        cout<<"-----读者界面-----"<<endl;
        cout<<"1.书籍查询"<<endl;
        cout<<"2.书籍借阅"<<endl;
        cout<<"3.书籍归还"<<endl;
        // cout<<"4.modify personal informatin"<<endl;
        cout<<"4.查看个人借阅日志"<<endl;
        cout<<"5.返回上一页"<<endl;
        cout<<"请输入您要使用的功能选项（1-5）：";
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
                apply25();
                break;
               
            case 5:
                return;
                break;
              
            
            default:
                cout<<"input error!"<<endl;
                

         }
        system("pause");

    }
    
	
}

/*==============================================================================
|函 数 名|:apply3
|功能描述|:游客功能界面
|输入参数|:无
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月16日
|作    者|：杜诗仪
========================================================================================*/ 
void Visitor::apply3()
{   //游客功能
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
                return;
                //last page
            default:
                cout<<"input error!"<<endl;
                
            
        }
        system("pause");
    }
	
}   





