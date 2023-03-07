#include "SmartPointer.h"

template <typename T>
	SmartPointer<T>::SmartPointer(T* ptr)  /// Конструктор, который создаёт указатель
	{
		this->ptr = ptr;
	}
	template <typename T>
	SmartPointer<T>::~SmartPointer()   /// Деструктор, который чистит память
	{
		delete ptr;
	}
	template <typename T>
	T& SmartPointer<T>::operator*()  /// Перегрузка оператора
	{
		return *ptr;
	}
