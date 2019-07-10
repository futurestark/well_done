/*****************************************************************************
 * This example demonstrates the development of data structures - Queue
 *
 * Этот пример демонстрирует разработку структуры данных - Очередь
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
struct Queue
{
	Queue () : _first (NULL), _last (NULL), _size (0)
	{}

	struct Node
	{
		Node (T el) : data (el), next (NULL)
		{}
		Node* next;
		T data;
	};

	void push (const T);
	void pop ();
	T& first ();
	T& last ();
	int size ();
	bool empty ();

private:
	Node* _first;
	Node* _last;
	int _size;
};

template <typename T>
void Queue<T>::push (const T el)
{
	try
	{
		if (_last != NULL)
		{
			Node* temp = new Node(el);
			_last->next = temp;
			_last = temp;
		}
		else
		{
			_last = _first = new Node (el);
		}
		_size++;
	}
	catch (std::bad_alloc)
	{
		std::cout << "std::bad_alloc" << std::endl;
	}
}

template <typename T>
void Queue<T>::pop ()
{
	try
	{
		if (_first == NULL)
			throw std::out_of_range("Error: Out of range");

		Node* temp = _first;
		_first = _first->next;
		delete temp;
		_size--;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
T& Queue<T>::first ()
{
	try
	{
		if (_first == NULL)
			throw std::out_of_range("Error: Queue is empty!");

		return _first->data;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
T& Queue<T>::last ()
{
	try
	{
		if (_last == NULL)
			throw std::out_of_range("Error: Queue is empty!");

		return _last->data;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
int Queue<T>::size ()
{
	return _size;
}

template <typename T>
bool Queue<T>::empty ()
{
	return _size == 0 ? true : false;
}

int main()
{
	Queue<int> queue;
	//std::cout << Queue.first() << std::endl;

	queue.push(10);
	queue.push(2);
	queue.push(4);
	queue.push(5);

	while (!queue.empty())
	{
		std::cout << queue.first() << " - " << queue.size() << std::endl;
		queue.pop();
	}

	//Call exception
	queue.pop();

	return 0;
}
