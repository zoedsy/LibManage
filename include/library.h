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
/*==============================================================================
|函 数 名|:book的赋值运算符重载
|功能描述|:将所有book内容传递给等号左侧
|输入参数|:Book const&
|输出参数|:Book&
|返 回 值|:得到的book的引用
|创建日期|:2020年7月14日
|修改日期|:2020年7月14日
|作    者|:刘沛东
========================================================================================*/
            Book& operator=(Book const&)noexcept;
            friend class library;
            Book()=default;
/*==============================================================================
|函 数 名|:Book的构造函数
|功能描述|:将书名、isbn，作者，出版社，数量，分类传递给构造的book对象
|输入参数|:书名、isbn，作者，出版社，数量，分类
|输出参数|:无
|返 回 值|:无
|创建日期|:2020年7月14日
|修改日期|:2020年7月14日
|作    者|:刘沛东
========================================================================================*/       
            Book(std::string const&n,std::string const&isbn,std::string const&at,std::string const&pr,int const&c,Category cg);
            // Book(Book const&)noexcept=default;
            /**
             * @brief remember to delete the pointer [count]
            */
            ~Book()noexcept=default;
/*==============================================================================
|函 数 名|:Book的 = 关系运算符
|功能描述|:只根据isbn判断两本书是否为同一本
|输入参数|:Book对象
|输出参数|:bool
|返 回 值|:1为等于，0为不等于
|创建日期|:2020年7月14日
|修改日期|:2020年7月14日
|作    者|:刘沛东
========================================================================================*/     
            bool operator==(Book const&b)const noexcept{return isbn==b.isbn;}
/*==============================================================================
|函 数 名|:info
|功能描述|:将书本的所有信息推到 输出流中
|输入参数|:ostream&
|输出参数|:ostream&
|返 回 值|:ostream&
|创建日期|:2020年7月14日
|修改日期|:2020年7月14日
|作    者|:刘沛东
========================================================================================*/ 
            std::ostream& info(std::ostream&)const noexcept;

/*==============================================================================
|函 数 名|:Book内容访问函数
|功能描述|:返回对应的私有成员内容
|输入参数|:无
|输出参数|:string（数量内容为int）
|返 回 值|:对应变量
|创建日期|:2020年7月14日
|修改日期|:2020年7月14日
|作    者|:刘沛东
========================================================================================*/   
            //返回书名
            inline const std::string GetName()const noexcept{return name;}
            //返回出版社
            inline const std::string GetPress()const noexcept{return press;}
            //返回作者
            inline const std::string GetAuthor()const noexcept{return author;}
            //返回ISBN
            inline const std::string GetIsbn()const noexcept{return isbn;}
            //返回书籍剩余数量          
            inline const int GetCount()const noexcept{return count;}
            //更改书名
            inline void ChangeName(std::string const&n)noexcept{name=n;}
            //借书
            inline bool borrow()noexcept{return --count==0;}
            //还书
            inline void ret()noexcept{++count;}
            std::string toString()const noexcept;
            /**
             * @brief move extra books to this heap if equals
             * keep the merged heap at least one book
            */
            Book& merge(Book &)noexcept;
            friend std::ostream& operator<<(std::ostream&,Book const&);
    };
    //字符串到category的转化，注意小写！
    Category StringToCategory(std::string const&str);
    //category到字符串的转化，注意小写！
    std::string CategoryToString(Category cate);
    /**
     * @brief 日志相关函数 方便创建事件/行为
     * @return 返回一个 事件/行为 的字符串
     * @author 刘沛东
    */
    std::string ActionCreator(std::string const&__act,std::string const&__bn,std::string const&__isbn);
    /**
     * @brief 日志直接关联类 产生一条日志消息
    */
    class Message final{
        std::string time,person,action;
        public:
        Message(std::string const&t,std::string const&p,std::string const&a)noexcept
            :time(t),person(p),action(a){}
        /**
         * @brief 重载函数调用运算符来产生日志信息
         * @return 日志信息
         * @date 2020/7/15
         * @author 刘沛东
        */
        std::string operator()()const noexcept;
    };
    /**
     * @brief partial core class of this system
     * 提供图书馆方面相关的所有功能
     * @date 2020/7/15
     * @author 刘沛东
    */
    class library{
        private:
            static library* lib;
            trace                                               borrow_trace;
            std::unordered_multimap<std::string,std::string>    NameToISBN;
            std::unordered_map<std::string,Book>                BooksMap;
            std::string                                         DestFile;
            /**
             * @brief fetch the data from file
            */
            void update(std::string const&file=DefaultFile)noexcept;
            /**
             * @brief set log file which can't be changed by anyone
            */
            static std::string LOGFILE;
            void log(Message const&m)noexcept;
            library()noexcept{update();}
        public:
            //------don't output info to screen func--------//
            const static std::string DefaultFile;//default file set
            /**
             * @brief default constructor 
             * using the default file to fetch data
            */
            static library* getLibrary();
            ~library()noexcept{};
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
             * @brief set the log file for debug or run in a diff env
             * if not set, use the default file to record logs
             * @return return current file set for log
            */
            std::string SetLogFile(std::string const&)noexcept;
            /**
             * @brief save data to specific file
            */
            void save(std::string const&file=DefaultFile);
            enum field{ISBN,NAME,AUTHOR,PRESS,BLUR};
            
            /**
             * @brief purchase a bunch of books
            */
            void buy(Admin const&,Book &)noexcept;
            
            //----------output info to screen func--------//
            
            
            
            /**
             * @brief borrow book by isbn
            */
            bool borrow(Reader const&,std::string const&_isbn)noexcept;
            /**
             * @brief borrow book with complete info
            */
            bool borrow(Reader const&,Book const&)noexcept;
            /**
             * @brief return book by passing all info
             * @return return true if succeed
            */
            bool ret(Reader const&,Book const&)noexcept;
            /**
             * @brief return book by passing the isbn
             * @return return true if succeed
            */
            bool ret(Reader const&,std::string const&_isbn)noexcept;
            /**
             * @brief change book name using the specific isbn by administrator
             * @return whether the isbn exists or not
            */
            bool changeBookName(Admin const&,std::string const&_isbn,std::string const&_newName);
            /**
             * @brief discard a bunch of books
            */
            void discard(Admin const&,Book const&)noexcept;
            /**
             * @brief search book by field
             * @return return true if exists
            */
            bool search(std::string const&seg,field f=field::NAME)noexcept;
            /**
             * @brief list all books
             * @param Details list all info about this book if Details is true
            */
            void list(bool Details=0)const noexcept;
            /**
             * @brief list all infomation of borrow_trace though lots of lines
             * for admin
            */
            void listBorrowTrace()const noexcept;
            /**
             * @brief return the book by pointing the specific line of the showed info via listBorrowTrace
            */
            void retListIndex(unsigned)noexcept;
            /**
             * @brief return all books of the Reader
            */
            void retAllBook(Reader const&)noexcept;
            /**
             * @brief output the personal borrow trace
             * output null if none
            */
           void personalBorrowTrace(Reader const&reader)noexcept;
    };
}
#endif//_LIBRARY_H_