#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

struct co
{
	int tren;
	int duoi;
	
};

co a[29];//du lieu luu cac quan co
int tt[29];//trang thai cac quan co
int ttluu[29];//trang thai luu cac quan co
int cl = 168;

int n;//so quan co can xu ly
//---------------------------------------
void nhaptufile(int &n)
{
	FILE *f;
    f=fopen("input.txt","rt");
    fscanf(f,"%d",&n);
    for(int i = 1; i <= n; i++)
        fscanf(f,"%d",&a[i]);
    fclose(f);
}
void nhapco(int &n)
{
	int i;
	cout<<"Nhap so quan co :";
	cin>>n;
	for(i = 1; i <= n; i++)
	{
		cout<<"\nQuan co thu "<<i<<" : ";
		cout<<"\nMat tren :";
		cin>>a[i].tren;
		cout<<"\nMat duoi : ";
		cin>>a[i].duoi;
	}
}
//---------------------------------------
void ktra()
{
	int sumt = 0, sumd = 0;
	int dochenh;
	int k;
	for(k = 1; k <= n; k++)
		if(tt[k] == 0)
		{
			sumt = sumt + a[k].tren;
			sumd = sumd + a[k].duoi;
		}
		else
		{
			sumt = sumt + a[k].duoi;
			sumd = sumd + a[k].tren;
		}
	dochenh = abs(sumt - sumd);
	if(dochenh < cl)
	{
		cl = dochenh;
		for(k = 1; k <= n; k++)
			ttluu[k] = tt[k];
	}
	
}
//----------------------------------------
void thu(int i)
{
	int k;
	for(k = 0; k <= 1; k++)
	{
		tt[i] = k;
		if(i < n) thu(i+1);
		else
			ktra();
			tt[i] = 0;
		
	}
	
}
//----------------------------------------
void kqua()
{
	int k, dem=0;
	cout<<"\nDo chenh be nhat : "<<cl;
	//so luong quan co phai quay
//	cout<<"\nTrang thai luu cac quan co: \n";
	for(k = 1; k <= n; k++)
	{
		if(ttluu[k] == 1){
			dem = dem + 1;
		}
	}
		cout<<"\nSo luong quan co phai quay : "<<dem;
		cout<<"\nTrang thai ung voi do chenh be nhat: \n";
		for(k = 1; k <= n; k++)
			cout<<ttluu[k]<<" ";

	
	
	
}
//----------------------------------------
int main()
{
	int i;
	nhaptufile(n);
//	nhapco(n);
	thu(1);
	kqua();
	getch();
}
