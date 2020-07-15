#ifndef _LIBTIME_H_
#define _LIBTIME_H_ 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#pragma warning(disable : 4996)
namespace LibSys{
    std::string getTime();
    int TimeSub(char a[20], char b[20]);


    int day_diff(int year_start, int month_start, int day_start
                , int year_end, int month_end, int day_end);
}
using namespace LibSys;
#endif//_LIBTIME_H_