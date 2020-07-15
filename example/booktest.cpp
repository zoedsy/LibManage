#include"../include/library.h"
#include<iostream>
int main(){
    using namespace LibSys;
    Book a,b,c;
    Book d("Down","111","Mark","citic",2,Category::ADVENTURE);
    a.info(std::cout)<<std::endl<<d.toString()<<std::endl;
    a=d;
    a.borrow();
    a.ChangeName("Done");
    a.ret();
    a.merge(d);
    std::cout<<d.toString()<<std::endl<<a.toString()<<std::endl<<std::endl;
    if(a==d)
    a.info(std::cout);
    return 0;
}