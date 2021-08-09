#include "7_LEKHANHDONG_N16DCDT024_1.h"

void drawText(int line, int cot, int focus, char Text[]) {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, focus);
	printf("%s\n", Text);
}
// phan lop
int menuLOP(ListLop &listlop) {
	system("cls");
	char MenuLOP[][100] = { "\t\|-----------------------------|Quan Ly Lop|-----------------------------|ESC-thoat|",
						"\t\|\t\t\           Xem danh sach lop                                      |",
						"\t\|\t\t\           Them lop                                               |",
						"\t\|\t\t\           Xoa lop                                                |",
						"\t\|\t\t\           Hieu chinh lop                                         |",
						"\t\|---------------------------------------------------------------------------------|",
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
		system("cls");
		cout << " Danh Sach Lop" << endl;
		IndsLopNienKhoa(listlop);
		cout << "ESC de thoat " << endl;
		char ch = _getch();
		if (ch == ESC) return 1;
		break;

		break;
	}
	case 3:
	{
		system("cls");
		xuLyThemLop(listlop);
		break;
	}
	case 4:
	{
		while (1) {
			system("cls");
			if (xuLyXoaLop(listlop) == 1) {
				cout << " Xoa thanh cong" << endl;
			}
			cout << "ESC de thoat -  an phim bat ki de tiep tuc" << endl;
			char ch = _getch();
			if (ch == ESC) return 1;
		}
		break;
	}
	case 5:
	{
		while (1) {
			system("cls");
			if (xuLyHieuChinhLop(listlop) == 1) {
				cout << " Hieu chinh thanh cong" << endl;
			}
			else {
				cout << " khong tim thay" << endl;
			}
			cout << "ESC de thoat - an phim bat ki de tiep tuc" << endl;
			char ch = _getch();
			if (ch == ESC) return 1;
		}
		break;
	}

	}
}
// phan monhoc
int menuMonHoc(MonHocPtr &tree) {
	system("cls");
	char MenuMH[][100] = { "\t\|--------------------------|Quan Ly Mon Hoc|-----------------------------|ESC-thoat|",
						"\t\|\t\t\        Xem danh sach Mon Hoc                                      |",
						"\t\|\t\t\        Them mon Hoc                                               |",
						"\t\|\t\t\        Xoa mon hoc                                                |",
						"\t\|\t\t\        Hieu chinh mon hoc                                         |",
						"\t\|----------------------------------------------------------------------------------|",

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
		if (ch == ESC) {
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
		system("cls");
		cout << "                  Danh Sach Mon Hoc" << endl;
		IndsMonhoc(tree);
		cout << "ESC de thoat " << endl;
		char ch = _getch();
		if (ch == ESC) return 1;
		break;

	}
	case 3:
	{
		system("cls");
		xuLyThemMonhoc(tree);
		break;
	}

	case 4:
	{
		while (1) {
			system("cls");
			if (xuLyXoaMonhoc(tree) == 1) {
				cout << " Xoa thanh cong" << endl;
			}
			else {
				cout << " khong tim thay" << endl;
			}
			cout << "ESC de thoat -  an phim bat ki de tiep tuc" << endl;
			char ch = _getch();
			if (ch == ESC) return 1;
		}
		break;
	}

	case 5:
	{
		while (1) {
			system("cls");
			if (xuLyHieuChinhMonhoc(tree) == 1) {
				cout << " Hieu chinh thanh cong" << endl;
			}
			else {
				cout << " khong tim thay" << endl;
			}
			cout << "ESC de thoat  -  an phim bat ki de tiep tuc" << endl;
			char ch = _getch();
			if (ch == ESC) return 1;
		}
		break;
	}

	}
}
// menu chinh
void menuChinh(MonHocPtr &tree, ListLop &listlop) {
	system("cls");
	char MenuChinh[][1000] = { "\t\|-----------------------------------|QUAN LI DIEM SINH VIEN|----------------------------------|ESC-thoat| ",
						"\t\|\t\t\t\t\        Quan ly lop                                           |",
						"\t\|\t\t\t\t\        Quan ly mon hoc                                       |",
						"\t\|\t\t\t\t\        Quan ly sinh vien                                     |",
						"\t\|\t\t\t\t\        Quan ly diem                                          |",
						"\t\|\t\t\t\t\        In bang diem mon hoc                                  |",
						"\t\|\t\t\t\t\        In diem trung binh lop                                |",
						"\t\|\t\t\t\t\        In bang diem tong ket sinh vien                       |",
						"\t\|---------------------------------------------------------------------------------------------|"
	};

	char ch;
	int i = 2;
	do {
		system("cls");

		for (int t = 1; t <= 9; t++) {
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
			if (i > 8) i = 2; //het dong k quay lai dong 2
		}
		if (ch == 72) {          //ky tu len
			i--;
			if (i < 2) i = 8;
		}
		if (ch == 27) { // esc
			exit(0);
		}
	} while (!(ch == 13));

	switch (i) {
	case 2:
	{
		while (true) {
			if (menuLOP(listlop) == 2) return;
		}

		break;
	}

	case 3:
	{
	
		while (true) {
			if (menuMonHoc(tree) == 2) return;
		}
	}
	case 4:
	{
		while (true) {
			if (menuSV(listlop) == 2) return;
		}
		break;
	}
	case 5:
	{
		while (true) {
			if (menuDiem(listlop,tree) == 2) return;
		}
		break;
	}
	case 6:
	{
		while (true) {
			if (inDiemLop(listlop,tree) == 2) return;
		}
		break;
		
	}
	case 7:
	{
		while(true) {
			if (inDiemTB(listlop, tree) == 2) return;
		}
		break;
	}
	case 8:
	{
		while (true) {
			if (inAll(listlop, tree) == 2) return;
		}
		break;
	}
	}
}

