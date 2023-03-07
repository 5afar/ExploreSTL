#include "SmartPointer.h"

template <typename T>

class SmartPointer {
public:

	SmartPointer(T* ptr)  /// Конструктор, который создаёт указатель
	{
		this->ptr = ptr;
	}
	~SmartPointer()   /// Деструктор, который чистит память
	{
		delete ptr;
	}

	T& operator*()   /// Перегрузка оператора
	{
		return *ptr;
	}
private:
	T* ptr;
};