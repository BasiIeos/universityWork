#include <iostream>

using namespace std;

class AVLTree
{
	public:
		AVLTree();
		void deleteNode(TreeNode *&node);
		~AVLTree();
		void inOrder(TreeNode *&root) const;
		void preOrder(TreeNode *&root) const;
		void postOrder(TreeNode *&root) const;
		int insert(TreeNode *&root, int k);
	private:
		struct TreeNode 
		{
			int data;
			TreeNode *left;
			TreeNode *right;
			int balance;
		};
		TreeNode *root;
};

AVLTree :: AVLTree()
{
	root = 0;
}

void deleteNode (TreeNode *&node)
{
	if (node->left != 0)
		deleteNode(node->left);
	if (node->right != 0)
		deleteNode(node->right);
	delete node;
}

AVLTree :: ~AVLTree()
{
	deleteNode(root);
}

int AVLTree :: insert(TreeNode *&root, int k)
{
	if (root == 0)
	{
		root = new TreeNode;
		root->data = k;
		root->left = 0;
		root->right = 0;
		root->balance = 0;
		return 1;
	}
	else if (root->data == k)
		return -1;
	else if (root->data > k)
	{
		int bal = insert(root->left, k);
		if (bal == -1)
			return -1;
		else if (bal == 1)
		{
			if (root->balance == 0)
			{
				root->balance = -1;
				return 1;
			}
			else if (root->balance == 1)
			{
				root->balance = 0;
				return 0;
			}
			else
			{
				TreeNode *b = root->left;
				if (b->data > k)
				{
					TreeNode *temp = b->right;
					b->right = root;
					root->left = temp;
					root->balance = 0;
					b->balance = 0;
					root = b;
				}
				else if (b->data < k)
				{
					TreeNode *c = b->right;
					TreeNode *temp1 = c->left;
					TreeNode *temp2 = c->right;
                                        c->left = b;
					c->right = root;
					b->right = temp1;
					root->left = temp2;
					if (c->data > k)
					{
						c->balance = 0;
						b->balance = 0;
						root->balance = 1;
					}
					else if (c->data < k)
					{
						c->balance = 0;
						b->balance = -1;
						root->balance = 0;
					}
					root = c;
				}
				return 0;
			}
		}
	}
	else
	{
		int bal = insert(root->right, k);
		if (bal == -1)
			return -1;
		else if (bal == 1)
		{
			if (root->balance == 0)
			{
				root->balance == 1;
				return 1;
			}
			else if (root->balance == -1)
			{
				root->balance = 0;
				return 0;
			}
			else
			{
				TreeNode *b = root->right;
				if (b->data < k)
				{
					TreeNode *temp = b->left;
					b->left = root;
					root->right = temp;
					root->balance = 0;
					b->balance = 0;
					root = b;
				}
				else if (b->data > k)
				{
					TreeNode *c = b->left;
					TreeNode *temp1 = c->right;
					TreeNode *temp2 = c->left;
					c->right = b;
					c->left = root;
					b->left = temp1;
					root->right = temp2;
					if (c->data < k)
					{
						c->balance = 0;
						b->balance = 0;
						root->balance = -1;
					}
					else if (c->data > k)
					{
						c->balance = 0;
						b->balance = 1;
						root->balance = 0;
					}
					root = c;
				}
				return 0;
			}
		}
	}
}

void AVLTree :: inOrder(TreeNode *&root) const
{
	if (root != 0)
	{
		inOrder(root->left);
		cout << root->data << ' ';
		inOrder(root->roght);
	}
}

void AVLTree :: preOrder(TreeNode *&root) const
{
	if (root != 0)
	{
		cout << root->data << ' ';
		preOrder(root->left);
		preOrder(root->right);
	}
}

void AVLTree :: postOrder(TreeNode *&root) const
{
	if (root != 0)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << ' ';
	}
}

int main()
{
	return 0;
