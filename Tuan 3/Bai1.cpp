#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int i, n, m;

void nhap()
{
	do{
		cout<<"Nhap m: ";//nhap vao so m tu ban phim
		cin>>m;
		cout<<"\nNhap n: ";//nhap vao so n tu ban phim, n be hon m
		cin>>n;
	}while(n>m);
	for( i = 0; i < m; i++)//in ra cac so tu 1 den m
	{
		cout<<i<<"\t";
	}
}

void xuat()
{
	cout<<"\nn so ngau nhien la: "<<endl;//xuat ra n so ngau nhien, nam trong khoang tu 1 den m
	for( i = 0; i < n; i++)
		cout<<rand()%m<<"\t";//ham xuat ngau nhien cac so be hon m
}

int main()
{
	nhap();
	xuat();
	getch();
}
