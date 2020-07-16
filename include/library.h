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
|�� �� ��|:book�ĸ�ֵ���������
|��������|:������book���ݴ��ݸ��Ⱥ����
|�������|:Book const&
|�������|:Book&
|�� �� ֵ|:�õ���book������
|��������|:2020��7��14��
|�޸�����|:2020��7��14��
|��    ��|:���涫
========================================================================================*/
            Book& operator=(Book const&)noexcept;
            friend class library;
            Book()=default;
/*==============================================================================
|�� �� ��|:Book�Ĺ��캯��
|��������|:��������isbn�����ߣ������磬���������ഫ�ݸ������book����
|�������|:������isbn�����ߣ������磬����������
|�������|:��
|�� �� ֵ|:��
|��������|:2020��7��14��
|�޸�����|:2020��7��14��
|��    ��|:���涫
========================================================================================*/       
            Book(std::string const&n,std::string const&isbn,std::string const&at,std::string const&pr,int const&c,Category cg);
            // Book(Book const&)noexcept=default;
            /**
             * @brief remember to delete the pointer [count]
            */
            ~Book()noexcept=default;
/*==============================================================================
|�� �� ��|:Book�� = ��ϵ�����
|��������|:ֻ����isbn�ж��������Ƿ�Ϊͬһ��
|�������|:Book����
|�������|:bool
|�� �� ֵ|:1Ϊ���ڣ�0Ϊ������
|��������|:2020��7��14��
|�޸�����|:2020��7��14��
|��    ��|:���涫
========================================================================================*/     
            bool operator==(Book const&b)const noexcept{return isbn==b.isbn;}
/*==============================================================================
|�� �� ��|:info
|��������|:���鱾��������Ϣ�Ƶ� �������
|�������|:ostream&
|�������|:ostream&
|�� �� ֵ|:ostream&
|��������|:2020��7��14��
|�޸�����|:2020��7��14��
|��    ��|:���涫
========================================================================================*/ 
            std::ostream& info(std::ostream&)const noexcept;

/*==============================================================================
|�� �� ��|:Book���ݷ��ʺ���
|��������|:���ض�Ӧ��˽�г�Ա����
|�������|:��
|�������|:string����������Ϊint��
|�� �� ֵ|:��Ӧ����
|��������|:2020��7��14��
|�޸�����|:2020��7��14��
|��    ��|:���涫
========================================================================================*/   
            //��������
            inline const std::string GetName()const noexcept{return name;}
            //���س�����
            inline const std::string GetPress()const noexcept{return press;}
            //��������
            inline const std::string GetAuthor()const noexcept{return author;}
            //����ISBN
            inline const std::string GetIsbn()const noexcept{return isbn;}
            //�����鼮ʣ������          
            inline const int GetCount()const noexcept{return count;}
            //��������
            inline void ChangeName(std::string const&n)noexcept{name=n;}
            //����
            inline bool borrow()noexcept{return --count==0;}
            //����
            inline void ret()noexcept{++count;}
            std::string toString()const noexcept;
            /**
             * @brief move extra books to this heap if equals
             * keep the merged heap at least one book
            */
            Book& merge(Book &)noexcept;
            friend std::ostream& operator<<(std::ostream&,Book const&);
    };
    //�ַ�����category��ת����ע��Сд��
    Category StringToCategory(std::string const&str);
    //category���ַ�����ת����ע��Сд��
    std::string CategoryToString(Category cate);
    /**
     * @brief ��־��غ��� ���㴴���¼�/��Ϊ
     * @return ����һ�� �¼�/��Ϊ ���ַ���
     * @author ���涫
    */
    std::string ActionCreator(std::string const&__act,std::string const&__bn,std::string const&__isbn);
    /**
     * @brief ��־ֱ�ӹ����� ����һ����־��Ϣ
    */
    class Message final{
        std::string time,person,action;
        public:
        Message(std::string const&t,std::string const&p,std::string const&a)noexcept
            :time(t),person(p),action(a){}
        /**
         * @brief ���غ��������������������־��Ϣ
         * @return ��־��Ϣ
         * @date 2020/7/15
         * @author ���涫
        */
        std::string operator()()const noexcept;
    };
    /**
     * @brief partial core class of this system
     * �ṩͼ��ݷ�����ص����й���
     * @date 2020/7/15
     * @author ���涫
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