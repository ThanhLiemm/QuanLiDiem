#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<string>
#include<windows.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#define MAX 50
#define MAXLIST 100
using namespace std;
enum Phai{nam =0, nu = 1};
//khai bao struct diem
typedef struct Diem
{
	string maMH;
	unsigned int lan;
	float diem;
};

typedef struct NodeDiem
{
	Diem d;
	struct NodeDiem *next;
};
typedef struct NodeDiem* NodeDiemPtr;

typedef struct SinhVien
{
	string maSV;
	string ho;
	string ten;
	Phai phai;
	string sdt;
	NodeDiemPtr firstD;
};

typedef struct NodeSV
{
	SinhVien sV;
	struct NodeSV* next;
};
typedef struct NodeSV* NodeSVPtr;

typedef struct Lop
{
	string maLop;
	string tenLop;
	unsigned int namNhapHoc;
	
};

struct LopPtr
{
	Lop Data;
	NodeSVPtr dSSV;
};

typedef struct ListLop
{
	unsigned int n = 0;
	LopPtr *dSLop[MAXLIST];
};

typedef struct MonHoc {
	string maMH;
	string tenMH;
	int soTCLT;
	int soTCTH;
};

typedef struct NodeMonHoc {
	MonHoc mh;
	NodeMonHoc *pLeft, *pRight;
};
typedef NodeMonHoc* MonHocPtr;

//-----------------------diem -------------------//
//khoi tao 
void Initialize(NodeDiemPtr &firstD);
// cap phat
NodeDiemPtr newNodeDiemPtr(void);
// them vao dau
void insert_First(NodeDiemPtr &firstD, Diem d);
// them vao sau mot node
void insert_After(NodeDiemPtr p, Diem d);
// tim kiem theo maMH, lan thi
NodeDiemPtr search_Diem(NodeDiemPtr firstD, string maMH,unsigned int lan);
// kiem tra mang co trong hay hk
int Empty(NodeDiemPtr firstD);
// xoa phan tu o dau
int delete_First(NodeDiemPtr &firstD);
//xoa phan tu o sau phan tu khac
int delete_After(NodeDiemPtr p);
// xoa phan tu theo maMH
int delete_maMH(NodeDiemPtr &firstD, string maMH, unsigned int lan);
// update diem theo ma mon hoc
int update_maMH(NodeDiemPtr &fristD, string maMH, float d);
// tinh diem trung binh cua sv
float average(NodeDiemPtr &firstD);


//----------------------- Sinh Vien -------------------//
//khoi tao
void Initialize(NodeSVPtr &firstSV);
// cap phat vung nho
NodeSVPtr newNodeSVPtr(void);
// them vao dau
void insert_First(NodeSVPtr &firstSV, SinhVien sv);
// them vao sau phant tu 
void insert_After(NodeSVPtr p, SinhVien sv);
// kiem tra mang co rong hay hk
int Empty(NodeSVPtr firstSV);
// xoa phan tu o dau
int delete_First(NodeSVPtr &firstSV);
// xoa phan tu o sau phan tu khac
int delete_After(NodeSVPtr p);
// tim kiem sv theo ma sv
NodeSVPtr search_SV(NodeSVPtr firstSV, string maSV);
// cap nhat thong tin sv
int updateSV(NodeSVPtr firstSV, SinhVien sv);
// xoa sv thong qua ma sv
int delete_maSV(NodeSVPtr firstSV, string maSV);

//----------------------- Lop -------------------//
//kiem tra co rong khong 
int empty(ListLop list);
//kiem tra xem danh sach da day chua;
int full(ListLop list);
// xoa phan tu o vi tri thu i
int delete_Lop_I(ListLop &list, int i);
// tim kiem thong tin lop thong qua ma lop
boolean search_MaLop(ListLop list, string malop);
// lay ra danh sach lop theo nien khoa
Lop search_NNH(ListLop list, unsigned int nNH);
// chinh sua thong tin cua lop
int update_lop(ListLop  &list, Lop lop);

int insert_Lop(ListLop &list, Lop lop);

//----------------------- MonHoc -------------------//
//khoi tao
void Initialize(MonHocPtr &tree);
// search ma mh
MonHocPtr SearchMH(MonHocPtr &root, string maMH);
// insert mon hoc
MonHocPtr InsertMH(MonHocPtr &tree, MonHoc &mh);
// xoa
void NodeThe(MonHocPtr &X, MonHocPtr &Y);
int XoaMonhoc(MonHocPtr &t, string maMH);



///////////////Xu ly///////////
//----------------------- MonHoc -------------------//

int xuLyThemMonhoc(MonHocPtr &tree);

int xuLyXoaMonhoc(MonHocPtr &tree);

int xuLyHieuChinhMonhoc(MonHocPtr &tree);

void IndsMonhoc(MonHocPtr tree);

bool Monhoc_Alpha_Compare(MonHoc S1, MonHoc S2);

void Monhoc_Convert(MonHocPtr t);

void Monhoc_Alpha_Sort(MonHocPtr t);

void IndsMonhoc(MonHocPtr tree);

//----------------------- LOP -------------------//

int xuLyHieuChinhLop(ListLop &list);

int xuLyThemLop(ListLop &list);

int xuLyXoaLop(ListLop &list);

void IndsLopNienKhoa(ListLop &list);





