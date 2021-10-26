#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>

int main()
{
	int n = 0, i = 0, k = 0, flag = 0;
	float max = 0, min = 0, sum = 0, temp = 0;
	float* a;
	int* number;

	srand(time(NULL));

	// ввод кол-ва элементов, максимума и минимума
	do {
		printf("enter the number of numbers\t"); scanf_s("%d", &n); printf("enter maximum number\t"); scanf_s("%f", &max); printf("enter minimum number\t"); scanf_s("%f", &min);
		if (max < min) system("cls");
		if (max<min) printf("Error: maximum less than minimum\n");
	} while (max < min); system("cls");
		// создание массива чисел и массива номеров чисел

		a = (float*)malloc(n * sizeof(float));

		number = (int*)malloc(n * sizeof(int));

		// ввод чисел и создание массива с номерами которые нужно вычесть 

		for (i = 0; i < n; i++) {
			flag = 1;
			temp = rand();
			a[i] = min + (temp / RAND_MAX) * (max - min);

			// перевод десятичной части числа в номер элемента

			temp = floor((a[i] - int(a[i])) * 1000000);

			// проверка на наличие данного номера в массиве номеров 

			for (int j = 0; j < i; j++) {
				if (temp == number[j]) {
					flag = 0;
				}
			}

			// если элемента не было то присвоить его значние новому элеметну массива номеров 

			if (flag) {
				number[k] = temp;
				k++;
			}
		}

		// вывод элементов

		for (i = 0; i < n; i++) {
			printf("%.7f | %d\n", a[i], number[i]);
		}

		// сумма всех элементов

		for (i = 0; i < n; i++) sum += a[i];

		// вычитание лишних

		for (i = 0; i < k; i++)
			if (number[i] < n)
				sum -= a[number[i]] * 2;

		printf("%f", sum);
	}