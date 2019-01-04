//TranNhanTo-58131391-CNTT-1
#include<iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
 
using namespace std;
 //-----------------------------------------------------------------------------------
struct xe
{
	char soxe[12];
	char loaixe[6];
	char hieuxe[15];
	xe *tiep;
};
struct con
{
	char macon[9];
	char hoten[30];
	char gt[4];
	con *noi;
};
struct HK
{
	char soHK[5];
	char maCH[9];
	char tenCH[30];
	char diachi[30];
	con *con1;
	xe *xe1;
	HK *sau;
};
//-----------------------------------------------------------------------------------
HK *dau;
void khoitao(HK *&dau)
{
	dau = NULL;
}
//-----------------------------------------------------------------------------------
void nhapxe(xe *&dauxe)
{
	xe *p, *q;
	char soxetmp[12];
	char loaixetmp[6];
	char hieuxetmp[15];
	do
	{
		cout<<"Nhap so xe, go enter de dung :";
		fflush(stdin);
		gets(soxetmp);
		if(strcmp(soxetmp, "\0") != 0)
		{
			p = new xe;
			strcpy(p->soxe,soxetmp);
			cout<<"Nhap loai xe :";
			fflush(stdin);
			gets(loaixetmp);
			cout<<"Nhap hieu xe :";
			fflush(stdin);
			gets(hieuxetmp);
			p->tiep == NULL;
			strcpy(p->loaixe,loaixetmp);
			strcpy(p->hieuxe,hieuxetmp);
			if(dauxe == NULL)
				dauxe = p;
			else q->tiep = p;
			q = p;
		}
	}while(strcmp(soxetmp, "\0") != 0); 
}

void nhapcon(con *&daucon)
{
	con *p, *q;
	char macontmp[9];
	char hotentmp[30];
	char gttmp[4];
	do{
		cout<<"Nhap ma so con, go enter de dung :";
		fflush(stdin);
		gets(macontmp);
		if(strcmp(macontmp, "\0") != 0)
		{
			p = new con;
			strcpy(p->macon,macontmp);
			cout<<"Nhap ho ten con :";
			fflush(stdin);
			gets(hotentmp);
			cout<<"nhap gioi tinh :";
			fflush(stdin);
			gets(gttmp);
			strcpy(p->hoten,hotentmp);
			strcpy(p->gt,gttmp);
			p->noi == NULL;
			//moc vao ds con
			if(daucon == NULL)
				daucon = p;
			else q->noi = p;
			q = p;
	}
}while(strcmp(macontmp, "\0") != 0);
}

void nhaphk(HK *&dau)
{
	HK *p, *q;
	char soHKtmp[5];
	char maCHtmp[9];
	char tenCHtmp[30];
	char diachitmp[30];
	do
	{
		cout<<"Nhap so ho khau: "; 
		fflush(stdin);
		gets(soHKtmp);
		if(strcmp(soHKtmp, "\0") != 0) 
		{
			p = new HK;
			strcpy(p->soHK,soHKtmp);
			cout<<"Nhap ma chu ho :";
			fflush(stdin);
			gets(maCHtmp);
			cout<<"Nhap ten chu ho :";
			fflush(stdin);
			gets(tenCHtmp);
			cout<<"Nhap dia chi :";
			fflush(stdin);
			gets(diachitmp);
			strcpy(p->maCH,maCHtmp);
			strcpy(p->tenCH,tenCHtmp);
			strcpy(p->diachi,diachitmp);
			p->xe1 = NULL;
			p->con1 = NULL;
			p->sau = NULL;
			cout<<"Nhap xe : \n";
			nhapxe(p->xe1);
			cout<<"Nhap con : \n";
			nhapcon(p->con1);
			if(dau == NULL)
				dau = p;
			else q->sau = p;
			q = p;
		}
	}while(strcmp(soHKtmp, "\0") != 0); 
}
//-----------------------------------------------------------------------------------
void incon(con *daucon)
{
	
	if(daucon!=NULL)
	{
		cout<<"Ma nhan khau : "<<daucon->macon<<endl;
		cout<<"Ho ten con : "<<daucon->hoten<<endl;
		cout<<"Gioi tinh : "<<daucon->gt<<endl;
		incon(daucon->noi);
	}
}

int indstv(HK *dau)
{
	char soHKtmp[5];
	HK *p;
	cout<<"\nNhap ho khau can tim : ";
	fflush(stdin);
	gets(soHKtmp);
	p = dau;
	while((p != NULL) && (strcmp(p->soHK,soHKtmp)!=0))
		p = p->sau;
	if(p == NULL)
		cout<<"\nKhong co ho khau nay!";
	else
		incon(p->con1);
		
}

//-----------------------------------------------------------------------------------
int TimXe(xe *&dauxe, string hieuxe){//Tim kiem vi tri cua xe 
	xe *tam;
	tam = dauxe;
	while(tam!=NULL)
	{
		if(tam->hieuxe == hieuxe)		
			{
				return 1;
				break;
			}
		tam = tam->tiep;
	}
}

void inxe(HK *dau, string hieuxe){//In xe theo hieu xe
	HK *tam;
	tam = dau;
	if(tam == NULL)	cout<<"Khong co ho khau nao!!";
	while(tam!=NULL)
	{
		if(TimXe(tam->xe1, hieuxe) == 1)
			{
				cout<<"\nSo ho khau : "<<tam->soHK;
				cout<<"\nMa chu ho : "<<tam->maCH;
				cout<<"\nTen chu ho : "<<tam->tenCH;
				cout<<"\nDia chi : "<<tam->diachi;
			}
		tam= tam->sau;
	}
}
//-----------------------------------------------------------------------------------
void xoaxe(xe *dauxe){//Xoa xe
	if(dauxe != NULL)
	{
		dauxe = dauxe->tiep;
	}
}

void xoaxehk(HK *dau){//Xoa xe cua mot ho khau
	if(dau!= NULL)
	{
		xoaxe(dau->xe1);
	}
}
//-----------------------------------------------------------------------------------
int main()
{
	khoitao(dau);
	nhaphk(dau);
	cout<<"\nNhap xong du lieu !"<<endl;
	cout<<"--------------------------------"<<endl;
	indstv(dau);
//	inxe(dau);
 // xoaxehk(dau);
	getch();
}
