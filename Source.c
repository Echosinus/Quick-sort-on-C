//Быстрая Сортировка
//Русанов Олег ИВТ-13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void QuickSor(int* s_arr, int arr_size)
{
	int sortsize = arr_size, first = 0, mid_elem = s_arr[(int)(arr_size / 2)], temp = 0;


	do
	{
		//провермяем массив слева на права пока не найдём элемент больше центрального
		while (s_arr[first] < mid_elem)
			first++;

		//проверяем массив справа на лево пока не найдём элемент меньше центрального
		while (s_arr[arr_size] > mid_elem)
			arr_size--;

		//меняем местами элемент который меньше центрального и больший центрального которые мы нашли 
		if (first <= arr_size)
		{
			temp = s_arr[first];
			s_arr[first] = s_arr[arr_size];
			s_arr[arr_size] = temp;
			first++;
			arr_size--;
		}

	} while (first <= arr_size);
	//повторяем функцию для массива меньших центрального
	if (arr_size > 0) QuickSor(s_arr, arr_size);
	//повторяем функцию для массива больших центрального
	if (sortsize > first) QuickSor(s_arr + first, sortsize - first);
}


void main()
{
	setlocale(LC_ALL, "Russian");
	int* arr;
	int i, n; //i счётчик n кол-во символов
	printf("Введите размер массива: ");
	if (!scanf("%d", &n)){
		printf("error"); return 0;
}


	arr = (int*)malloc(n * sizeof(int));//выделяем память и вводим элементы 
	printf("Введите элементы массива \n");
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		if (!scanf("%d", &arr[i])) {
			printf("error"); return 0;
		}
	}


	QuickSor(arr, n - 1);
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	free(arr);
	system("pause");
}
