#include"../include/trace.h"
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

void trace::show_all()const
{
    std::list<trace::tip>::iterator it = book_trace.begin();
    std::cout << "序号\tISBN\t书名\t借出时间\n";
    int size = book_trace.size();
    if (size != 0)
    {
        for (int i = 1; i <= size; i++)
        {
            std::cout << i << "\t" << it->isbn <<'\t'<< it->name <<'\t'<< it->lend_time << std::endl;
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
std::list<std::string> trace::search_people(std::string name)
{
    std::list<trace::tip>::iterator it = book_trace.begin();
    std::list<std::string> ISBNs;
    std::cout << "正在按姓名查找记录：" << std::endl;
    int size = book_trace.size();
    if (size != 0)
    {
        for (int i = 1; i <= size; i++)
        {
            if (it->name == name){
                std::cout << i << "\t" << it->isbn <<'\t'<< it->name<<'\t' << it->lend_time << std::endl;
                ISBNs.push_back(it->isbn);
            }
            it++;
        }
        std::cout << std::endl;
        it = book_trace.begin();
    }
    else
    {
        std::cout << "没有借阅记录";
    }return ISBNs;
}
std::string trace::remove_people(std::string name)
{
    std::list<trace::tip>::iterator it = book_trace.begin();
    std::cout << "正在按姓名移除借阅记录：" << std::endl;
    int size = book_trace.size();
    if (size == 0)
    {
        std::cout << "没有借阅记录，无法删除！";
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
                std::cout << "该借书记录已被移除！" << std::endl;
                std::cout << i << "\t" << it->isbn<<'\t' << it->name <<'\t'<< it->lend_time << std::endl;
                std::string temp = it->lend_time;
                book_trace.erase(it);
                flag = 0;
                return temp;
            }
            it++;
        }
        if (flag)
            std::cout << "没有找到该姓名";
        it = book_trace.begin();
        return "";
    }
}
trace::tip trace::remove_ID(int n)
{
    std::list<trace::tip>::iterator it = book_trace.begin();
    std::cout << "正在按序号移除记录:" << std::endl;
    int size = book_trace.size();
    if (size == 0)
    {
        std::cout << "没有借阅记录，无法移除！";
        return {"","",""};
    }
    else if (n > size || n < 0)
    {
        std::cout << "序号错误，找不到该条信息！";
        return {"","",""};
    }
    else 
    {
        for (int i = 1; i <= size; i++)
        {

            if (i == n)
            {
                size--;
                std::cout << "该记录已被移除！" << std::endl;
                std::cout << i << "\t" << it->isbn<<'\t' << it->name<<'\t' << it->lend_time << std::endl;
                std::string temp = it->lend_time;
                trace::tip ret={it->name,it->isbn,it->lend_time};
                book_trace.erase(it);
                return ret;
            }
            it++;
        }
        it = book_trace.begin();
        return {"","",""};
    }
}