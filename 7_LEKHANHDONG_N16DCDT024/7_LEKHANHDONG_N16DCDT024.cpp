#include "7_LEKHANHDONG_N16DCDT024.h"


//---------------------- goto xy ---------------//
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}

//----------//




//-----------------------diem -------------------//
//khoi tao 
void Initialize(NodeDiemPtr &firstD)
{
	firstD = NULL;
};
// cap phat
NodeDiemPtr newNodeDiemPtr(void)
{
	NodeDiemPtr p = new NodeDiem;
	return p;
};
// them vao dau
void insert_First(NodeDiemPtr &firstD, Diem d)
{
	if (firstD == NULL) {
		firstD = newNodeDiemPtr();
		firstD->d = d;
		firstD->next = NULL;
	}
	else
	{
		NodeDiemPtr p = new NodeDiem;
		p->d = d;
		p->next = firstD;
		firstD = p;
	}
};
// them vao sau mot node
void insert_After(NodeDiemPtr p, Diem d) {
	if (p == NULL) cout << "Can not add node" << endl;
	else
	{
		NodeDiemPtr q = new NodeDiem;
		q->d = d;
		q->next = p->next;
		p->next = q;
	}
}
// tim kiem theo maMH cua 
NodeDiemPtr search_Diem(NodeDiemPtr firstD, string maMH, unsigned int lan){
	for (NodeDiemPtr p = firstD; p != NULL; p = p->next)
		if (p->d.maMH == maMH && p->d.lan==lan) return p;
	return NULL;
}
// kiem tra mang co trong hay hk
int Empty(NodeDiemPtr firstD) {
	return (firstD == NULL);
}
// xoa phan tu o dau
int delete_First(NodeDiemPtr &firstD) {
	if (Empty(firstD))
		return 0;
	NodeDiemPtr p = firstD;
	firstD = p->next;
	delete p;
	return 1;
}
//xoa phan tu o sau phan tu khac
int delete_After(NodeDiemPtr p) {
	if ((p == NULL) || (p->next == NULL)) return 0;
	NodeDiemPtr q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}
// xoa phan tu theo maMH
int delete_maMH(NodeDiemPtr &firstD, string maMH,unsigned int lan) {
	NodeDiemPtr p, q;
	p = search_Diem(firstD, maMH,lan);
	if (p == NULL) {
		cout << "Gia tri khong ton tai" << endl;
		return 0;
	}
	else {
		if (p == firstD) return delete_First(firstD);
		else {
			q = firstD;
			while (q->next != p)
				q = q->next;
			return delete_After(q);
		}
	}
}
// update diem theo ma mon hoc
int update_maMH(NodeDiemPtr &fristD, string maMH, float d);
// tinh diem trung binh cua sv
float average(NodeDiemPtr &firstD) {
	NodeDiemPtr p;
	float s = 0;
	int n = 0;
	for (p = firstD; p != NULL; p = p->next) {
		s += p->d.diem;
		n++;
	}
	if (n == 0) return 0;
	else return s / n;
}


//----------------------- Sinh Vien -------------------//
//khoi tao
void Initialize(NodeSVPtr &firstSV) {
	firstSV = NULL;
}
// cap phat vung nho
NodeSVPtr newNodeSVPtr(void) {
	NodeSVPtr p = new NodeSV;
	return p;
}
// them vao dau
void insert_First(NodeSVPtr &firstSV, SinhVien sv) {
	if (firstSV == NULL) {
		firstSV = newNodeSVPtr();
		firstSV->sV = sv;
		firstSV->next = NULL;
		firstSV->sV.firstD = NULL;
	}
	else {
		NodeSVPtr p = new NodeSV;
		p->sV = sv;
		p->sV.firstD = NULL;
		p->next = firstSV;
		firstSV = p;
	}
}
// them vao sau phant tu 
void insert_After(NodeSVPtr p, SinhVien sv) {
	if (p == NULL) cout << "Can not add node" << endl;
	else {
		NodeSVPtr q = new NodeSV;
		q->sV = sv;
		q->next = p->next;
		p->next = q;
	}
}
// kiem tra mang co rong hay hk
int Empty(NodeSVPtr firstSV) {
	return (firstSV == NULL);
}
// xoa phan tu o dau
int delete_First(NodeSVPtr &firstSV) {
	if (Empty(firstSV)) return 0;
	else {
		NodeSVPtr p = firstSV;
		firstSV = p->next;
		delete p;
		return 1;
	}
}
// xoa phan tu o sau phan tu khac
int delete_After(NodeSVPtr p) {
	NodeSVPtr q;
	if (p == NULL || p->next == NULL) return 0;
	q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}
