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
    //ͨ������������Ϣ�����
    void search_people(std::string);
    //չʾȫ����Ϣ
    void show_all();
    //ͨ������ɾ���������飩
    void remove_people(std::string);
    //ͨ��show_all�����ɾ���������飩
    void remove_ID(int n);

    ~trace();
};
void trace::show_all()
{
    std::cout << "���\tISBN\t������\t����ʱ��\n";
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
