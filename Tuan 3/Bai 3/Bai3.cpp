#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>

#include<iostream>

using namespace std;

class khachhang{ //khoi tao lop khach hang
	public:
		char khid[5];
		char tenkh[20];
		int sodutk; //so tien con lai trong tai khoan
};

class giaodich{ //khoi tao lop trans
	public:
		char khid[5];
		char loaigd[5]; //co 2 loai: gui tien va rut tien
		int luongtiengd; // so luong tien khi giao dich
};

class xuly{ //khoi tao lop xu ly
		vector <khachhang> dskh;
		vector <giaodich> dstrans;
	public:
		bool themkh (khachhang kh);
		int thuchiengd(char khid[5], char loaigd[5], int luongtiengd);
		void indskh();
		void insaoke(char khid[5]);
		void docfilekh();
		void docfilegd();
		void ghifilekh(khachhang kh);
		void ghifilegd(giaodich gd);
		void update();
};

void xuly::docfilekh() //doc danh sach khac hang tu file customer
{
	FILE *f = fopen("customer.txt","rb");
	int i = 0;
	khachhang tmp;
	while (!feof(f))
	{
		fread(&tmp,sizeof(khachhang),1,f);
		dskh.insert(dskh.begin()+i, tmp);
		i++;
	}
	dskh.pop_back();
	fclose(f);
}

void xuly::docfilegd() //doc danh sach giao dich tu file trans
{
	FILE *g = fopen("trans.txt","rb");
	int i = 0;
	giaodich tmp;
	while (!feof(g))
	{
		fread(&tmp,sizeof(giaodich),1,g);
		dstrans.insert(dstrans.begin()+i, tmp);
		i++;
	}
	dstrans.pop_back();
	fclose(g);
}

void xuly::ghifilekh(khachhang kh) //ghi thong tin 1 khach hang vao file customer
{
	FILE *f = fopen("customer.txt","ab");
	fwrite(&kh,sizeof(khachhang),1,f);
	fclose(f);
}

void xuly::ghifilegd(giaodich gd) //ghi thong tin 1 giao dich vao file trans
{
	FILE *f = fopen("trans.txt","ab");
	fwrite(&gd,sizeof(giaodich),1,f);
	fclose(f);
}

void xuly::update()// cap nhat thong tin khach hang o file customer
{
	FILE *f = fopen("customer.txt","wb");
	for (int i = 0; i < dskh.size(); i++)
		fwrite(&dskh[i],sizeof(khachhang),1,f);
	fclose(f);
}

bool xuly::themkh(khachhang kh)// them 1 khach hang vao file customer
{
	int size = dskh.size();
	for (int i = 0; i < size; i++)
		if (strcmp(dskh[i].khid,kh.khid) == 0)
			return false;
	dskh.insert(dskh.begin()+dskh.size(), kh);
	ghifilekh(kh);
	return true;	
}

int xuly::thuchiengd(char khid[5], char loaigd[5], int luongtiengd) //qua trinh giao dich
{
	giaodich gd;
	strcpy(gd.khid,khid);
	strcpy(gd.loaigd,loaigd);
	gd.luongtiengd = luongtiengd;
	khachhang kh;
	int i;
	for (i = 0; i < dskh.size(); i++) //tim kiem khach hang dua vao ma so
		if (strcmp(khid,dskh[i].khid) == 0)
		{
			strcmp(kh.khid,dskh[i].khid);
			strcmp(kh.tenkh,dskh[i].tenkh);
			kh.sodutk = dskh[i].sodutk;
			break;
		}
	if(i==dskh.size())	//khi khong co khach hang nao
		return 0;
	if(strcmp(loaigd,"rut") == 0)
		if(kh.sodutk < luongtiengd) //khi khong du tien rut
			return 1;
		else //thuc hien qua trinh rut tien
		{
			kh.sodutk -= luongtiengd;
			dskh[i].sodutk = kh.sodutk;
			dstrans.insert(dstrans.begin() + dstrans.size(), gd);
			ghifilegd(gd);
			update();
		}			
	else //qua trinh gui tien
	{
		kh.sodutk += luongtiengd;
		dskh[i].sodutk = kh.sodutk;
		dstrans.insert(dstrans.begin() + dstrans.size(), gd);
		ghifilegd(gd);
		update();
	}
	return 2; //giao dich thanh cong			
}

