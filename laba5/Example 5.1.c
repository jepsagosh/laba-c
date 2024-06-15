﻿// Двумерный массив.
// Объявим двумерный массив, заполним его целыми числами и выведем построчечно на экран. 

#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <locale.h> // Библиотека для указания локации (региональной кодировки)

#define N 4        // Деректива препроцессору заменить в файле все N на 9
#define M 4        // Деректива препроцессору заменить в файле все M на 9

int main()
{
	setlocale(LC_ALL, "Rus");

	int A[N][M] = {0}, i, j;

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++) A[i][j] = i * j;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) printf("%4i", A[i][j]);
		printf("\n");
	}

	return 0;
}

/*

Упражнения.

1. Добавьте возможность заполнения массива с клавиатуры: 
1.1 поэлементно
1.2 построчично, для этого можите использовать следующий код

	char line[1024];
	for (i = 0; i < M; i++) {
		printf(" Введите элементы %3i строки массива A[%i][]: ", i, i);
		gets(line);
		j = 0;
		for (char* tok = strtok(line, " "); tok; tok = strtok(NULL, " ")) {
			A[i][j++] = atoi(tok);
		}
	}

2. Подсчитайте сумму элементов каждой строки и каждого столбца, 
   суммы элементов главной и побочной диагонали (если матрица квадратная)
   и выведите на экран в следующем формате:

         | 11
   ------|---
   1 2 3 |  6
   0 5 4 |  9
   3 2 2 |  7
   ------|---  
   4 9 9 |  7

3. Сделайте массив динамическим:

3.1. Одномерным с выделением памяти под каждый новый элемент 
     (см. Exrmple (realloc)) и заданным числом столюцов матрицы. 
3.2. Одномерным с заданным числом столюцов матрицы и
     выделением памяти под каждую новую строку.
3.1. Двумерным (как массив указателей) с выделением памяти под каждую новую строку
	 (с помощью добавления памяти в массив указателей) и заданным числом столюцов.

	 Справка о двумерном динамическом массиве:
	 Сначала создаётся массив указателей, а после этого каждому элементу этого 
	 массива присваиваем адрес вновь созданного массива. 
	 Это значит, что можно 
	 1. Создавать массивы "неправильной формы", то есть массив строк, каждая из которых имеет свой размер.
	 2. Работать по отдельности с каждой строкой массива: освобождать память или изменять размер строки.
	 Бывает ситуация, при которой память не может быть выделена. В этом случае функция malloc (и calloc) 
	 возвращает NULL. Поэтому, перед выделением памяти необходимо обнулить указатель, 
	 а после выделения проверить, не равен ли он NULL.

	 Вопрос:
	 А как тогда расположины в памяти строки матрицы созданной с помощью многомерного динамического массива?

*/