/*
 * @Author: DuShiyi
 * @Date: 2020-07-15 17:56:32
 * @LastEditTime: 2020-07-17 00:18:18
 * @LastEditors: Please set LastEditors
 * @Description: about person(admin ,visitor,reader)
 * @FilePath: \LibManage\src\person.cpp
 */    
#include"../include/person.h"
#include"../include/library.h"

// logs = new Logs();
//���幦�ܵȴ�����
using LibSys::library;
// LibSys::library* lib1= LibSys::library::getLibrary();
/*
|�� �� ��|:apply10
|��������|:����Ա��½����ʾ�����鼮
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|��������
========================================================================================*/ 
void Admin::apply10(){
    //��ʾ��������
    LibSys::library* lib1= LibSys::library::getLibrary();
    system("cls");
    lib1->list(true);
    system("pause");
    //back admin function menu
    // apply1();    
}
// Logs* Person::ls = new Logs();
// library* Person::lib = new library();
/*==============================================================================
|�� �� ��|:apply11
|��������|:����Ա��½���search����
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Admin::apply11(){
    //search
    LibSys::library* lib1= LibSys::library::getLibrary();
    string s1;
    char c;
    system("cls");
    cout<<"��ϣ��ͨ�����ַ�ʽ�������鼮��"<<endl;
    cout<<"���������롮N��,ISBN�����롮I��,�����������롮A��,�������������롮P��:";
    cin>>c;
    cout<<"��������ؼ���:";
    cin>>s1;
    
    switch(c){
        case 'N':

            if(lib1->search(s1,LibSys::library::field::NAME)){
              

            }else{
                cout<<"δ�ҵ���Ӧ�鼮"<<endl;
            }
            break;
        case 'I':
            if(lib1->search(s1,LibSys::library::field::ISBN)){
            
            }else{
                cout<<"δ�ҵ���Ӧ�鼮"<<endl;
            }
            break;
        case 'A':
             if(lib1->search(s1,LibSys::library::field::AUTHOR)){
                
            }else{
                cout<<"δ�ҵ���Ӧ�鼮"<<endl;
            }
            break;
        case 'P':
            if(lib1->search(s1,LibSys::library::field::PRESS)){
               
            }else{
                cout<<"δ�ҵ���Ӧ�鼮"<<endl;
            }
            break;

    }
    system("pause");
    //back admin function menu
    
}
/*==============================================================================
|�� �� ��|:apply12
|��������|:����Ա��½����޸��鼮���ݽ���
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Admin::apply12(){
    //INFORMATION MODIFY
    LibSys::library* lib1= LibSys::library::getLibrary();
    string _isbn;
    string newname;
    cout<<"���������ISBN��";
    cin>>_isbn;
    cout<<"��������������֣�";
    cin>>newname;
    lib1->changeBookName(*this,_isbn,newname);
    // cout<<"successfully change book name!"<<endl;
    //���ع�����ҳ
    system("pause");
    // apply1();
    
}

/*==============================================================================
|�� �� ��|:apply13
|��������|:����Ա��½��Ĳ����鼮��Ϣ�Ľ���
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Admin::apply13(){
    //information insert
    LibSys::library* lib1= LibSys::library::getLibrary();
    string n;string isbn;string author;string press;int count;string cg;
    cout<<"�밴��ʾ����ʽ������¼�������Ϣ(���� ISBN ������ ����� �ϼ�����):";
    cin>>n;cin>>isbn;cin>>author;cin>>press;cin>>count;cin>>cg;
    LibSys::Book b(n,isbn,author,press,count,LibSys::StringToCategory(cg));
    lib1->buy(*this,b);
    // cout<<"successfully insert book"<<endl;
    // system("pause");
    // apply1();

}
/*==============================================================================
|�� �� ��|:apply14
|��������|:����Ա��½����鼮��Ϣɾ������
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Admin::apply14(){
    //information delete
    LibSys::library* lib1= LibSys::library::getLibrary();
    string n;string isbn;string author;string press;int count;string cg;
    cout<<"�밴��ʾ����ʽ������ɾ�������Ϣ(���� ISBN ������ ���� �ϼ�����):";
    cin>>n;cin>>isbn;cin>>author;cin>>press;cin>>count;cin>>cg;
    LibSys::Book b(n,isbn,author,press,count,LibSys::StringToCategory(cg));
    lib1->discard(*this,b);
    // cout<<"successfully delete book"<<endl;
    system("pause");
    // apply1();


}
/*==============================================================================
|�� �� ��|:apply11
|��������|:����Ա��½���search����
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Admin::apply15(){
    //look up borrowlog
    LibSys::library* lib1= LibSys::library::getLibrary();
    lib1->listBorrowTrace();
    system("pause");
    // apply1();
}

/*
|�� �� ��|:apply10
|��������|:����Ա��½����ʾ�����鼮
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|��������
========================================================================================*/ 
void Reader::apply20(){
    //��ʾ��������
    LibSys::library* lib1= LibSys::library::getLibrary();
    system("cls");
    lib1->list(1);
    system("pause");
    //back admin function menu
    // apply2();
}

