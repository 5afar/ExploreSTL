#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
Библиотека стандартных шаблонов (STL)
VECTOR

*/


int main()
{
    setlocale(LC_ALL, "ru");
    vector<int> intVector;
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
    intVector.pop_back();            /// Удаляет последний элемент вектора

    return 0;
}

