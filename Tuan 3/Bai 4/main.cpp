//Tran Nhan To - 58131391
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<limits.h>
#include<iostream>

using namespace std;

#define max 100

struct canh{
   	int x,y;

};

//doc du lieu tu tap tin
void docfile(int a[max][max], int &n)
{
   	FILE*f = fopen("Input.txt","rb");
   	fscanf(f,"%d",&n);
   	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
       	fscanf(f,"%d", &a[i][j]);
     	}
   	fclose(f);
}
// xuat du lieu ban dau ra man hinh
void xuat(int a[max][max], int n)
{
	FILE*f = fopen("Input.txt","rb");
    for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
       	cout<<a[i][j]<<"  ";
     	}
     	cout<<endl<<endl;
     }
}

//xuat du lieu ra tap tin
void ghifile(canh L[max], int n, int sum){
    FILE*f = fopen("Output.txt","wb");
    fprintf(f,"%d\r\n", sum);
    for(int i = 0; i < n-1; i++)
        fprintf(f, "%d-%d\r\n", L[i].x+1, L[i].y+1);
    fclose(f);
}

//thuat toan Prim
void timkhungmin(int a[max][max], int n)
{
    char D[max];
    canh L[max];
    int min = INT_MAX;
	int dem = 0, sum = 0;
    for(int i = 0; i < n; i++)
    	D[i]=0;
        for(int j = 1; j < n; j++)
            if(min > a[0][j] && a[0][j] != 0){
                min = a[0][j];
                L[0].y = j;
            }
            L[0].x = 0;
            D[0] = 1;
            D[L[0].y] = 1;
            sum += min;
            dem++;
    do{
        min = INT_MAX;
        for(int i = 0; i < n; i++)
            if(D[i] == 1)
            for(int j = 0; j < n; j++)
                if(a[i][j] > 0 && min > a[i][j] && D[j] == 0){
                    min = a[i][j];
                    L[dem].x = i;
                    L[dem].y = j;
                    }
    	sum += min;
        D[L[dem].y] = 1;
        dem++;
    }while(dem < n-1);
    ghifile(L,n,sum);
    cout<<"Ket qua:"<<endl;
    cout<<sum<<endl;
	for(int i = 0; i < n-1; i++){
		cout<<L[i].x+1<<"-"<<L[i].y+1;
		cout<<endl;
	}
}

//chuong trinh chinh
int main(){
    int a[max][max],n;
    docfile(a,n);
    xuat(a,n);
    timkhungmin(a,n);
	getch();
 }
