#include "7_LEKHANHDONG_N16DCDT024.h"
using namespace std;

#define KEY_LEFT 75
// Di qua phai 
#define KEY_RIGHT 77
// Di len
#define KEY_UP 72
// Di xuong
#define KEY_DOWN 80
// ENTER
#define ENTER 13
//ESC
#define ESC 27

// ham ve
void drawText(int line, int cot, int focus, char Text[]);
// phan lop
int menuLOP(MonHocPtr &tree);
// phan monhoc
int menuMonHoc(MonHocPtr &tree);
// menu chinh
void menuChinh(MonHocPtr &tree, ListLop &listlop);
// menu sv
int menuSV(ListLop &listlop);
// menu diem
int menuDiem(ListLop &listlop,MonHocPtr &tree);

//in 
// in diem theo mon lan cua mot lop
int inDiemLop(ListLop listlop, MonHocPtr root);
// in diem trung binh cua tat ca sv trong lop
int inDiemTB(ListLop listlop, MonHocPtr root);
// in diem tat ca cac mon cua sv trong mo hop
int inAll(ListLop listlop, MonHocPtr root);
