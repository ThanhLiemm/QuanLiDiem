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
int empty(ListLop &list) {
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
		list.dSLop[i - 1] = lop;
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
		*list.dSLop[j - 1] = list.dSLop[j];
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
		if (strcmp(p->mh.maMH, maMH) == 0) {
			return p;
		}
		if (strcmp(p->mh.maMH, maMH) == 1) {
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
	if (strcmp(mh.maMH, tree->mh.maMH) == -1) {
		InsertMH(tree->pLeft, mh);
	}
	else if (strcmp(mh.maMH, tree->mh.maMH) == 1) {
		InsertMH(tree->pRight, mh);
	}
	return tree;
}
// xoa
MonHocPtr rp;
void Xoanode2con(MonHocPtr &k) {

	if (k->pLeft != NULL) {
		Xoanode2con(k->pLeft);
		//r la nut cuc trai cua cay con ben phai, nut goc la rp
	}
	else {

		rp->mh = k->mh;
		rp = k;
		k = rp->pRight;

	}
}
int XoaMonhoc(MonHocPtr &tree, string maMH) {
	MonHocPtr p = SearchMH(tree, maMH);
	if (p == NULL) {
		return 0;
	}
	else {
		rp = p;
		if (rp->pRight == NULL) {
			// p la nut la hoac la nut chi co cay con ben trai
			p = rp->pLeft;
		}
		else if (rp->pLeft == NULL) {
			// p la nut co cay con ben phai
			p = rp->pRight;
		}
		else {
			Xoanode2con(rp->pRight);
		}
		delete rp;
		return 1;
	}
}

// update mon hoc
int updateMonhoc(MonHocPtr &tree,MonHoc mh){
	MonHocPtr mhPtr = SearchMH(tree,mh.maMH);
	if(mhPtr == NULL) return 0;
	mhPtr.mh = mh;
	return 1;
}


