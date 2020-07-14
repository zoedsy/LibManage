#include"log.h"
#include<iostream>
#include<string>
using namespace std;
void logins();
int main()
{
	while (1)
	{
		logins();
		system("pause");
	}
	return 0;
};
void apply1()   //管理员功能
{
	system("pause");
	exit(0);
}
void apply2()   //读者功能
{
	system("pause");
	exit(0);
}
void apply3()    //游客功能
{
	system("pause");
	exit(0);
}
void logins()
{
L0:
	logs l;
	cout << " ------小川图书管理系统登录------" << endl;
	cout << "       1.管理员                  " << endl;
	cout << "       2.读者                    " << endl;
	cout << "       3.游客                    " << endl;
	cout << "       4.退出                    " << endl;
	cout << " --------------------------------" << endl;
	int i;  cin >> i;
	switch (i)
	{
	case 1:
	{
	L1:
		system("cls");
		cout << "--------管理员--------" << endl;
		cout << "***********************" << endl;
		cout << "       1.登录          " << endl;
		cout << "       2.注册          " << endl;
		cout << "       3.修改密码      " << endl;
		cout << "       4.退出程序      " << endl;
		cout << "***********************" << endl;
		int m; cin >> m;
		switch (m)
		{
		case 1:
		{
			if (l.goin1() == 1)
				apply1();
			break;
		}
		case 2:
		{
			l.registers1();
			goto L1;
		}
		case 3:
		{
			l.change1();
			goto L1;
		}
		case 4:
		{
			cout << "退出登陆界面" << endl;
			break;
		}
		default:
		{
			cout << "无效操作数字，请重新输入" << endl;
			goto L1;
		}
		}
		break;
	}
	case 2:
	{
	L2:
		system("cls");
		cout << "---------读者---------" << endl;
		cout << "***********************" << endl;
		cout << "       1.登录          " << endl;
		cout << "       2.注册          " << endl;
		cout << "       3.修改密码      " << endl;
		cout << "       4.退出程序      " << endl;
		cout << "***********************" << endl;
		int m; cin >> m;
		switch (m)
		{
		case 1:
		{
			if (l.goin2() == 1)
				apply2();
			break;
		}
		case 2:
		{
			l.registers2();
			goto L2;
		}
		case 3:
		{
			l.change2();
			goto L2;
		}
		case 4:
		{
			cout << "退出登陆界面" << endl;
			break;
		}
		default:
		{
			cout << "无效操作数字，请重新输入" << endl;
			goto L2;
		}
		}
		break;
	}
	case 3:
	{
		cout << "---------游客---------" << endl;
		apply3();
	}
	break;
	case 4:
	{
		cout << "-------退出成功-------" << endl;
		system("pause");
		exit(0);
		break;
	}
	default:
	{
		cout << "--输入错误，请重新输入--" << endl;
		goto L0;
		break;
	}
	}
	system("pause");
}