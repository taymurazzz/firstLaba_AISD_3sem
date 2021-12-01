#include "Header.h"

int main() {
	setlocale(LC_ALL, "Russian");
	spisok obj;

	// начало работы 
	obj.begin_of_work();


	size_t varT;
	int varI;

	int i;
	int var;

	cout << "Доступные действия:" << endl;
	cout << "1)Добавить в конец списка " << endl << "2)Добавить в начало списка " << endl << "3)Удалить последний элемент " << endl << "4)Удалить первый элемент " << endl << "5)Добавить элемент по индексу " << endl << "6)Получить элемент по индексу " << endl << "7)Удалить элемент по индексу " << endl << "8)Получить размер списка " << endl << "9)Удалить все элементы " << endl << "10)Замена элемента по индексу на передаваемый элемент " << endl << "11)Проверка на пустоту списка " << endl << "12)Перегрузка оператора << (вывод спика) " << endl << "13)Поменять порядок на обратный " << endl << "14)Показать доступные действия " << endl << "15) Закончить работу со списком" << endl << endl;

	while (1) {
		cout << "Выберите действие:";
		cin >> var;
		cout << endl;
		if (var == 1) {
			cout << "Введите чиcло ";
			cin >> varI;
			cout << endl;
			obj.push_back(varI);
		}
		if (var == 2) {
			cout << "Введите чиcло ";
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
			cout << "Введите число и индекс через пробел: ";
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
			cout << "Введите индекс: ";
			cin >> varT;
			try {
				cout << endl << "Элемент по индексу " << varT << " ---  " << obj.at(varT) << endl;
			}
			catch (const invalid_argument error) {
				cout << error.what() << endl;
			}
		}
		if (var == 7) {
			cout << "Введите индекс: ";
			cin >> varT;
			try {
				obj.remove(varT);
			}
			catch (const invalid_argument error) {
				cout << error.what() << endl;
			}
		}
		if (var == 8) {
			cout << "Размер списка = " << obj.get_size() << endl;
		}
		if (var == 9) {
			obj.clear();
		}
		if (var == 10) {
			cout << "Введите индекс и число: ";
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
				cout << "Список пустой" << endl;
			}
			if (obj.isEmpty() == 0) {
				cout << "Список не пустой" << endl;
			}
		}
		if (var == 12) {
			cout << "Список сейчас (элементы через пробел справа налево) : ";
			if (obj.isEmpty() != 1) {
				obj.printSpisok();
			}
			else {
				cout << "Пустой";
			}
			cout << endl;
		}
		if (var == 13) {
			obj.reverse();
		}
		if (var == 14) {
			cout << "1)Добавить в конец списка " << endl << "2)Добавить в начало списка " << endl << "3)Удалить последний элемент " << endl << "4)Удалить первый элемент " << endl << "5)Добавить элемент по индексу " << endl << "6)Получить элемент по индексу " << endl << "7)Удалить элемент по индексу " << endl << "8)Получить размер списка " << endl << "9)Удалить все элементы " << endl << "10)Замена элемента по индексу на передаваемый элемент " << endl << "11)Проверка на пустоту списка " << endl << "12)Перегрузка оператора << (вывод спика) " << endl << "13)Поменять порядок на обратный " << endl << "14)Показать доступные действия " << endl << "15) Закончить работу со списком" << endl << endl;
		}
		if (var == 15) {
			break;
		}
	}


	// конец 
	obj.end_of_work();
}