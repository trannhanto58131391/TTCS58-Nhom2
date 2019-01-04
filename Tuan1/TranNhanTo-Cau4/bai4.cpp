//TranNhanTo-58131391-CNTT-1
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int i;
//nhap mang tu file heapsort.txt
void nhaptufile(int a[], int &n)
{
    FILE *f;
    f=fopen("heapsort.txt","rt");
    fscanf(f,"%d",&n);
    for(i = 0; i <= n; i++)
        fscanf(f,"%d",&a[i]);
    fclose(f);

}
//tao mang ngau nhien voi n phan tu
void nhapmangngaunhien(int a[], int n)
{
	for(int i = 0; i < n; i++)
		a[i] = rand()%51;
}
//nhap mang tu bphim voi n phan tu
void nhapmangtubp(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap phan tu thu A["<<i<<"] = ";
		cin>>a[i];
		cout<<endl;
	}
}
//xuat mang ra
void xuatmang(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<"\t";
}
//hoan vi 2 ptu a va b
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//hoan vi nut cha thu i phai lon hon nut con
void chinhheap(int a[], int n, int i)
{
	int t = 2*i+1;
	int p = 2*i+2;
	int L ;
	if(t < n && a[t] > a[i])
		L = t;
	else
		L = i;
	if(p < n && a[p] > a[L])
		L = p;
	if(i != L)
	{
		swap(a[i],a[L]);
		chinhheap(a,n,L);
	}
}
//sap xep
void xayheap(int a[], int n)
{
	for(i = n/2-1; i >= 0; i--)
		chinhheap(a,n,i);
}
void heapsort(int a[], int n)
{
	xayheap(a,n);
	for(i = n-1; i > 0; i--)
	{
		swap(a[0],a[i]);
		chinhheap(a,i,0);
	}
}
//------------ham chinh-----------------------
int main()
{
	int n;
	int a[50];
	cout<<"Nhap so phan tu cua mang :";
	cin>>n;
//	nhaptufile(a,n);
	nhapmangngaunhien(a,n);
//	nhapmangtubp(a,n);
	cout<<"\nMang vua nhap : \n";
	xuatmang(a,n);
	cout<<"\nSap xep heapsort : \n";
	heapsort(a,n);
	xuatmang(a,n);
	getch();
	return 0;
}
