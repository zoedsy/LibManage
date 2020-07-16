#include "../src/library.cpp"
#include "../src/trace.cpp"
#include "../src/libtime.cpp"
#include "../src/book.cpp"
#include <iostream>
int main()
{
    library mylib;
    cout << endl;
    mylib.list(1);
    auto it = mylib.BooksMap.begin();
    cout << endl;
    cout << it->first;
    Admin me;
    Book a("Effective_C++","978-7-121-12332-0","侯捷","电子工业出版社",2,Category::PRIMER);
    mylib.buy(me,a);
    mylib.list(1);
    mylib.save();
    system("pause");
}