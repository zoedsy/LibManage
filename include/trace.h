#pragma once
#include <string>
#include <list>
#include <iosfwd>
#include <iterator>
class trace
{
public:
    struct tip{
        std::string account;
        std::string isbn;
        std::string lend_time;
        bool operator==(const tip &object)const
        {
            return this->account == object.account && this->isbn == object.isbn;
        }
    };
private:
    mutable std::list<tip> book_trace;

public:
    /**
     * @brief initialization and get the borrow_trace from the file
     * @return null
     * @date 2020/7/16
     * @author ÁõÅæ¶«
    */
    trace()noexcept;
    /**
     * @brief destruction and save the borrow_trace to the file
     * @return null
     * @date 2020/7/16
     * @author ÁõÅæ¶«
    */
    ~trace()noexcept;
    /**
     * @name append
     * @brief get the borrow list of the person
     * @param Account the personal account
     * @param ISBN ISBN of the book
     * @param LEND_TIME the time of the book lend
     * @return null
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    void append(std::string const&Account, std::string const&ISBN, std::string const&LEND_TIME)
    {
        book_trace.push_back({Account,ISBN,LEND_TIME});
    }
    /**
     * @name search_people
     * @brief get the borrow list of the person
     * @param account the account of the person
     * @return return the list of ISBN the person borrowed
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    std::list<std::string> search_people(std::string accout);
    /**
     * @brief show all borrow list
     * @param null
     * @return null
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    void show_all()const;
    /**
     * @brief show all borrow list
     * @param null
     * @return the lent_time of the book
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    std::string remove_people(std::string);
    /**
     * @brief return the indexed book
     * @param index the index showed
     * @return info of the trace
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    tip remove_ID(int index);
    /**
     * @brief get the trace of specifc trace
     * @param object us the similar trace to search for the original trace
     * @return the lent_time of the book
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    std::string erase(tip const&object)noexcept;

};
