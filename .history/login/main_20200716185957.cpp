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
		// cout<<"bugbugbugbug"<<endl;
		firstPage();
	}
	return 0;
};

void firstPage(){
    system("cls")
	cout << " ------Ð¡´¨Í¼Êé¹ÜÀíÏµÍ³------" << endl;
	cout << "       1.¹ÜÀíÔ±                  " << endl;
	cout << "       2.¶ÁÕß                    " << endl;
	cout << "       3.ÓÎ¿Í                    " << endl;
	cout << "       4.ÍË³öÏµÍ³                    " << endl;
	cout << " --------------------------------" << endl;
	cout << "ÇëÊäÈëÑ¡Ïî£¨1-4£©:";
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
			cout << "--------¹ÜÀíÔ±½çÃæ--------" << endl;
			cout << "***********************" << endl;
			cout << "       1.µÇÂ½          " << endl;
			cout << "       2.ÐÞ¸ÄÃÜÂë      " << endl;
			cout << "       3.·µ»ØÉÏÒ»¼¶      " << endl;
			cout << "***********************" << endl;
			int m; cin >> m;  
			thirdPage1(m);
			
			break;
		}

		case 2:
		{
			
		
			system("cls");
			cout << "---------¶ÁÕß½çÃæ---------" << endl;
			cout << "***********************" << endl;
			cout << "       1.µÇÂ½          " << endl;
			cout << "       2.×¢²á          " << endl;
			cout << "       3.ÐÞ¸ÄÃÜÂë      " << endl;
			cout << "       4.·µ»ØÉÏÒ»¼¶      " << endl;
			cout << "***********************" << endl;
			int m; cin >> m;
			thirdPage2(m);
			break;
		}
		case 3:
		{
			Visitor vis;

			cout << "---------ÓÎ¿Í½çÃæ--------" << endl;
			vis.apply3();
		}
		break;
		case 4:
		{
			cout << "------ÍË³öÏµÍ³-------" << endl;
			system("pause");
			exit(0);
			break;
		}
		default:
		{
			cout << "--´íÎóÑ¡Ïî--" << endl;
			firstPage();
			
		}
		break;
	}

}
void thirdPage1(int i){
	Admin adm;
	Logs* ls1=Logs::getLogs();
	switch (i)
			{
			case 1:
			{
				if (ls1->goin1() == 1)
					// cout<<"dgfasdg"<<endl;
					adm.apply1();
				break;
			}
			case 2:
			{
				ls1->change1();
				secondPage(1);
			}
			case 3:
			{
				cout << "·µ»ØÉÏÒ»¼¶" << endl;
				firstPage();
				break;
			}
			default:
			{
				cout << "--´íÎóÑ¡Ïî--" << endl;
				secondPage(1);
			}
			}
	
}
void thirdPage2(int i){
		Reader rea;
		Logs* ls1=Logs::getLogs();
		switch (i)
			{
			case 1:
			{
				if (ls1->goin2() == 1)
					// cout<<"kdshjglahsgsg"<<endl;
					rea.Reader::apply2();
					
				break;
			}
			case 2:
			{
				ls1->registers2();
				secondPage(2);
			}
			case 3:
			{
				ls1->change2();
				secondPage(2);
			}
			case 4:
			{
				cout << "·µ»ØÉÏÒ»Ò³" << endl;
				firstPage();
				break;
			}
			default:
			{
				cout << "---´íÎóÑ¡Ïî--" << endl;
				secondPage(2);
			}
			}

}


// void logins()
// {
// L0:
// 	// logs l;
// 	cout << " ------Ð¡ï¿½ï¿½Í¼ï¿½ï¿½ï¿½ï¿½ï¿½ÏµÍ³ï¿½ï¿½Â?------" << endl;
// 	cout << "       1.ï¿½ï¿½ï¿½ï¿½Ô±                  " << endl;
// 	cout << "       2.ï¿½ï¿½ï¿½ï¿½                    " << endl;
// 	cout << "       3.ï¿½Î¿ï¿½                    " << endl;
// 	cout << "       4.ï¿½Ë³ï¿½                    " << endl;
// 	cout << " --------------------------------" << endl;
// 	cout << "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ñ¡ï¿½î£¨1-4ï¿½ï¿½:";
// 	int i;  cin >> i;
// 	switch (i)
// 	{
// 	case 1:
// 	{
// 		Admin adm;
// 	L1:
// 		system("cls");
// 		cout << "--------ï¿½ï¿½ï¿½ï¿½Ô±--------" << endl;
// 		cout << "***********************" << endl;
// 		cout << "       1.ï¿½ï¿½Â¼          " << endl;
// 		cout << "       2.ï¿½Þ¸ï¿½ï¿½ï¿½ï¿½ï¿½      " << endl;
// 		cout << "       3.ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»Ò³      " << endl;
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
// 			cout << "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»Ò³" << endl;
// 			goto L0;
// 			break;
// 		}
// 		default:
// 		{
// 			cout << "ï¿½ï¿½Ð§ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ö£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½" << endl;
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
// 		cout << "---------ï¿½ï¿½ï¿½ï¿½---------" << endl;
// 		cout << "***********************" << endl;
// 		cout << "       1.ï¿½ï¿½Â¼          " << endl;
// 		cout << "       2.×¢ï¿½ï¿½          " << endl;
// 		cout << "       3.ï¿½Þ¸ï¿½ï¿½ï¿½ï¿½ï¿½      " << endl;
// 		cout << "       4.ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»Ò³      " << endl;
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
// 			cout << "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»Ò³" << endl;
// 			goto L0;
// 			break;
// 		}
// 		default:
// 		{
// 			cout << "ï¿½ï¿½Ð§ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ö£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½" << endl;
// 			goto L2;
// 		}
// 		}
// 		break;
// 	}
// 	case 3:
// 	{
// 		Visitor vis;

// 		cout << "---------ï¿½Î¿ï¿½---------" << endl;
// 		vis.apply3();
// 	}
// 	break;
// 	case 4:
// 	{
// 		cout << "-------ï¿½Ë³ï¿½ï¿½É¹ï¿½-------" << endl;
// 		system("pause");
// 		exit(0);
// 		break;
// 	}
// 	default:
// 	{
// 		cout << "--ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?--" << endl;
// 		goto L0;
// 		break;
// 	}
// 	}
// 	system("pause");
// }
