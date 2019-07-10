/*****************************************************************************
 * This example demonstrates the development of data structures - Deque
 *
 * Этот пример демонстрирует разработку структуры данных - Двусторонняя очередь
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
struct Deque
{
	Deque () : _first (NULL), _last (NULL), _size (0)
	{}

	struct Node
	{
		Node (T el) : data (el)
		{}
		Node* previous;
		Node* next;
		T data;
	};

	void push_back (const T);
	void push_front (const T);
	void pop_back ();
	void pop_front ();
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
void Deque<T>::push_back (const T el)
{
	try
	{
		if (_last != NULL)
		{
			Node* temp = new Node(el);
			_last->next = temp;
			temp->previous = _last;
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
void Deque<T>::push_front (const T el)
{
	try
	{
		if (_first != NULL)
		{
			Node* temp = new Node(el);
			_first->previous = temp;
			temp->next = _first;
			_first = temp;
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
void Deque<T>::pop_back ()
{
	try
	{
		if (_last == NULL)
			throw std::out_of_range("Error: Out of range");

		Node* temp = _last;
		_last = _last->previous;
		delete temp;
		_size--;

		if (_last)
			_last->next = NULL;
		else
			_first = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
void Deque<T>::pop_front()
{
	try
	{
		if (_first == NULL)
			throw std::out_of_range("Error: Out of range");

		Node* temp = _first;
		_first = _first->next;
		_size--;

		if (_first)
			_first->previous = NULL;
		else
			_last = NULL;
		delete temp;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
T& Deque<T>::first ()
{
	try
	{
		if (_first == NULL)
			throw std::out_of_range("Error: Deque is empty!");

		return _first->data;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
T& Deque<T>::last ()
{
	try
	{
		if (_last == NULL)
			throw std::out_of_range("Error: Deque is empty!");

		return _last->data;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
int Deque<T>::size ()
{
	return _size;
}

template <typename T>
bool Deque<T>::empty ()
{
	return _size == 0 ? true : false;
}

int main()
{
	Deque<int> deque;
	//std::cout << deque.first() << std::endl;

	{
		deque.push_back(10);
		deque.push_back(2);
		deque.push_back(4);
		deque.push_back(5);

		while (!deque.empty())
		{
			std::cout << deque.last() << " - " << deque.size() << std::endl;
			deque.pop_back();
		}

		//Call exception
		deque.pop_back();
		deque.pop_front();
	}

	{
		deque.push_back(10);
		deque.push_back(2);
		deque.push_back(4);
		deque.push_back(5);

		while (!deque.empty())
		{
			std::cout << deque.first() << " - " << deque.size() << std::endl;
			deque.pop_front();
		}

		//Call exception
		deque.pop_back();
		deque.pop_front();
	}

	{
		deque.push_front(10);
		deque.push_front(2);
		deque.push_front(4);
		deque.push_front(5);

		while (!deque.empty())
		{
			std::cout << deque.last() << " - " << deque.size() << std::endl;
			deque.pop_back();
		}

		//Call exception
		deque.pop_back();
		deque.pop_front();
	}

	{
		deque.push_front(10);
		deque.push_front(2);
		deque.push_front(4);
		deque.push_front(5);

		while (!deque.empty())
		{
			std::cout << deque.first() << " - " << deque.size() << std::endl;
			deque.pop_front();
		}

		//Call exception
		deque.pop_back();
		deque.pop_front();
	}

	return 0;
}
