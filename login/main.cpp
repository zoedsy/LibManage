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
void apply1()   //����Ա����
{
	system("pause");
	exit(0);
}
void apply2()   //���߹���
{
	system("pause");
	exit(0);
}
void apply3()    //�ο͹���
{
	system("pause");
	exit(0);
}
void logins()
{
L0:
	logs l;
	cout << " ------С��ͼ�����ϵͳ��¼------" << endl;
	cout << "       1.����Ա                  " << endl;
	cout << "       2.����                    " << endl;
	cout << "       3.�ο�                    " << endl;
	cout << "       4.�˳�                    " << endl;
	cout << " --------------------------------" << endl;
	int i;  cin >> i;
	switch (i)
	{
	case 1:
	{
	L1:
		system("cls");
		cout << "--------����Ա--------" << endl;
		cout << "***********************" << endl;
		cout << "       1.��¼          " << endl;
		cout << "       2.ע��          " << endl;
		cout << "       3.�޸�����      " << endl;
		cout << "       4.�˳�����      " << endl;
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
			cout << "�˳���½����" << endl;
			break;
		}
		default:
		{
			cout << "��Ч�������֣�����������" << endl;
			goto L1;
		}
		}
		break;
	}
	case 2:
	{
	L2:
		system("cls");
		cout << "---------����---------" << endl;
		cout << "***********************" << endl;
		cout << "       1.��¼          " << endl;
		cout << "       2.ע��          " << endl;
		cout << "       3.�޸�����      " << endl;
		cout << "       4.�˳�����      " << endl;
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
			cout << "�˳���½����" << endl;
			break;
		}
		default:
		{
			cout << "��Ч�������֣�����������" << endl;
			goto L2;
		}
		}
		break;
	}
	case 3:
	{
		cout << "---------�ο�---------" << endl;
		apply3();
	}
	break;
	case 4:
	{
		cout << "-------�˳��ɹ�-------" << endl;
		system("pause");
		exit(0);
		break;
	}
	default:
	{
		cout << "--�����������������--" << endl;
		goto L0;
		break;
	}
	}
	system("pause");
}