// menu sv

int menuSV(ListLop &listlop) {
	//tao ra mot cai lop gia



	system("cls");
	char MenuSV[][100] = { "\t\|--------------------------|Quan Ly Sinh Vien|-----------------------------|ESC-thoat|",
						"\t\|\t\t\        Xem thong tin sinh vien                                    |",
						"\t\|\t\t\        Them sinh vien                                             |",
						"\t\|\t\t\        Xoa sinh vien                                              |",
						"\t\|\t\t\        Hieu chinh sinh vien                                       |",
						"\t\|----------------------------------------------------------------------------------|",

	};
	char ch;
	int i = 2;
	do {
		system("cls");
		for (int t = 1; t <= 6; t++) {
			if (t == i) {
				//				gotoxy(40,t-1);
				drawText(7 + t, 2, 3, MenuSV[t - 1]);
			}
			else {
				//				gotoxy(40,t);
				drawText(7 + t, 2, 14, MenuSV[t - 1]);
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
		if (ch == ESC) {
			return 2;
		}
	} while (!(ch == 13));

	switch (i) {
	case 1:
	{
		cout << "helloe";
		break;
	}
	case 2:
	{
	Loop:while (1) {
		system("cls");
		string masv;
		
		cout << "nhap chuoi rong de thoat!" << endl;
		cout << "Nhap vao ma sinh vien: ";
		fflush(stdin);
		getline(cin, masv);
		if (masv == "")
		{
			std::cin.ignore();
			return 1;
		}
		for (int i = 0; i < listlop.n; i++) {
			NodeSVPtr sv = listlop.dSLop[i]->dSSV;
			if (sv == NULL) continue;
			while (sv) {
				if (sv->sV.maSV == masv) {
					cout << "=========================================================" << endl;
					cout << "Ma so sinh vien: " << sv->sV.maSV << endl;
					cout << "Ho sinh vien:    " << sv->sV.ho << endl;
					cout << "Ten sinh vien:   " << sv->sV.ten << endl;
					cout << "Phai sinh vien:  " << sv->sV.phai << endl;
					cout << "So dt sinh vien: " << sv->sV.sdt << endl;
					cout << "Ma lop:          " << listlop.dSLop[i]->Data.maLop << endl;
					cout << "=========================================================" << endl;
					cout << "Nhap bat ky nut nao de tiep tuc, esc de thoat!";
					char ch = _getch();
					if (ch == ESC)
					{
						return 1;
					}
					else goto Loop;
				}
				sv = sv->next;
			}
		}
		cout << "Khong tim thay sinh vien co ma la: " << masv << endl;
		cout << "Nhap bat ky nut nao de tiep tuc, esc de thoat!";
		char ch = _getch();
		if (ch == ESC)
		{
			return 1;
		}
		else goto Loop;
	}
		 break;
	}
	case 3:
	{
		while (1) {
			system("cls");
			string malop;
			
			cout << "nhap chuoi rong de thoat!" << endl;
			cout << "Nhap vao ma lop: ";
			fflush(stdin);
			getline(cin, malop);
			if (malop == "") break;
			if (search_MaLop(listlop, malop))
			{
				LopPtr* lop = getlop(listlop, malop);
				while (1) {
					system("cls");
					string phai;
					SinhVien sv;
					cout << "Nhap vao ma sv: ";
					getline(cin, sv.maSV);
					if (sv.maSV == "") break;
					fflush(stdin);
					cout << "Nhap vao ten sv: ";
					cin >> sv.ten;

					cout << "Nhap vao ho sv: ";
					cin >> sv.ho;

					cout << "Nhap vao phai sv M(default)/F  : ";
					cin >> phai;
					if (phai == "F" || phai == "f")
						sv.phai = nu;
					else
						sv.phai = nam;
					string number;
					do {
						cout << "Nhap vao sdt sv: ";
						cin >> number;
					} while (!checkNumber(number));
					sv.sdt = number;

					insert_First(lop->dSSV, sv);
					Lop_Save(listlop);
					cout << "Nhap bat ky nut nao de tiep tuc, esc de thoat!";
					char ch = _getch();
					if (ch == ESC)
					{	
						getchar();
						return 1;
					}
					else {
						continue;
					}
				}
			}
			else {
				continue;
			}

		}

		break;
	}

	case 4:
	{	
	Loop1:while (1) {
		system("cls");
		string masv;
		cout << "nhap chuoi rong de thoat!" << endl;
		cout << "Nhap vao ma sinh vien: ";
		getline(cin, masv);
		if (masv == "") return 1;
		for (int i = 0; i < listlop.n; i++) {
			NodeSVPtr sv = listlop.dSLop[i]->dSSV;
			if (sv == NULL) continue;
			while (sv) {
				if (sv->sV.maSV == masv) {
					cout << "=========================================================" << endl;
					cout << "Ma so sinh vien: " << sv->sV.maSV << endl;
					cout << "Ho sinh vien:    " << sv->sV.ho << endl;
					cout << "Ten sinh vien:   " << sv->sV.ten << endl;
					cout << "Phai sinh vien:  " << sv->sV.phai << endl;
					cout << "So dt sinh vien: " << sv->sV.sdt << endl;
					cout << "Ma lop:          " << listlop.dSLop[i]->Data.maLop << endl;
					cout << "=========================================================" << endl;
					cout << "ban co chac muon xoa sinh vien nay (Y/N)!: ";
					string str;
					cin >> str;
					if (str == "y" || str == "Y") {
						if (delete_maSV(listlop.dSLop[i]->dSSV, sv->sV.maSV) == 1) {
							Lop_Save(listlop);
							cout << "Xoa sinh vien thanh cong! " << endl;
						}
						else
							cout << "Xoa sinh vien that bai!" << endl;
						cout << "Nhap bat ky nut nao de tiep tuc, esc de thoat!";
						char ch = _getch();
						if (ch == ESC)
						{
							return 1;
						}
						else goto Loop1;
					}
					else goto Loop1;
				}
				sv = sv->next;
			}
		}
		cout << "Khong tim thay sinh vien co ma la: " << masv << endl;
		cout << "Nhap bat ky nut nao de tiep tuc, esc de thoat!";
		char ch = _getch();
		if (ch == ESC) return 1;
		else goto Loop;
	}
		 break;
	}

	case 5:
	{
	Loop2:while (1) {
		system("cls");
		string masv;
		cout << "nhap chuoi rong de thoat!" << endl;
		cout << "Nhap vao ma sinh vien: ";
		getline(cin, masv);
		if (masv == "") return 1;
		for (int i = 0; i < listlop.n; i++) {
			NodeSVPtr sv = listlop.dSLop[i]->dSSV;
			if (sv == NULL) continue;
			while (sv) {
				if (sv->sV.maSV == masv) {
					cout << "=========================================================" << endl;
					cout << "Ma so sinh vien: " << sv->sV.maSV << endl;
					cout << "Ho sinh vien:    " << sv->sV.ho << endl;
					cout << "Ten sinh vien:   " << sv->sV.ten << endl;
					cout << "Phai sinh vien:  " << sv->sV.phai << endl;
					cout << "So dt sinh vien: " << sv->sV.sdt << endl;
					cout << "Ma lop:          " << listlop.dSLop[i]->Data.maLop << endl;
					cout << "=========================================================" << endl;
					cout << "ban co chac muon chinh sua thong tin sinh vien nay (Y/N)!: ";

					string str;
					cin >> str;
					if (str == "y" || str == "Y") {
						string phai;
						SinhVien newSV;
						newSV.maSV = sv->sV.maSV;
						std::cin.ignore();
						cout << "Nhap vao ten sv: ";
						getline(cin, newSV.ten);

						cout << "Nhap vao ho sv: ";
						getline(cin, newSV.ho);

						cout << "Nhap vao phai sv M(default)/F  : ";
						cin >> phai;
						if (phai == "F" || phai == "f")
							newSV.phai = nu;
						else
							newSV.phai = nam;

						string number;
						do {
							cout << "Nhap vao sdt sv: ";
							cin >> number;
						} while (!checkNumber(number));
						newSV.sdt = number;

						if (updateSV(listlop.dSLop[i]->dSSV, newSV) == 1) {
							Lop_Save(listlop);
							cout << "Update vien thanh cong! " << endl;
						}
						else
							cout << "Update sinh vien that bai!" << endl;
						
						cout << "Nhap bat ky nut nao de tiep tuc, esc de thoat!";
						char ch = _getch();
						if (ch == ESC)
						{
							return 1;
						}
						else goto Loop2;
					}
					else goto Loop2;
				}
				sv = sv->next;
			}
		}
		cout << "Khong tim thay sinh vien co ma la: " << masv << endl;
		cout << "Nhap bat ky nut nao de tiep tuc, esc de thoat!";
		char ch = _getch();
		if (ch == ESC) return 1;
		else goto Loop;
	}
		  break;
	}
	}


}
// menu diem
int menuDiem(ListLop &listlop, MonHocPtr &tree) {
	system("cls");
	char MenuDIEM[][100] = { "\t\|--------------------------|Quan Ly Diem|--------------------------------|ESC-thoat|",
						"\t\|\t\t\        Them Diem                                                  |",
						"\t\|\t\t\        Xem danh sach diem cua sinh vien                           |",
						"\t\|\t\t\        Hieu chinh diem                                            |",
						"\t\|----------------------------------------------------------------------------------|",

	};
	char ch;
	int i = 2;
	do {
		system("cls");
		for (int t = 1; t <= 5; t++) {
			if (t == i) {
				//				gotoxy(40,t-1);
				drawText(7 + t, 2, 3, MenuDIEM[t - 1]);
			}
			else {
				//				gotoxy(40,t);
				drawText(7 + t, 2, 14, MenuDIEM[t - 1]);
			}
		}
		do {
			ch = _getch();
			if (ch == 224) ch = _getch();
		} while (!(ch == 224 || ch == 13 || ch == 27 || ch == 80 || ch == 72));
		if (ch == 80) {         //ky tu xuong
			i++;
			if (i > 4) i = 2; //het dong k quay lai dong 2
		}
		if (ch == 72) {          //ky tu len
			i--;
			if (i < 2) i = 4;
		}
		if (ch == ESC) {
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
		while (1) {
			system("cls");
			string malop;
			cout << "nhap chuoi rong de thoat!" << endl;
			cout << "Nhap vao ma lop: ";
			getline(cin, malop);
			if (malop == "") break;

			string maMH;
			cout << "Nhap vao ma mon hoc: ";
			getline(cin, maMH);
			if (maMH == "") break;

			string number;
			do {
				cout << "Nhap vao so lan thi: ";
				cin >> number;
			} while (!checkNumber(number));
			unsigned int lan = stoi(number);
			if (lan <= 0) break;
			MonHocPtr monhoc = SearchMH(tree, maMH);
			if (search_MaLop(listlop, malop) && monhoc)
			{
				LopPtr* lop = getlop(listlop, malop);
				if (lop->dSSV != NULL)
				{
					cout <<"Ma lop: "<<lop->Data.maLop << "\t" << "So Lan: "<<lan << "\t" << "Ma MH: " << monhoc->mh.maMH << endl;
					for (NodeSVPtr p = lop->dSSV; p != NULL; p = p->next) {
						
						Diem d;
						std::string::size_type sz;
						string number;
						do {
							cout << p->sV.maSV << "\t" << p->sV.ten << "\t" << "diem : ";
							cin >> number;
						} while (!checkFloat(number));
						///them diem vao trong
						d.diem = std::stof(number, &sz);
						d.lan = lan;
						d.maMH = monhoc->mh.maMH;

						// add vo
						insert_First(p->sV.firstD, d);

					}
					Lop_Save(listlop);
					cout << "Nhap diem thanh cong! nhan esc de thoat!";
					char ch = _getch();
					if (ch == ESC)
					{
						return 1;
					}
				}
				else
				{
					cout << "Lop khong co sin vien nao!";
					char ch = _getch();
					if (ch == ESC)
					{
						return 1;
					}
					continue;
				}
			}
			else {
				continue;
			}

		}
		break;

	}
	case 3:
	{
		system("cls");
		string masv;
		cout << "nhap vao ma sinh vien: ";
		cin >> masv;
		for (int i = 0; i < listlop.n; i++) {
			NodeSVPtr sv = listlop.dSLop[i]->dSSV;
			NodeSVPtr p;
			for (p = sv; p != NULL; p = p->next) {
				if (p->sV.maSV == masv)
				{
					cout << "Ma SV: " << p->sV.maSV << "\t" << "Ten SV: " << p->sV.ten<<endl;
					if (p->sV.firstD != NULL)
					{
						NodeDiemPtr diem;
						cout << "Ma mh" << "\t" << "Diem" << "\t" << "Lan" << endl;
						for (diem = p->sV.firstD; diem != NULL; diem = diem->next) {	
							cout << diem->d.maMH << "\t" << diem->d.diem << "\t" << diem->d.lan << endl;
						}
						cout << "Hien thi diem thanh cong!" <<
						_getch();
						return 1;
					}
					else
					{
						cout << "Sinh vien chua co diem mon nao";
						_getch();
						return 1;
					}
				}
			}
			cout << "Ma Sv khong hop le! ";
			_getch();
			return 1;
		}
		break;
	}

	case 4:
	{
		system("cls");
		string maSV;
		string maMH;
		unsigned int lan;
		cout << "Nhap vao ma sv: ";
		cin >> maSV;
		NodeSVPtr sv = getSV(listlop, maSV);
		//NodeSVPtr sv = NULL;
;
		if (sv == NULL) {
			cout << "Ma sinh vien khong hop le! (press any key to exit)";
			_getch();
			return 1;
		}
		cout << "Nhap vao ma mon hoc: ";
		cin >> maMH;
		string number;
		do {
			cout << "Nhap vao so lan thi: ";
			cin >> number;
		} while (!checkNumber(number));
		lan = unsigned(stoi(number));
		NodeDiemPtr d = search_Diem(sv->sV.firstD, maMH, lan);
		if (d == NULL) {
			cout << "Ma mon hoc hoac lan thi khong hop le! (press any key to exit)";
			_getch();
			return 1 ;
		}
		cout << "Ma sv: " << sv->sV.maSV << "\t" << "Ten sv: " << sv->sV.ten << endl;
		cout << "Ma mh:" << d->d.maMH << "\t" << "lan :" << d->d.lan << "\t" << "diem: " << d->d.diem << endl;
		do {
			cout << "Nhap vao diem ban muon: ";
			cin >> number;
		} while (!checkFloat(number));
		std::string::size_type sz;
		d->d.diem = std::stof(number, &sz);
		Lop_Save(listlop);
		cout << "Update diem thanh cong! (press any key to quit)";
		_getch();
		break;
	}

	}


}

//in 
// in diem theo mon lan cua mot lop
int inDiemLop(ListLop listlop, MonHocPtr root) {
	system("cls");
	string maLop;
	string maMH;
	unsigned int lan;
	cout << "nhap vao ma lop: ";
	cin >> maLop;
	LopPtr* lop = getlop(listlop, maLop);
	if (lop == NULL) {
		cout << "Ma lop khong dung! ";
		_getch();
		return 2;
	}
	cout << "Nhap vao ma mon hoc: ";
	cin >> maMH;
	cout << "Nhap lan thi: ";
	cin >> lan;
	NodeDiemPtr d;
	if (lop->dSSV == NULL)
		d = NULL;
	else
		d = search_Diem(lop->dSSV->sV.firstD, maMH, lan);
	if (d == NULL) {
		cout << "Ma mon hoc hoac lan thi khong hop le! (press any key to exit)";
		_getch();
		return 2;
	}
	//toi phan in
	MonHocPtr mh = SearchMH(root, maMH);
	cout << "Lop: " << lop->Data.tenLop << "\t" << "Lan Thi: " << lan << "\t" << "Mon Hoc: " << mh->mh.tenMH << endl;
	NodeSVPtr p;
	int i = 1;
	cout << "STT" << "\t" << "Ma SV" << "\t" << "Ho" << "\t" << "Ten" << "\t" << "Diem" << endl;;
	for(p=lop->dSSV; p!=NULL;p=p->next)
	{
		NodeDiemPtr d = search_Diem(p->sV.firstD, maMH, lan);
		cout << i << "\t" << p->sV.maSV << "\t" << p->sV.ho << "\t" << p->sV.ten << "\t" << d->d.diem << endl;
		i++;
	}

	cout << "In diem thanh cong! (press any key to quit";
	_getch();
	return 2;
}
// in diem trung binh cua tat ca sv trong lop
int inDiemTB(ListLop listlop, MonHocPtr root) {
	system("cls");
	string maLop;
	string maMH;
	unsigned int lan;
	cout << "nhap vao ma lop: ";
	cin >> maLop;
	LopPtr* lop = getlop(listlop, maLop);
	if (lop == NULL) {
		cout << "Ma lop khong dung! ";
		_getch();
		return 2;
	}
	//toi phan in
	MonHocPtr mh = SearchMH(root, maMH);
	cout << "Lop: " << lop->Data.tenLop << "\t" << "Nam Hoc: " << lop->Data.namNhapHoc<< endl;
	NodeSVPtr p;
	int i = 1;
	cout << "STT" << "\t" << "Ma SV" << "\t" << "Ho" << "\t" << "Ten" << "\t" << "Diem TB" << endl;;
	for (p = lop->dSSV; p != NULL; p = p->next)
	{
		float diemTB = average(p->sV.firstD);
		cout << i << "\t" << p->sV.maSV << "\t" << p->sV.ho << "\t" << p->sV.ten << "\t" << diemTB << endl;
		i++;
	}

	cout << "In diem thanh cong! (press any key to quit)";
	_getch();
	return 2;
}
// in diem tat ca cac mon cua sv trong mo hop
int inAll(ListLop listlop, MonHocPtr root) {
	system("cls");
	string maLop;
	string maMH;
	unsigned int lan;
	cout << "nhap vao ma lop: ";
	cin >> maLop;
	LopPtr* lop = getlop(listlop, maLop);
	if (lop == NULL) {
		cout << "Ma lop khong dung! ";
		_getch();
		return 2;
	}
	//toi phan in
	MonHocPtr mh = SearchMH(root, maMH);
	cout << "Lop: " << lop->Data.tenLop << "\t" << "Nam Hoc: " << lop->Data.namNhapHoc << endl;
	NodeSVPtr p;
	int i = 1;
	cout << "STT" << "\t" << "Ma SV" << "\t" << "Ho" << "\t" << "Ten" << "\t";
	NodeDiemPtr diem;
	if(lop->dSSV==NULL) {
		cout << "Lop chua co diem mon nao";
		_getch();
		return 2;
	}
	for (diem = lop->dSSV->sV.firstD; diem != NULL; diem = diem->next) {
		cout << "Ma " << diem->d.maMH << "\t";
	}
	cout << endl;
	for (p = lop->dSSV; p != NULL; p = p->next)
	{
		cout << i << "\t" << p->sV.maSV << "\t" << p->sV.ho << "\t" << p->sV.ten << "\t";
		NodeDiemPtr diem;
		for (diem = p->sV.firstD; diem != NULL; diem = diem->next) {
			cout << diem->d.diem << "\t" <<"\t";
		}
		cout << endl;
		i++;
	}

	cout << "In diem thanh cong! (press any key to quit)";
	_getch();
	return 2;
}