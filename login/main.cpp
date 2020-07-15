// #include"log.h"
#include"..\include\person.h"
#include<iostream>
#include<string>
using namespace std;

void firstPage();
void secondPage(int);
void thirdPage1(int);
void thirdPage2(int);

int main()
{
	while (1)
	{
		system("cls");
		firstPage();
	}
	return 0;
};

void firstPage(){

	cout << " ------С��ͼ�����ϵͳ��¼------" << endl;
	cout << "       1.����Ա                  " << endl;
	cout << "       2.����                    " << endl;
	cout << "       3.�ο�                    " << endl;
	cout << "       4.�˳�                    " << endl;
	cout << " --------------------------------" << endl;
	cout << "������ѡ�1-4��:";
	int i;  cin >> i;
	secondPage(i);
	
	system("pause");

}
void secondPage(int i){
	switch (i)
		{
		case 1:
		{
			
	
			system("cls");
			cout << "--------����Ա--------" << endl;
			cout << "***********************" << endl;
			cout << "       1.��¼          " << endl;
			cout << "       2.�޸�����      " << endl;
			cout << "       3.������һҳ      " << endl;
			cout << "***********************" << endl;
			int m; cin >> m;  
			thirdPage1(m);
			
			break;
		}

		case 2:
		{
			
		
			system("cls");
			cout << "---------����---------" << endl;
			cout << "***********************" << endl;
			cout << "       1.��¼          " << endl;
			cout << "       2.ע��          " << endl;
			cout << "       3.�޸�����      " << endl;
			cout << "       4.������һҳ      " << endl;
			cout << "***********************" << endl;
			int m; cin >> m;
			thirdPage2(m);
			break;
		}
		case 3:
		{
			Visitor vis;

			cout << "---------�ο�---------" << endl;
			vis.apply3();
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
			firstPage();
			
		}
		break;
	}

}
void thirdPage1(int i){
	Admin adm;
	switch (i)
			{
			case 1:
			{
				if (adm.ls->goin1() == 1)
					cout<<"dgfasdg"<<endl;
					adm.apply1();
				break;
			}
			case 2:
			{
				adm.ls->change1();
				secondPage(1);
			}
			case 3:
			{
				cout << "������һҳ" << endl;
				firstPage();
				break;
			}
			default:
			{
				cout << "��Ч�������֣�����������" << endl;
				secondPage(1);
			}
			}
	
}
void thirdPage2(int i){
		Reader rea;
		switch (i)
			{
			case 1:
			{
				if (rea.ls->goin2() == 1)
					// cout<<"kdshjglahsgsg"<<endl;
					rea.Reader::apply2();
					
				break;
			}
			case 2:
			{
				rea.ls->registers2();
				secondPage(2);
			}
			case 3:
			{
				rea.ls->change2();
				secondPage(2);
			}
			case 4:
			{
				cout << "������һҳ" << endl;
				firstPage();
				break;
			}
			default:
			{
				cout << "��Ч�������֣�����������" << endl;
				secondPage(2);
			}
			}

}


// void logins()
// {
// L0:
// 	// logs l;
// 	cout << " ------С��ͼ�����ϵͳ��¼------" << endl;
// 	cout << "       1.����Ա                  " << endl;
// 	cout << "       2.����                    " << endl;
// 	cout << "       3.�ο�                    " << endl;
// 	cout << "       4.�˳�                    " << endl;
// 	cout << " --------------------------------" << endl;
// 	cout << "������ѡ�1-4��:";
// 	int i;  cin >> i;
// 	switch (i)
// 	{
// 	case 1:
// 	{
// 		Admin adm;
// 	L1:
// 		system("cls");
// 		cout << "--------����Ա--------" << endl;
// 		cout << "***********************" << endl;
// 		cout << "       1.��¼          " << endl;
// 		cout << "       2.�޸�����      " << endl;
// 		cout << "       3.������һҳ      " << endl;
// 		cout << "***********************" << endl;
// 		int m; cin >> m;  
// 		switch (m)
// 		{
// 		case 1:
// 		{
// 			if (adm.ls->goin1() == 1)
// 				adm.apply1();
// 			break;
// 		}
// 		case 2:
// 		{
// 			adm.ls->change1();
// 			goto L1;
// 		}
// 		case 3:
// 		{
// 			cout << "������һҳ" << endl;
// 			goto L0;
// 			break;
// 		}
// 		default:
// 		{
// 			cout << "��Ч�������֣�����������" << endl;
// 			goto L1;
// 		}
// 		}
// 		break;
// 	}

// 	case 2:
// 	{
// 		Reader rea;
// 	L2:
// 		system("cls");
// 		cout << "---------����---------" << endl;
// 		cout << "***********************" << endl;
// 		cout << "       1.��¼          " << endl;
// 		cout << "       2.ע��          " << endl;
// 		cout << "       3.�޸�����      " << endl;
// 		cout << "       4.������һҳ      " << endl;
// 		cout << "***********************" << endl;
// 		int m; cin >> m;
// 		switch (m)
// 		{
// 		case 1:
// 		{
// 			if (rea.ls->goin2() == 1)
// 				rea.apply2();
// 			break;
// 		}
// 		case 2:
// 		{
// 			rea.ls->registers2();
// 			goto L2;
// 		}
// 		case 3:
// 		{
// 			rea.ls->change2();
// 			goto L2;
// 		}
// 		case 4:
// 		{
// 			cout << "������һҳ" << endl;
// 			goto L0;
// 			break;
// 		}
// 		default:
// 		{
// 			cout << "��Ч�������֣�����������" << endl;
// 			goto L2;
// 		}
// 		}
// 		break;
// 	}
// 	case 3:
// 	{
// 		Visitor vis;

// 		cout << "---------�ο�---------" << endl;
// 		vis.apply3();
// 	}
// 	break;
// 	case 4:
// 	{
// 		cout << "-------�˳��ɹ�-------" << endl;
// 		system("pause");
// 		exit(0);
// 		break;
// 	}
// 	default:
// 	{
// 		cout << "--�����������������--" << endl;
// 		goto L0;
// 		break;
// 	}
// 	}
// 	system("pause");
// }
