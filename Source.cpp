#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n = 0;
	printf("Введите количество вершин: ");
	scanf_s("%d", &n);
	int** matr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matr[i][j] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			matr[i][j] = rand() % 2;
			matr[j][i] = matr[i][j];
			if (i == j)
				matr[i][j] = 0;
		}

	}



	printf("\n       Матрица:\n№  ");
	for (int i = 0; i < n; i++) {
		printf(" %d", i + 1);
	}
	printf("\n__|");
	for (int i = 0; i < n; i++) {
		printf("__");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		{
			printf("%d | ", i + 1);
			for (int j = 0; j < n; ++j)
				printf("%d ", matr[i][j]);
			printf("\n");
		}
	}
	printf("------------------------------------------\n");

	int kr = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
			if (matr[i][j] == 1) {
				kr += 1;
			}

	}
	printf("\nРазмер графа = %d", kr);

	int domin = 0, izol = 0, k = 0, kv = 0;
	for (int i = 0; i < n; i++) {
		domin = 0;
		for (int j = 0; j < n; j++) {
			if (matr[i][j] == 1)
				domin += 1;
		}
		if (domin == n - 1) {
			printf("\nДоминирующая вершина - №%d", i + 1);
			k++;
		}
		if (domin == 0) {
			printf("\nИзолированная вершина - №%d", i + 1);
			izol++;
		}
		if (domin == 1) {
			printf("\nКонцевая вершина - №%d", i + 1);
			kv++;
		}
	}
	if (kv == 0)
		printf("\nКонцевых вершин нет");
	if (k == 0)
		printf("\nДоминирующих вершин нет");
	if (izol == 0)
		printf("\nИзолированных вершин нет");


	printf("\n------------------------------------------\n");


	int** matr1 = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr1[i] = (int*)malloc(sizeof(int) * kr);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < kr; j++)
			matr1[i][j] = 0;

	int in = 0, in1 = 0, in2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (matr[i][j] == 1) {
				matr1[i][in] = 1;
				matr1[j][in] = 1;
				in++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		free(matr[i]);
	}
	free(matr);

	printf("\n       Матрица:\n№  ");
	for (int i = 0; i < kr; i++) {
		printf(" %d", i + 1);
	}
	printf("\n__|");
	for (int i = 0; i < kr; i++) {
		printf("__");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		{
			printf("%d | ", i + 1);
			for (int j = 0; j < kr; ++j)
				printf("%d ", matr1[i][j]);
			printf("\n");
		}
	}
	printf("------------------------------------------\n");

	domin = 0, izol = 0, k = 0, kv = 0;
	int k1 = 0;
	for (int i = 0; i < n; i++) {
		domin = 0;
		for (int j = 0; j < kr; j++) {
			if (matr1[i][j] == 1) {
				domin += 1;
			}
		}
		if (domin == n - 1) {
			printf("\nДоминирующая вершина - №%d", k1 + 1);
			k++;
		}
		if (domin == 0) {
			printf("\nИзолированная вершина - №%d", k1 + 1);
			izol++;
		}
		if (domin == 1) {
			printf("\nКонцевая вершина - №%d", k1 + 1);
			kv++;
		}
		k1++;
	}
	if (kv == 0)
		printf("\nКонцевых вершин нет");
	if (k == 0)
		printf("\nДоминирующих вершин нет");
	if (izol == 0)
		printf("\nИзолированных вершин нет");



	for (int i = 0; i < n; i++) {
		free(matr1[i]);
	}
	free(matr1);

	_getch();

}
