// Vasily Kontorer
// Assignment 2
// Implementation of binary search tree

#include <iostream>
#include <string>

using namespace std;

template <typename K, typename T>
class Btree
{
	private:
		struct Node
		{
			K* key;
			T* data;
			Node* left;
			Node* right;
		}
		Node* root;
	public:
		Btree();
		~Btree();
		void deletenode(Node* a);
		void insert(K key, T data);
		void inOrder();
		void traverse(Node* a);
}

template <typename K, typename T>
Btree :: Btree()
{
	root = 0;
}

template <typename K, typename T>
Btree:: ~Btree
{
	deletenode(root);
}

template <typename K, typename T>
void Btree :: deletenode(Node* a)
{
	if (a != 0)
	{
		deletenode(root->left);
		deletenode(root->right);
	}
	delete a;
}

template <typename K, typename T>
void Btree :: insert(K* k, t* d)
{
	Node* cur = root;
	while (cur != 0)
		if (cur->key > k)
			cur = cur->left;
		else
			cur = cur->right;
	cur->key = k;
	cur->data = d;
	cur->left = 0;
	cur->right = 0;
}

template <typename K, typename T>
void Btree :: inOrder()
{
	traverse(root);
}

template <typename K, typename T>
void Btree :: traverse(Node* a)
{
	if (a != 0)
	{
		traverse(a->left);
		cout << a->key << '\n';
		cout << a->data << '\n';
		traverse(a->right);
	}
}