// tim kiem sv theo ma sv
NodeSVPtr search_SV(NodeSVPtr firstSV, string maSV) {
	for (NodeSVPtr p = firstSV; p != NULL; p = p->next)
		if (p->sV.maSV == maSV) return p;
	return NULL;
}
// cap nhat thong tin sv
int updateSV(NodeSVPtr &firstSV, SinhVien sv) {
	NodeSVPtr p;
	for (p = firstSV; p != NULL; p = p->next) {
		if (p->sV.maSV == sv.maSV) {
			p->sV = sv;
			return 1;
		}
	}
	return 0;
}
// xoa sv thong qua ma sv
int delete_maSV(NodeSVPtr &firstSV, string maSV) {
	NodeSVPtr p, q;
	p = search_SV(firstSV, maSV);
	if (p == NULL) {
		cout << "Khong co sv ma so: " << maSV << endl;
		return 0;
	}
	else {
		if (p == firstSV) return delete_First(firstSV);
		else {
			q = firstSV;
			while (q->next != p) q = q->next;
			return delete_After(q);
		}
	}
}
//get sv trong theo maSV
NodeSVPtr getSV(ListLop listlop, string maSV) {
	for (int i = 0; i < listlop.n; i++) {
		NodeSVPtr first = listlop.dSLop[i]->dSSV;
		NodeSVPtr p;
		for (p = first; p != NULL; p = p->next) {
			if (p->sV.maSV == maSV) return p;
		}
	}
	return NULL;
}

//----------------------- Lop -------------------//
//kiem tra co rong khong 
int empty(ListLop list) {
	return list.n == 0;
}
//kiem tra xem danh sach da day chua;
int full(ListLop list) {
	return (list.n == MAXLIST ? 1 : 0);
}

int insert_Lop(ListLop &list, Lop lop)
{
	if (empty(list)) {
		list.dSLop[list.n] = new LopPtr();
		list.dSLop[list.n]->Data = lop;
		list.dSLop[list.n]->dSSV = NULL;
		list.n = 1;
	}
	else {
		list.n++;
		list.dSLop[list.n-1] = new LopPtr();
		list.dSLop[list.n-1]->Data = lop;
		list.dSLop[list.n-1]->dSSV = NULL;
		
	}
	return 1;
}


// xoa phan tu o vi tri thu i
int delete_Lop_I(ListLop &list, int i) {
	int j;
	if (i<0 || i>list.n || list.n == 0) return 0;
	//if (i == 0) i = 1;
	for (j = i; j < list.n; j++)
		list.dSLop[j] = list.dSLop[j+1];
	list.n--;
}



// tim kiem thong tin lop thong qua ma lop
boolean search_MaLop(ListLop list, string malop) {
	if (list.n == 0) return false;
	for (int i = 0; i < list.n; i++)
	{
		if (list.dSLop[i]->Data.maLop == malop) return true;
	}
	return false;
}
LopPtr* getlop(ListLop list, string malop) {
	if (list.n == 0) return NULL ;
	for (int i = 0; i < list.n; i++)
	{
		if (list.dSLop[i]->Data.maLop == malop) return list.dSLop[i];
	}
	return NULL ;
}

// lay ra danh sach lop theo nien khoa
//boolean search_NNH(ListLop list, unsigned int nNH) {
//	if (list.n == 0) return true;
//	LopPtr lop = new Lop[100];
//	int count = 0;
//	for (int i = 0; i < list.n; i++) {
//		Lop temp = *list.dSLop[i];
//		if (temp.namNhapHoc == nNH) {
//			lop[count] = temp;
//		}
//	}
//	return lop;
//}

// chinh sua thong tin cua lop
int update_lop(ListLop  &list, Lop lop) {
	// kiem tra ma lop
	for (int i = 0; i < list.n; i++)
	{
		if (list.dSLop[i]->Data.maLop == lop.maLop) {
			list.dSLop[i]->Data = lop;
			return 1;
		}
	}
	return 0;
}

