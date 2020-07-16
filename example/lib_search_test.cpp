#include"../include/library.h"
#include"windows.h"
// #include"../src/library.cpp"
// #include"../src/trace.cpp"
// #include"../src/book.cpp"
// #include"../src/libTime.cpp"
    using namespace LibSys;
void library::update(std::string const&f)noexcept{
    std::cout<<"update"<<std::endl;
}
void library::save(const std::string &){
    std::cout<<"save"<<std::endl;

}
void lib_search_test(library &lib,Admin&);
/**
 * @brief library test
 * @local .../example
 * @gcc  g++ -std=c++11 .\lib_search_test.cpp  ..\src\*.obj  -olib_test 
*/
int main(){
    SetConsoleTitle("library");
    library lib;
    Admin admin;
    Book b("123","73219851","����","null",12,Category::ADVENTURE);
    Book b2("Effective C++","978-7-121-12332-0","���","���ӹ�ҵ������",2,Category::ADVENTURE);
    Book b3("������ԣ������棩","978-7-302-33314-2","��ˬ","�廪��ѧ������",1,Category::PRIMER);
    Book b4("�㷨���������ŵ�����","978-7-302-52","��������������","�廪��ѧ������",12,Category::PRIMER);
    
    lib.buy(admin,b);
    lib.buy(admin,b2);
    lib.buy(admin,b3);
    lib.buy(admin,b4);
    lib.SetLogFile("logfile.dat");
    lib_search_test(lib,admin);

    system("pause");
    return 0;
}
void lib_search_test(library &lib,Admin& admin){
    Book b5("�㷨���������ŵ�����","978-7-302-52","��������������","�廪��ѧ������",30,Category::PRIMER);
    puts("BLUR:Search ��");
    lib.search("��",library::field::BLUR);
    puts("ISBN:Search ��");
    lib.search("��",library::field::ISBN);
    puts("PRESS:Search ��");
    lib.search("��",library::field::PRESS);
    puts("NAME:Search ��");
    lib.search("��",library::field::NAME);
    puts("AUTHOR:Search ��");
    lib.search("��",library::field::AUTHOR);
    
    puts("ISBN: search 302");
    lib.search("978-7-302-52",library::field::ISBN);

    puts("before buy");
    lib.search("��",library::field::BLUR);
    puts("after buy");
    lib.buy(admin,b5);
    lib.search("��",library::field::BLUR);
}