#pragma once
#include <string>
#include <list>
#include <iostream>
#include <iterator>
class trace
{
public:
    struct tip{
        std::string name;
        std::string isbn;
        std::string lend_time;
        bool operator==(const tip &object)
        {
            return name == object.name && isbn == object.isbn;
        }
    };
private:
    mutable std::list<tip> book_trace;
    mutable std::list<trace::tip>::iterator it = book_trace.begin();

public:
    trace() = default;
    void append(std::string NAME, std::string ISBN, std::string LEND_TIME)
    {
        book_trace.push_back({NAME,ISBN,LEND_TIME});
    }
    //ͨ������������Ϣ�����
    std::list<std::string> search_people(std::string);
    //չʾȫ����Ϣ
    void show_all()const;
    //ͨ������ɾ�����������飩   �ر�ģ�����ֵΪ����ʱ����ַ���
    std::string remove_people(std::string);
    //ͨ��show_all�����ɾ�����������飩
    tip remove_ID(int n);
    std::string erase(tip const&object)noexcept;

    ~trace() = default;
};
