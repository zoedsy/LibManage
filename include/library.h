#ifndef _LIBRARY_H_
#define _LIBRARY_H_ 1
#include<iosfwd>
#include<string>
#include<unordered_map>
namespace LibSys{
    enum Category{MAGAZINE,TEXTBOOK,PRIMER,AUTOBIOGRAPHY,FAIRY,NOVEL,ADVENTURE,FICTION,SUNDRIES};

    class library;
    /**
     * @brief the book class which contains the all info of book itself
    */
    class Book{
        private:
            std::string name,author,press;
            int count;
            const Category cate;
        public:
            friend class library;
            const std::string isbn;
            Book()=delete;
            Book(std::string n,std::string isbn,std::string pr,int const&c,Category cg);
            Book(Book const&)noexcept;
            /**
             * @brief remember to delete the pointer [count]
            */
            ~Book()noexcept;
            Book& operator=(Book const&)noexcept=delete;
            bool operator==(Book const&b)const noexcept{return isbn==b.isbn;}
            inline const std::string GetName()const noexcept{return name;}
            inline const std::string GetPress()const noexcept{return press;}
            inline const std::string GetAuthor()const noexcept{return author;}
            inline const std::string GetIsbn()const noexcept{return isbn;}
            inline void ChangeName(std::string const&n)noexcept{name=n;}
            inline bool borrow()noexcept{return --count==0;}
            inline void ret()noexcept{++count;}
    };
    std::string ActionCreator(const char*__act,const char*__bn,const char*__isbn){
        return std::string(__act)+" "+__bn+"(ISBN:"+__isbn+")";
    }
    class visitor;
    class member;
    class admin;
    class Message final{
        std::string time,person,action;
        public:
        Message(std::string const&t,std::string const&p,std::string const&a)noexcept
            :time(t),person(p),action(a){}
        std::string operator()()const noexcept;
    };
    /**
     * @brief remember to log every action
    */
    class library{
        private:
            std::unordered_map<std::string,Book>                BooksMap;
            std::unordered_map<member,Book>                   borrow_trace;
            std::unordered_multimap<std::string,std::string>    NameToISBN;
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
            enum field{ISBN,NAME,AUTHOR,PRESS,BLUR};
            /**
             * @brief search book by bookname or else
            */
            bool borrow(member const&,std::string const&,field)noexcept;
            /**
             * @brief search book with complete info
            */
            bool borrow(member const&,Book const&)noexcept;
            /**
             * @brief return book
            */
            bool ret(member const&,Book const&)noexcept;
            bool changeBookName(admin const&,std::string const&,field,std::string const&);
            /**
             * @brief purchase a bunch of books
            */
            void buy(admin const&,Book const&)noexcept;
            /**
             * @brief discard a bunch of books
            */
            void discard(admin const&,Book const&)noexcept;
            [[deprecated]]void sell(visitor const&,Book const&)noexcept;
            /**
             * @brief search book by field
            */
            bool search(std::string const&seg,field f=field::NAME)noexcept;
            /**
             * @brief list all books
             * @param Details list all info about this book if Details is true
            */
            void list(bool Details=0)const noexcept;
    };
}
#endif//_LIBRARY_H_
