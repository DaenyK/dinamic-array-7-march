#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include "Header.h"
#include <stdlib.h>
using namespace std;

unsigned short int q;

void main()

{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	unsigned short int nz;

	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;

		switch (nz)
		{
		case 1:
		{
			//1.	Дан двумерный массив целых чисел
			//a.Сформировать одномерный массив, каждый элемент которого равен сумме четных положительных элементов соответствующего столбца двумерного массива

			int *m = NULL;
			int *newM = NULL;

			int coll, row, sum = 0;
			printf("введите кол-во строк массива: ");
			scanf("%d", &row);
			cin.get();
			printf("\nвведите кол-во столбцов массива: ");
			scanf("%d", &coll);

			m = (int*)calloc((coll*row), sizeof(int));
			newM = (int*)calloc((coll), sizeof(int));
			if (m != NULL&&newM != NULL)
			{
				createMatrix(m, row, coll);
				printMatrix(m, row, coll);

				for (int j = 0; j < row; j++)
				{
					for (int i = 0; i < coll; i++)
					{
						if ((*(m + i*coll + j)) % 2 == 0 && (*(m + i*coll + j)) > 0)
							sum += (*(m + i*coll + j));

					}
					*newM = sum;
					sum = 0;
					newM++;
				}

				print_arr(newM - coll, coll);
			}


			else
			{
				printf("error\n");
				exit(EXIT_FAILURE);
			}
		}break;
		}

		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
			cout << "ошибка" << endl;
		}
	} while (nz > 0);


}