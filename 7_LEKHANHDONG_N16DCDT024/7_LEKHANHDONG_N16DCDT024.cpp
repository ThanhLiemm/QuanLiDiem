#include "7_LEKHANHDONG_N16DCDT024.h"

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
float average(NodeDiemPtr &firstD);


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
		firstSV->sV = sv;
		firstSV->next = NULL;
	}
	else {
		NodeSVPtr p = new NodeSV;
		p->sV = sv;
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
int updateSV(NodeSVPtr firstSV, SinhVien sv);
// xoa sv thong qua ma sv
int delete_maSV(NodeSVPtr firstSV, string maSV) {
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

//----------------------- Lop -------------------//
//kiem tra co rong khong 
int empty(ListLop list) {
	return list.n == 0;
}
//kiem tra xem danh sach da day chua;
int full(ListLop list) {
	return (list.n == MAXLIST ? 1 : 0);
}
// them lop o vi tri thu i gia tri la lop
int insert_Lop(ListLop &list, int i, Lop lop) {
	int j;
	if (i<0 || i> list.n + 1 || full(list)) return 0;
	if (empty(list)) {
		*list.dSLop[0] = lop;
		list.n = 1;
	}
	else {
		if (i == 0) i = 1;
		for (j = list.n - 1; j >= i - 1; j--)
			list.dSLop[j + 1] = list.dSLop[j];
		*list.dSLop[i - 1] = lop;
		list.n++;
	}
	return 1;
}
// xoa phan tu o vi tri thu i
int delete_Lop(ListLop &list, int i) {
	int j;
	if (i<0 || i>list.n || list.n == 0) return 0;
	if (i == 0) i = 1;
	for (j = 1; j < list.n; j++)
		list.dSLop[j - 1] = list.dSLop[j];
	list.n--;
}
// tim kiem thong tin lop thong qua ma lop
LopPtr search_MaLop(ListLop list, string malop) {
	if (list.n == 0) return NULL;
	for (int i = 0; i < list.n; i++)
	{
		Lop tem = *list.dSLop[i];
		if (tem.maLop == malop) return list.dSLop[i];
	}
	return NULL;
}
// lay ra danh sach lop theo nien khoa
LopPtr search_NNH(ListLop list, unsigned int nNH) {
	if (list.n == 0) return NULL;
	LopPtr lop = new Lop[100];
	int count = 0;
	for (int i = 0; i < list.n; i++) {
		Lop temp = *list.dSLop[i];
		if (temp.namNhapHoc == nNH) {
			lop[count] = temp;
		}
	}
	return lop;
}
// chinh sua thong tin cua lop
int update_Lop(ListLop list, Lop lop) {
	// kiem tra ma lop
	LopPtr oldLop = search_MaLop(list, lop.maLop);
	if (&lop == NULL) return 0;
	*oldLop = lop;
	return 1;
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
			cout << "ma mon hoc da ton tai ! nhap lai"<<endl;
			continue;
		}
		cout << "Nhap ten mon hoc : ";
		cin >> mh.tenMH;
		cout << "Nhap so tin chi ly thuyet : ";
		cin >> mh.soTCLT;
		cout << "Nhap so tin chi thuc hanh : ";
		cin >> mh.soTCTH;
		cout << "check - " + mh.soTCLT;
		
		// SAVE
		InsertMH(tree, mh);
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

		// SAVE
		XoaMonhoc(tree, mamh);
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
		return 1;
	}
}


void IndsMonhoc(MonHocPtr tree) {
	if (tree != NULL)
	{
		IndsMonhoc(tree->pLeft);
		IndsMonhoc(tree->pRight);
		cout << " MA MON HOC: " + tree->mh.maMH +"  ";
		cout << " TEN MON HOC: " + tree->mh.tenMH+" " ;
		cout << " STCLT: "<<tree->mh.soTCLT << "  ";
		cout << " STCTH: "<<tree->mh.soTCTH << endl;
	}
//	else {
//		cout << "2";
//		cout << " Danh Sach trong" << endl;
//		cout << "ESC de thoat  -  an phim bat ki de tiep tuc" << endl;
//		char ch = _getch();
//		if (ch == 27) return;
//	}
}

/////////////// lop ///////////////


int xuLyThemLop(ListLop &list) {
	Lop lop;
	while (1) {
		cout << "Nhap ma lop : ";
		cin >> lop.maLop;
		if (search_MaLop(list, lop.maLop) != NULL) {
			cout << "ma lop da ton tai ! nhap lai" << endl;
			continue;
		}
		cout << "Nhap ten lop : ";
		cin >> lop.tenLop;
		cout << "Nhap nam nhap hoc : ";
		cin >> lop.namNhapHoc;

		// SAVE
		//insert_Lop()
		return 1;
	}
}

void xuLyXoaLop(ListLop &list) {
	string malop;
	while (1) {
		cout << "Nhap ma lop : ";
		cin >> malop;
		LopPtr lopptr = search_MaLop(list, malop);
		if ( lopptr == NULL) {
			cout << "ma lop không ton tai ! nhap lai" << endl;
			continue;
		}
		// ktr
		if (lopptr->dSSV == NULL) { // ton tai sinh vien
			cout << "lop dang ton tai sinh vien ! khong the xoa" << endl;
			cout << "ESC de thoat  -  an phim bat ki de tiep tuc" << endl;
			char ch = _getch();
			if (ch == 27) return;
		}
		//xoa dc
		cout << "ban co chac muon xoa lop nay (Y/N)?";
		string check;
		cin >> check;
		if (check == "N") {
			return;
		}
		
		// xu li xoa lop
		for (int j = 1; j < list.n; j++) {
			if (list.dSLop[j]->maLop == malop) {
				delete_Lop(list, j);
				return;
			}
		}
		// SAVE
		return;
	}
}


int xuLyHieuChinhLop(ListLop &list) {
	Lop lop;
	while (1) {
		cout << "Nhap ma lop : ";
		cin >> lop.maLop;
		LopPtr lopptr = search_MaLop(list, lop.maLop);
		if (lopptr == NULL) {
			cout << "ma lop không ton tai ! nhap lai" << endl;
			continue;
		}
		cout << " MA LOP: " + lopptr->maLop + "  ";
		cout << " TEN LOP: " + lopptr->tenLop + "  ";
		cout << " NAM NHAP HOC: " + lopptr->namNhapHoc; cout << " ";
		cout << "Nhap ten lop can hieu chinh: ";
		cin >> lop.tenLop;
		cout << "Nhap mam nhap hoc hieu chinh: ";
		cin >> lop.namNhapHoc;
		
		//SAVE
		update_Lop(list, lop);
		return 1;
	}
}

void IndsLopNienKhoa(ListLop &list) {
	int nienkhoa;
	cout << "Nhap nien khoa: ";
	cin >>nienkhoa;
	LopPtr lop = new Lop[100];
	lop = search_NNH(list, nienkhoa);
	if (lop[0].namNhapHoc == 0) {
		cout << "khong co lop nao cua nien khoa nay" << endl;
		cout << "ESC de thoat  -  an phim bat ki de tiep tuc" << endl;
		char ch = _getch();
		if (ch == 27) return;
	}
	for (int i = 0; i < 100;i++) {
		cout << "Ma lop " + lop[i].maLop + "   ";
		cout << "Ten lop " + lop[i].tenLop + "   ";
		cout << "Năm nhập học " + lop[i].namNhapHoc<<endl;
	}
}
