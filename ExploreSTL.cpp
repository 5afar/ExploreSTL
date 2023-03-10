#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include<queue>
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
    vector<int>::iterator i; ///итератор вектора типа инт
    intVector.reserve(6);           /// Данный метод принудительно выделяет память для вектора
    intVector.push_back(7);
    intVector.push_back(9);
    intVector.push_back(3);
    i = intVector.begin();
    cout << *i << endl;
    for (int i = 0; i < intVector.size(); ++i) {
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
    i = intVector.begin();
    cout << *i << endl;
    for (vector<int>::const_iterator f = intVector.cbegin(); f < intVector.cend(); ++f)  /// циклично выводит вектор на экран при помощи итератора
    {
        cout << *f << endl;
    }
    vector<int> V{ 100,200,300,400,500 };
    vector<int>::iterator iV;
    iV = V.begin();
    advance(iV, 2);   /// Меняет положение итератора
    V.insert(iV, 999);  /// вставляет элемент в вектор на место куда указывает итератор
    vector<int>::iterator iErase;
    iErase = V.begin();
    V.erase(iErase);
    cout << "After insert 999 --------" << endl;
    for (vector<int>::const_iterator f = V.cbegin(); f < V.cend(); ++f)  /// циклично выводит вектор на экран при помощи итератора
    {
        cout << *f << endl;
    }
    cout << intVector.empty() << endl; ///Проверяет пустой ли вектор
    intVector.resize(5);            ///Увеличивает или уменьшает вектор до указанного масштаба и при необходимости заполняет его нулями
    
}

/*
LIST
Реализует динамическую структуру данных, а именно, двусвязный список
Контейнер, в котором реализована быстрая редакция данных (Добавление новых элементов и удаление)
Нет перегрузки оператора [] и итератор произвольного доступа
Нет возможности обратиться к конкретному элементу списка, необходимо проходится по всему контейнеру через каждый элемент

*/
template <typename T>
void PrintList(const list<T>& lst)   /// метод который принимает на входе ссылку на лист и выводит все его элементы в столбик
{
    for (auto i = lst.begin(); i != lst.end(); ++i) {
        cout << *i << endl;
    }
}
void List() {
    list<char> myList = {'a','b','c'};
    myList.push_back('b');   /// добавляет элемент в конец списка
    myList.push_front('f');   /// добавляет элемент в начало списка
    list<char>::iterator i = myList.begin();  /// присваиваем итератору ссылку на начало списка
    cout <<"First element = "<< * i << endl;  ///вывод элемента, на который ссылается итератор
    for (list<char>::iterator f = myList.begin(); f != myList.end(); ++f)   ///стандартный вывод элементов в цикле
    {
        cout << "Cicle - " << *f << endl;
    }
    myList.sort(); ///сортирует список от меньшего к большему либо в порядке алфавита
    cout << "After sort =====" << endl;
    PrintList(myList);
    myList.pop_back();   /// удаляет последний элемент списка
    myList.pop_front();  /// удаляет первый элемент списка
    cout << "After pop ======" << endl;
    PrintList(myList);

    myList.push_back('a');
    myList.push_back('f');
    myList.push_back('z');

    cout << "After unique =======" << endl;
    myList.unique();  /// удаляет дубликаты, которые стоят последовательно
    PrintList(myList);

    cout << "After reverse ======" << endl;
    myList.reverse(); /// разворачивает список
    PrintList(myList);
    auto it = myList.begin();
    cout << "After insert ======" << endl;
    advance(it, 3);                          /// Метод, который смещает итератор
    myList.insert(it, 'o');                  /// вставляет элемент в то место, на которое указывает итератор (метод erase работает также)
    PrintList(myList);
    myList.remove('k');   /// удаляет все элементы, которые равны введенному
    cout << "After assign ========" << endl;
    list<int>  li;
    li.assign(4, 69);   //// очищает лист от всех данных и заполняет его указанным количеством указанного элемента
    PrintList(li);
}

/*
FORWARD LIST
Данный контейнер является односвязным списком со всеми присущими ему свойствами
Он быстрее работает при маленьком объеме, а потому имеет меньший набор инструментов для взаимодействия с данными
Вся работа осуществляется в начале списка и чем он становится больше, тем медленнее происходит работы

*/
void fwlist() {
    forward_list<int> fwl;
    fwl.assign(4, 69);/// заполнил список одинаковыми элементами
    forward_list<int>::iterator it = fwl.begin();
    advance(it, 2);
    fwl.insert_after(it, 7);/// вставляет элемент после указанного итератором
}

