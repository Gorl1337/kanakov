#include "Header.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
int main(int argc, char** argv)
{
	FILE* fo;
	errno_t fa;
	
	setlocale(LC_ALL, "Russian");

	int a = 1, b = 0, min = 0, max = 0, n = 0, k = 0, f = 0, l = 0;
	
	sscanf_s(argv[1], "%d", &n);
	sscanf_s(argv[2], "%d", &k);

	if (k != 1)
		k = 0;

	float* mas = (float*)malloc(n * sizeof(float));
	float* mas1 = (float*)malloc(n * sizeof(float));
	float* mas2 = (float*)malloc(n * sizeof(float));
	float* mas0 = (float*)malloc(n * sizeof(float));
	
	fa = fopen_s(&fo, "C:\\Users\\gg\\source\\repos\\laba\\output.txt", "r");
	for (int i = 0; i < n; i++)
		fscanf_s(fo, "%f", &(mas[i]));
	fclose(fo);

	for (int i = 0; i < n; i++)
	{
		mas1[i] = mas[i];
		mas2[i] = mas[i];
		mas0[i] = mas[i];
	}
	while (a != 0)
	{
		printf("Введите 1 для печати неотсортированного массива\n");
		printf("Введите 2 для сравнения времени 3 сортировок\n");
		printf("Введите 3 для вычисления времени сортировки вставками\n");
		printf("Введите 4 для вычисления времени сортировки пузырьком\n");
		printf("Введите 5 для вычисления времени быстрой сортировки\n");
		printf("Введите 6 для вычисления первой нормы массива\n");
		printf("Введите 7 для вычисления второй нормы массива\n");
		printf("Введите 8 для вычисления Гёльдеровой нормы массива\n");
		printf("Введите 9 для вычисления бесконечной нормы массива\n");
		printf("Введите 10 для вычисления нормировки массива\n");
		printf("Введите 11 для вычисления всех норм массива\n");
		printf("Введите 0 для выхода из программы\n\n");
		scanf_s("%d", &a);

		if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8 && a != 9 && a != 10 && a != 11 && a != 0)
		{
			clrscr();
			printf("Не то вводишь\n\n");
		}

		if ((k == 0) && ((a == 5) || (a == 2) || (a == 3) || (a == 4)))
		{
			clrscr();
			printf("Сортировки делать нельзя(\n\n");
			a = 12;
		}

		if (a == 1)
		{
			clrscr();
			PrintMas(mas, n);
		}
		if (a == 2)
		{
			clrscr();
			clock_t start1 = clock();
			Vstavki(mas, n);
			clock_t end1 = clock();
			printf("Вставками=%lf\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

			clock_t start2 = clock();
			Puzirek(mas1, n);
			clock_t end2 = clock();
			printf("Пузырьком=%lf\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

			clock_t start3 = clock();
			Bistro(mas2, n);
			clock_t end3 = clock();
			printf("Быстрая=%lf\n\n", (double)(end3 - start3) / CLOCKS_PER_SEC);

		}
		if (a == 3)
		{
			clrscr();
			clock_t start1 = clock();
			Vstavki(mas, n);
			clock_t end1 = clock();
			printf("Вставками=%lf\n\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
		}
		if (a == 4)
		{
			clrscr();
			clock_t start2 = clock();
			Puzirek(mas, n);
			clock_t end2 = clock();
			printf("Пузырьком=%lf\n\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
		}
		if (a == 5)
		{
			clrscr();
			clock_t start3 = clock();
			Bistro(mas, n);
			clock_t end3 = clock();
			printf("Быстрая=%lf\n\n", (double)(end3 - start3) / CLOCKS_PER_SEC);
		}
		if (a == 6)
		{
			clrscr();
			long double x = 0;
			for (int i = 0; i < n; i++)
				x += fabs(mas[i]);
			printf("Первая норма=%lf\n\n", x);
		}
		if (a == 7)
		{
			clrscr();
			long double x = 0, w = 0;
			for (int i = 0; i < n; i++)
				w += pow(mas[i], 2);
			x = sqrt(w);
			printf("Вторая норма=%lf\n\n", x);
		}
		if (a == 8)
		{
			clrscr();
			long double x = 0, w = 0;
			double p = 0;
			printf("Введите p-норму\n\n");
			scanf_s("%lf", &p);
			if (p < 1)
				break;
			for (int i = 0; i < n; i++)
				w += pow(fabs(mas[i]), p);
			x = pow(w, (long double)(1 / p));
			printf("\nНорма Гёльдера(%.0lf)=%lf\n\n", p, x);
		}
		if (a == 9)
		{
			clrscr();
			Bistro(mas, n);
			printf("Бесконечная норма=%f\n\n", mas[n - 1]);
		}
		if (a == 10)
		{
			clrscr();
			long double x = 0, w = 0;
			for (int i = 0; i < n; i++)
				w += pow(mas[i], 2);
			x = sqrt(w);
			printf("Нормировка:\n");
			for (int i = 0; i < n; i++)
				printf("%f\n", mas[i] * (1.0 / x));
			printf("\n");
		}
		if (a == 11)
		{
			clrscr();
			double x1 = 0, x2 = 0, x3 = 0, x4 = 0, w2 = 0, w3 = 0, w4 = 0, p = 0;

			printf("Введите p-норму\n\n");
			scanf_s("%lf", &p);
			if (p < 1)
				break;

			//Первая норма
			for (int i = 0; i < n; i++)
				x1 += fabs(mas[i]);

			//Вторая норма
			for (int i = 0; i < n; i++)
				w2 += pow(mas[i], 2);
			x2 = sqrt(w2);

			//Норма Гёльдера
			for (int i = 0; i < n; i++)
				w3 += pow(fabs(mas[i]), p);
			x3 = pow(w3, 1.0 / p);

			//Нормировка
			for (int i = 0; i < n; i++)
				w4 += pow(mas[i], 2);
			x4 = sqrt(w4);
			printf("\nРаспечатать нормировку?\n1-да\n2-нет\n\n");
			scanf_s("%d", &a);
			if (a == 1)
			{
				printf("Нормировка:\n");
				for (int i = 0; i < n; i++)
					printf("%f\n", mas[i] * (1.0 / x4));
			}
			if (a == 2)
				a = 12;

			//Бесконечная норма
			Bistro(mas, n);

			printf("\nПервая норма=%lf\n", x1);
			printf("Вторая норма=%lf\n", x2);
			printf("Норма Гёльдера(%.0lf)=%lf\n", p, x3);
			printf("Бесконечная норма=%f\n\n", mas[n - 1]);
		}

		if (a == 5 || a == 2 || a == 3 || a == 4)
		{
			printf("Введите 2 для печати массива\n");
			printf("Введите 3 для сброса\n");
			printf("Введите 0 для выхода из программы\n\n");
			scanf_s("%d", &a);
			clrscr();
		}
		if (a == 2)
		{
			clrscr();
			PrintMas(mas, n);
			printf("\nВведите 3 для сброса\n");
			printf("Введите 0 для выхода из программы\n\n");
			scanf_s("%d", &a);
			clrscr();
		}

		for (int i = 0; i < n; i++)
		{
			mas[i] = mas0[i];
			mas1[i] = mas0[i];
			mas2[i] = mas0[i];
		}
	}
	
	free(mas);
	free(mas1);
	free(mas2);
	free(mas0);
	return 0;
}
