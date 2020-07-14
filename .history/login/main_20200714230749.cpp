#include"..\include\log.h"
#include"..\include\person.h"
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


void logins()
{
L0:
	// logs l;
	cout << " ------小川图书管理系统登录------" << endl;
	cout << "       1.管理员                  " << endl;
	cout << "       2.读者                    " << endl;
	cout << "       3.游客                    " << endl;
	cout << "       4.退出                    " << endl;
	cout << " --------------------------------" << endl;
	cout << "请输入选项（1-4）:";
	int i;  cin >> i;
	switch (i)
	{
	case 1:
	{
		Admin adm;
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
			if (adm.ls->goin1() == 1)
				adm.apply1();
			break;
		}
		case 2:
		{
			adm.ls->registers1();
			goto L1;
		}
		case 3:
		{
			adm.ls->change1();
			goto L1;
		}
		case 4:
		{
			cout << "返回上一页" << endl;
			goto L0;
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
		Reader rea;
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
			if (rea.ls->goin2() == 1)
				rea.apply2();
			break;
		}
		case 2:
		{
			rea.ls->registers2();
			goto L2;
		}
		case 3:
		{
			rea.ls->change2();
			goto L2;
		}
		case 4:
		{
			cout << "返回上一页" << endl;
			goto L0;
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
		Visitor vis;

		cout << "---------游客---------" << endl;
		vis.apply3();
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