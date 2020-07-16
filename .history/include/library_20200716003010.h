#ifndef _LIBRARY_H_
#define _LIBRARY_H_ 1
#include"trace.h"
#include"person.h"
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
            int count=0;
            Category cate=Category::SUNDRIES;
            std::string isbn;
        public:
            Book& operator=(Book const&)noexcept;
            friend class library;
            Book()=default;
            Book(std::string const&n,std::string const&isbn,std::string const&at,std::string const&pr,int const&c,Category cg);
            // Book(Book const&)noexcept=default;
            /**
             * @brief remember to delete the pointer [count]
            */
            ~Book()noexcept=default;
            bool operator==(Book const&b)const noexcept{return isbn==b.isbn;}
            std::ostream& info(std::ostream&)const noexcept;
            inline const std::string GetName()const noexcept{return name;}
            inline const std::string GetPress()const noexcept{return press;}
            inline const std::string GetAuthor()const noexcept{return author;}
            inline const std::string GetIsbn()const noexcept{return isbn;}
            inline const int GetCount()const noexcept{return count;}
            inline void ChangeName(std::string const&n)noexcept{name=n;}
            inline bool borrow()noexcept{return --count==0;}
            inline void ret()noexcept{++count;}
            std::string toString()const noexcept;
            /**
             * @brief move extra books to this heap if equals
             * keep the merged heap at least one book
            */
            Book& merge(Book &)noexcept;
            friend std::ostream& operator<<(std::ostream&,Book const&);
    };
    Category StringToCategory(std::string const&str);
    std::string CategoryToString(Category cate);
    std::string ActionCreator(const char*__act,const char*__bn,const char*__isbn);
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
            trace                                               borrow_trace;
            std::unordered_multimap<std::string,std::string>    NameToISBN;
            std::string                                         DestFile;
            /**
             * @brief fetch the data from file
            */
            void update(std::string const&file=DefaultFile)noexcept;
            /**
             * @brief set log file which can't be changed by anyone
            */
            static const std::string LOGFILE;
            void log(Message const&m)noexcept;
        public:
            const static std::string DefaultFile;//default file set
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
            bool borrow(Reader const&,std::string const&_isbn)noexcept;
            /**
             * @brief search book with complete info
            */
            bool borrow(Reader const&,Book const&)noexcept;
            /**
             * @brief return book
            */
            bool ret(Reader const&,Book const&)noexcept;
            bool ret(Reader const&,std::string const&_isbn)noexcept;
            bool changeBookName(Admin const&,std::string const&_isbn,std::string const&_newName);
            /**
             * @brief purchase a bunch of books
            */
            void buy(Admin const&,Book &)noexcept;
            /**
             * @brief discard a bunch of books
            */
            void discard(Admin const&,Book const&)noexcept;
            [[deprecated]]void sell(Person const&,Book const&)noexcept{}
            /**
             * @brief search book by field
            */
            bool search(std::string const&seg,field f=field::NAME)noexcept;
            /**
             * @brief list all books
             * @param Details list all info about this book if Details is true
            */
            void list(bool Details=0)const noexcept;
            void listBorrowTrace()const noexcept;
            void retAllBook(Reader const&)noexcept;
            void retListIndex(unsigned)noexcept;
    };
}
#endif//_LIBRARY_H_
