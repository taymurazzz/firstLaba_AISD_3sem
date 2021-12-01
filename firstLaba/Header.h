#include <iostream>

using namespace std;

class spisok {
public:
	spisok* all;
	spisok* allHead;
	spisok* allLast;

	spisok* tmp;
	spisok* tmpHead;
	spisok* tmpLast;

	int data;
	spisok* prev;
	spisok* next;

	spisok() {
		all = NULL;
		allHead = NULL;
		allLast = NULL;

		tmp = NULL;
		tmpHead = NULL;
		tmpLast = NULL;

		data = NULL;
		prev = NULL;
		next = NULL;
	}

	friend ostream& operator << (ostream& stream, spisok* ALL);

	void begin_of_work() {					// исключений нет 
		all = new spisok;
		allHead = new spisok;
		allLast = new spisok;

		allHead->next = allLast;
		allHead->prev = NULL;
		allLast->prev = allHead;
		allLast->next = NULL;

		tmp = new spisok;
		tmpHead = new spisok;
		tmpLast = new spisok;
		tmpHead->next = tmpLast;
		tmpHead->prev = NULL;
		tmpLast->prev = tmpHead;
		tmpLast->next = NULL;
	}

	void push_back(int new_data) {				// исключений нет 
		if (allHead->next != allLast) {
			all = allLast->prev;
			all->next = new spisok;
			all->next->next = allLast;
			allLast->prev = all->next;
			all->next->prev = all;
			all = all->next;
			all->data = new_data;
		}
		if (allHead->next == allLast) {
			all->data = new_data;
			allHead->next = all;
			all->prev = allHead;
			all->next = allLast;
			allLast->prev = all;
		}
	}

	void push_front(int new_data) {				// исключений нет 
		if (allHead->next != allLast) {
			all = allHead->next;
			all->prev = new spisok;
			all->prev->next = all;
			allHead->next = all->prev;
			all->prev->prev = allHead;
			all = all->prev;
			all->data = new_data;
		}
		if (allHead->next == allLast) {
			all->data = new_data;
			allHead->next = all;
			all->prev = allHead;
			all->next = allLast;
			allLast->prev = all;
		}
	}

	void pop_back() {					// исключение если список пустой 
		if (isEmpty() == 1) {
			throw out_of_range("Список пустой, удалить последний элемент невозможно");
		}
		else {
			all = allLast->prev;
			all->prev->next = allLast;
			allLast->prev = all->prev;
			all = NULL;
		}
	}

	void pop_front() {					// исключение если список пустой 
		if (isEmpty() == 1) {
			throw out_of_range("Список пустой, удалить первый элемент невозможно");
		}
		else {
			all = allHead->next;
			allHead->next = all->next;
			all->next->prev = allHead;
			all = NULL;
		}
	}

	void insert(int new_data, size_t index) {	// добавить исключение если введен идекс которого нет
		if ((index < 0) || (index > (get_size() - 1))) {
			throw invalid_argument("введен неправильный индекс");
		}
		else {
			int i = 0;
			all = allHead->next;
			while (i != index) {
				all = all->next;
				i = i + 1;
			}
			tmp = new spisok;
			tmp->prev = all->prev;
			all->prev->next = tmp;
			tmp->next = all;
			all->prev = tmp;
			tmp->data = new_data;
		}
	}

	int at(size_t index) {				// исключение если введен несуществующий индекс 
		if ((index < 0) || (index > (get_size() - 1))) {
			throw invalid_argument("введен неправильный индекс");
		}
		else {
			all = allHead->next;
			int i = 0;
			while (i != index) {
				all = all->next;
				i = i + 1;
			}
			return all->data;
		}
	}

	void remove(size_t index) {			// исключение если введен несуществующий индекс 
		if ((index < 0) || (index > (get_size() - 1))) {
			throw invalid_argument("введен неправильный индекс");
		}
		else {
			all = allHead->next;
			int i = 0;
			while (i != index) {
				all = all->next;
				i = i + 1;
			}
			all->prev->next = all->next;
			all->next->prev = all->prev;
			all = NULL;
		}
	}

	size_t get_size() {					// исключений нет
		all = allHead->next;
		size_t size = 0;
		while (all->next != NULL) {
			all = all->next;
			size = size + 1;
		}
		return size;
	}
	void clear() {						// исключений нет
		all = allHead->next;
		while (all->next != NULL) {
			all = all->next;
			all->prev = NULL;
		}

		allHead->next = allLast;
		allLast->prev = allHead;
	}
	void set(size_t index, int new_data) {			// исключение если индекс не существует
		if ((index < 0) || (index > (get_size() - 1))) {
			throw invalid_argument("введен неправильный индекс");
		}
		else {
			all = allHead->next;
			int i = 0;
			while (i != index) {
				all = all->next;
				i = i + 1;
			}
			all->data = new_data;
		}
	}

	bool isEmpty() {								// исключений нет
		if (allHead->next == allLast) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void printSpisok() {				// исключений нет
		cout << allHead->next;
	}

	void reverse() {					// исключений нет

		if (isEmpty() == 0) {
			tmp = new spisok;
			tmpLast = new spisok;
			tmpHead = new spisok;

			tmpHead->next = tmp;
			tmpHead->prev = NULL;

			tmp->next = tmpLast;

			tmpLast->prev = tmp;
			tmpLast->next = NULL;

			all = allHead->next;
			while (all->next != NULL) {
				tmp->data = all->data;
				tmp->prev = new spisok;
				tmp->prev->next = tmp;
				tmpHead = tmp->prev;


				tmp = tmp->prev;
				all = all->next;
			}
			all = allHead->next;
			tmp = tmpHead->next;
			while (tmp->next != NULL) {

				all->data = tmp->data;

				tmp = tmp->next;
				all = all->next;
			}
		}

	}

	void end_of_work() {				// исключений нет 
		all = new spisok;
		allHead = new spisok;
		allLast = new spisok;

		tmp = new spisok;
		tmpHead = new spisok;
		tmpLast = new spisok;
	}
	~spisok() {
		delete all;
		delete allHead;
		delete allLast;

		delete tmp;
		delete tmpHead;
		delete tmpLast;
	}

};