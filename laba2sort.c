#include "Header.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
void Qsort(float* mas, int l, int u)
{
	int i = l;
	int j = u;
	float tmp = 0;

	float x = mas[(int)((l + u) / 2)];

	do
	{
		while (mas[i] < x)++i;
		while (mas[j] > x)--j;

		if (i <= j)
		{
			tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i < j);
	if (l < j) 
		Qsort(mas, l, j);
	if (i < u)
		Qsort(mas, i, u);
}
void Bistro(float* a, int n)
{
	Qsort(a, 0, n - 1);
}
void Puzirek(float* a, int n)
{
	int i = 0, j = 0;
	float	tmp = 0;
	for (; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
void Vstavki(float* a, int n)
{
	int i = 1, j = 0;
	float tmp = 0;
	for (; i < n; i++)
	{
		tmp = a[i];
		for (j = i - 1; j > 0; j--)
		{
			if (a[j] > tmp)
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = tmp;
	}
}
void PrintMas(float* a, int n)
{
		for (int i = 0; i < n; i++)
			printf("%f\n", a[i]);
		printf("\n");
}
void clrscr()
{
	system("@cls || clear");
}
