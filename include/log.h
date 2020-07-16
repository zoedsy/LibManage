#ifndef _log_h
#define _log_h
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
class Logs
{
private:
	vector<string>Account1;
	vector<string>Password1;
	vector<string>Account2;
	vector<string>Password2;//向量数组储存密码和账户
	static Logs*ls;
	Logs(){

	}
public:
	static Logs*getLogs();

	/* ============================================================
|函 数 名|：autosave1
|功能描述|：将改变后的数据存储到管理员账号密码文件中
|输入参数|：无
|输出参数|：无
|返 回 值|：无
|创建日期|：2020年7月13日
|修改日期|：2020年7月16日
|作    者|：徐婉滢
=========================================================== */
	void autosave1()
	{
		ofstream file;
		file.open("admin.txt", ios::out);
		if (!file.is_open())
		{
			cout << "文件打开失败！" << endl;
			exit(1);
		}
		else
		{
			file.clear();
			file << "账号：" << endl;			//依照admin文件格式输出数据
			file << Account1.size() << endl;
			for (auto a : Account1)
			{
				file << a << endl;
			}
			file << "密码：" << endl;
			file << Password1.size() << endl;
			for (auto b : Password1)
			{
				file << b << endl;
			}
		}
		file.close();
	}
	/* ============================================================
|函 数 名|：autoget1
|功能描述|：在对管理员数据进行修改前，将存有管理员账号密码的文件的数据保存到对应向量数组中
|输入参数|：无
|输出参数|：无
|返 回 值|：无
|创建日期|：2020年7月13日
|修改日期|：2020年7月16日
|作    者|：徐婉滢
=========================================================== */
	void autoget1()
	{
		ifstream infile;
		infile.open("admin.txt", ios::in);
		if (!infile.is_open())
		{
			cout << "文件打开失败！" << endl;
			exit(1);
		}
		else
		{
			string tmp, account, password;
			int size;
			infile >> tmp;
			if (tmp == "账号：") {		//依照admin文件格式输入数据
				Account1.clear();
				infile >> size;
				for (int i = 0; i < size; i++) {
					infile >> account;
					Account1.push_back(account);
				}
			}
			infile >> tmp;
			if (tmp == "密码：") {
				Password1.clear();
				infile >> size;
				for (int i = 0; i < size; i++) {
					infile >> password;
					Password1.push_back(password);
				}
			}
		}
		infile.close();
	}
	/* ============================================================
|函 数 名|：goin1
|功能描述|：利用管理员账号密码进行登录
|输入参数|：无
|输出参数|：无
|返 回 值|：无
|创建日期|：2020年7月13日
|修改日期|：2020年7月16日
|作    者|：徐婉滢
=========================================================== */
	int goin1()                //管理员
	{
		autoget1();
		string account;
		string password;
	L3: system("cls");
		cout << "账号：";
		cin >> account;
		cout << "密码：";
		cin >> password;
		int tmp[2] = { 0,0 };
		for (auto a = Account1.begin(); a != Account1.end(); a++)
		{
			tmp[0]++;
			if (*a == account)
			{
				for (auto p = Password1.begin(); p != Password1.end(); p++)
				{
					tmp[1]++;
					if ((*p == password) && (tmp[0] == tmp[1]))
					{
						cout << "登陆成功" << endl;
						return 1;
					}
					else if ((tmp[1] == Password1.size()) && (*p != password))
					{
						cout << "账号或密码错误,请输入您要执行的选项：" << endl;
						cout << "        1.重新输入           2.退出" << endl;

						int i;
					L4:
						cin >> i;
						switch (i)
						{
						case 1:		goto  L3;
							break;
						case 2:		cout << "退出本系统" << endl;
							break;
						default:    cout << "无法识别选项，请重新输入：";
							goto L4;
						}
						return 0;
					}
				}
			}
			else if ((tmp[0] == Account1.size()) && (*a != account))
			{
				cout << "账号或密码错误,请输入您要执行的选项：" << endl;
				cout << "        1.重新输入           2.退出" << endl;

				int i;
			L5: cin >> i;
				switch (i)
				{
				case 1:		goto  L3;
					break;
				case 2:		cout << "退出本系统" << endl;
					break;
				default:    cout << "无法识别选项，请重新输入：";
					goto L5;
				}
			}
		}
		return 0;
	}
	/* ============================================================
|函 数 名|：change1
|功能描述|：修改管理账号对应的密码
|输入参数|：无
|输出参数|：无
|返 回 值|：无
|创建日期|：2020年7月13日
|修改日期|：2020年7月16日
|作    者|：徐婉滢
=========================================================== */
	int change1()
	{
		autoget1();
		string account, password, password2, password3;
	L12:
		system("cls");
		cout << "账号：";
		cin >> account;
		cout << "密码：";
		cin >> password;
		int tmp[2] = { 0,0 };
		for (auto a = Account1.begin(); a != Account1.end(); a++)
		{
			tmp[0]++;
			if (*a == account)
			{
				for (auto p = Password1.begin(); p != Password1.end(); p++)
				{
					tmp[1]++;
					if ((*p == password) && (tmp[0] == tmp[1]))
					{
					L14:
						cout << "请输入新密码(密码不超过18位)：";
						cin >> password2;
						if (password2.length() > 18)
						{
							cout << "密码大于18位，请重新输入" << endl;
							goto L14;
						}
						cout << "请再次确认新密码：";
						cin >> password3;
						if (password2 != password3)
						{
							cout << "两次输入密码不一致，请重新输入" << endl;
							goto L14;
						}
						*p = password2;
						autosave1();
						cout << "修改密码成功！" << endl;
						return 0;
					}
					else if ((tmp[1] == Password1.size()) && (*p != password))
					{
						cout << "账号或密码错误,请输入您要执行的选项：" << endl;
						cout << "  1.重新输入           2.退出" << endl;

						int i;
					L13:
						cin >> i;
						switch (i)
						{
						case 1:		goto  L12;
							break;
						case 2:		cout << "退出本系统" << endl;
							break;
						default:    cout << "无法识别选项，请重新输入：";
							goto L13;
						}
					}
				}
			}
			else if ((tmp[0] == Account1.size()) && (*a != account))
			{
				cout << "账号或密码错误,请输入您要执行的选项：" << endl;
				cout << "        1.重新输入           2.退出" << endl;

				int i;
			L20: cin >> i;
				switch (i)
				{
				case 1:		goto  L12;
					break;
				case 2:		cout << "退出本系统" << endl;
					break;
				default:    cout << "无法识别选项，请重新输入：";
					goto L20;
				}
			}
		}
		return 0;
	}
	/* ============================================================
	将账号密码信息存入读者对应的文件，功能同autosave1
=========================================================== */
	void autosave2()
	{
		ofstream file;
		file.open("reader.txt", ios::out);
		if (!file.is_open())
		{
			cout << "文件打开失败！" << endl;
			exit(1);
		}
		else
		{
			file.clear();
			file << "账号：" << endl;			//依照reader文件格式输出数据
			file << Account2.size() << endl;
			for (auto a : Account2)
			{
				file << a << endl;
			}
			file << "密码：" << endl;
			file << Password2.size() << endl;
			for (auto b : Password2)
			{
				file << b << endl;
			}
		}
		file.close();
	}
	/* ============================================================
	获取文件中读者对应的账号密码，功能同autoget1
=========================================================== */
	void autoget2()
	{
		ifstream infile;
		infile.open("reader.txt", ios::in);
		if (!infile.is_open())
		{
			cout << "文件打开失败！" << endl;
			exit(1);
		}
		else
		{
			string tmp, account, password;
			int size;
			infile >> tmp;
			if (tmp == "账号：") {								//依照reader文件格式输入数据
				Account1.clear();
				infile >> size;
				for (int i = 0; i < size; i++) {
					infile >> account;
					Account2.push_back(account);
				}
			}
			infile >> tmp;
			if (tmp == "密码：") {
				Password1.clear();
				infile >> size;
				for (int i = 0; i < size; i++) {
					infile >> password;
					Password2.push_back(password);
				}
			}
		}
		infile.close();
	}
	/* ============================================================
	读者进行登录，功能同goin1
=========================================================== */
	int goin2()                //读者
	{
		autoget2();
		string account;
		string password;
	L8:	system("cls");
		cout << "账号：";
		cin >> account;
		cout << "密码：";
		cin >> password;
		int tmp[2] = { 0,0 };
		for (auto a = Account2.begin(); a != Account2.end(); a++)
		{
			tmp[0]++;
			if (*a == account)
			{
				for (auto p = Password2.begin(); p != Password2.end(); p++)
				{
					tmp[1]++;
					if ((*p == password) && (tmp[0] == tmp[1]))
					{
						cout << "登陆成功" << endl;
						return 1;
					}
					else if ((tmp[1] == Password2.size()) && (*p != password))
					{
						cout << "账号或密码错误,请输入您要执行的选项：" << endl;
						cout << "        1.重新输入           2.退出" << endl;

						int i;
					L6:
						cin >> i;
						switch (i)
						{
						case 1:		goto  L8;
							break;
						case 2:		cout << "退出本系统" << endl;
							break;
						default:    cout << "无法识别选项，请重新输入：";
							goto L6;
						}
						return 0;
					}
				}
			}
			else if ((tmp[0] == Account2.size()) && (*a != account))
			{
				cout << "账号或密码错误,请输入您要执行的选项：" << endl;
				cout << "        1.重新输入           2.退出" << endl;

				int i;
			L7: cin >> i;
				switch (i)
				{
				case 1:		goto  L8;
					break;
				case 2:		cout << "退出本系统" << endl;
					break;
				default:    cout << "无法识别选项，请重新输入：";
					goto L7;
				}
			}
		}
		return 0;
	}
	/* ============================================================
|函 数 名|：registers2
|功能描述|：读者进行账号密码注册
|输入参数|：无
|输出参数|：无
|返 回 值|：无
|创建日期|：2020年7月13日
|修改日期|：2020年7月16日
|作    者|：徐婉滢
=========================================================== */
	void registers2()
	{
		string account;
		string password;
		string password2;
		autoget2();
	L10: system("cls");
		cout << "请输入注册账号：";
		cin >> account;
		for (auto a : Account2)
		{
			if (a == account)
			{
				cout << "该账号已被注册，请重新输入" << endl;
				system("pause");
				goto L10;
			}
		}
	L22: cout << "请输入密码(密码不超过18位)：";
		cin >> password;
		if (password.length() > 18)
		{
			cout << "密码大于18位，请重新输入" << endl;
			goto L22;
		}
		cout << "请再次输入密码：";
		cin >> password2;
		while (password != password2)
		{
			cout << "两次密码不一致，请再次确认：";
			cin >> password2;
		}
		Account2.push_back(account);				//压入Accout向量数组中
		Password2.push_back(password);			//压入Password向量数组中
		autosave2();
		cout << "注册成功" << endl;
		system("pause");
		system("cls");
	}
	/* ============================================================
	  读者进行密码修改，功能同change1
=========================================================== */
	int change2()
	{
		autoget2();
		string account, password, password2, password3;
	L16:
		system("cls");
		cout << "账号：";
		cin >> account;
		cout << "密码：";
		cin >> password;
		int tmp[2] = { 0,0 };
		for (auto a = Account2.begin(); a != Account2.end(); a++)
		{
			tmp[0]++;
			if (*a == account)
			{
				for (auto p = Password2.begin(); p != Password2.end(); p++)
				{
					tmp[1]++;
					if ((*p == password) && (tmp[0] == tmp[1]))
					{
					L17:
						cout << "请输入新密码(密码不超过18位)：";
						cin >> password2;
						if (password2.length() > 18)
						{
							cout << "密码大于18位，请重新输入" << endl;
							goto L17;
						}
						cout << "请再次确认新密码：";
						cin >> password3;
						if (password2 != password3)
						{
							cout << "两次输入密码不一致，请重新输入" << endl;
							goto L17;
						}
						*p = password2;
						autosave2();
						cout << "修改密码成功！" << endl;
						system("pause");
						return 0;
					}
					else if ((tmp[1] == Password2.size()) && (*p != password))
					{
						cout << "账号或密码错误,请输入您要执行的选项：" << endl;
						cout << "  1.重新输入           2.退出" << endl;

						int i;
					L18:
						cin >> i;
						switch (i)
						{
						case 1:		goto  L16;
							break;
						case 2:		cout << "退出本系统" << endl;
							break;
						default:    cout << "无法识别选项，请重新输入：";
							goto L18;
						}
					}
				}
			}
			else if ((tmp[0] == Account2.size()) && (*a != account))
			{
				cout << "账号或密码错误,请输入您要执行的选项：" << endl;
				cout << "        1.重新输入           2.退出" << endl;

				int i;
			L19: cin >> i;
				switch (i)
				{
				case 1:		goto  L16;
					break;
				case 2:		cout << "退出本系统" << endl;
					break;
				default:    cout << "无法识别选项，请重新输入：";
					goto L19;
				}
			}
		}
		return 0;
	}
};

#endif



