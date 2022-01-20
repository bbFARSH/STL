#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_VECTOR_INSERT
//#define STL_DEQUE
#define STL_LIST_INSERT
#define STL_LIST_ERASE
template<typename T> void print(const vector<T>& vec)
{
	for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}
void main()
{
	setlocale(LC_ALL, "Ru");
#ifdef STL_ARRAY
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	//vector  - это последовательный контейнер, который хранит данные в виде динамического массива
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;
	//int* data = vec.data();
	vec.push_back(55);
	//data = vec.data();
	vec.push_back(89);
	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << tab;
			//cout << *(data + i) << tab;
			//cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;
#endif // STL_VECTOR
#ifdef STL_VECTOR_INSERT
	vector<int> vec = { 0,1,1,2,3,5,8 };
	int index;
	int count;
	int value;
	cout << "Введите индекс добавляемого значения:\t "; cin >> index;
	cout << "Введите количество добавлений:\t\t "; cin >> count;
	cout << "Введите добавляемое значение:\t"; cin >> value;
	// insert(position, count, value)
	if (index < vec.size())vec.insert(vec.begin() + index, count, value);
	else cout << "Error: out of range" << endl;
	print(vec);
	std::vector<int>powers = { 1024,2048,4096,8192,16384 };
	//vec.insert(vec.begin() + 4, powers.begin(), powers.end());
	//for (int i : vec)cout << i << tab; cout << endl;
	//vec.insert(vec.begin() + 4, vec.begin()+5, vec.begin() + 8);
	//for (int i : vec)cout << i << tab; cout << endl;
	vec.insert(vec.begin() + 8, { 256,384,512,768 });
	for (int i : vec)cout << i << tab; cout << endl;
	//////////////////////////////////////////////////////////// ERASE ////////////////////////////////////////////////////
	cout << "Введите индекс удаляемого значения:\t "; cin >> index;
	cout << "Введите количество удалений:\t\t"; cin >> count;
	vec.erase(vec.begin() + index,vec.begin() + index+count);
	print(vec);
	cout << "\n--------------------------------------------------------------------------\n" << endl;
	vec.swap(powers);
	print(vec);
	print(powers);
#endif // STL_VECTOR_INSERT
#ifdef STL_DEQUE
	//deque - "двунаправленная очередь" - это контейнер, который хранит данные в виде списка динамических массивов(векторов),
	// что увелчивает производительность при добавлении/удалении элементов,
	// но немного снижает производительность при доступе к элементам,
	// В ОТЛИЧИЕ ОТ ВЕКТОРА, deque позволяет добавлять/удалять элементы
	// не только с конца и но с начала очереди.
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);

	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << tab;
	}
	cout << endl;
	std::deque<int> d_powers = { 256,512,768 };
	//deque.push_back(std::move(d_powers.begin()+ 1));
	for (int i : deque) cout << i << tab; cout << endl;
	for (int i : d_powers) cout << i << tab; cout << endl;

#endif // STL_DEQUE
#ifdef STL_LIST_INSERT
	std::list<int> list = { 3,5,8,13,21 };
	for (int i : list)cout << i << tab; cout << endl;
	int index;
	int count;
	int value;
	cout << "Введите индекс добавляемого значения:\t "; cin >> index;
	cout << "Введите количество добавлений:\t\t "; cin >> count;
	cout << "Введите добавляемое значение:\t"; cin >> value;
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < index; i++)it++;
	list.insert(it, count, value);
	if (index < int(list.size()));
	else cout << "Error: out of range " << endl;
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_LIST_INSERT
}