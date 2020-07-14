#include"../include/library.h"
#include"../include/nowtime.h"
#include<iostream>
#include<fstream>
namespace LibSys{
    //import namespace std
    using namespace std;
    //---------Book------------------//
    Book& Book::operator=(Book const&b)noexcept{
        name=b.name;
        author=b.author;
        press=b.press;
        count=b.count;
        cate=b.cate;
        isbn=b.isbn;
    }
    //---------Message----------------//
    string Message::operator()()const noexcept{
        return time+'\t'+person+'\t'+action;
    }

    //--------library-------------//
    void library::log(Message const&meg)noexcept{
        ofstream ofs(LOGFILE,ios::app);
        if(ofs){
            ofs<<meg()<<endl;
        }else 
            std::cerr<<"log error! Please reset log file!"<<std::endl;
        ofs.close();
        }

    string library::setDestFile(string const&NewFile)noexcept{
        string old_file=DestFile;
        DestFile=NewFile;
        return old_file;
        }

    bool library::borrow(member const&m,std::string const&seg,field f)noexcept{
            switch(f)
            {
            case ISBN:
                try{
                    BooksMap.at(seg);
                    Book book=BooksMap[seg];
                    if(--BooksMap[seg].count==0)
                        BooksMap.erase(seg);
                    borrow_trace[m]=book;
                    log(Message(getTime(),,ActionCreator("borrow",book.GetName().c_str(),book.isbn.c_str())));
                    return true;
                }catch(std::out_of_range&){
                    return false;
                }
                break;
            case NAME:
                
                break;
            case AUTHOR:
                break;
            case PRESS:
                break;
            default:
            //use regex to search
                break;
            }
        }
    bool library::borrow(member const&m,Book const&book)noexcept{
        for(auto&&it:BooksMap){
            if(it.second==book){
                if(--it.second.count==0){
                    borrow_trace[const_cast<member>(m)]=book;
                    log(Message(getTime(),,ActionCreator("borrow",book.GetName().c_str(),book.isbn.c_str())));
                    return true;
                }
            }
        }return false;
    }
    bool library::ret(member const&m,Book const&book)noexcept{
        borrow_trace.erase(m);
        log(Message(getTime(),,ActionCreator("return",book.GetName().c_str(),book.isbn.c_str())));
    }
    void library::list(bool Det)const noexcept{
        if(Det){
            for(auto&&it:BooksMap){
                std::cout<<it.first<<" "<<it.second<<std::endl;
            }
        }else{
            for(auto&&it:BooksMap){
                std::cout<<it.first<<" "<<it.second.isbn<<std::endl;
            }
        }
    }
    bool library::search(string const&seg,field f)noexcept{
        switch(f){
            case ISBN:
                try{
                    BooksMap.at(seg);
                    return true;
                }catch(std::out_of_range&){
                    return false;
                }
                break;
            case NAME:
                for(auto&&it:NameToISBN){
                    if(it.first==seg)
                        return true;
                }
                return false;
                break;
            case AUTHOR:
                for(auto&&it:BooksMap){
                    if(it.second.author==seg)
                        return true;
                }
                return false;
                break;
            case PRESS:
            for(auto&&it:BooksMap){
                    if(it.second.press==seg)
                        return true;
                }
                return false;
                break;
            default:
            //use regex to search
                break;
            }
        }
    void library::buy(admin const&ad,Book const&book)noexcept{

    }
    bool library::changeBookName(admin const&,std::string const&,field,std::string const&){

    }
    void library::discard(admin const&,Book const&)noexcept{
        
    }
}
