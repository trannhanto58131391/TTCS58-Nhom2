//Tran Nhan To - 58131391
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <winbgim.h>

#include <iostream>


using namespace std;

int Mx, My;
class toado{
	protected:
		int x, y;
		friend class dthang;
		friend class chunhat;
		friend class vuong;
		friend class tron;
		friend class tamgiac;
	public:
		void nhap(){
			cout<<endl<<"Toa do Ox: "; cin>>x;		
			cout<<"Toa do Oy: "; cin>>y;	
		}
};

class dthang{
	private:
		toado d1,d2;
	public:
		void nhapdt(){
			cout<<"Diem thu nhat: ";
			d1.nhap();
			cout<<"Diem thu hai: ";
			d2.nhap();
			cout<<"-----------------------------------------------------------";
		}
		void vedt(){			
			line(d1.x+Mx/2, -d1.y+My/2, d2.x+Mx/2, -d2.y+My/2);
		}
};

class chunhat{
	private:
		toado tt, dp;
	public:
		void nhapchunhat(){
			cout<<"Diem tren trai: ";
			tt.nhap();
			cout<<"Diem duoi phai: ";
			dp.nhap();
			cout<<"-----------------------------------------------------------";
		}
		void vechunhat(){			
			rectangle(tt.x+Mx/2, -tt.y+My/2, dp.x+Mx/2, -dp.y+My/2);
		}
};

class vuong{
	private:
		toado tt, dp;
	public:
		void nhapvuong(){
			do
			{
				cout<<"Diem tren trai: ";
				tt.nhap();
				cout<<"Diem duoi phai: ";
				dp.nhap();
				if (abs(tt.x-dp.x) != abs(tt.y-dp.y))
					cout<<"Khong phai hinh vuong!"<<endl;
				cout<<"-----------------------------------------------------------";
			}
			while (abs(tt.x-dp.x) != abs(tt.y-dp.y));
		}
		void vevuong(){			
			rectangle(tt.x+Mx/2, -tt.y+My/2, dp.x+Mx/2, -dp.y+My/2);
		}
};

class tron{
	private:
		toado tam;
		int bk;
	public:
		void nhaptron(){
				cout<<"Tam duong tron: ";
				tam.nhap();
				cout<<"Ban kinh: ";
				cin>>bk;
				cout<<"-----------------------------------------------------------";
		}
		void vetron(){			
			circle(tam.x+Mx/2,-tam.y+My/2,bk);
		}
};

class tamgiac{
	private:
		toado t1, t2, t3;
	public:
		void nhaptamgiac(){
				cout<<"Diem thu nhat: ";
				t1.nhap();
				cout<<"Diem thu hai: ";
				t2.nhap();
				cout<<"Diem thu ba: ";
				t3.nhap();
				cout<<"-----------------------------------------------------------";
		}
		void vetamgiac(){			
			line(t1.x+Mx/2, -t1.y+My/2, t2.x+Mx/2, -t2.y+My/2);
			line(t1.x+Mx/2, -t1.y+My/2, t3.x+Mx/2, -t3.y+My/2);
			line(t2.x+Mx/2, -t2.y+My/2, t3.x+Mx/2, -t3.y+My/2);
		}	
};

int main(){
	int chon;
	dthang dt;
	chunhat cn;
	vuong v;
	tron t;
	tamgiac tg;
	initwindow(800, 600);
    cleardevice();
    Mx=getmaxx(), My=getmaxy();
    cout<<"\t========Chon hinh can ve.======="<<endl;
    cout<<"\t\t1. Ve duong thang."<<endl;
    cout<<"\t\t2. Ve hinh tam giac."<<endl;
    cout<<"\t\t3. Ve hinh chu nhat."<<endl;
    cout<<"\t\t4. Ve hinh vuong."<<endl;
    cout<<"\t\t5. Ve hinh tron."<<endl;
    cout<<"\t\t0. Thoat!"<<endl;
    do
    {
	    cout<<endl<<"\tNhap lua chon: ";
	    cin>>chon;
		switch(chon)
		{
			case 1:
				setcolor(5);
				dt.nhapdt();
				dt.vedt();
				break;
			case 2:
				setcolor(6);
				tg.nhaptamgiac();
				tg.vetamgiac();
				break;
			case 3:
				setcolor(7);
				cn.nhapchunhat();
				cn.vechunhat();
				break;
			case 4:
				setcolor(8);
				v.nhapvuong();
				v.vevuong();
				break;
			case 5:
				setcolor(9);
				t.nhaptron();
				t.vetron();
				break;
			case 0:
				break;
		}
		delay(100);
	}
    while (chon!=0);	
    return 0;
}
