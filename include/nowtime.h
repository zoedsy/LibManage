#ifndef _nowtime_h
#define _nowtime_h
#include<stdio.h>
#include<time.h>
#include <iostream>
#pragma warning(disable : 4996) 
using namespace std;
#endif

string getTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d %H/%M/%S", localtime(&timep));
	return tmp;
}
