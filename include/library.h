#ifndef _LIBRARY_H_
#define _LIBRARY_H_ 1
#include<iosfwd>
#include<string>
#include<map>

namespace LibSys{
    enum Category{MAGAZINE,TEXTBOOK,PRIMER,AUTOBIOGRAPHY,FAIRY,NOVEL,ADVENTURE,FICTION,SUNDRIES};
    struct ISBN{
        std::string isbn;
        bool operator==(ISBN const&i)const noexcept{return isbn==i.isbn;}
    };
    /**
     * @brief the book class which contains the all info of book itself
    */
    class Book{
        private:
            std::string name,author,press;
            int*count;
            const Category cate;
        public:
            const ISBN isbn;
            Book()=delete;
            Book(std::string n,std::string isbn,std::string pr,int const&c,Category cg);
            Book(Book const&)noexcept;
            /**
             * @brief remember to delete the pointer [count]
            */
            ~Book()noexcept;
            Book& operator=(Book const&)noexcept;
            bool operator==(Book const&b){return isbn==b.isbn;}
            inline const std::string GetName()const noexcept{return name;}
            inline const std::string GetPress()const noexcept{return press;}
            inline const std::string GetAuthor()const noexcept{return author;}
            inline const std::string GetIsbn()const noexcept{return isbn.isbn;}
            inline bool borrow()noexcept{return --*count==0;}
            inline void ret()noexcept{++*count;}
    };
    struct visitor_tag{};
    struct member_tag:visitor_tag{};
    struct admin_tag:member_tag{};
    class visitor{
        protected:
            std::string name;
            /*
            data
            */
        
        public:
            typedef visitor_tag tag;

    };
    class member:public visitor{
        private:
        //data
        public:
            typedef member_tag tag;
    };
    class admin:public member{
        private:
        public:
            typedef admin_tag tag;
    };
    class Message final{
        std::string time,person,action;
        public:
        Message(std::string const&t,std::string const&p,std::string const&a)noexcept
            :time(t),person(p),action(a){}
        std::string operator()()noexcept{return time+" : "+person+" "+action;}
    };
    /**
     * @brief remember to log every action
    */
    class library{
        private:
            std::map<std::string,Book> BooksMap;
            std::map<visitor*,Book>borrow_trace;
            std::string DestFile;
            /**
             * @brief fetch the data from file
            */
            void update(std::string const&file=DefaultFile)noexcept;
            /**
             * @brief set log file which can't be changed by anyone
            */
            static constexpr char*LOGFILE="";
            void log(Message const&m)noexcept;
        public:
            constexpr static char*DefaultFile="";//default file set
            /**
             * @brief default constructor 
             * using the default file to fetch data
            */
            library()noexcept{update();}
            ~library()noexcept;
            /**
             * @brief assign the file to reload
             * @param file the assigned file
            */
            library(std::string const&file)noexcept{update(file);}
            /**
             * @brief set the data file before exit
             * if not set, use the default file to keep the data
             * @return return current file set for storage
            */
            std::string setDestFile(std::string const&)noexcept;
            /**
             * @brief save data to specific file
            */
            void save(std::string const&file="");
            /**
             * @brief search book by bookname or else
            */
            bool borrow(member const&,std::string const&)noexcept;
            /**
             * @brief search book by ISBN
            */
            bool borrow(member const&,ISBN const&)noexcept;
            /**
             * @brief search book with complete info
            */
            bool borrow(member const&,Book const&)noexcept;
            /**
             * @brief return book
            */
            bool ret(member const&,Book const&)noexcept;
            bool changeBookName(admin const&,Book const&,std::string const&);
            bool changeBookName(admin const&,ISBN const&,std::string const&);
            void buy(admin const&,Book const&)noexcept;
    };
}
#endif//_LIBRARY_H_
