#include "SmartPointer.h"

template <typename T>

class SmartPointer {
public:

	SmartPointer(T* ptr)
	{
		this->ptr = ptr;
	}
	~SmartPointer()
	{
		delete ptr;
	}
private:
	T* ptr;
};