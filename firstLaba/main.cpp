#include "Header.h"

int main() {
	setlocale(LC_ALL, "Russian");
	spisok obj;

	// ������ ������ 
	obj.begin_of_work();


	size_t varT;
	int varI;

	int i;
	int var;

	cout << "��������� ��������:" << endl;
	cout << "1)�������� � ����� ������ " << endl << "2)�������� � ������ ������ " << endl << "3)������� ��������� ������� " << endl << "4)������� ������ ������� " << endl << "5)�������� ������� �� ������� " << endl << "6)�������� ������� �� ������� " << endl << "7)������� ������� �� ������� " << endl << "8)�������� ������ ������ " << endl << "9)������� ��� �������� " << endl << "10)������ �������� �� ������� �� ������������ ������� " << endl << "11)�������� �� ������� ������ " << endl << "12)���������� ��������� << (����� �����) " << endl << "13)�������� ������� �� �������� " << endl << "14)�������� ��������� �������� " << endl << "15) ��������� ������ �� �������" << endl << endl;

	while (1) {
		cout << "�������� ��������:";
		cin >> var;
		cout << endl;
		if (var == 1) {
			cout << "������� ��c�� ";
			cin >> varI;
			cout << endl;
			obj.push_back(varI);
		}
		if (var == 2) {
			cout << "������� ��c�� ";
			cin >> varI;
			cout << endl;
			obj.push_front(varI);
		}
		if (var == 3) {
			try {
				obj.pop_back();
			}
			catch (const out_of_range error) {
				cout << error.what() << endl;
			}
		}
		if (var == 4) {
			try {
				obj.pop_front();
			}
			catch (const out_of_range error) {
				cout << error.what() << endl;
			}
		}
		if (var == 5) {
			cout << "������� ����� � ������ ����� ������: ";
			cin >> varI >> varT;
			cout << endl;

			try {
				obj.insert(varI, varT);
			}
			catch (const invalid_argument error) {
				cout << error.what() << endl;
			}
		}
		if (var == 6) {
			cout << "������� ������: ";
			cin >> varT;
			try {
				cout << endl << "������� �� ������� " << varT << " ---  " << obj.at(varT) << endl;
			}
			catch (const invalid_argument error) {
				cout << error.what() << endl;
			}
		}
		if (var == 7) {
			cout << "������� ������: ";
			cin >> varT;
			try {
				obj.remove(varT);
			}
			catch (const invalid_argument error) {
				cout << error.what() << endl;
			}
		}
		if (var == 8) {
			cout << "������ ������ = " << obj.get_size() << endl;
		}
		if (var == 9) {
			obj.clear();
		}
		if (var == 10) {
			cout << "������� ������ � �����: ";
			cin >> varT >> varI;
			cout << endl;
			try {
				obj.set(varT, varI);
			}
			catch (const invalid_argument error) {
				cout << error.what() << endl;
			}
		}
		if (var == 11) {
			if (obj.isEmpty() == 1) {
				cout << "������ ������" << endl;
			}
			if (obj.isEmpty() == 0) {
				cout << "������ �� ������" << endl;
			}
		}
		if (var == 12) {
			cout << "������ ������ (�������� ����� ������ ������ ������) : ";
			if (obj.isEmpty() != 1) {
				obj.printSpisok();
			}
			else {
				cout << "������";
			}
			cout << endl;
		}
		if (var == 13) {
			obj.reverse();
		}
		if (var == 14) {
			cout << "1)�������� � ����� ������ " << endl << "2)�������� � ������ ������ " << endl << "3)������� ��������� ������� " << endl << "4)������� ������ ������� " << endl << "5)�������� ������� �� ������� " << endl << "6)�������� ������� �� ������� " << endl << "7)������� ������� �� ������� " << endl << "8)�������� ������ ������ " << endl << "9)������� ��� �������� " << endl << "10)������ �������� �� ������� �� ������������ ������� " << endl << "11)�������� �� ������� ������ " << endl << "12)���������� ��������� << (����� �����) " << endl << "13)�������� ������� �� �������� " << endl << "14)�������� ��������� �������� " << endl << "15) ��������� ������ �� �������" << endl << endl;
		}
		if (var == 15) {
			break;
		}
	}


	// ����� 
	obj.end_of_work();
}