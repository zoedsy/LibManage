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
	vector<string>Password2;//�������鴢��������˻�
	static Logs*ls;
	Logs(){

	}
public:
	static Logs*getLogs();

	/* ============================================================
|�� �� ��|��autosave1
|��������|�����ı������ݴ洢������Ա�˺������ļ���
|�������|����
|�������|����
|�� �� ֵ|����
|��������|��2020��7��13��
|�޸�����|��2020��7��16��
|��    ��|��������
=========================================================== */
	void autosave1()
	{
		ofstream file;
		file.open("admin.txt", ios::out);
		if (!file.is_open())
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
			exit(1);
		}
		else
		{
			file.clear();
			file << "�˺ţ�" << endl;			//����admin�ļ���ʽ�������
			file << Account1.size() << endl;
			for (auto a : Account1)
			{
				file << a << endl;
			}
			file << "���룺" << endl;
			file << Password1.size() << endl;
			for (auto b : Password1)
			{
				file << b << endl;
			}
		}
		file.close();
	}
	/* ============================================================
|�� �� ��|��autoget1
|��������|���ڶԹ���Ա���ݽ����޸�ǰ�������й���Ա�˺�������ļ������ݱ��浽��Ӧ����������
|�������|����
|�������|����
|�� �� ֵ|����
|��������|��2020��7��13��
|�޸�����|��2020��7��16��
|��    ��|��������
=========================================================== */
	void autoget1()
	{
		ifstream infile;
		infile.open("admin.txt", ios::in);
		if (!infile.is_open())
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
			exit(1);
		}
		else
		{
			string tmp, account, password;
			int size;
			infile >> tmp;
			if (tmp == "�˺ţ�") {		//����admin�ļ���ʽ��������
				Account1.clear();
				infile >> size;
				for (int i = 0; i < size; i++) {
					infile >> account;
					Account1.push_back(account);
				}
			}
			infile >> tmp;
			if (tmp == "���룺") {
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
|�� �� ��|��goin1
|��������|�����ù���Ա�˺�������е�¼
|�������|����
|�������|����
|�� �� ֵ|����
|��������|��2020��7��13��
|�޸�����|��2020��7��16��
|��    ��|��������
=========================================================== */
	int goin1()                //����Ա
	{
		autoget1();
		string account;
		string password;
	L3: system("cls");
		cout << "�˺ţ�";
		cin >> account;
		cout << "���룺";
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
						cout << "��½�ɹ�" << endl;
						return 1;
					}
					else if ((tmp[1] == Password1.size()) && (*p != password))
					{
						cout << "�˺Ż��������,��������Ҫִ�е�ѡ�" << endl;
						cout << "        1.��������           2.�˳�" << endl;

						int i;
					L4:
						cin >> i;
						switch (i)
						{
						case 1:		goto  L3;
							break;
						case 2:		cout << "�˳���ϵͳ" << endl;
							break;
						default:    cout << "�޷�ʶ��ѡ����������룺";
							goto L4;
						}
						return 0;
					}
				}
			}
			else if ((tmp[0] == Account1.size()) && (*a != account))
			{
				cout << "�˺Ż��������,��������Ҫִ�е�ѡ�" << endl;
				cout << "        1.��������           2.�˳�" << endl;

				int i;
			L5: cin >> i;
				switch (i)
				{
				case 1:		goto  L3;
					break;
				case 2:		cout << "�˳���ϵͳ" << endl;
					break;
				default:    cout << "�޷�ʶ��ѡ����������룺";
					goto L5;
				}
			}
		}
		return 0;
	}
	/* ============================================================
|�� �� ��|��change1
|��������|���޸Ĺ����˺Ŷ�Ӧ������
|�������|����
|�������|����
|�� �� ֵ|����
|��������|��2020��7��13��
|�޸�����|��2020��7��16��
|��    ��|��������
=========================================================== */
	int change1()
	{
		autoget1();
		string account, password, password2, password3;
	L12:
		system("cls");
		cout << "�˺ţ�";
		cin >> account;
		cout << "���룺";
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
						cout << "������������(���벻����18λ)��";
						cin >> password2;
						if (password2.length() > 18)
						{
							cout << "�������18λ������������" << endl;
							goto L14;
						}
						cout << "���ٴ�ȷ�������룺";
						cin >> password3;
						if (password2 != password3)
						{
							cout << "�����������벻һ�£�����������" << endl;
							goto L14;
						}
						*p = password2;
						autosave1();
						cout << "�޸�����ɹ���" << endl;
						return 0;
					}
					else if ((tmp[1] == Password1.size()) && (*p != password))
					{
						cout << "�˺Ż��������,��������Ҫִ�е�ѡ�" << endl;
						cout << "  1.��������           2.�˳�" << endl;

						int i;
					L13:
						cin >> i;
						switch (i)
						{
						case 1:		goto  L12;
							break;
						case 2:		cout << "�˳���ϵͳ" << endl;
							break;
						default:    cout << "�޷�ʶ��ѡ����������룺";
							goto L13;
						}
					}
				}
			}
			else if ((tmp[0] == Account1.size()) && (*a != account))
			{
				cout << "�˺Ż��������,��������Ҫִ�е�ѡ�" << endl;
				cout << "        1.��������           2.�˳�" << endl;

				int i;
			L20: cin >> i;
				switch (i)
				{
				case 1:		goto  L12;
					break;
				case 2:		cout << "�˳���ϵͳ" << endl;
					break;
				default:    cout << "�޷�ʶ��ѡ����������룺";
					goto L20;
				}
			}
		}
		return 0;
	}
	/* ============================================================
	���˺�������Ϣ������߶�Ӧ���ļ�������ͬautosave1
=========================================================== */
	void autosave2()
	{
		ofstream file;
		file.open("reader.txt", ios::out);
		if (!file.is_open())
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
			exit(1);
		}
		else
		{
			file.clear();
			file << "�˺ţ�" << endl;			//����reader�ļ���ʽ�������
			file << Account2.size() << endl;
			for (auto a : Account2)
			{
				file << a << endl;
			}
			file << "���룺" << endl;
			file << Password2.size() << endl;
			for (auto b : Password2)
			{
				file << b << endl;
			}
		}
		file.close();
	}
	/* ============================================================
	��ȡ�ļ��ж��߶�Ӧ���˺����룬����ͬautoget1
=========================================================== */
	void autoget2()
	{
		ifstream infile;
		infile.open("reader.txt", ios::in);
		if (!infile.is_open())
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
			exit(1);
		}
		else
		{
			string tmp, account, password;
			int size;
			infile >> tmp;
			if (tmp == "�˺ţ�") {								//����reader�ļ���ʽ��������
				Account1.clear();
				infile >> size;
				for (int i = 0; i < size; i++) {
					infile >> account;
					Account2.push_back(account);
				}
			}
			infile >> tmp;
			if (tmp == "���룺") {
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
	���߽��е�¼������ͬgoin1
=========================================================== */
	int goin2()                //����
	{
		autoget2();
		string account;
		string password;
	L8:	system("cls");
		cout << "�˺ţ�";
		cin >> account;
		cout << "���룺";
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
						cout << "��½�ɹ�" << endl;
						return 1;
					}
					else if ((tmp[1] == Password2.size()) && (*p != password))
					{
						cout << "�˺Ż��������,��������Ҫִ�е�ѡ�" << endl;
						cout << "        1.��������           2.�˳�" << endl;

						int i;
					L6:
						cin >> i;
						switch (i)
						{
						case 1:		goto  L8;
							break;
						case 2:		cout << "�˳���ϵͳ" << endl;
							break;
						default:    cout << "�޷�ʶ��ѡ����������룺";
							goto L6;
						}
						return 0;
					}
				}
			}
			else if ((tmp[0] == Account2.size()) && (*a != account))
			{
				cout << "�˺Ż��������,��������Ҫִ�е�ѡ�" << endl;
				cout << "        1.��������           2.�˳�" << endl;

				int i;
			L7: cin >> i;
				switch (i)
				{
				case 1:		goto  L8;
					break;
				case 2:		cout << "�˳���ϵͳ" << endl;
					break;
				default:    cout << "�޷�ʶ��ѡ����������룺";
					goto L7;
				}
			}
		}
		return 0;
	}
	/* ============================================================
|�� �� ��|��registers2
|��������|�����߽����˺�����ע��
|�������|����
|�������|����
|�� �� ֵ|����
|��������|��2020��7��13��
|�޸�����|��2020��7��16��
|��    ��|��������
=========================================================== */
	void registers2()
	{
		string account;
		string password;
		string password2;
		autoget2();
	L10: system("cls");
		cout << "������ע���˺ţ�";
		cin >> account;
		for (auto a : Account2)
		{
			if (a == account)
			{
				cout << "���˺��ѱ�ע�ᣬ����������" << endl;
				system("pause");
				goto L10;
			}
		}
	L22: cout << "����������(���벻����18λ)��";
		cin >> password;
		if (password.length() > 18)
		{
			cout << "�������18λ������������" << endl;
			goto L22;
		}
		cout << "���ٴ��������룺";
		cin >> password2;
		while (password != password2)
		{
			cout << "�������벻һ�£����ٴ�ȷ�ϣ�";
			cin >> password2;
		}
		Account2.push_back(account);				//ѹ��Accout����������
		Password2.push_back(password);			//ѹ��Password����������
		autosave2();
		cout << "ע��ɹ�" << endl;
		system("pause");
		system("cls");
	}
	/* ============================================================
	  ���߽��������޸ģ�����ͬchange1
=========================================================== */
	int change2()
	{
		autoget2();
		string account, password, password2, password3;
	L16:
		system("cls");
		cout << "�˺ţ�";
		cin >> account;
		cout << "���룺";
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
						cout << "������������(���벻����18λ)��";
						cin >> password2;
						if (password2.length() > 18)
						{
							cout << "�������18λ������������" << endl;
							goto L17;
						}
						cout << "���ٴ�ȷ�������룺";
						cin >> password3;
						if (password2 != password3)
						{
							cout << "�����������벻һ�£�����������" << endl;
							goto L17;
						}
						*p = password2;
						autosave2();
						cout << "�޸�����ɹ���" << endl;
						system("pause");
						return 0;
					}
					else if ((tmp[1] == Password2.size()) && (*p != password))
					{
						cout << "�˺Ż��������,��������Ҫִ�е�ѡ�" << endl;
						cout << "  1.��������           2.�˳�" << endl;

						int i;
					L18:
						cin >> i;
						switch (i)
						{
						case 1:		goto  L16;
							break;
						case 2:		cout << "�˳���ϵͳ" << endl;
							break;
						default:    cout << "�޷�ʶ��ѡ����������룺";
							goto L18;
						}
					}
				}
			}
			else if ((tmp[0] == Account2.size()) && (*a != account))
			{
				cout << "�˺Ż��������,��������Ҫִ�е�ѡ�" << endl;
				cout << "        1.��������           2.�˳�" << endl;

				int i;
			L19: cin >> i;
				switch (i)
				{
				case 1:		goto  L16;
					break;
				case 2:		cout << "�˳���ϵͳ" << endl;
					break;
				default:    cout << "�޷�ʶ��ѡ����������룺";
					goto L19;
				}
			}
		}
		return 0;
	}
};

#endif



