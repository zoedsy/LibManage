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
    trace() = default;
    void append(std::string NAME, std::string ISBN, std::string LEND_TIME)
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
    //通过姓名删除（代表还书）   特别的，返回值为借书时间的字符串
    std::string remove_people(std::string);
    //通过show_all的序号删除（代表还书）
    std::string remove_ID(int n);

    ~trace() = default;
};
void trace::show_all()
{
    std::cout << "序号\tISBN\t借书人\t借书时间\n";
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
        std::cout << "没有借阅记录";
    }
}
void trace::search_people(std::string name)
{
    std::cout << "正在按人查找信息" << std::endl;
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
        std::cout << "没有借阅记录";
    }
}
std::string trace::remove_people(std::string name)
{
    std::cout << "正在按人删除信息" << std::endl;
    int size = book_trace.size();
    if (size == 0)
    {
        std::cout << "没有借阅记录!无法删除！";
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
                std::cout << "正在移除借阅记录" << std::endl;
                std::cout << i << "\t" << it->isbn << it->name << it->lend_time << std::endl;
                std::string temp = it->lend_time;
                book_trace.erase(it);
                flag = 0;
                return temp;
            }
            it++;
        }
        if (flag)
            std::cout << "没有找到该姓名！";
        it = book_trace.begin();
        return "";
    }
}
std::string trace::remove_ID(int n)
{
    std::cout << "正在按序号删除信息" << std::endl;
    int size = book_trace.size();
    if (size == 0)
    {
        std::cout << "没有借阅记录！无法删除";
        return "";
    }
    else if (n > size || n < 0)
    {
        std::cout << "请输入正确的序号！";
        return "";
    }
    else if
    {
        for (int i = 1; i <= size; i++)
        {

            if (i == n)
            {
                size--;
                std::cout << "正在移除借阅记录" << std::endl;
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
}