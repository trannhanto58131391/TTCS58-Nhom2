//Tran Nhan To - 58131391
#include<stdio.h>
#include<conio.h>
#include <string>
#include<iostream>

#include "bignum.h"

using namespace std;

void menu()
{
	char chon;
	string a, b;
    do
    {
        printf("\n\t\tMENU");
        printf("\n\t1. Cong 2 so nguyen");
        printf("\n\t2. Tru 2 so nguyen");
        printf("\n\t3. Nhan 2 so nguyen");
        printf("\n\tNhap 0 de thoat!");
        chon=getch();
        switch(chon)
        {
            case '1': {
            	cout<<endl<<"\t--------------------------";
            	cout<< "\n\tNhap a: ";
                getline(cin, a);
                cout<< "\n\tNhap b: ";
                getline(cin, b);
                cout<<"\n\tTong 2 so nguyen: "<< cong(a, b) << endl;
				break;
			}
            case '2': {
            	cout<<endl<<"\t--------------------------";
            	cout<< "\n\tNhap a: ";
                getline(cin, a);
                cout<< "\n\tNhap b: ";
                getline(cin, b);
                cout<<"\n\tHieu 2 so nguyen: "<< tru(a, b) << endl;
				break;
			}
            case '3': {
            	cout<<endl<<"\t--------------------------";
            	cout<< "\n\tNhap a: ";
                getline(cin, a);
                cout<< "\n\tNhap b: ";
                getline(cin, b);
                cout<<"\n\tTich 2 so nguyen: "<< nhan(a, b) << endl;
				break;
			}
            case '0': exit(1);
            default: printf("\n--------------------------------Nhap lai.");
        }
    } while (chon!='0');
}

int main()
{
	menu();
	getch();
}
