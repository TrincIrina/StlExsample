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
	// ������� ��������� map ��� �������� ���������� ���������
	map <string, string> options; 
	cout << "������� ������ �������: ";
	cin >> options["VectorSize"];
	cout << "������� ���������� ��������� �������� ��������� �������: ";
	cin >> options["VectorMin"];
	cout << "������� ����������� ��������� �������� ��������� �������: ";
	cin >> options["VectorMax"];
	cout << "������� ��� ���������� �����: ";
	cin >> options["FileName"];
	cout << endl;

	// ������� ������ ��� �������� ��������� ��������
	vector <int> a; 
	for (int i = 0; i < stoi(options["VectorSize"]); i++) {
		// �� ������� ������� ��������� � ������ ��������� �������� � ��������� ����� ���������
		a.push_back(rand() % (
			stoi(options["VectorMax"]) - stoi(options["VectorMin"]) + 1) + 
			stoi(options["VectorMin"]));
	} 
	cout << "������: ";
	// ������� ������ � ������� ������ at
	for (int i = 0; i < stoi(options["VectorSize"]); i++) {
		cout << a.at(i) << "\t"; 
	}
	cout << endl << endl;

	list <string> b;  // ������� ������ ��� �������� �������� �������� �� �����
	string line;      // ������� ���������� ��� ����������� ����������� ����� � ������
	ifstream in("Fail.txt"); // ��������� ���������� �����
	// ���� ���� ������
	if (in.is_open()) 
	{
		// ��������� � ������ ��������, ����������� �� �����, �������� ����������� �� �������
		for (in >> line; !in.eof(); in >> line) {
			b.push_back(line); 
		}
	}
	// ��������� ����
	in.close();  

	// ������� � ������� �������� ������ � ������� ���������
	cout << "�������� ������: "; 
	for (auto iter = b.begin(); iter != b.end(); iter++) {
		cout << *iter << "\t";
	}

	// ������� ����� ������ ��� �������� ��������������� ���������
	list <string> b2; 
	for (auto iter = b.begin(); iter != b.end(); iter++) { 
		// ���������� �� ��������� ������
		if (bool found = std::find(b2.begin(), b2.end(), *iter) != b2.end())
		{
			// ���� � ����� ������ ������ ������� ������� ��������� ������
			// ��������� �� ��������� �������� �����
			continue;   
		}
		// ���� ��� - �������� ������� � ����� ������
		b2.push_back(*iter); 
	}
	cout << endl << endl;
	// ������� ����� ������ � ������� � ������� ���������
	cout << "�������� ������: "; 
	for (auto iter = b2.begin(); iter != b2.end(); iter++) {
		cout << *iter << "\t";
	}
	cout << endl;
	// ������� ���������� ��� ������ � ����
	ofstream out; 
	// ���������� ����� ������ � ����� ���� � ����� ��������� ���������
	out.open(options["FileName"]); 
	if (out.is_open())
	{
		for (auto iter = b2.begin(); iter != b2.end(); iter++) {
			out << *iter << " ";
		}
	}
	// ��������� ��������� ����
	out.close(); 
}