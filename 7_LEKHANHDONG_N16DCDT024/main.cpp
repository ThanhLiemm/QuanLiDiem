// 7_LEKHANHDONG_N16DCDT024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "7_LEKHANHDONG_N16DCDT024_1.h"


int main()
{
	MonHocPtr tree;
	Initialize(tree);
	ListLop listlop;
	//Lop lop;
	//lop.maLop = "1234";
	//lop.namNhapHoc = 2020;
	//lop.tenLop = "D20CQCN020-N";
	//insert_Lop(listlop, lop);
	//Initialize(listlop.dSLop[0]->dSSV);
	Monhoc_Load(tree);
	while (true) {
		menuChinh(tree, listlop);
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
