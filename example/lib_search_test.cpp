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
void lib_borrow_test(library &lib,Reader const&);
/**
 * @brief library test
 * @local .../example
 * @gcc  g++ -std=c++11 .\lib_search_test.cpp  ..\src\*.obj  -olib_test 
*/
int main(){
    SetConsoleTitle("library");
    std::cerr<<"begin!!!!!!!!!!!!"<<std::endl<<std::endl;
    library lib("");
    Admin admin;
    Book b("123","73219851","张三","null",12,Category::ADVENTURE);
    Book b2("Effective C++","978-7-121-12332-0","侯捷","电子工业出版社",2,Category::ADVENTURE);
    Book b3("汇编语言（第三版）","978-7-302-33314-2","王爽","清华大学出版社",1,Category::PRIMER);
    Book b4("算法竞赛从入门到进阶","978-7-302-52","罗永军、郭卫斌","清华大学出版社",12,Category::PRIMER);
    
    lib.SetLogFile("logfile.dat");
    lib.buy(admin,b);
    lib.buy(admin,b2);
    lib.buy(admin,b3);
    lib.buy(admin,b4);
    lib_search_test(lib,admin);
    lib_borrow_test(lib,Reader());
    system("pause");
    return 0;
}
void lib_borrow_test(library &lib,Reader const&r){
    lib.list();
    Book b("算法竞赛从入门到进阶","978-7-302-52","罗永军、郭卫斌","清华大学出版社",1,Category::PRIMER);
    lib.borrow(r,"978-7-302-52");
    lib.borrow(r,"978-7-302-33314-2");
    lib.list(1);
    lib.borrow(r,"978-7-302-33314-2");
    if(lib.ret(r,"978-7-302-33314-2"))std::cout<<"B"<<std::endl;
    else std::cout<<"N"<<std::endl;
    lib.personalBorrowTrace(r);
    // lib.listBorrowTrace();
    // lib.retListIndex(1);
    // lib.retAllBook(r);
}
void lib_change_name_test(library&lib,Admin& admin){
    lib.changeBookName(admin,"978-7-302-52","张三传奇录");
    lib.list();
}
void lib_search_test(library &lib,Admin& admin){
    Book b5("算法竞赛从入门到进阶","978-7-302-52","罗永军、郭卫斌","清华大学出版社",30,Category::PRIMER);
    Book b6("算法竞赛从入门到进阶","978-7-302-52","罗永军、郭卫斌","清华大学出版社",30,Category::PRIMER);
    puts("BLUR:Search 张");
    lib.search("张",library::field::BLUR);
    puts("ISBN:Search 张");
    lib.search("张",library::field::ISBN);
    puts("PRESS:Search 张");
    lib.search("张",library::field::PRESS);
    puts("NAME:Search 张");
    lib.search("张",library::field::NAME);
    puts("AUTHOR:Search 张");
    lib.search("张",library::field::AUTHOR);
    
    puts("ISBN: search 302");
    lib.search("978-7-302-52",library::field::ISBN);

    puts("before buy");
    lib.search("军",library::field::BLUR);
    puts("after buy");
    lib.buy(admin,b5);
    lib.search("军",library::field::BLUR);
    // std::cout<<b5.GetCount()<<std::endl;
    lib.discard(admin,b6);
    lib.search("军",library::field::BLUR);
    lib_change_name_test(lib,admin);
}