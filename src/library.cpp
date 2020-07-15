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

    //-----load all the book info------//
    void library::update(std::string const&file) noexcept{
        fstream data;
        data.open("../data/" + file,ios::out | ios::app);
        data.close();
        data.open("../data/" + file, ios::in);
        if(data.fail()){
            cout << "fail to find the book data!";
            exit(1);
        }
        string str;
        getline(cin,str);
        data>> str;
        int number = atoi(str.c_str());
        for(int i = 0 ; i < number ; i++){
            int temp,count;
            string name,isbn,author,press,cate;
            data >>temp >>name >> isbn>>author >> press >> count >>cate;
            Category n_cate = StringToCategory(cate);
            Book mybook(name,isbn,author,press,count,n_cate);
            BooksMap.insert(make_pair(isbn,mybook));
            NameToISBN.insert(make_pair(name,isbn));
        }
        data.close();
    }
    void library::save(std::string const&file){
        fstream data;
        data.open("../data/" + file, ios::out|ios::ate);
        if(data.fail()){
            cout <<"fail to open the saving target!";
            exit(1);
        }
        data << "序号\t书名\tISBN\t作者\t出版社\t数量\t分类\n";
        data << BooksMap.size() << endl;
        auto it = BooksMap.begin();
        for(int i = 1 ; i <= BooksMap.size() ;i++)
        {
            Book *temp;
            temp = &(it->second);
            data << i << "\t"<<temp->name <<"\t"<< temp->isbn <<"\t"<< temp->author <<"\t"<< temp-> press <<"\t" <<temp->count <<"\t"<< CategoryToString(temp->cate) << endl;
            it++;
        }
        data.close();
    }
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

    bool library::borrow(Reader const&m,std::string const&seg)noexcept{
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
        std::string BorrowTime=borrow_trace.erase({book.name,book.isbn,""});
        log(Message(getTime(),m.GetAccount(),ActionCreator("return",book.GetName().c_str(),book.isbn.c_str())));
        return BorrowTime!="";
    }
    bool library::ret(Reader const&m,std::string const&_isbn)noexcept{
        return ret(m,BooksMap[_isbn]);
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
            case NAME:
                bool found=false;
                std::cout<<"Book: "<<seg<<std::ends;
                    for(auto&&it:NameToISBN){
                        if(it.first==seg){
                            found=true;
                            std::cout<<"\tISBN: "<<it.second<<std::endl;
                        }
                    }
                return found;
            case AUTHOR:
                bool found=false;
                std::cout<<"Author: "<<seg<<std::ends;
                for(auto&&it:BooksMap){
                    if(it.second.author==seg)
                        std::cout<<"\tBook: "<<it.second.name
                            <<"\tISBN: "<<it.second.isbn<<std::endl;
                        found=true;
                }
                return found;
            case PRESS:
                bool found=false;
                std::cout<<"Press: "<<seg<<std::ends;
                for(auto&&it:BooksMap){
                    if(it.second.press==seg)
                        std::cout<<"\tBook: "<<it.second.name
                            <<"\tISBN: "<<it.second.isbn<<std::endl;
                        found=true;
                }
                return found;
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
    void library::listBorrowTrace()const noexcept{
        borrow_trace.show_all();
    }
    void library::retAllBook(Reader const&m)noexcept{
        auto&& traces=borrow_trace.search_people(m.GetAccount());
        for(auto&&tr:traces){
            ret(m,tr);
        }
        borrow_trace.remove_people(m.GetAccount());
    }
    void library::retListIndex(unsigned Ind)noexcept{
        auto ISBNToName=[&](std::string const&isbn)->std::string{
            for(auto&&it:NameToISBN){
                if(it.second==isbn)
                    return it.first;
            }return "";
        };
        auto&&temp=borrow_trace.remove_ID(Ind);
        log(Message(getTime(),temp.name,
            ActionCreator("return",ISBNToName(temp.isbn).c_str(),temp.isbn.c_str())));
    }
}
