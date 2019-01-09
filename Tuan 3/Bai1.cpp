#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int i, n, m;

void nhap()
{
	do{
		cout<<"Nhap m: ";
		cin>>m;
		cout<<"\nNhap n: ";
		cin>>n;
	}while(n>m);
	for( i = 0; i < m; i++)
	{
		cout<<i<<"\t";
	}
}

void xuat()
{
	cout<<"\nn so ngau nhien la: "<<endl;
	for( i = 0; i < n; i++)
		cout<<rand()%m<<"\t";
}

int main()
{
	nhap();
	xuat();
	getch();
}
