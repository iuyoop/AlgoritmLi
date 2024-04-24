#include "header.h"

int main() {

	printf(" \n | Wall this < -2.0 > | ");
	float** field, **field_way;
	field = allocation_memory(ROWS, COLS, -1);
	field = create_wall(field);
	print_field(field, ROWS, COLS);

	printf(" \n | Way | \n");
	field = search_Li(field);

	print_field(field, ROWS, COLS);

	return 0;
}