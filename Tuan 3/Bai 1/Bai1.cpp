//tran nhan to -58131391
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<map>

#include<iostream>

using namespace std;

int n,m;

void random()// tao n so ngau nhien khong trung nhau va thuoc khoang tu 1 den m
{
	int k;
	map<int, bool> vis;
	for(int i = 0; i < n; ++i){
        // Random cho toi khi k chua co trong map vis
        do{
            k = 1 + rand()%m;
        }while(vis.find(k) != vis.end());
        cout<<k<<"  ";
        // Danh dau k da co.
        vis[k] = true;
    }
}

int main()
{
	srand(time(NULL));
	cout<<"Nhap m: ";//nhap vao so m tu ban phim
	cin>>m;
	do{
		cout<<"\nNhap n: ";//nhap vao so n tu ban phim, n be hon m
		cin>>n;
	}while(n>=m);
	cout<<"------------------------------------------------------------"<<endl;
	for(int i = 1; i <= m; i++)//in ra cac so tu 1 den m
	{
		cout<<i<<"  ";
	}
	cout<<endl<<n<<" so ngau nhien thuoc khoang tu 1 den "<<m<<" la:"<<endl;
	random();
	getch();
}
