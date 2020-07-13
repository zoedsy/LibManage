#include"library.h"
#include<iostream>
namespace LibSys{
    Book::Book(std::string n,std::string is,std::string pr,int const&c,Category cg)try
        :name(n),isbn({is}),press(pr),count(new int(c)),cate(cg){}
        catch(std::bad_alloc const&){std::cerr<<"out of the contain of library"<<std::endl;}
}
