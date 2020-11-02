#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 26 * 4;

int N;
vector<int> _tree[MAX_SIZE];
bool visitedByInorder[MAX_SIZE];
bool visitedByPostorder[MAX_SIZE];

void preorder(int curNodeIndex, int visitCnt) {

	// root leftNode rightNode

	char curChar = curNodeIndex + 'A';
	cout << curChar;

	if (visitCnt == N-1) return;

	int leftNode = _tree[curNodeIndex][0];
	int rightNode = _tree[curNodeIndex][1];

	
	if (leftNode != -1) {
		visitCnt++;
		preorder(leftNode, visitCnt);
	}

	if (rightNode != -1) {
		visitCnt++;
		preorder(rightNode, visitCnt);
	}

	return;
}

void lnorder(int curNodeIndex) {

	// leftNode root rightNode

	char curChar = curNodeIndex + 'A';

	int leftNode = _tree[curNodeIndex][0];
	int rightNode = _tree[curNodeIndex][1];

	if (leftNode == -1 || visitedByInorder[leftNode]) {
//		visitedByInorder[curNodeIndex] = true;
//		cout << curChar;
		
	}
	else {
		lnorder(leftNode);
	}

	visitedByInorder[curNodeIndex] = true;
	cout << curChar;


	if (rightNode != -1 && !visitedByInorder[rightNode]) {
		lnorder(rightNode);		
	}

	return;

}



void postorder(int curNodeIndex) {

	// leftNode rightNode root

	char curChar = curNodeIndex + 'A';
	//cout << curChar << " ";
	int leftNode = _tree[curNodeIndex][0];
	int rightNode = _tree[curNodeIndex][1];

	if (leftNode == -1 || visitedByPostorder[leftNode]);
	else {
		postorder(leftNode);
	}

	if (rightNode == -1 || visitedByPostorder[rightNode]);
	else {
		postorder(rightNode);
	}

	if ((leftNode == -1 && rightNode == -1) 
		|| (leftNode == -1 && rightNode != -1 && visitedByPostorder[rightNode]) 
		|| (leftNode != -1 && rightNode == -1 && visitedByPostorder[leftNode])
		|| (leftNode != -1 && rightNode != -1 && visitedByPostorder[leftNode] && visitedByPostorder[rightNode])) {
		visitedByPostorder[curNodeIndex] = true;
			cout << curChar;
	}
	

	return;


}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {

		char root, leftNode, rightNode;
		cin >> root >> leftNode >> rightNode;

		int rootIndex = root - 'A';

		if (leftNode == '.') _tree[rootIndex].push_back(-1);
		else {
			_tree[rootIndex].push_back(leftNode - 'A');
		}
		if (rightNode == '.') _tree[rootIndex].push_back(-1);
		else {
			_tree[rootIndex].push_back(rightNode - 'A');
		}

	}

	preorder(0,0);
	cout << "\n";
	lnorder(0);
	cout << "\n";
	postorder(0);


	return 0;
}