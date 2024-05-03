#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<ctype.h>
using namespace std;

struct MonHoc{
	char mamon[10];
	char tenmon[22];
	int sotinchi;
	
};
struct Node
{
	MonHoc infor;
	Node *next;	
};
typedef Node *TRO;
//Khoi tao danh sach rong
void Rong(TRO &L)
{
	L=NULL;
}
//Kiem tra dsach rong
int KTRong(TRO L)
{
	return L == NULL;
}
void FakeData(TRO &L)
{
	TRO mon1= new Node();
	TRO mon2= new Node();
	TRO mon3= new Node();
	TRO mon4= new Node();
	TRO mon5= new Node();
	
	strcpy(mon1->infor.mamon, "SV001");
	strcpy(mon1->infor.tenmon, "C++");
	mon1->infor.sotinchi=4;
	
	strcpy(mon2->infor.mamon, "SV002");
	strcpy(mon2->infor.tenmon, "C#");
	mon2->infor.sotinchi=3;
	
	strcpy(mon3->infor.mamon, "SV003");
	strcpy(mon3->infor.tenmon, "java");
	mon3->infor.sotinchi=4;
	
	strcpy(mon4->infor.mamon, "SV004");
	strcpy(mon4->infor.tenmon, "CTDL&GT");
	mon4->infor.sotinchi=6;
	
	strcpy(mon5->infor.mamon, "SV005");
	strcpy(mon5->infor.tenmon, "KTMT & HDH");
	mon5->infor.sotinchi=3;
	
	L=mon1;
	mon1->next=mon2;
	mon2->next=mon3;
	mon3->next=mon4;
	mon4->next=mon5;
	mon5->next=NULL;
}
void hienthi(TRO L, MonHoc X)
{
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma mon";
	cout<<setw(16)<<"Ten mon";
	cout<<setw(15)<<"So tin chi"<<endl;
	TRO Q=L;
	int i=0;
	while(Q != NULL)
	{
		i=i+1;
		MonHoc X=Q->infor;
		cout<<setw(5)<<i;
		cout<<setw(10)<<X.mamon;
		cout<<setw(15)<<X.tenmon;
		cout<<setw(10)<<X.sotinchi<<endl;
		Q=Q->next;
	}
}
void TimKiemTheoTen(TRO L, string ten)
{
	MonHoc X;
	while(L != NULL && L->infor.tenmon != ten)
	{
		L=L->next;
	}
	if(L != NULL)
	{
		X=L->infor;
		cout<<setw(10)<<"Ma mon";
		cout<<setw(16)<<"Ten mon";
		cout<<setw(15)<<"So tin chi"<<endl;
		cout<<setw(10)<<X.mamon;
		cout<<setw(15)<<X.tenmon;
		cout<<setw(10)<<X.sotinchi<<endl;
	}
}
void XoaMonVuaTim(TRO L, string ten, MonHoc X)
{
	if(L==NULL)
	{
		cout<<"danh sach rong";
	}
	TRO Q=L;
	TRO P=NULL;
	while(Q!=NULL&&Q->infor.tenmon!=ten)
	{
		P=Q;
		Q=Q->next;
	}
	if(Q==NULL)
		cout<<"Khong tim thay de xoa\n";
	else 
	{
		if(P==NULL)
			L=Q->next;
		else
		{
			P->next=Q->next;
		}
		delete Q;
		cout<<"Da xoa\n";
	}
	hienthi(L,X);
}
void Chen(TRO &L, MonHoc X)
{
	int d=1;
	TRO M,Q=L;
	while(Q != NULL && d < 4)
	{
		M=Q;
		Q=Q->next;
		d++;
	}
	if(Q==NULL)
	{
		cout<<"Vi tri khong thich hop";
		return;
	}
	TRO P = new Node();
	strcpy(P->infor.mamon, "SV006");
	strcpy(P->infor.tenmon, "HDT");
	P->infor.sotinchi=6;
	P->next=M->next;
	M->next=P;
	hienthi(L,X);
}
int main()
{
	MonHoc X;
	TRO L;
	Rong(L);
	FakeData(L);
	hienthi(L,X);
	string ten;
	cout<<"Nhap ten can tim: ";
	getline(cin,ten);
	cout<<"Ten mon hoc duoc tim thay la: "<<endl;
	TimKiemTheoTen(L,ten);
	XoaMonVuaTim(L,ten,X);
	Chen(L,X);
return 0;
}

