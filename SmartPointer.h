#pragma once
template <typename T>
class SmartPointer
{
public:
	SmartPointer(T *ptr);
	~SmartPointer();
	T& operator*();

private:
	T *ptr;
};

