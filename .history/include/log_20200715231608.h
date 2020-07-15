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
	public:
		void autosave1()
		{
			ofstream file;
			file.open("admin.txt", ios::out);
			if (!file.is_open())
			{
				cout << "文件打开失败！" << endl;
			}
			else
			{
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
		void autoget1()
		{
			ifstream infile;
			infile.open("admin.txt", ios::in);
			if (!infile.is_open())
			{
				cout << "文件打开失败！" << endl;
			}
			else
			{
				string tmp, account, password;
				int size;
				infile >> tmp;
				if (tmp == "账号：") {								//依照admin文件格式输入数据
					infile >> size;
					for (int i = 0; i < size; i++) {
						infile >> account;
						Account1.push_back(account);
					}
				}
				infile >> tmp;
				if (tmp == "密码：") {
					infile >> size;
					for (int i = 0; i < size; i++) {
						infile >> password;
						Password1.push_back(password);
					}
				}
			}
			infile.close();
		}
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
		void registers1()   //管理员
		{
			{
				string account;
				string password;
				string password2;
				autoget1();
			L9: system("cls");
				cout << "请输入注册账号：";
				cin >> account;
				for (auto a : Account1)
				{
					if (a == account)
					{
						cout << "该账号已被注册，请重新输入" << endl;
						goto L9;
					}
				}
				cout << "请输入密码(密码不超过18位)：";
				cin >> password;
				cout << "请再次输入密码：";
				cin >> password2;
				while (password != password2)
				{
					cout << "两次密码不一致，请再次确认：";
					cin >> password2;
				}
				Account1.push_back(account);				//压入Accout向量数组中
				Password1.push_back(password);			//压入Password向量数组中
				autosave1();
				cout << "注册成功" << endl;
				system("pause");
				system("cls");
			}
		}
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
							cout << "请输入新密码：" ;  
							cin >> password2;
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
		void autosave2()
		{
			ofstream file;
			file.open("reader.txt", ios::out);
			if (!file.is_open())
			{
				cout << "文件打开失败！" << endl;
			}
			else
			{
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
		void autoget2()
		{
			ifstream infile;
			infile.open("reader.txt", ios::in);
			if (!infile.is_open())
			{
				cout << "文件打开失败！" << endl;
			}
			else
			{
				string tmp, account, password;
				int size;
				infile >> tmp;
				if (tmp == "账号：") {								//依照reader文件格式输入数据
					infile >> size;
					for (int i = 0; i < size; i++) {
						infile >> account;
						Account2.push_back(account);
					}
				}
				infile >> tmp;
				if (tmp == "密码：") {
					infile >> size;
					for (int i = 0; i < size; i++) {
						infile >> password;
						Password2.push_back(password);
					}
				}
			}
			infile.close();
		}
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
						goto L10;
					}
				}
				cout << "请输入密码(密码不超过18位)：";
				cin >> password;
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
							cout << "请输入新密码：";
							cin >> password2;
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


// class Logs
// {
// 	private:
// 		vector<string>Account1;
// 		vector<string>Password1;
// 		vector<string>Account2;
// 		vector<string>Password2;//向量数组储存密码和账户
// 	public:
// 		void autosave1()
// 		{
// 			ofstream file;
// 			file.open("admin.txt", ios::out);
// 			if (!file.is_open())
// 			{
// 				cout << "文件打开失败！" << endl;
// 				exit(1);
// 			}
// 			else
// 			{
// 				file.clear();
// 				file << "账号：" << endl;			//依照admin文件格式输出数据
// 				file << Account1.size() << endl;
// 				for (auto a : Account1)
// 				{
// 					file << a << endl;
// 				}
// 				file << "密码：" << endl;
// 				file << Password1.size() << endl;
// 				for (auto b : Password1)
// 				{
// 					file << b << endl;
// 				}
// 			}
// 			file.close();
// 		}
// 		void autoget1()
// 		{
// 			ifstream infile;
// 			infile.open("admin.txt", ios::in);
// 			if (!infile.is_open())
// 			{
// 				cout << "文件打开失败！" << endl;
// 				exit(1);
// 			}
// 			else
// 			{
// 				string tmp, account, password;
// 				int size;
// 				infile >> tmp;
// 				if (tmp == "账号：") {								//依照admin文件格式输入数据
// 					Account1.clear();
// 					infile >> size;
// 					for (int i = 0; i < size; i++) {
// 						infile >> account;
// 						Account1.push_back(account);
// 					}
// 				}
// 				infile >> tmp;
// 				if (tmp == "密码：") {
// 					Password1.clear();
// 					infile >> size;
// 					for (int i = 0; i < size; i++) {
// 						infile >> password;
// 						Password1.push_back(password);
// 					}
// 				}
// 			}
// 			infile.close();
// 		}
// 		int goin1()                //管理员
// 		{
// 				autoget1();
// 				string account;
// 				string password;
// 			    system("cls");
// 				cout << "账号：";
// 				cin >> account;
// 				cout << "密码：";
// 				cin >> password;
// 				int tmp[2] = { 0,0 };
// 				for (auto a = Account1.begin(); a != Account1.end(); a++)
// 				{
// 					tmp[0]++;
// 					if (*a == account)
// 					{
// 						for (auto p = Password1.begin(); p != Password1.end(); p++)
// 						{
// 							tmp[1]++;
// 							if ((*p == password) && (tmp[0] == tmp[1]))
// 							{
// 								cout << "登陆成功" << endl;
// 								return 1;
// 							}
// 							else if ((tmp[1] == Password1.size()) && (*p != password))
// 							{
// 								cout << "账号或密码错误,请输入您要执行的选项：" << endl;
// 								cout << "        1.重新输入           2.退出" << endl;
// 								goin11();
// 								return 0;
// 							}
// 						}
// 					}
// 					else if ((tmp[0] == Account1.size()) && (*a != account))
// 					{
// 						cout << "账号或密码错误,请输入您要执行的选项：" << endl;
// 						cout << "        1.重新输入           2.退出" << endl;
// 						goin11();
// 					}
// 				}
// 				return 0;
// 			}
// 		int goin11()
// 		{
// 			int i;
// 			cin >> i;
// 			switch (i)
// 			{
// 			case 1:		goin1();
// 				break;
// 			case 2:		cout << "退出本系统" << endl;
// 				break;
// 			default:    cout << "无法识别选项，请重新输入：";
// 				      goin11();
// 			}
// 			return 0;
// 		}

// 		int change1()
// 		{
// 			autoget1();
// 			string account, password, password2;
// 			system("cls");
// 			cout << "账号：";
// 			cin >> account;
// 			cout << "密码：";
// 			cin >> password;
// 			int tmp[2] = { 0,0 };
// 			for (auto a = Account1.begin(); a != Account1.end(); a++)
// 			{
// 				tmp[0]++;
// 				if (*a == account)
// 				{
// 					for (auto p = Password1.begin(); p != Password1.end(); p++)
// 					{
// 						tmp[1]++;
// 						if ((*p == password) && (tmp[0] == tmp[1]))
// 						{
// 							password2=change11();
// 							*p = password2;
// 							autosave1();
// 							cout << "修改密码成功！" << endl;
// 							system("pause");
// 							return 0;
// 						}
// 						else if ((tmp[1] == Password1.size()) && (*p != password))
// 						{
// 							cout << "账号或密码错误,请输入您要执行的选项：" << endl;
// 							cout << "  1.重新输入           2.退出" << endl;
// 							change12();
// 						}
// 					}
// 				}
// 				else if ((tmp[0] == Account1.size()) && (*a != account))
// 				{
// 					cout << "账号或密码错误,请输入您要执行的选项：" << endl;
// 					cout << "        1.重新输入           2.退出" << endl;
// 				}
// 			}
// 			return 0;
// 		}
// 		string change11()
// 		{
// 			string password2, password3;
// 			cout << "请输入新密码(密码不超过18位)：";
// 			cin >> password2;
// 			if (password2.length() > 18)
// 			{
// 				cout << "密码大于18位，请重新输入" << endl;
// 				change11();
// 			}
// 			cout << "请再次确认新密码：";
// 			cin >> password3;
// 			if (password2 != password3)
// 			{
// 				cout << "两次输入密码不一致，请重新输入" << endl;
// 				change11();
// 			}
// 			return password2;
// 		}
// 		int change12()
// 		{
//             int i;
// 		     cin >> i;
// 			switch (i)
// 			{
// 			case 1:		change1();
// 				break;
// 			case 2:		cout << "退出本系统" << endl;
// 				break;
// 			default:    cout << "无法识别选项，请重新输入：";
// 				change12();
// 			}
// 			return 0;
// 		}
// 			void autosave2()
// 		{
// 			ofstream file;
// 			file.open("reader.txt", ios::out);
// 			if (!file.is_open())
// 			{
// 				cout << "文件打开失败！" << endl;
// 				exit(1);
// 			}
// 			else
// 			{
// 				file.clear();
// 				file << "账号：" << endl;			//依照reader文件格式输出数据
// 				file << Account2.size() << endl;
// 				for (auto a : Account2)
// 				{
// 					file << a << endl;
// 				}
// 				file << "密码：" << endl;
// 				file << Password2.size() << endl;
// 				for (auto b : Password2)
// 				{
// 					file << b << endl;
// 				}
// 			}
// 			file.close();
// 		}
// 		void autoget2()
// 		{
// 			ifstream infile;
// 			infile.open("reader.txt", ios::in);
// 			if (!infile.is_open())
// 			{
// 				cout << "文件打开失败！" << endl;
// 				exit(1);
// 			}
// 			else
// 			{
// 				string tmp, account, password;
// 				int size;
// 				infile >> tmp;
// 				if (tmp == "账号：") {								//依照reader文件格式输入数据
// 					infile >> size;
// 					Account2.clear();
// 					for (int i = 0; i < size; i++) {
// 						infile >> account;
// 						Account2.push_back(account);
// 					}
// 				}
// 				infile >> tmp;
// 				if (tmp == "密码：") {
// 					infile >> size;
// 					Password2.clear();
// 					for (int i = 0; i < size; i++) {
// 						infile >> password;
// 						Password2.push_back(password);
// 					}
// 				}
// 			}
// 			infile.close();
// 		}
// 		int goin2()                //读者
// 		{
// 			autoget2();
// 			string account;
// 			string password;
// 			system("cls");
// 			cout << "账号：";
// 			cin >> account;
// 			cout << "密码：";
// 			cin >> password;
// 			int tmp[2] = { 0,0 };
// 			for (auto a = Account2.begin(); a != Account2.end(); a++)
// 			{
// 				tmp[0]++;
// 				if (*a == account)
// 				{
// 					for (auto p = Password2.begin(); p != Password2.end(); p++)
// 					{
// 						tmp[1]++;
// 						if ((*p == password) && (tmp[0] == tmp[1]))
// 						{
// 							cout << "登陆成功" << endl;
// 							return 1;
// 						}
// 						else if ((tmp[1] == Password2.size()) && (*p != password))
// 						{
// 							cout << "账号或密码错误,请输入您要执行的选项：" << endl;
// 							cout << "        1.重新输入           2.退出" << endl;
// 							goin21();
// 							return 0;
// 						}
// 					}
// 				}
// 				else if ((tmp[0] == Account2.size()) && (*a != account))
// 				{
// 					cout << "账号或密码错误,请输入您要执行的选项：" << endl;
// 					cout << "        1.重新输入           2.退出" << endl;
// 					goin21();
// 					return 0;
					
// 				}
// 			}
// 			return 0;
// 		}
// 		int goin21()
// 		{
// 			int i;
// 			cin >> i;
// 			switch (i)
// 			{
// 			case 1:		goin2();
// 				break;
// 			case 2:		cout << "退出本系统" << endl;
// 				break;
// 			default:    cout << "无法识别选项，请重新输入：";
// 				goin11();
// 			}
// 			return 0;
// 		}
// 		void registers2()
// 		{
// 				string account;
// 				string password;
// 				string password2;
// 				autoget2();
// 			    system("cls");
// 				cout << "请输入注册账号：";
// 				cin >> account;
// 				for (auto a : Account2)
// 				{
// 					if (a == account)
// 					{
// 						cout << "该账号已被注册，请重新输入" << endl;
// 						system("pause");
// 						registers2();
// 					}
// 				}
// 				password=registers21();
// 				Account2.push_back(account);				//压入Accout向量数组中
// 				Password2.push_back(password);			 //压入Password向量数组中
// 				autosave2();
// 				cout << "注册成功" << endl;
// 				system("pause");
// 				system("cls");
// 			}
// 		string registers21()
// 		{
// 			string password, password2;
// 		    cout << "请输入密码(密码不超过18位)：";
// 			cin >> password;
// 			if (password.length() > 18)
// 			{
// 				cout << "密码大于18位，请重新输入" << endl;
// 				registers21();
// 			}
// 			cout << "请再次输入密码：";
// 			cin >> password2;
// 			while (password != password2)
// 			{
// 				cout << "两次密码不一致，请再次确认：";
// 				cin >> password2;
// 			}
// 			return password;
// 		}
// 		int change2()
// 		{
// 			autoget2();
// 			string account, password, password2;
// 			system("cls");
// 			cout << "账号：";
// 			cin >> account;
// 			cout << "密码：";
// 			cin >> password;
// 			int tmp[2] = { 0,0 };
// 			for (auto a = Account2.begin(); a != Account2.end(); a++)
// 			{
// 				tmp[0]++;
// 				if (*a == account)
// 				{
// 					for (auto p = Password2.begin(); p != Password2.end(); p++)
// 					{
// 						tmp[1]++;
// 						if ((*p == password) && (tmp[0] == tmp[1]))
// 						{
// 							password2 = change21();
// 							*p = password2;
// 							autosave2();
// 							cout << "修改密码成功！" << endl;
// 							system("pause");
// 							return 0;
// 						}
// 						else if ((tmp[1] == Password2.size()) && (*p != password))
// 						{
// 							change22();
// 						}
// 					}
// 				}
// 				else if ((tmp[0] == Account2.size()) && (*a != account))
// 				{
// 					cout << "账号或密码错误,请输入您要执行的选项：" << endl;
// 					cout << "        1.重新输入           2.退出" << endl;
// 					change22();
// 				}
// 			}
// 			return 0;
// 		}
// 		string change21()
// 		{
// 			string password2, password3;
// 			cout << "请输入新密码(密码不超过18位)：";
// 			cin >> password2;
// 			if (password2.length() > 18)
// 			{
// 				cout << "密码大于18位，请重新输入" << endl;
// 				change21();
// 			}
// 			cout << "请再次确认新密码：";
// 			cin >> password3;
// 			if (password2 != password3)
// 			{
// 				cout << "两次输入密码不一致，请重新输入" << endl;
// 				change21();
// 			}
// 			return password2;
// 		}
// 		int change22()
// 		{
// 			int i;
// 			cin >> i;
// 			switch (i)
// 			{
// 			case 1:		change2();
// 				break;
// 			case 2:		cout << "退出本系统" << endl;
// 				break;
// 			default:    cout << "无法识别选项，请重新输入：";
// 				change22();
// 			}
// 			return 0;
// 		}
// };
#endif



