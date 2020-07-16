// #include"../include/library.h"
#include"../src/library.cpp"
#include"../src/trace.cpp"
#include"../src/book.cpp"
#include"../src/libTime.cpp"
int main(){
    using namespace LibSys;
    library lib;
    lib.search("Èý",library::field::BLUR);
    return 0;
}