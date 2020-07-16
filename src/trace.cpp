#include"../include/trace.h"
#include <iostream>
#include<fstream>
trace::trace()noexcept{
    std::ifstream ifs("data/borrow_trace.dat");
    if(ifs){
        std::string NumOfLine,s1,s2,s3;
        ifs>>NumOfLine;
        auto&& lines=std::stoul(NumOfLine);
        for(unsigned long i=0;i<lines;++i){
            ifs>>NumOfLine>>s1>>s2>>s3;
            book_trace.push_back({NumOfLine,s1,s2+' '+s3});
        }
    }else 
        std::cerr<<"borrow_trace file doesn't open!"<<std::endl;
}
trace::~trace()noexcept{
    std::ofstream ofs("data/borrow_trace.dat");
    if(ofs){
        ofs<<book_trace.size()<<std::endl;
        for(auto&&it:book_trace){
            ofs<<it.account<<'\t'
                <<it.isbn<<'\t'
                <<it.lend_time<<std::endl;
        }
    }else 
        std::cerr<<"borrow_trace file doesn't open! the data can't be saved correctly"<<std::endl;

}
std::string trace::erase(tip const&object)noexcept
{
    std::string time;
    for (auto it = book_trace.begin(); it != book_trace.end(); it++)
    {
        if (*it==object)
        {
            time = it->lend_time;
            book_trace.erase(it);
            return time;
        }
    }std::cerr<<"δ����飬�޷��黹"<<std::endl;
    return time;
}

void trace::show_all()const
{
    std::list<trace::tip>::iterator it = book_trace.begin();
    std::cout << "���\tISBN\t����\t���ʱ��\n";
    int size = book_trace.size();
    if (size != 0)
    {
        for (int i = 1; i <= size; i++)
        {
            std::cout << i << "\t" << it->isbn <<'\t'<< it->account <<'\t'<< it->lend_time << std::endl;
            it++;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "û�н��ļ�¼";
    }
}
std::list<std::string> trace::search_people(std::string account)
{
    std::list<trace::tip>::iterator it = book_trace.begin();
    std::list<std::string> ISBNs;
    std::cout << "���ڰ��������Ҽ�¼��" << std::endl;
    int size = book_trace.size();
    if (size != 0)
    {
        for (int i = 1; i <= size; i++)
        {
            if (it->account == account){
                std::cout << i << "\t" << it->isbn <<'\t'<< it->account<<'\t' << it->lend_time << std::endl;
                ISBNs.push_back(it->isbn);
            }
            it++;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "û�н��ļ�¼";
    }return ISBNs;
}
std::string trace::remove_people(std::string account)
{
    std::list<trace::tip>::iterator it = book_trace.begin();
    std::cout << "���ڰ������Ƴ����ļ�¼��" << std::endl;
    int size = book_trace.size();
    if (size == 0)
    {
        std::cout << "û�н��ļ�¼���޷�ɾ����";
        return "";
    }
    else
    {
        bool flag = 1;
        for (int i = 1; i <= size; i++)
        {
            if (it->account == account)
            {
                size--;
                std::cout << "�ý����¼�ѱ��Ƴ���" << std::endl;
                std::cout << i << "\t" << it->isbn<<'\t' << it->account <<'\t'<< it->lend_time << std::endl;
                std::string temp = it->lend_time;
                book_trace.erase(it);
                flag = 0;
                return temp;
            }
            it++;
        }
        if (flag)
            std::cout << "û���ҵ�������";
        return "";
    }
}
trace::tip trace::remove_ID(int n)
{
    std::list<trace::tip>::iterator it = book_trace.begin();
    std::cout << "���ڰ�����Ƴ���¼:" << std::endl;
    int size = book_trace.size();
    if (size == 0||n > size || n < 0)
    {
        std::cout << "û�н��ļ�¼���޷��Ƴ���";
        return {"","",""};
    }
    else 
    {
        for (int i = 1; i <= size; i++)
        {

            if (i == n)
            {
                size--;
                std::cout << "�ü�¼�ѱ��Ƴ���" << std::endl;
                std::cout << i << "\t" << it->isbn<<'\t' << it->account<<'\t' << it->lend_time << std::endl;
                std::string temp = it->lend_time;
                trace::tip ret={it->account,it->isbn,it->lend_time};
                book_trace.erase(it);
                return ret;
            }
            it++;
        }
        return {"","",""};
    }
}