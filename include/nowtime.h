#ifndef _nowtime_h_
#define _nowtime_h_ 1
#include<stdio.h>
#include<time.h>
#include <iostream>
#pragma warning(disable : 4996) 
using namespace std;

string getTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d %H/%M/%S", localtime(&timep));
	return tmp;
}

#endif//_nowtime_h_