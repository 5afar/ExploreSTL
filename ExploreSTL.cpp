#include <iostream>
#include <string>
#include <vector>
#include "SmartPointer.h"

using namespace std;


/*
Библиотека стандартных шаблонов (STL)
VECTOR
Вектор выделяет места под элементы больше чем изначальный размер
Пока существует выделенная ячейка элементы будут добавлятся в них
Как только вся ёмкость будет занята выделится новое количество памяти с очередным запасом
Вектор не всегда переписывает данные в новый массив, когда нужно добавить новые элементы
*/




void vec(){
    vector<int> intVector;
    intVector.reserve(6);           /// Данный метод принудительно выделяет память для вектора
    intVector.push_back(7);
    intVector.push_back(9);
    intVector.push_back(3);
    for (int i = 0; i < intVector.size(); i++) {
        cout << i + 1 <<". " << intVector[i] << endl;
        int s = intVector[i] + 3;
        cout << "S = " << s << endl;
    }
    cout << intVector.at(1) << endl; /// Метод отличается от квадратных скобок тем,
                                     ///что он при выходе за границы памяти бросает исключение и не вторгается в чужую память
                                     /// Он работает медленнее из-за того, что каждый раз проверяет границы вектора
    intVector.clear();               /// Чистит вектор
    intVector = { 303,506,777 };
    intVector.shrink_to_fit();       /// Освобождает память и сокращает резерв до реального размера вектора
    intVector.pop_back();            /// Удаляет последний элемент вектора
    cout << intVector.empty() << endl; ///Проверяет пустой ли вектор
    intVector.resize(5);            ///Увеличивает или уменьшает вектор до указанного масштаба и при необходимости заполняет его нулями
    
}

int main()
{
    setlocale(LC_ALL, "ru");
    vec();
    SmartPointer<int> sp = new int();

    return 0;
}