void xuly::indskh() //in danh sach khach hang tu file customer ra man hinh
{
	cout<<"Ma KH:"<<"\t"<<"Ten KH:"<<"\t\t"<<"So du TK:"<<endl;
	cout<<"------"<<"\t"<<"-------"<<"\t\t"<<"---------"<<endl;
	for (int i = 0; i < dskh.size(); i++)
		cout<<dskh[i].khid<<"\t"<<dskh[i].tenkh<<"\t"<<dskh[i].sodutk<<endl;
}

void xuly::insaoke(char khid[5]) //in thong tin giao dich cua 1 khach hang tu file trans ra man hinh
{
	cout<<"Ma KH:"<<"\t"<<"Loai GD"<<"\t\t"<<"So tien GD:"<<endl;
	cout<<"------"<<"\t"<<"-------"<<"\t\t"<<"---------"<<endl;
	for (int i = 0; i < dstrans.size(); i++)
		if(strcmp(dstrans[i].khid, khid) == 0)
			if (strcmp(dstrans[i].loaigd,"gui") == 0)
				cout<<dstrans[i].khid<<"\tGui tien\t"<<dstrans[i].luongtiengd<<endl;
			else
				cout<<dstrans[i].khid<<"\tRut tien\t"<<dstrans[i].luongtiengd<<endl;
}	

khachhang nhapkhtubp() //nhap thong tin khach hang tu ban phim
{
	khachhang kh;
	cin.sync();
	cout<<"Ma khach hang: ";
	cin.get(kh.khid,5);
	cin.sync();
	cout<<"Ten khach hang: ";
	cin.get(kh.tenkh,20);
	cin.sync();
	cout<<"So du tien tai khoan: ";
	cin>>kh.sodutk;
	cin.sync();
	return kh;	
}

giaodich nhapgdtubp() //nhap thong tin giao dich cua 1 khach hang tu ban phim
{
	giaodich gd;
	cin.sync();
	cout<<"Ma khach hang: ";
	cin.get(gd.khid,5);
	cin.sync();
	cout<<"So tien giao dich: ";
	cin>>gd.luongtiengd;
	cin.sync();
	return gd;
}
int main()
{
	xuly t;
	int chon;
	khachhang kh;
	giaodich gd;
	t.docfilekh();
	t.docfilegd();
	cout<<"\n\t\t============MENU=============="<<endl; //menu
	cout<<"\t\t1.Them moi khach hang."<<endl;
	cout<<"\t\t2.Cho phep khach hang gui tien."<<endl;
	cout<<"\t\t3.Cho phep khach hang rut tien."<<endl;
	cout<<"\t\t4.In danh sach khach hang."<<endl;
	cout<<"\t\t5.In sao ke cho mot khach hang."<<endl;
	cout<<"\t\tNhap lua chon: "; cout<<endl;
	cout<<"\t\t0.Thoat!"<<endl;
	cout<<"\t============================================="<<endl;
	do
	{
		cout<<"\tNhap lua chon: ";
		cin>>chon;
		cout<<endl;
		switch(chon)
		{
			case 1:{
				cout<<"\t---------THEM KHACH HANG----------"<<endl;
				kh = nhapkhtubp();
				t.themkh(kh);
				cout<<"\t----------------------------------"<<endl;
				break;
			}
			case 2:{
				cout<<"\t------------GUI TIEN--------------"<<endl;
				gd = nhapgdtubp();
				strcpy(gd.loaigd,"gui");
				t.thuchiengd(gd.khid,gd.loaigd,gd.luongtiengd);
				t.docfilekh();
				cout<<"\t----------------------------------"<<endl;
				break;
			}
				
			case 3:{
				cout<<"\t------------RUT TIEN--------------"<<endl;
				gd = nhapgdtubp();
				strcpy(gd.loaigd,"rut");
				t.thuchiengd(gd.khid,gd.loaigd,gd.luongtiengd);
				t.docfilekh();
				cout<<"\t----------------------------------"<<endl;		
				break;
			}
				
			case 4:{
				cout<<"\t-------DANH SACH KHACH HANG-------"<<endl;
				cin.sync();
				t.indskh();
				cout<<"\t----------------------------------"<<endl;
				break;
			}
				
			case 5:{
				cout<<"\t-----------BANG SAO KE------------"<<endl;
				cin.sync();
				cout<<"Nhap ma khach hang can liet ke: ";
				cin.get(gd.khid,5);
				cout<<endl;
				t.insaoke(gd.khid);
				cout<<"\t----------------------------------"<<endl;
				break;
			}
		}
		cout<<endl;
	}
	while (chon!=0);
}
