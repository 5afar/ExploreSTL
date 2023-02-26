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
    int a, b, c;
    int array[10]{ 0,1,2,3,4,5,6,7,8,9 };
    string str = "Hello world!";
    vector<int> intVector;
    vector<char> charVector;
    intVector.push_back(7);
    intVector.push_back(9);
    intVector.push_back(3);
    for (int i = 0; i < intVector.size(); i++) {
        cout << i + 1 <<". " << intVector[i] << endl;
        int s = intVector[i] + 3;
        cout << "S = " << s << endl;
    }




    return 0;
}

