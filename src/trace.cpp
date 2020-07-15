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
std::list<std::string> trace::search_people(std::string name)
{
    std::list<std::string> ISBNs;
    std::cout << "���ڰ��˲�����Ϣ" << std::endl;
    int size = book_trace.size();
    if (size != 0)
    {
        for (int i = 1; i <= size; i++)
        {
            if (it->name == name){
                std::cout << i << "\t" << it->isbn << it->name << it->lend_time << std::endl;
                ISBNs.push_back(it->isbn);
            }
            it++;
        }
        std::cout << std::endl;
        it = book_trace.begin();
    }
    else
    {
        std::cout << "û�н��ļ�¼";
    }return ISBNs;
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
trace::tip trace::remove_ID(int n)
{
    std::cout << "���ڰ����ɾ����Ϣ" << std::endl;
    int size = book_trace.size();
    if (size == 0)
    {
        std::cout << "û�н��ļ�¼���޷�ɾ��";
        return {"","",""};
    }
    else if (n > size || n < 0)
    {
        std::cout << "��������ȷ����ţ�";
        return {"","",""};
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