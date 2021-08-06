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
void menuChinh(MonHocPtr &tree);

