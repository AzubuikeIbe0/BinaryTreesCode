#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {

	BinaryTree T1;

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

	T1.GetHeight();

	//T1.PreOrder();
	//cout << endl;

	T1.InOrder();
	cout << endl;

	T1.DeleteNode(1);
	T1.DeleteNode(3);
	T1.DeleteNode(5);
	T1.DeleteNode(7);
	T1.DeleteNode(9);

	T1.InOrder();
	cout << endl;

	
	

	/*T1.PostOrder();*/



	

	/*T1.DeleteNodePrivate(root, 7);*/
	//T1.InsertNodePrivate(root, 7);
	//cout << endl;

	//T1.PreOrder(root);

//                       1
//            __________/ \__________
//           /                        \
//          2                          3
//      ____/ \____                ____/ \____
//     /           \              /           \
//    4             5            6             7
//  __/ \__       __/ \__      __/ \__       __/ \__
// /       \     /       \    /       \     /       \
//8         9   10        11 12       13   14       15
// |         |   |         |  |         |   |         |
//16        17  18        19 20        21  22        23





	return 0;
}