//TranNhanTo-58131391-CNTT-1
//doc du lieu tu ban phim,ghi ra man hinh
#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;


int n,i,j,hang,cot;
int m[10][10];
//--------------------
void Nhap(){
	cout << "Nhap cac phan tu cua ma tran : \n"; 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
           	cin>>m[i][j];
        }
}

void Xuat(int m[10][10],int d,int n){
	cout<<"Ket qua :\n";
	d=0; hang=n-1; cot=n-1;
	while(d<=n/2){
	for(i=d;i<=cot;i++)
    	cout<<m[d][i]<<"\t";
    for(i=d+1;i<=hang;i++)
    	cout<<m[i][cot]<<"\t";
    for(i=cot-1;i>=d;i--)
    	cout<<m[hang][i]<<"\t";
    for(i=hang-1;i>d;i--)
    	cout<<m[i][d]<<"\t";
    d++; hang--;cot--;
	}
}

int main(){
	do
	{
		cout<<"Nhap kich thuot ma tran :";
		cin>>n;
	}while(n>10);
	Nhap();
	Xuat(m,0,n);
	getch();
}
