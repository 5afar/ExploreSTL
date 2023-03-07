#include "SmartPointer.h"

template <typename T>
	SmartPointer<T>::SmartPointer(T* ptr)  /// �����������, ������� ������ ���������
	{
		this->ptr = ptr;
	}
	template <typename T>
	SmartPointer<T>::~SmartPointer()   /// ����������, ������� ������ ������
	{
		delete ptr;
	}
	template <typename T>
	T& SmartPointer<T>::operator*()  /// ���������� ���������
	{
		return *ptr;
	}
