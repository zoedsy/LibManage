#ifndef _LIBRARY_H_
#define _LIBRARY_H_ 1
#include<iosfwd>
#include<string>
#include<map>

namespace LibSys{
    using Str=std::string;
    enum Category{MAGAZINE,TEXTBOOK,PRIMER,AUTOBIOGRAPHY,FAIRY,NOVEL,ADVENTURE,FICTION,SUNDRIES};
    /**
     * @brief the book class which contains the all info of book itself
    */
    class Book{
        private:
            Str name;
            int*count;
            const Category cate;
        public:
            const Str ISBN;
            Book()=delete;
            Book(Str n,Str isbn,int const&c,Category cg);
            Book(Book const&)noexcept;
            ~Book();
            Book& operator=(Book const&);
            const Str GetName()const noexcept{return name;}
    };
    struct visitor_tag{};
    struct member_tag:visitor_tag{};
    struct admin_tag:member_tag{};
    class visitor{
        protected:
            Str name;
            /*
            data
            */
        
        public:
            typedef visitor_tag tag;

    };
    enum access{MEMBER,ADMIN};
    class member:public visitor{
        private:
        //data
        public:
            constexpr static access ACCESS=MEMBER;
            typedef member_tag tag;
    };
    class admin:public member{
        private:
        public:
            constexpr static access ACCESS=ADMIN;
            typedef admin_tag tag;
    };
    class library{
        private:
            std::map<std::string,Book> BooksMap;
            std::map<visitor*,Book>borrow_trace;
        public:

    };

}
#endif//_LIBRARY_H_