/*
SET
Реализован на основе бинарного дерева
Всегда упорядочивает данные
Всегда хранит уникальные значения
В контейнере нельзя менять элементы потому, что от значения элемента зависит его положение в массиве
Сет позволяет ускорить поиск элементов в больших массивах данных
MULTISET позволяет хранить несколько одинаковых элементов
*/
void Set() {
    set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(0);
    for (auto& item : mySet) {
        cout << item << endl;
    }
    set<int>::iterator it =mySet.find(2);  /// осуществляет поиск определенного элемента и возвращает значение итератора
    multiset<int> myMultiset = { 0,1,1,66,16,48,99 };
    auto i1 = myMultiset.lower_bound(30);  /// возвращает итератор на искомый элемент, если он отсутствует, то возвращается итератор на следующий по величине
    auto i2 = myMultiset.upper_bound(1); /// возвращает итератор на следующий по величине
    auto eq = myMultiset.equal_range(48); /// возвращает итератор на искомый элемент и следующий за ним

}
/*
MAP
Такой же контейнер как и SET, но состоит из пар <ключ,значение>

*/
void MAP() {
    map<string, string>Dic;
    pair<string, string> p = { "hi","привет" };  /// способ создания пары
    Dic.insert(p);  /// добавление ранее созданной пары в коллекцию
    Dic.insert(make_pair("good", "хорошо"));   /// второй способ добавления пары в коллекцию
    Dic.insert(pair<string, string>("bad", "плохо"));  /// третий способ добавления пары в коллекци.
    Dic.emplace("create", "создать"); /// четвертый способ добавления пары в коллекцию

    for (auto& item : Dic) {
        cout << item.first<<" "<<item.second << endl;
    }

}

/*
        Адаптеры контейнеров

            Stack стек действует по принципу первый пришел последний ушел
            Позволяет добавлять в определенном порядке и извлекать в определенном порядке элементы
            Со стеком не работают итераторы
*/

void Stack() {
    stack<int>st;
    st.push(2);  /// добавляет элемент в контейнер
    st.push(24);
    st.emplace(9);  /// более новый метод, который работает быстрее чем пуш
    st.pop();/// удаляет последний добавленный элемент
    while (!st.empty()) {   /// для извлечения элементов можно использовать цикл, 
                            ///который проверяет пустой ли стек и, если не пустой, продолжает выводить элементы и убирать их из стека
        cout << st.top() << endl;
        st.pop();
    }
    auto d = st._Get_container();  /// снимает ограничения стека и дает возможность обращаться к элементам по индексу
    stack<int, list<int>> slist;   /// ограничивает функционал листа до стека

}


/*
    queue
    работает по принципу первый пришел первый ушел
    Не работает с вектором

*/
void Que() {
    queue<int > qu;
    qu.emplace(3);   /// метод добавления новых элементов
    qu.emplace(2);
    cout<<qu.back()<<endl;    /// дает доступ к последнему элементу очереди
    bool e = qu.empty();   /// проверяет контейнер на пустоту
    cout<<qu.front()<<endl;   /// дает доступ к первому элементу очереди
    qu.pop();     /// извлекает первый элемент из очереди
    cout << qu.size() << endl;    /// проверяет размер очереди
    auto a =qu._Get_container();  /// снимает ограничения с контейнера
}

/*
Priority queue
очередь с приоритетом позволяет упорядочить данные
изначально сортируется от большего к меньшему
Не может использовать лист
Нельзя получить изначальный контейнер
*/
void Pq() {
    priority_queue<int>q;
    q.emplace(0);  /// добавляет элемент работает быстрее есть не во всех стандартах
    q.push(3);  /// добавляет элемент
    cout << q.size() << endl; /// показывает размер очереди
    cout<<q.top()<<endl;  /// позволяет получить доступ к первому элементу в очереди
    bool b =q.empty();  /// проверяет пустой ли контейнер
}
int main()
{
    setlocale(LC_ALL, "ru");
    int arr[] = { 5,11,94,99,44 };
   /* for each (int var in arr)             /// Начиная со стандарта C++ 11 данное написание не работает
    {
        cout << var << endl;
    }
    */
    for (int& i : arr)   /// стандартный цикл range-based 
    {
        cout << i << endl;
    }
    cout << "The vector is working now ===========" << endl;
    vec();
    cout << "Vector is done!" << endl;
    SmartPointer<int> s = new int(5);
    cout << *s << endl;
    cout << "The list is working now =============" << endl;
    List();
    cout << "List is done!" << endl;
    cout << "The forward list is working now =============" << endl;
    fwlist();
    cout << "Forward list is done!" << endl;
    cout << "The set is working now =============" << endl;
    Set();
    cout << "Set is done!" << endl;
    cout << "The map is working now =============" << endl;
    MAP();
    cout << "Map is done!" << endl;
    cout << "The stack is working now =============" << endl;
    Stack();
    cout << "stack is done!" << endl;
    cout << "The queue is working now =============" << endl;
    Que();
    cout << "Queue is done!" << endl;
    cout << "The priority queue is working now =============" << endl;
    Pq();
    cout << "Priority queue is done!" << endl;
    return 0;
}
