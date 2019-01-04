//Tran Nhan To - 58131391
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>

using namespace std;

ifstream f("input3.txt");

struct nv{
	int manv;
	char hoten[20];
	char cv[20];
	int hsl;
	int hscv;
	int thang;
	int nam;
	int luong;
	int luongcb;
};

nv a[30];//du lieu luu nhan vien
int n;//so nv can quan ly

void Nhap()
{
	if(f.fail()){
		cout<<"Loi file !"<<endl;
	}
	else{
		cout<<"Doc file thanh cong."<<endl;
		cout<<"===========================";
		cout<<endl;
		f>>n;
		for(int i=0;i<n;i++){
			f>>a[i].manv;
			f>>a[i].hoten;
			f>>a[i].hsl;
			f>>a[i].cv;
			f>>a[i].hscv;
			f>>a[i].thang;
			f>>a[i].nam;
		}
	}
}
//xuat thong tin nhan vien
void Xuat()
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Ma so nv: "<<a[i].manv<<endl;
		cout<<"Ho ten nv: "<<a[i].hoten<<endl;
		cout<<"He so luong: "<<a[i].hsl<<endl;
		cout<<"Chuc vu: "<<a[i].cv<<endl;
		cout<<"He so chuc vu: "<<a[i].hscv<<endl;
		cout<<"------------------------------";
		cout<<endl;
	}
}
//tinh luong va sap xep luong tang dan
void Luong()
{
	for(int i = 0; i < n; i++){
		a[i].luongcb = 2000000;
		a[i].luong =  a[i].luongcb * (a[i].hscv + a[i].hsl);
		cout<<"Luong cua "<<a[i].cv<<" : \t"<<a[i].luong<<endl;

	}
	cout<<"===========================";
	cout<<endl;
	cout<<"Sap xep luong tang dan."<<endl;
	cout<<endl;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(a[i].luong > a[j].luong){
				swap(a[i], a[j]);		
			}		
		}
	}
	for(int i = 0; i < n; i++){
		
		cout<<a[i].hoten<<"\t"<<a[i].cv<<"\t"<<a[i].luong<<endl;
	}
	cout<<"===========================";
	cout<<endl;;
	cout<<endl;
}
//tim kiem thong tin nhan vien theo ma nhan vien
void timkiemnv()
{
	int maso;
	cout<<"Nhap ma so nhan vien can tim:";
	cin>>maso;
	for(int i = 0; i < n; i++)
	{
		if(a[i].manv == maso)
		{
			cout<<"-------------TTNV---------------";
			cout<<endl;
			cout<<"Ma so nv: "<<a[i].manv<<endl;
			cout<<"Ho ten nv: "<<a[i].hoten<<endl;
			cout<<"He so luong: "<<a[i].hsl<<endl;
			cout<<"Chuc vu: "<<a[i].cv<<endl;
			cout<<"He so chuc vu: "<<a[i].hscv<<endl;
		}
	}
}
//xoa thong tin nhan vien theo ma nhan vien
void xoanv()
{
	int maso;
	cout<<"===========================";
	cout<<endl;
	cout<<"Nhap ma so nhan vien can xoa :";
	cin>>maso;
	for(int i = 0; i < n; i++){
		if(a[i].manv == maso){
			a[i].manv = a[i+1].manv;
			a[i].hoten[i] = a[i+1].hoten[i];
			a[i].hscv = a[i+1].hscv;
			a[i].hsl = a[i+1].hsl;
			a[i].cv[i] = a[i+1].cv[i];
			a[i].thang = a[i+1].thang;
			a[i].nam = a[i+1].nam;
			a[i].luong = a[i+1].luong;
			n--;	
		}
	}
	cout<<endl;
	cout<<"Da xoa nhan vien !!!!!!";
	cout<<endl<<endl;
}
int main()
{
	Nhap();
	Xuat();
	Luong();
	timkiemnv();
	xoanv();
	cout<<"Danh sach nv sau khi xoa."<<endl;
	cout<<"-------------TTNV---------------";
	cout<<endl;
	Xuat();
	getch();
}
