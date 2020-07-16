#pragma once
#include <string>
#include <list>
#include <iostream>
#include <iterator>
class trace
{
public:
    struct tip{
        std::string name;
        std::string isbn;
        std::string lend_time;
        bool operator==(const tip &object)
        {
            return name == object.name && isbn == object.isbn;
        }
    };
private:
    mutable std::list<tip> book_trace;

public:
    trace() = default;
    /**
     * @name append
     * @brief get the borrow list of the person
     * @param NAME the personal account
     * @param ISBN ISBN of the book
     * @param LEND_TIME the time of the book lend
     * @return null
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    void append(std::string NAME, std::string ISBN, std::string LEND_TIME)
    {
        book_trace.push_back({NAME,ISBN,LEND_TIME});
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
     * @param n the index showed
     * @return info of the trace
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    tip remove_ID(int n);
    /**
     * @brief get the trace of specifc trace
     * @param object us the similar trace to search for the original trace
     * @return the lent_time of the book
     * @date 2020/7/14
     * @author ÂíÏþ³¿
    */
    std::string erase(tip const&object)noexcept;

    ~trace() = default;
};
