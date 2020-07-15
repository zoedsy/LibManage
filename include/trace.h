#pragma once
#include <string>
#include <list>
#include <iostream>
#include <iterator>
class trace
{
private:
    typedef struct
    {
        std::string name;
        std::string isbn;
        std::string lend_time;
    } tip;
    std::list<tip> book_trace;
    std::list<trace::tip>::iterator it = book_trace.begin();

public:
    trace();
    void append(std::string NAME, std::string ISBN, std::string lend)
    {
        tip temp;
        temp.name = NAME;
        temp.isbn = ISBN;
        temp.lend_time = lend;
        book_trace.push_back(temp);
    }
    //通过姓名查找信息并输出
    void search_people(std::string);
    //展示全部信息
    void show_all();
    //通过姓名删除（代表还书）
    void remove_people(std::string);
    //通过show_all的序号删除（代表还书）
    void remove_ID(int n);

    ~trace();
};
void trace::show_all()
{
    std::cout << "序号\tISBN\t借书人\t借书时间\n";
    int size = book_trace.size();
    for (int i = 1; i <= size; i++)
    {
        std::cout << i << "\t" << it->isbn << it->name << it->lend_time << std::endl;
        it++;
    }
    std::cout << std::endl;
    it = book_trace.begin();
}

trace::trace(/* args */)
{
}

trace::~trace()
{
}
