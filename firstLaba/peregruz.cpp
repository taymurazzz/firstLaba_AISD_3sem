#include "Header.h"

ostream& operator << (ostream& stream, spisok* ALL) {

	while (ALL->next != NULL) {
		stream << ALL->data << " ";
		ALL = ALL->next;
	}
	return stream;
}