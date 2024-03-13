#include <iostream>
#include "Tree.h"
using namespace std;

int main() {

	Tree T1;
	T1.InsertNode(1);

	T1.InsertNode(2);
	T1.InsertNode(3);

	T1.InsertNode(4);
	T1.InsertNode(5);
	T1.InsertNode(6);
	T1.InsertNode(7);

	T1.InsertNode(8);
	T1.InsertNode(9);
	T1.InsertNode(10);
	T1.InsertNode(11);

	T1.PrintTree();
	//1, 2, 4, 8, 9, 5, 3, 6, 10, 11, 7,

	T1.InOrder();
	//8, 4, 9, 2, 5, 1, 10, 6, 11, 3, 7,

	//T1.InsertNode();
	//1, 2, 4, 8, 9, 5, 3, 6, 10, 11, 7,

	//T1.PostOrder(root);
	//8, 9, 4, 5, 2, 10, 11, 6, 7, 3, 1,


	//T1.PreOrder(root);
	//cout << endl;
	/*1, 2, 4, 8, 9, 5, 3, 6, 10, 11, 7,*/

	/*T1.DeleteNodePrivate(root, 7);*/
	//T1.InsertNodePrivate(root, 7);
	//cout << endl;

	//T1.PreOrder(root);



	return 0;
}