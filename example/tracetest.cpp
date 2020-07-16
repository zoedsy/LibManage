#include"../include/trace.h"
#include"../include/library.h"
int main(){
    trace tr;
    tr.append("name","isbn","2020");
    tr.append("name","isbn","2020");
    tr.show_all();
    tr.erase({"name","isbn",""});
    tr.search_people("name");
    system("pause");
    return 0;
}