#pragma once
#include <string>
#include <list>
#include <iostream>
#include <iterator>
class trace
{
private:
    struct tip{
        std::string name;
        std::string isbn;
        std::string lend_time;
        bool operator==(const tip &object)
        {
            return name == object.name && isbn == object.isbn;
        }
    };
    std::list<tip> book_trace;
    std::list<trace::tip>::iterator it = book_trace.begin();

public:
    trace() = default;
    void append(std::string NAME, std::string ISBN, std::string LEND_TIME)
    {
        book_trace.push_back({NAME,ISBN,LEND_TIME});
    }
    //ͨ������������Ϣ�����
    void search_people(std::string);
    //չʾȫ����Ϣ
    void show_all();
    //ͨ������ɾ�����������飩   �ر�ģ�����ֵΪ����ʱ����ַ���
    std::string remove_people(std::string);
    //ͨ��show_all�����ɾ�����������飩
    std::string remove_ID(int n);
    std::string erase(tip const&object)noexcept;

    ~trace() = default;
};
