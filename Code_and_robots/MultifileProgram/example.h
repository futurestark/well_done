#ifndef EXAMPLE_H
#define EXAMPLE_H

namespace myExample {

template <typename Type>
class Example
{
	Type first;
	Type second;
public:
	Example();
	Example(Type, Type);

	Type& First();
	Type& Second();
};

template <typename Type>
Example<Type>::Example() : first(0), second (0)
{}

template <typename Type>
Example<Type>::Example(Type v1, Type v2) : first(v1), second (v2)
{}

template <typename Type>
Type &Example<Type>::First()
{
	return first;
}

template <typename Type>
Type &Example<Type>::Second()
{
	return second;
}

}

#endif // EXAMPLE_H
