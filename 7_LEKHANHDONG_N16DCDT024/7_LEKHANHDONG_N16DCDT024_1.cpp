#include "7_LEKHANHDONG_N16DCDT024_1.h"

void drawText(int line, int cot, int focus, char Text[]) {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, focus);
	printf("%s\n", Text);
}
// phan lop
int menuLOP() {
	system("cls");
	char MenuLOP[][100] = { "\t\|--------------------------|Quan Ly Lop|-----------------------------|ESC-thoat|",
						"\t\|\t\t\        Xem danh sach lop                                     |",
						"\t\|\t\t\        Them lop                                              |",
						"\t\|\t\t\        Xoa lop                                               |",
						"\t\|\t\t\        Hieu chinh lop                                        |",
						"\t\|--------------------------------------------------------------------------|",

	};

	char ch;
	int i = 2;
	do {
		system("cls");
		for (int t = 1; t <= 6; t++) {
			if (t == i) {
				//				gotoxy(40,t-1);
				drawText(7 + t, 2, 3, MenuLOP[t - 1]);
			}
			else {
				//				gotoxy(40,t);
				drawText(7 + t, 2, 14, MenuLOP[t - 1]);
			}
		}
		do {
			ch = _getch();
			if (ch == 224) ch = _getch();
		} while (!(ch == 224 || ch == 13 || ch == 27 || ch == 80 || ch == 72));
		if (ch == KEY_DOWN) {         //ky tu xuong
			i++;
			if (i > 5) i = 2; //het dong k quay lai dong 2
		}
		if (ch == KEY_UP) {          //ky tu len
			i--;
			if (i < 2) i = 5;
		}
		if (ch == ESC) {
			return 2;
		}
	} while (!(ch == ENTER));

	switch (i) {
	case 2:
	{

		break;
	}

	}
}
// phan monhoc
int menuMonHoc() {
	system("cls");
	char MenuMH[][100] = { "\t\|--------------------------|Quan Ly Mon Hoc|-----------------------------|ESC-thoat|",
						"\t\|\t\t\        Xem danh sach Mon Hoc                                     |",
						"\t\|\t\t\        Them mon Hoc                                              |",
						"\t\|\t\t\        Xoa mon hoc                                               |",
						"\t\|\t\t\        Hieu chinh mon hoc                                        |",
						"\t\|--------------------------------------------------------------------------|",

	};


	char ch;
	int i = 2;
	do {
		system("cls");
		for (int t = 1; t <= 6; t++) {
			if (t == i) {
				//				gotoxy(40,t-1);
				drawText(7 + t, 2, 3, MenuMH[t - 1]);
			}
			else {
				//				gotoxy(40,t);
				drawText(7 + t, 2, 14, MenuMH[t - 1]);
			}
		}
		do {
			ch = _getch();
			if (ch == 224) ch = _getch();
		} while (!(ch == 224 || ch == 13 || ch == 27 || ch == 80 || ch == 72));
		if (ch == 80) {         //ky tu xuong
			i++;
			if (i > 5) i = 2; //het dong k quay lai dong 2
		}
		if (ch == 72) {          //ky tu len
			i--;
			if (i < 2) i = 5;
		}
		if (ch == 27) {
			return 2;
		}
	} while (!(ch == 13));

	switch (i) {
	case 1:
	{

		break;
	}
	case 2:
	{
		//				NhapDSMH();
		break;
	}

	}
}
// menu chinh
int menuChinh() {
	system("cls");
	char MenuChinh[][1000] = { "\t\|-----------------------------------|QUAN LI DIEM SINH VIEN|----------------------------------|ESC-thoat| ",
						"\t\|\t\t\t\t\        Quan ly lop                                           |",
						"\t\|\t\t\t\t\        Quan ly mon hoc                                       |",
						"\t\|\t\t\t\t\        Quan ly sinh vien                                     |",
						"\t\|\t\t\t\t\        Quan ly diem                                          |",
						"\t\|\t\t\t\t\        In danh sach lop                                      |",
						"\t\|\t\t\t\t\        In danh sach mon hoc                                  |",
						"\t\|\t\t\t\t\        In bang diem mon hoc                                  |",
						"\t\|\t\t\t\t\        In diem trung binh lop                                |",
						"\t\|\t\t\t\t\        In bang diem tong ket sinh vien                       |",
						"\t\|------------------------------------------------------------------------------------------|"
	};

	char ch;
	int i = 2;
	do {
		system("cls");

		for (int t = 1; t <= 11; t++) {
			if (t == i) {
				drawText(7 + t, 2, 3, MenuChinh[t - 1]);
			}
			else {
				drawText(7 + t, 2, 14, MenuChinh[t - 1]);
			}

		}
		do {
			ch = _getch();
			if (ch == 224) ch = _getch();
		} while (!(ch == 224 || ch == 13 || ch == 27 || ch == 80 || ch == 72));
		if (ch == 80) {         //ky tu xuong
			i++;
			if (i > 10) i = 2; //het dong k quay lai dong 2
		}
		if (ch == 72) {          //ky tu len
			i--;
			if (i < 2) i = 10;
		}
		if (ch == 27) { // esc
			exit(0);
		}
	} while (!(ch == 13));

	switch (i) {
	case 2:
	{
		menuLOP();
		break;
	}

	case 3:
	{
		menuMonHoc();
		break;
	}
	}
}