//----------------------- MonHoc -------------------//
//khoi tao
void Initialize(MonHocPtr &tree) {
	tree = NULL;
}
// search ma mh
MonHocPtr SearchMH(MonHocPtr &root, string maMH) {
	MonHocPtr p;
	p = root;
	while (p != NULL) {
		if (p->mh.maMH == maMH) {
			return p;
		}
		if (p->mh.maMH > maMH) {
			p = p->pLeft;
		}
		else {
			p = p->pRight;
		}
	}
	return NULL;
}
// insert mon hoc
MonHocPtr InsertMH(MonHocPtr &tree, MonHoc &mh) {
	if (tree == NULL) {
		MonHocPtr p = new NodeMonHoc();
		p->pLeft = p->pRight = NULL;
		p->mh = mh;
		tree = p;
		return tree;

	}
	if (mh.maMH < tree->mh.maMH) {
		InsertMH(tree->pLeft, mh);
	}
	else if (mh.maMH > tree->mh.maMH) {
		InsertMH(tree->pRight, mh);
	}
	return tree;
}

// update mon hoc
int updateMonhoc(MonHocPtr &tree,MonHoc mh){
	MonHocPtr mhPtr = SearchMH(tree,mh.maMH);
	if(mhPtr == NULL) return 0;
		//mhPtr.mh = mh;
	return 1;
}


// xoa 
void NodeThe(MonHocPtr &X, MonHocPtr &Y)
{
	if (Y->pLeft != NULL)
	{
		NodeThe(X, Y->pLeft);
	}
	else 
	{
		X->mh.maMH = Y->mh.maMH; 
		X = Y; 
		Y = Y->pRight; 
	}
}

int XoaMonhoc(MonHocPtr &t, string maMH)
{
	if (t == NULL)
	{
		return 0; 
	}
	else
	{
		if (maMH < t->mh.maMH)
		{
			XoaMonhoc(t->pLeft, maMH);
		}
		else if (maMH > t->mh.maMH)
		{
			XoaMonhoc(t->pRight, maMH);
		}
		else 
		{
			MonHocPtr X = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else 
			{
				NodeThe(X, t->pRight);
			}
			delete X; 
			return 1;
		}
	}
}


////////////////// xu ly ///////////////////////////

///////////// mon hoc //////////////////////

int xuLyThemMonhoc(MonHocPtr &tree) {
	MonHoc mh;
	while (1) {
			cout << "Nhap ma mon hoc : ";
			cin >> mh.maMH;
			if (SearchMH(tree, mh.maMH) != NULL) {
				cout << "ma mon hoc da ton tai ! nhap lai" << endl;
				continue;
			}
			cout << "Nhap ten mon hoc : ";
			cin >> mh.tenMH;
			cout << "Nhap so tin chi ly thuyet : ";
			cin >> mh.soTCLT;
		
			cout << "Nhap so tin chi thuc hanh : ";
			cin >> mh.soTCTH;
		
		InsertMH(tree, mh);
		Monhoc_Save(tree);	
		return 1;
	}
}

int xuLyXoaMonhoc(MonHocPtr &tree) {
	string mamh;
	while (1) {
		cout << "Nhap ma mon hoc can xoa : ";
		cin >> mamh;
		if (SearchMH(tree, mamh) == NULL) {
			cout << "ma mon hoc khong ton tai ! nhap lai"<<endl;
			continue;
		}
		cout << "ban co chac muon xoa mon hoc nay (Y/N)?";
		string check;
		cin >> check;
		for (auto & c : check) check = toupper(c);
		if (check != "Y") {
			return 0;
		}

		XoaMonhoc(tree, mamh);
		Monhoc_Save(tree);
		return 1;
	}
}

int xuLyHieuChinhMonhoc(MonHocPtr &tree) {
	MonHoc mh;
	while (1) {
		cout << "Nhap ma mon hoc can hieu chinh: ";
		cin >> mh.maMH;
		MonHocPtr mhptr = SearchMH(tree,mh.maMH);
		if (mhptr == NULL) {
			cout << "ma mon hoc khong ton tai ! nhap lai"<<endl;
			continue;
		}
		// hien thi thong tin mon hoc da nhap 
		cout << "	Thong tin mon hoc"<<endl;
		cout << " MA MON HOC: " + mhptr->mh.maMH + "  ";
		cout << " TEN MON HOC: " + mhptr->mh.tenMH + " ";
		cout << " STCLT: " << mhptr->mh.soTCLT << "  ";
		cout << " STCTH: " << mhptr->mh.soTCTH << endl<<endl;

		cout << "Nhap ten mon hoc can hieu chinh: ";
		cin >> mh.tenMH;
		cout << "Nhap so tin chi ly thuyet can hieu chinh: ";
		cin >> mh.soTCLT;
		cout << "Nhap so tin chi thuc hanh can hieu chinh : ";
		cin >> mh.soTCTH;
		// SAVE
		mhptr->mh.tenMH = mh.tenMH;
		mhptr->mh.soTCLT = mh.soTCLT;
		mhptr->mh.soTCTH = mh.soTCTH;

		Monhoc_Save(tree);
		return 1;
	}
}


