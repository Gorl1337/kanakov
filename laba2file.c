#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(int argc, char** argv)
{
	int n = 0, max = 0, min = 0, a = 0;
	float c = 0, l = 0;
	setlocale(LC_ALL, "Rus");
	sscanf_s(argv[1], "%d", &n);
	FILE* fo;
	FILE* fo1;
	errno_t fa, fa1;
	float* mas = (float*)malloc(n * sizeof(float));
	printf("Файл нужно заполнить:\n");
	printf("Введите 1 для чтения массива из файла\n");
	printf("Введите 2 для создания случайного массива\n");
	printf("Введите 3 для ввода массива с клавиатуры\n");
	scanf_s("%d", &a);
	if (a == 1)
	{
		fa = fopen_s(&fo, "C:\\Users\\gg\\source\\repos\\Filelaba2\\output1.txt", "r");
		for (int i = 0; i < n; i++)
			fscanf_s(fo, "%f", &(mas[i]));
		fclose(fo);

		fa1 = fopen_s(&fo1, "C:\\Users\\gg\\source\\repos\\laba\\output.txt", "w");
		for (int i = 0; i < n; i++)
			fprintf(fo1, "%f\n", mas[i]);
		fclose(fo1);
	}
	if (a == 2)
	{
		printf("Введите минимум ");
		scanf_s("%d", &min);

		printf("Введите максимум ");
		scanf_s("%d", &max);
		fa = fopen_s(&fo, "C:\\Users\\gg\\source\\repos\\laba\\output.txt", "w");

		for (int i = 0; i < n; i++)
		{
			float b = 0;
			b = (float)rand();
			l = (float)((b / RAND_MAX) * (max - min) + min);
			fprintf(fo, "%f\n", l);
		}
		fclose(fo);
	}
	if (a == 3)
	{
		fa = fopen_s(&fo, "C:\\Users\\gg\\source\\repos\\laba\\output.txt", "w");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%f", &c);
			fprintf(fo, "%f\n", c);
		}
		fclose(fo);
	}
	free(mas);
	return 0;
}
