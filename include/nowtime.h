<<<<<<< HEAD
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
=======
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
>>>>>>> 9bf07aed318804657ffa4baeb81846f84c4a452f
