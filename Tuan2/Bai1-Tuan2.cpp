//Tran Nhan To - 58131391
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>

#define fo "output1.txt"

using namespace std;

int a[50][50],n,m;
int i,j;
//nhap ma tran kich thuot nxn
void nhapmang()
{
	do{
	cout<<"So dong va so cot phai bang nhau!"<<endl;
	cout<<"Nhap so dong cua ma tran: ";
	cin>>n;
	cout<<"Nhap so cot cua ma tran: ";
	cin>>m;
	}while((m!=n) || ((m<3 || m>10) && (n<3 || n>10)));
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
		{
			a[i][j]=rand()%21;
		}
}
//xuat ma tran ra man hinh
void xuatmang()
{
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
}
//xoa dong thu i
void xoadong()
{
	int dong;
	do{
	cout<<"\nNhap dong can xoa: ";
	cin>>dong;
	}while(dong < 0 && dong >= n);
	for(i = dong; i <= n-1; i++){
		for(j = 1; j <= m; j++)
			a[i][j]=a[i+1][j];
	}
	n--;
	xuatmang();
}
//xoa cot thu j
void xoacot()
{
	int cot;
	do{
		cout<<"\nNhap cot can xoa: ";
		cin>>cot;
	}while(cot < 0 && cot >= n);
	for(i  = cot; i <= m-1; i++){
		for(j = 1; j <= n; j++)
			a[j][i]=a[j][i+1];
	}
	m--;
	xuatmang();
}
//kiem tra ma tran co doi xung khong
int ktra(int a[50][50], int n)
{
    for(i = 1; i < n; i++)          
        for(j = 1; j < n; j++)
        {
            if(a[i][j] !=  a[j][i])
                return 0;
        }
    return 1;
}
//tim so hoang hau
bool maxduongcheo()
{
	int k,h;
	for (k = i, h = j; k >= 0 && h < n; k--, h++)
        if (a[k][h] > a[i][j]) 
            return false;
                
    for (k = i+1, h = j-1; k < n && h >= 0; k++, h--)
        if (a[k][h] > a[i][j])
        return false;
            
    for (k = i-1, h = j-1; k >= 0 && h >= 0; k--,h--)
        if (a[k][h] > a[i][j])
            return false;
             
    for (k = i+1, h = j+1; k < n && h < n; k++, h++)
        if (a[k][h] > a[i][j])
            return false;
                 
      return true;
				
}
bool maxdongcot()
{
    for (int k = 0; k < n; k++ )
    	if (a[k][j]>a[i][j])         
        	return false;
    for (int k = 0; k < n; k++ )   
		if (a[i][k]>a[i][j])
            return false;
  	return true;
}
//ham main
int main()
{
	nhapmang();
	xuatmang();
	xoadong();
	xoacot();
	if(ktra(a,n)==0)
		cout<<"\nMa tran vua nhap k doi xung!";
	else
		cout<<"\nMa tran doi xung!";
	cout<<"\nCac so hoang hau co trong ma tran la :"<<endl;
//	timsohh();
	getch();
}