// vector mon hoc sort monhoc theo ten mon hoc
vector<MonHoc> MonHoc_Arr;

bool Monhoc_Alpha_Compare(MonHoc S1,MonHoc S2)
{
	return (S1.maMH < S2.maMH);
}

void Monhoc_Convert(MonHocPtr t)
{
	if (t == NULL)
		return;
	Monhoc_Convert(t->pLeft);
	MonHoc_Arr.push_back(t->mh);
	Monhoc_Convert(t->pRight);
}


void Monhoc_Alpha_Sort(MonHocPtr t)
{
	MonHoc_Arr.erase(MonHoc_Arr.begin(), MonHoc_Arr.end());
	Monhoc_Convert(t);
	sort(MonHoc_Arr.begin(), MonHoc_Arr.end(), Monhoc_Alpha_Compare);
}

void IndsMonhoc(MonHocPtr tree) {
	Monhoc_Alpha_Sort(tree);
	for (int i = 0; i < MonHoc_Arr.size(); i++)
	{
		gotoxy(0, wherey());
		cout << " MA MON HOC: " + MonHoc_Arr[i].maMH;
		gotoxy(20, wherey());
		cout << " TEN MON HOC: " + MonHoc_Arr[i].tenMH;
		gotoxy(40, wherey());
		cout << " STCLT: " << MonHoc_Arr[i].soTCLT;
		gotoxy(60, wherey());
		cout << " STCTH: " << MonHoc_Arr[i].soTCTH << endl;
	}

}



/////////////// lop ///////////////


int xuLyThemLop(ListLop &list) {
	Lop lop;
	if (full(list) == 1) {
		cout << "list lop da day ! ";
		cout << "an phim bat ki de thoat";
		_getch();
		return 0;
	}
	while (1) {
		cout<< "Nhap ma lop : ";
		cin>>lop.maLop;
		
		if ( search_MaLop(list, lop.maLop) != NULL) {
			cout << "ma lop da ton tai ! nhap lai" << endl;
			continue;
		}
		cout << "Nhap ten lop : ";
		cin >> lop.tenLop;
		cout << "Nhap nam nhap hoc : ";
		cin >> lop.namNhapHoc;

		// SAVE
		insert_Lop(list,lop);
		Lop_Save(list);
		return 1;
	}
}

int xuLyXoaLop(ListLop &list) {
	string malop;
	while (1) {
		cout << "Nhap ma lop : ";
		cin >> malop;
		if (!search_MaLop(list, malop)) {
			cout << "ma lop khong ton tai ! nhap lai" << endl;
			continue;
		}

		// xu li xoa lop
		for (int j = 0; j < list.n; j++) {
			if (list.dSLop[j]->Data.maLop == malop) {
				if (list.dSLop[j]->dSSV != NULL) {
					cout << "lop dang ton tai sinh vien ! khong the xoa" << endl;
					_getch();
					return 0;
				}
				//xoa dc
				cout << "ban co chac muon xoa lop nay (Y/N)?";
				string check;
				cin >> check;
				for (auto & c : check) check = toupper(c);
				if (check != "Y") {
					return 0;
				}
				delete_Lop_I(list, j);
				// SAVE
				Lop_Save(list);
				return 1;
			}
		}
	
		return 0;
	}
}


int xuLyHieuChinhLop(ListLop &list) {
	Lop lop;
	while (1) {
		cout << "Nhap ma lop : ";
		cin >> lop.maLop;
		if (!search_MaLop(list, lop.maLop)) {
			cout << "ma lop không ton tai ! nhap lai" << endl;
			continue;
		}
		//cout << " MA LOP: " + lopp->maLop + "  ";
		//cout << " TEN LOP: " + lopptr->tenLop + "  ";
		//cout << " NAM NHAP HOC: " + lopptr->namNhapHoc; cout << " ";
		cout << "Nhap ten lop can hieu chinh: ";
		cin >> lop.tenLop;
		cout << "Nhap mam nhap hoc hieu chinh: ";
		cin >> lop.namNhapHoc;	
		//SAVE
		update_lop(list, lop);
		Lop_Save(list);
		return 1;
	}
}

