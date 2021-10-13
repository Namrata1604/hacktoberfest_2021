#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
	int data;
	Node* left, *right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

class BinaryTree {
private:
	ll sum = 0, res = 0;
public:
	Node* create() // create Binary Tree
	{
		ll rootData; cin >> rootData;
		Node* root = new Node(rootData);
		queue<Node* > pendingNode;
		pendingNode.push(root);
		while (pendingNode.size() != 0)
		{
			Node* f = pendingNode.front();
			pendingNode.pop();
			ll leftData; cin >> leftData;

			ll rightData; cin >> rightData;
			if (leftData != -1)
			{
				Node* leftRoot = new Node(leftData);
				pendingNode.push(leftRoot);
				f->left = leftRoot;
			}
			if (rightData != -1)
			{
				Node* rightRoot = new Node(rightData);
				pendingNode.push(rightRoot);
				f->right = rightRoot;
			}
		}
		return root;
	}

	void print(Node* root) // print Binary tree
	{
		if (root == NULL) return;
		queue<Node* > q;
		q.push(root);
		while (!q.empty())
		{
			Node* f = q.front();
			q.pop();
			cout << f->data << " : ";
			if (f->left != NULL)
			{
				cout << f->left->data << ' ';
				q.push(f->left);
			}
			if (f->right != NULL)
			{
				cout << f->right->data << ' ';
				q.push(f->right);
			}
			cout << '\n';
		}
	}

	ll height(Node *root) // Height of Binary Tree
	{
		if (!root) return 0;
		return 1 + max(height(root->left), height(root->right));
	}

	ll treePathsSum(Node *root)
	{
		if (root == NULL) return 0;
		res = res * 10 + root->data;
		root->data = res;
		if (root->left == NULL and root->right == NULL)
			sum += root->data;
		treePathsSum(root->left);
		res = root->data;
		treePathsSum(root->right);
		return sum;
	}

	ll diameter(Node* root) // Diameter Of Bianry Tree
	{
		if (!root) return 0;
		ll ld = diameter(root->left);
		ll rd = diameter(root->right);
		ll lft = height(root->left);
		ll rght = height(root->right);
		return max({1 + lft + rght, ld, rd});
	}
};

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
	BinaryTree bt;
	Node *root = bt.create();
	cout << "Tree : \n" ;
	bt.print(root);
	cout << "TreePathsSum : \n";
	bt.treePathsSum(root);
	bt.print(root);
	cout << "Height : " << bt.height(root) << '\n';
	cout << "Diameter : " << bt.diameter(root) << '\n';
	return 0;
}
