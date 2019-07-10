/*****************************************************************************
 * This example demonstrates the development of data structures - Binary Tree (no balance)
 *
 * Этот пример демонстрирует разработку структуры данных - Бинарное дерево (не сбалансированное)
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <exception>

template <typename T>
struct BinTree
{
	int _size;

	struct Node
	{
		Node (T el) : data(el)
		{}
		Node (T el, Node* left, Node* right) : data(el), left(left), right(right)
		{}
		T data;
		Node* left;
		Node* right;
	};

public:
	BinTree() : root(NULL)
	{}
	Node* root; //private

	void add (T, Node*&);
	void print (Node*&);
	void clear(Node*&);
	int size ();
	bool empty ();
};

template <typename T>
void BinTree<T>::add (T el, Node*& ro)
{
	if (ro == NULL)
	{
		ro = new Node(el);
		_size++;
		return;
	}

	if (ro->right == NULL && el > ro->data)
	{
		ro->right = new Node (el);
		_size++;
	}
	if (ro->left == NULL && el < ro->data)
	{
		ro->left = new Node (el);
		_size++;
	}

	if (el > ro->data)
		add (el, ro->right);
	if (el < ro->data)
		add (el, ro->left);
}

template <typename T>
void BinTree<T>::print (Node*& n)
{
	if (n == NULL)
		return;

	std::cout << n->data << "(";
		print(n->left);
	std::cout << "&";
		print(n->right);
	std::cout << ")";
}

template <typename T>
void BinTree<T>::clear(Node*& n)
{
	if (n == NULL)
		return;

	clear(n->left);
	clear(n->right);

	delete n;
	n = NULL;
	_size--;
}

template <typename T>
int BinTree<T>::size ()
{
	return _size;
}

template <typename T>
bool BinTree<T>::empty ()
{
	return _size == 0 ? true : false;
}

int main()
{
	BinTree<int> tree;

	//No balance tree
	tree.add(50, tree.root);
	tree.add(70, tree.root);
	tree.add(100, tree.root);
	tree.add(60, tree.root);
	tree.add(10, tree.root);
	tree.add(30, tree.root);
	tree.add(20, tree.root);
	tree.add(40, tree.root);
	tree.add(80, tree.root);
	tree.add(200, tree.root);
	tree.add(150, tree.root);

	tree.print(tree.root);

	std::cout << std::endl << std::endl << "Size: " << tree.size() << std::endl;
	tree.clear(tree.root);
	std::cout << "Size: " << tree.size() << std::endl;

	std::cout << std::endl << "Hard no balance tree" << std::endl << std::endl;

	//Hard no balance tree
	for (int i = 0; i <= 100; i += 10)
		tree.add(i, tree.root);

	tree.print(tree.root);

	std::cout << std::endl << std::endl << "Size: " << tree.size() << std::endl;
	tree.clear(tree.root);
	std::cout << "Size: " << tree.size() << std::endl << std::endl;
}
