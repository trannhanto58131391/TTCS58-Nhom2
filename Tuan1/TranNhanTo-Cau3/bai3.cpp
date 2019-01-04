#include<conio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

//-----------khai bao cau truc----------------------
struct nut
{
	int info;
	nut *left, *right;
};

typedef nut Node;
Node *root, *root1;
//----------khoi tao cay--------------------
void khoitao(Node *&root)
{
	root = NULL;
}
//---------------tao nut tren cay------------------
void mocnut(Node *&root, int x)
{
	if(root == NULL)
	{
		root =  new Node;
		root->info  =  x;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if(root->info >=  x)
			mocnut(root->left,x);
		else
			mocnut(root->right,x);
	}
}
//--------------tao cay ngau nhien-------------------
void taocayngaunhien(Node *&root)
{
	int tam;
	do
	{
		cout<<"Nhap so nut :";
		cin>>tam;
		tam = rand()%51;
		if(tam = 0)
		{
			mocnut(root,tam);
		}
	}
	while(tam != 0);
}
//-------------tao cay tu ban phim--------------------
void taocay(Node *&root)
{
	int tmp;
	do
	{
		cout<<"Nhap so nguyen, 0 de dung  : ";
		cin>>tmp;
		if(tmp != 0)
			mocnut(root,tmp);
			
	}while(tmp != 0);
}
//------------in cay ra man hinh----------
void xuat(Node *root)
{
	if(root != NULL)
	{
		cout<<root->info<<" ";
		xuat(root->left);
		xuat(root->right);
	}
}
//------------duyet cay LNR---------------------
void duyetLNR(Node *root)
{
	if(root != NULL)
	{
		duyetLNR(root->left);
		cout<<root->info<<" ";
		duyetLNR(root->right);
	}
}
//--------------chieu cao cua cay-------------------
int max(int a, int b)
{
	if(a >= b)
		return a;
	return b;
	
}
int chieucao(Node *root)
{
	if(root == NULL)
		return  0;
	return 1 + max(chieucao(root->left), chieucao(root->right));
}
//-------------in nut o muc i ra man hinh--------------------
void inmuci(Node *root,int i, int muc =  1)
{
	if(root != NULL)
		if(muc == i)
			cout<<root->info<<"   ";
		else
		{
			inmuci(root->left, i, muc+1);
			inmuci(root->right, i, muc+1);
		}
}
//-------------xoa 1 nut tren cay--------------------
void thaythe(Node *q, Node *p){
    // tim phan tu trai nhat cua cay ben phai
    //if(root==NULL) return;
    if(p->left != NULL){
        thaythe(q,p->left);
    }
    else {
        q->info = p->info;
        q=p;
        p=p->right;
    }

}
//xoa phan tu
void xoanut(Node *root, int x)
{
	if(root == NULL) return;
	if(root->info > x) xoanut(root->left,x);
	if(root->info < x) xoanut(root->right,x);
	if(root->info == x)
	{
		Node *q = root;
		if(root->left == NULL) root = root->right;
		else 
			if(root->right == NULL){
            	root = root->left;
        	}
        	// xoa node co 2 phan tu Trai va Phai
       		else thaythe(q,root->right);
        	delete q;
	}	
}
//------------ham chinh---------------------
int main()
{
	int i,x,k;
	khoitao(root);
//	taocayngaunhien(root);
	taocay(root);
	cout<<"Cay vua tao :\n";
	xuat(root);
	cout<<"\nDuyet LNR  : \n";
	duyetLNR(root);
	cout<<"\nChieu cao cua cay la : "<<chieucao(root);
	cout<<"\nNhap muc: ";
	cin>>i;
	cout<<"\nCac nut o muc thu "<<i<<" la : ";
	inmuci(root,i);
	cout<<"\nNhap phan tu can xoa : ";
	cin>>k;
	xoanut(root,k);
	cout<<"Cay moi sau khi xoa nut :\n";
	duyetLNR(root);
	getch();
}
