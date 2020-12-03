#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <iostream>
#pragma warning (disable : 4996)

int* alg;
int** arr;


void BFSD(int v, int a) {
	std::queue <int> qu;
	qu.push(v);
	alg[v] = 0;
	while (!qu.empty()) {
		v = qu.front();
		printf(" %d  ", v + 1);
		qu.pop();
		for (int i = 0; i < a; i++) {
			if ((arr[v][i] == 1) && (alg[i] == -1)) {
				qu.push(i);
				alg[i] = alg[v] + 1;
			}
		}
	}
}

void main()
{
	int begin;
	int n;
	int minimum = 1000;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	printf("Введите порядок массива - ");
	scanf("%d", &n);

	alg = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		alg[i] = -1;
	}

	arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) arr[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				arr[i][j] = rand() % 2;
				arr[j][i] = arr[i][j];
			}
			else if (i == j) arr[i][j] = 0;
		}
	}

	printf(" ");

	for (int k = 1; k <= n; k++) printf(" %d", k);
	printf("\n   -----------\n");
	for (int i = 0; i < n; i++) {

		printf("%d |", i + 1);
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("Введите вершину с которой хотите начать обход - ");
	scanf("%d", &begin);
	printf("Посещенные вершины: ");
	BFSD(begin - 1, n);
	printf("\n--------------------------------------------\n");
	printf("| Вершины    |");
	for (int i = 1; i <= n; i++) {
		printf("| %d |", i);
	}

	printf("\n--------------------------------------------\n");
	printf("| Расстояние |");
	for (int i = 0; i < n; i++) {
		printf("| %d |", alg[i]);
	}
	printf("\n--------------------------------------------\n");
	for (int i = 0; i < n; i++) {

		if ((minimum > alg[i]) && (alg[i] != 0)) {
			minimum = alg[i];
		}
	}

	printf(" Кратчайшее расстояние - %d , у вершины:", minimum);
	for (int i = 0; i < n; i++) {
		if (alg[i] == minimum) {
			printf(" %d ", i + 1);
		}
	}
	system("pause");
}