void IndsLopNienKhoa(ListLop &list) {
	if (empty(list)) {
		cout << "khong co lop nao trong danh sach" << endl;
		return;
	}
	int nienkhoa;
	cout << "Nhap nien khoa: ";
	cin >> nienkhoa;
	
	for (int i = 0; i < list.n; i++)
	{
		if (list.dSLop[i]->Data.namNhapHoc == nienkhoa) {
			gotoxy(0, wherey());
			cout << "MA LOP: "+ list.dSLop[i]->Data.maLop;
			gotoxy(20, wherey());
			cout << "TEN LOP: "+ list.dSLop[i]->Data.tenLop;
			gotoxy(40, wherey());
			cout << "NIEN KHOA: " << list.dSLop[i]->Data.namNhapHoc<< endl;
		}
	}
	return;
}




//////////////// SAVE //////////////////

//--------Monhoc------------//

int countTree(MonHocPtr T)
{
	if (T == NULL) return 0;
	else
		if (T->pLeft == NULL && T->pRight == NULL) return 1;
		else return countTree(T->pLeft) + countTree(T->pRight);
}

void SaveMH(ofstream &fileout, MonHocPtr tree) {
	if (tree != NULL) {
		fileout << tree->mh.maMH << ",";
		fileout << tree->mh.tenMH << ",";
		fileout << tree->mh.soTCLT << ",";
		fileout << tree->mh.soTCTH << ",";
		SaveMH(fileout, tree->pLeft);
		SaveMH(fileout, tree->pRight);
	}

}

void Monhoc_Save(MonHocPtr tree)
{
	ofstream fileout;
	fileout.open("dsmonhoc.txt", ios_base::out);
	SaveMH(fileout, tree);
	fileout.close();
	return;
}

//--------Diem------------//
void SaveDiem(ofstream &fileout, Diem d) {
	fileout << "-";
	fileout << d.maMH << ",";
	fileout << d.lan << ",";
	fileout << d.diem << ",";
}

void Diem_Save(ofstream &fileout, NodeDiemPtr First) {
	if (Empty(First) || First == NULL || First->d.maMH == "") {
		return;
	}
	NodeDiemPtr p;
	for (p = First; p->next != NULL; p = p->next) {
		SaveDiem(fileout, p->d);
	}
	SaveDiem(fileout, p->d);

	return;
}

//--------Sinhvien------------//
void SaveSV(ofstream &fileout, SinhVien sv) {

	fileout << sv.maSV << ",";
	fileout << sv.ho << ",";
	fileout << sv.ten << ",";
	fileout << sv.phai << ",";
	fileout << sv.sdt << ",";
	Diem_Save(fileout, sv.firstD);
	fileout << "/";
}

void Sinhvien_Save(ofstream &fileout, NodeSVPtr First) {

	if (First == NULL || Empty(First) || First->sV.maSV == "") {
		return;
	}
	NodeSVPtr p;
	for (p = First; p->next != NULL; p = p->next) {
		SaveSV(fileout, p->sV);
	}
	SaveSV(fileout, p->sV);
	return;
}

//--------Lop------------//
void SaveLop(ofstream &fileout, LopPtr lop) {
	fileout << lop.Data.maLop << ",";
	fileout << lop.Data.tenLop << ",";
	fileout << lop.Data.namNhapHoc << ",";
	Sinhvien_Save(fileout, lop.dSSV);
}

void Lop_Save(ListLop list) {
	ofstream fileout;
	fileout.open("dslop.txt", ios_base::out);
	NodeSVPtr p;
	for (int i = 0; i < list.n; i++) {
		SaveLop(fileout, *list.dSLop[i]);
		fileout << "~";
		fileout << endl;
	}
	fileout.close();
	return;
}


//////////////// LOAD //////////////////

//--------Monhoc------------//


