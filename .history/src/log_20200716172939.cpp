/*
 * @Author: your name
 * @Date: 2020-07-16 17:28:47
 * @LastEditTime: 2020-07-16 17:29:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \LibManage\src\log.cpp
 */ 
#include"..\include\log.h"

Logs* Logs::getLogs(){
	return ls;
}

Logs* Logs::ls = new Logs;
