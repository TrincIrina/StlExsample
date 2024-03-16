#include <iostream>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	// создаем коллекцию map для хранения параметров программы
	map <string, string> options; 
	cout << "Введите размер вектора: ";
	cin >> options["VectorSize"];
	cout << "Введите минимально возможное значение элементов вектора: ";
	cin >> options["VectorMin"];
	cout << "Введите максимально возможное значение элементов вектора: ";
	cin >> options["VectorMax"];
	cout << "Введите имя текстового файла: ";
	cin >> options["FileName"];
	cout << endl;

	// создаем вектор для хранения случайных значений
	vector <int> a; 
	for (int i = 0; i < stoi(options["VectorSize"]); i++) {
		// по размеру вектора добавляем в вектор случайные значения в указанном ранее диапазоне
		a.push_back(rand() % (
			stoi(options["VectorMax"]) - stoi(options["VectorMin"]) + 1) + 
			stoi(options["VectorMin"]));
	} 
	cout << "Вектор: ";
	// выводим вектор с помощью метода at
	for (int i = 0; i < stoi(options["VectorSize"]); i++) {
		cout << a.at(i) << "\t"; 
	}
	cout << endl << endl;

	list <string> b;  // создаем список для хранения исходных значений из файла
	string line;      // создаем переменную для конвертации содержимого файла в список
	ifstream in("Fail.txt"); // считываем содержимое файла
	// если файл открыт
	if (in.is_open()) 
	{
		// добавляем в список элементы, считываемые из файла, элементы считываются до пробела
		for (in >> line; !in.eof(); in >> line) {
			b.push_back(line); 
		}
	}
	// закрываем файл
	in.close();  

	// выводим в консоль исходный список с помощью итератора
	cout << "Исходный список: "; 
	for (auto iter = b.begin(); iter != b.end(); iter++) {
		cout << *iter << "\t";
	}

	// создаем новый список для хранения неповторяющихся элементов
	list <string> b2; 
	for (auto iter = b.begin(); iter != b.end(); iter++) { 
		// проходимся по исходному списку
		if (bool found = std::find(b2.begin(), b2.end(), *iter) != b2.end())
		{
			// если в новом списке найден текущий элемент исходного списка
			// переходим на следующую итерацию цикла
			continue;   
		}
		// если нет - добавить элемент в новый список
		b2.push_back(*iter); 
	}
	cout << endl << endl;
	// выводим новый список в консоль с помощью итератора
	cout << "Итоговый список: "; 
	for (auto iter = b2.begin(); iter != b2.end(); iter++) {
		cout << *iter << "\t";
	}
	cout << endl;
	// создаем переменную для записи в файл
	ofstream out; 
	// записываем новый список в новый файл с ранее указанным названием
	out.open(options["FileName"]); 
	if (out.is_open())
	{
		for (auto iter = b2.begin(); iter != b2.end(); iter++) {
			out << *iter << " ";
		}
	}
	// закрываем созданный файл
	out.close(); 
}