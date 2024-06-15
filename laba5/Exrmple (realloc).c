#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {

	setlocale(LC_ALL, "Rus");

	int* x = NULL;
	int number, i, found;
	int count = 0;
	while (printf("Есть что записать? "), scanf_s("%i", &number)) {
		found = 0;
		for (i = 0; i < count; i++) {
			if (number == x[i]) {
				found = 1;
				break;
			}
		}
		if (!found) {
			x = realloc(x, ++count * sizeof(int));
			if (x == NULL) {
				printf("Ошибка выделения памяти");
				return 1;
			}
			x[count - 1] = number;
		}
	}
	printf("Вы ввели: ");
	for (i = 0; i < count; i++) 
		printf("%3i", x[i]);
	
	free(x);
	x = NULL;
	return 0;
}