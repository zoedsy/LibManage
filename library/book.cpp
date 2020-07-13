#include"library.h"
#include<iostream>
namespace LibSys{
    Book::Book(Str n,Str isbn,int const&c,Category cg)try
        :name(n),ISBN(isbn),count(new int(c)),cate(cg){}
        catch(std::bad_alloc const&){std::cerr<<"out of the contain of library"<<std::endl;}
}
