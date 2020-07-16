#ifndef _LIBTIME_H_
#define _LIBTIME_H_ 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#pragma warning(disable : 4996)
namespace LibSys{
    /**
     * @brief return standard format of time
     * @param null
     * @return standard format of time "yyyy/mm/dd hh/mm/ss"
     * @date 2020/7/14
     * @author 胡义林
    */
    std::string getTime();

    /**
     * @brief calculate time diff in the form of a-b
     * @param a[20] standart time format
     * @param b[20] standart time format
     * @return 0
     * @date 2020/7/14
     * @author 李小溪
    */
    int TimeSub(char a[20], char b[20]);

    /**
     * @brief calculate day diff in the form of a-b
     * @param easy to understand
     * @return day diff
     * @date 2020/7/14
     * @author 李小溪
    */
    int day_diff(int year_start, int month_start, int day_start
                , int year_end, int month_end, int day_end);
}
//for easily usage
using namespace LibSys;
#endif//_LIBTIME_H_