#include"../include/library.h"
#include"../include/libTime.h"
#include"../include/person.h"
#include<iostream>
#include<fstream>
namespace LibSys{
    //import namespace std
    using namespace std;
    
    //---------Message----------------//
    std::string Message::operator()()const noexcept{
        return time+'\t'+person+'\t'+action;
    }
    std::string ActionCreator(const char*__act,const char*__bn,const char*__isbn){
        return std::string(__act)+" "+__bn+"(ISBN:"+__isbn+")";
    }
    //--------library-------------//
    const std::string library::DefaultFile="defaultfile.dat";
    const std::string library::LOGFILE="logfile.dat";

    void library::log(Message const&meg)noexcept{
        std::ofstream ofs(library::LOGFILE,std::ios::app);
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

    bool library::borrow(Reader const&m,std::string const&seg,field f)noexcept{
            switch(f)
            {
            case ISBN:
                try{
                    BooksMap.at(seg);
                    Book book=BooksMap[seg];
                    if(--BooksMap[seg].count==0)
                        BooksMap.erase(seg);
                    borrow_trace.append(m.GetAccount(),seg,getTime());
                    log(Message(getTime(),m.GetAccount(),ActionCreator("borrow",book.GetName().c_str(),book.isbn.c_str())));
                    return true;
                }catch(std::out_of_range&){
                    return false;
                }
                break;
            case NAME:
                for(auto&&it:NameToISBN){

                }
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
    bool library::borrow(Reader const&m,Book const&book)noexcept{
        for(auto&&it:BooksMap){
            if(it.second==book){
                if(--it.second.count==0){
                    borrow_trace.append(m.GetAccount(),book.GetIsbn(),getTime());
                    log(Message(getTime(),m.GetAccount(),
                        ActionCreator("borrow",book.GetName().c_str(),book.isbn.c_str())));
                    return true;
                }
            }
        }return false;
    }
    bool library::ret(Reader const&m,Book const&book)noexcept{
        borrow_trace.erase({book.name,book.isbn,""});
        log(Message(getTime(),m.GetAccount(),ActionCreator("return",book.GetName().c_str(),book.isbn.c_str())));
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
    void library::buy(Admin const&ad,Book &book)noexcept{
        try{
            BooksMap.at(book.GetIsbn());
            BooksMap[book.GetIsbn()].merge(book);
        }catch(std::out_of_range&){
            BooksMap[book.GetIsbn()]=book;
        }
        log(Message(getTime(),ad.GetAccount(),
                        ActionCreator("buy/add",book.GetName().c_str(),book.isbn.c_str())));
    }
    bool library::changeBookName(Admin const&Ad,std::string const&_isbn,field,std::string const&new_name){
        try{
            BooksMap.at(_isbn);
            BooksMap[_isbn].ChangeName(new_name);
            log(Message(getTime(),Ad.GetAccount(),
                        ActionCreator("change book: ",_isbn.c_str(),(" to "+new_name).c_str())));
        }catch(std::out_of_range&){
            std::cerr<<"Book Not Exists!"<<std::endl;
        }
    }
    void library::discard(Admin const&Ad,Book const&book)noexcept{
        try{
            BooksMap.at(book.GetIsbn());
            log(Message(getTime(),Ad.GetAccount(),
                ActionCreator("discard "+book.GetCount(),book.GetName().c_str(),book.isbn.c_str())));
            for(int i=0;i<book.GetCount();++i)
                if(BooksMap[book.GetIsbn()].borrow()){
                    std::cerr<<"Book "<<book.GetName()
                        <<"\tISBN: "<<book.GetIsbn()
                        <<"run out"<<std::endl;
                log(Message(getTime(),Ad.GetAccount(),
                    ActionCreator("discard all",book.GetName().c_str(),book.isbn.c_str())));
                }
        }catch(std::out_of_range&){
            std::cerr<<"Book No Found!"<<std::endl;
        }
    }
}