/*==============================================================================
|�� �� ��|:apply21
|��������|�����ߵ�½���search����
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Reader::apply21(){
    //search
    LibSys::library* lib1= LibSys::library::getLibrary();
    string s1;
    char c;
    system("cls");
    cout<<"��ϣ��ͨ�����ַ�ʽ�������鼮��"<<endl;
    cout<<"���������롮N��,ISBN�����롮I��,�����������롮A��,�������������롮P��:";
    cin>>c;
    cout<<"��������ؼ���:";
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
    // apply2();
}
/*==============================================================================
|�� �� ��|:apply22
|��������|:���ߵ�½��Ľ��Ľ���
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Reader::apply22(){
    //borrow
    LibSys::library* lib1= LibSys::library::getLibrary();
    string isbn;
    cout<<"���������ISBN:"<<endl;
    cin>>isbn;
    lib1->borrow(*this,isbn);
    system("pause");
}
/*==============================================================================
|�� �� ��|:apply11
|��������|:���ߵ�½��Ĺ黹����
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Reader::apply23(){
    //return
    LibSys::library* lib1= LibSys::library::getLibrary();
    int flag=0;

    do{
        
        char a;
        string isbn;
        cout<<"��ϣ���黹�����鱾��(Y/N):";
        cin>>a;
        if(a=='Y'){
            lib1->retAllBook(*this);
            flag=0;
            // cout<<"successfully return all the books!"<<endl;
        }else if(a=='N'){
            cout<<"��������Ҫ�黹���鼮��ISBN:";
            cin>>isbn;
            lib1->ret(*this,isbn);
            flag=0;
            // cout<<"successfully return  the book!"<<endl;
        }else{
            cout<<"�������!"<<endl;
            flag=1;
        }
    }while(flag);
    system("pause");
    
}


/*==============================================================================
|�� �� ��|:apply25
|��������|:���ߵ�½��Ĳ��ĸ��˽�����Ϣ�Ľ���
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Reader::apply25(){
    //look up borrowlog
    LibSys::library* lib1= LibSys::library::getLibrary();
    lib1->personalBorrowTrace(*this);
     system("pause");
}
/*==============================================================================
|�� �� ��|:apply31
|��������|:�οͲ��������鼮��Ϣ�Ľ���
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Visitor::apply31(){
    //look up all the information
    LibSys::library* lib1= LibSys::library::getLibrary();
    lib1->list(true);
    system("pause");
    

}
/*==============================================================================
|�� �� ��|:apply32
|��������|:�ο������鼮��Ϣ�Ľ���
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Visitor::apply32(){
    //search information
    while(1){
        LibSys::library* lib1= LibSys::library::getLibrary();
        string s1;
        char c;
        int flag=1;
        system("cls");
        cout<<"��ϣ��ͨ�����ַ�ʽ�������鼮��"<<endl;
        cout<<"���������롮N��,ISBN�����롮I��,�����������롮A��,�������������롮P��:";
        cin>>c;
        cout<<"��������ؼ���:";
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
            default:
                cout<<"����������ʽ��ʽ����"<<endl;
                cout<<"0.�������� 1.������һҳ��";
                cin>>flag;

        }
        if(flag) break;
        system("pause");
    }
    
    //back admin function menu
    
}

/*==============================================================================
|�� �� ��|:apply1
|��������|:����Ա��½����ѡ�����
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Admin::apply1()  
{
    
    while(1){
        int i;
        system("cls");
        cout<<"----����Ա����----"<<endl;
        cout<<"0.��ʾ�����鼮" <<endl;
        cout<<"1.�鼮��ѯ"<<endl;
        cout<<"2.�鼮�޸�"<<endl;
        cout<<"3.�鼮��Ϣ����"<<endl;
        cout<<"4.�鼮��Ϣɾ��"<<endl;
        cout<<"5.�鿴�û����ļ�¼"<<endl;
        cout<<"6.������һҳ"<<endl;
        cout<<"��������Ҫʹ�õĹ���ѡ�0-6��:";

        cin>>i;
        system("cls");
        switch(i){

            case 0:
                //��ʾ�����鼮�Ľӿ�
                apply10();
                break;
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
                cout<<"�������!"<<endl;

        }
    
	    // system("pause");
    }
}
/*==============================================================================
|�� �� ��|:apply2
|��������|:���ߵ�½���ܽ���
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Reader::apply2()   //���߹���
{
    while(1){
        int i;
        system("cls");
        cout<<"-----���߽���-----"<<endl;
        cout<<"0.��ʾ�����鼮" <<endl;
        cout<<"1.�鼮��ѯ"<<endl;
        cout<<"2.�鼮����"<<endl;
        cout<<"3.�鼮�黹"<<endl;
        // cout<<"4.modify personal informatin"<<endl;
        cout<<"4.�鿴���˽�����־"<<endl;
        cout<<"5.������һҳ"<<endl;
        cout<<"��������Ҫʹ�õĹ���ѡ�0-5����";
        cin>>i;
        system("cls");
        switch(i){
            case 0:
                apply20();
                break;
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
                cout<<"�������!"<<endl;
                

         }
        

    }
    
	
}

/*==============================================================================
|�� �� ��|:apply3
|��������|:�ο͹��ܽ���
|�������|:��
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��16��
|��    ��|����ʫ��
========================================================================================*/ 
void Visitor::apply3()
{   //�ο͹���
    while(1){
        system("cls");
        int i;
        cout<<"-----�οͽ���-----"<<endl;
        cout<<"1.��ѯ���йݲ��鼮"<<endl;
        cout<<"2.��ѯ�鼮"<<endl;
        cout<<"3.������һҳ"<<endl;
        cout<<"��������Ҫʹ�õĹ���ѡ�1-3��:";
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
                cout<<"�������!"<<endl;
                
            
        }
        
    }
	
}   




