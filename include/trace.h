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
std::string trace::erase(tip const&object)noexcept
{
    std::string time;
    for (auto it = book_trace.begin(); it != book_trace.end(); it++)
    {
        if (*it==object)
        {
            time = it->lend_time;
            book_trace.erase(it);
        }
    }
    return time;
}

void trace::show_all()
{
    std::cout << "���\tISBN\t������\t����ʱ��\n";
    int size = book_trace.size();
    if (size != 0)
    {
        for (int i = 1; i <= size; i++)
        {
            std::cout << i << "\t" << it->isbn << it->name << it->lend_time << std::endl;
            it++;
        }
        std::cout << std::endl;
        it = book_trace.begin();
    }
    else
    {
        std::cout << "û�н��ļ�¼";
    }
}
void trace::search_people(std::string name)
{
    std::cout << "���ڰ��˲�����Ϣ" << std::endl;
    int size = book_trace.size();
    if (size != 0)
    {
        for (int i = 1; i <= size; i++)
        {
            if (it->name == name)
                std::cout << i << "\t" << it->isbn << it->name << it->lend_time << std::endl;
            it++;
        }
        std::cout << std::endl;
        it = book_trace.begin();
    }
    else
    {
        std::cout << "û�н��ļ�¼";
    }
}
std::string trace::remove_people(std::string name)
{
    std::cout << "���ڰ���ɾ����Ϣ" << std::endl;
    int size = book_trace.size();
    if (size == 0)
    {
        std::cout << "û�н��ļ�¼!�޷�ɾ����";
        return "";
    }
    else
    {
        bool flag = 1;
        for (int i = 1; i <= size; i++)
        {
            if (it->name == name)
            {
                size--;
                std::cout << "�����Ƴ����ļ�¼" << std::endl;
                std::cout << i << "\t" << it->isbn << it->name << it->lend_time << std::endl;
                std::string temp = it->lend_time;
                book_trace.erase(it);
                flag = 0;
                return temp;
            }
            it++;
        }
        if (flag)
            std::cout << "û���ҵ���������";
        it = book_trace.begin();
        return "";
    }
}
std::string trace::remove_ID(int n)
{
    std::cout << "���ڰ����ɾ����Ϣ" << std::endl;
    int size = book_trace.size();
    if (size == 0)
    {
        std::cout << "û�н��ļ�¼���޷�ɾ��";
        return "";
    }
    else if (n > size || n < 0)
    {
        std::cout << "��������ȷ����ţ�";
        return "";
    }
    else 
    {
        for (int i = 1; i <= size; i++)
        {

            if (i == n)
            {
                size--;
                std::cout << "�����Ƴ����ļ�¼" << std::endl;
                std::cout << i << "\t" << it->isbn << it->name << it->lend_time << std::endl;
                std::string temp = it->lend_time;
                book_trace.erase(it);
                return temp;
            }
            it++;
        }
        it = book_trace.begin();
        return "";
    }
}