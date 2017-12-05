#define CHILD 3

#include<vector>
#include <cstdlib>
#include <climits>
#include <iostream>
#include<algorithm>
using namespace std;

class node
{
public:
	char name;
	int val;
	vector<node*> children;
};

node* root;

node* p_min_at(node* s, int lower, int upper);
node* p_max_at(node* s, int lower, int upper);

node* p_min_at(node* s, int lower, int upper)
{
	cout << s->name << "\n";

	if (s->children.size() == 0)	return s;
	node* ret = NULL;
	int MIN = INT_MAX;

	for (int i = s->children.size() - 1; i >= 0; i--)
	{
		node* temp = p_max_at(s->children[i], lower, min(MIN, upper));

		if (temp->val <= lower) return temp;
		else if (temp->val < MIN)
		{
			MIN = temp->val;
			ret = temp;
		}
	}
	return ret;
}

node* p_max_at(node* s, int lower, int upper)
{
	cout << s->name << "\n";
	if (s->children.size() == 0)	return s;
	node* ret = NULL;
	int MAX = INT_MIN;

	for (int i = s->children.size() - 1; i >= 0; i--)
	{
		node* temp = p_min_at(s->children[i], max(MAX, lower), upper);

		if (temp->val >= upper) return temp;
		else if (temp->val > MAX)
		{
			MAX = temp->val;
			ret = temp;
		}
	}
	return ret;
}

node* make_node(char name, int val)
{
	node* ret = new node();
	ret->name = name;	ret->val = val;	
	return ret;
}

void __init__()
{
	node* L = make_node('L', 2);
	node* M = make_node('M', 3);
	node* N = make_node('N', 8);
	node* O = make_node('O', 5);
	node* P = make_node('P', 7);
	node* Q = make_node('Q', 6);
	node* R = make_node('R', 0);
	node* S = make_node('S', 1);
	node* T = make_node('T', 5);
	node* U = make_node('U', 2);
	node* V = make_node('V', 8);
	node* W = make_node('W', 4);
	node* X = make_node('X', 10);
	node* Y = make_node('Y', 2);

	node* E = make_node('E', 0);
	E->children.push_back(L); E->children.push_back(M);
	node* F = make_node('F', 0);
	F->children.push_back(N);		F->children.push_back(O);
	node* G = make_node('G', 0);
	G->children.push_back(P);		G->children.push_back(Q);
	node* H = make_node('H', 0);
	H->children.push_back(R);		H->children.push_back(S);
	node* I = make_node('I', 0);
	I->children.push_back(T);		I->children.push_back(U);
	node* J = make_node('J', 0);
	J->children.push_back(V);		J->children.push_back(W);
	node* K = make_node('K', 0);
	K->children.push_back(X);		K->children.push_back(Y);

	node* B = make_node('B', 0);
	B->children.push_back(E);		B->children.push_back(F);	B->children.push_back(G);
	node* C = make_node('C', 0);
	C->children.push_back(H);		C->children.push_back(I);	
	node* D = make_node('D', 0);
	D->children.push_back(J);		D->children.push_back(K);

	node* A = make_node('A', 0);
	A->children.push_back(B);		A->children.push_back(C);	A->children.push_back(D);

	root = A;

}

int main(void)
{
	__init__();
  	node* choice = p_max_at(root, INT_MIN, INT_MAX);

	return 0;
}