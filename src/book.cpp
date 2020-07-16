#include"../include/library.h"
#include<iostream>
#include<map>
namespace LibSys{
    //-----auxilary function-----//
    std::string CategoryToString(Category cate){
        switch(cate){
            case MAGAZINE:
                return "magezine";
            case TEXTBOOK:
                return "textbook";
            case PRIMER:
                return "primer";
            case AUTOBIOGRAPHY:
                return "autobiography";
            case FAIRY:
                return "fairy";
            case NOVEL:
                return "novel";
            case ADVENTURE:
                return "adventure";
            case FICTION:
                return "fiction";
            case SUNDRIES:
                return "sundries";
            default:
                return "";
        }
    }
    Category StringToCategory(std::string const&str){
        if(str=="magezine")return Category::MAGAZINE;
        else if(str=="textbook")return Category::TEXTBOOK;
        else if(str=="primer")return Category::PRIMER;
        else if(str=="autobiography")return Category::AUTOBIOGRAPHY;
        else if(str=="fairy")return Category::FAIRY;
        else if(str=="novel")return Category::NOVEL;
        else if(str=="adventure")return Category::ADVENTURE;
        else if(str=="fiction")return Category::FICTION;
        else if(str=="sundries")return Category::SUNDRIES;
        return Category::SUNDRIES;
    }
    //----friend function of Book----//
    std::ostream& operator<<(std::ostream&os,Book const&book){
        return book.info(os);
    }
    //------member part--------//

    Book& Book::operator=(Book const&b)noexcept{
        name=b.name;
        author=b.author;
        press=b.press;
        count=b.count;
        cate=b.cate;
        isbn=b.isbn;
        return *this;
    }
    Book::Book(std::string const&n,std::string const&isbn,std::string const&at,std::string const&pr,int const&c,Category cg)
        :name(n),isbn(isbn),author(at),press(pr),count(c),cate(cg){}
    
    Book& Book::merge(Book &b)noexcept{
        count+=b.count;
        b.count=0;
        return *this;
    }

    std::ostream& Book::info(std::ostream&os=std::cout)const noexcept{
        os<<"ISBN: "<<isbn
        <<"\tname: "<<name
        <<"\nauthor: "<<author
        <<"\tpress: "<<press
        <<"\nremains: "<<count<<"\t belongs to "<<CategoryToString(cate)<<std::endl;
        return os;
    }

    std::string Book::toString()const noexcept{
        return
            isbn+' '+name+' '+author+' '+press+' '
            +std::to_string(count)+' '+CategoryToString(cate);
        }
}