void LoadMH(ifstream &filein, MonHoc &mh) {
	//mamh
	getline(filein, mh.maMH, ',');

	// tenmh
	getline(filein, mh.tenMH, ',');

	// stclt
	string stclt;
	getline(filein, stclt, ',');
	mh.soTCLT = atoi(stclt.c_str());

	// stcth
	string stcth;
	getline(filein, stcth, ',');
	mh.soTCTH = atoi(stcth.c_str());
}

void Monhoc_Load(MonHocPtr &tree) {
	ifstream filein;
	MonHoc mh;
	filein.open("dsmonhoc.txt", ios::in);
	if (filein.fail()) {
		return;
	}
	while (!filein.eof()) {
		LoadMH(filein, mh);
		if (mh.maMH == "") {
			return;
		}
		InsertMH(tree, mh);
	}
	filein.close();
	return;
}


//--------Diem------------//
int LoadDiem(ifstream &filein, Diem &d) {

	//ma mh
	getline(filein, d.maMH, ',');

	//lan
	string lan;
	getline(filein, lan, ',');
	d.lan = atoi(lan.c_str());

	//diem
	//lan
	string diem;
	getline(filein, diem, ',');
	d.diem = atoi(diem.c_str());

	int num = filein.tellg();
	string test;
	getline(filein, test, '/');
	if (test == "") {
		getline(filein, test, '~');
		if (test == "") {
			return 1;
		}
		filein.seekg(num + 1);
		return 0;
	}
	else {
		filein.seekg(num + 1);
		return 0;
	}
}

int Diem_Load(ifstream &filein, NodeDiemPtr &First) {

	if (First != NULL) {
		return 0;
	}

	Diem d;
	while (1) {
		int check = LoadDiem(filein, d);
		insert_After(First, d);
		if (check == 1) return 1;

	}
	filein.close();

	return 0;
}



//--------Sinhvien------------//

int LoadSV(ifstream &filein, SinhVien &sv) {

	//ma sv
	getline(filein, sv.maSV, ',');

	//ma ho
	getline(filein, sv.ho, ',');

	//ma ten
	getline(filein, sv.ten, ',');

	//ma sv
	string phai;
	getline(filein, phai, ',');
	if (phai == "0") {
		sv.phai = nam;
	}
	else {
		sv.phai = nu;
	}

	//sdt
	getline(filein, sv.sdt, ',');

	int num = filein.tellg();
	string test;
	getline(filein, test, '/');
	if (test == "") {
		getline(filein, test, '~');
		if (test == "") {
			return 1;
		}
		filein.seekg(num + 1);
		return 2;
	}
	else {
		// load diem
		filein.seekg(num + 1);
		int check = Diem_Load(filein, sv.firstD);
		if (check == 1) return 1;
	}
	return 0;
	_getch();
	//filein.ignore(1);
}

void Sinhvien_Load(ifstream &filein, NodeSVPtr &First) {
	SinhVien sv;

	while (1) {
		int check = LoadSV(filein, sv);
		if (sv.maSV == "") {
			break;
		}
		insert_First(First, sv);
		if (check == 1) break;
		//ThemcuoiSV(First, sv);
	}
	filein.close();

	return;
}
//--------Lop------------//
void LoadLop(ifstream &filein, LopPtr &lop) {

	//ma lop
	getline(filein, lop.Data.maLop, ',');

	//ten lop
	getline(filein, lop.Data.tenLop, ',');

	//ma sv
	string nam;
	getline(filein, nam, ',');
	lop.Data.namNhapHoc = atoi(nam.c_str());

	// load sinh vien
	Sinhvien_Load(filein, lop.dSSV);
	string tam;
	getline(filein, tam);

}

void Lop_Load(ListLop &list) {
	ifstream filein;
	LopPtr lop;
	filein.open("dslop.txt", ios::in);

	if (filein.fail() || !filein)
	{
		// file is empty 
		return;
	}
	// clear list;

	while (!filein.eof()) {
		LoadLop(filein, lop);
		if (lop.Data.maLop == "") {
			break;
		}
		//insert_load_Lop(list, lop);
		cout << "c-" + lop.Data.maLop + "-" + lop.dSSV[0].sV.maSV;
		cout << "xong";
		_getch();
	}
	filein.close();

	return;
}
//check int 
bool checkNumber(const string& str)
{
	for (char const &c : str) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}
//check float
bool checkFloat(const string& str)
{
	for (char const &c : str) {
		if (isdigit(c) == 0 && c != '.') return false;
	}
	return true;
}