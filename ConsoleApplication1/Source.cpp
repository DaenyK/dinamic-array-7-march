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
		cout << "������� ����� �������: ";
		cin >> nz;

		switch (nz)
		{
		case 1:
		{
			//1.	��� ��������� ������ ����� �����
			//a.������������ ���������� ������, ������ ������� �������� ����� ����� ������ ������������� ��������� ���������������� ������� ���������� �������

			int *m = NULL;
			int *newM = NULL;

			int coll, row, sum = 0;
			printf("������� ���-�� ����� �������: ");
			scanf("%d", &row);
			cin.get();
			printf("\n������� ���-�� �������� �������: ");
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

		cout << "������ ���������� 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
			cout << "������" << endl;
		}
	} while (nz > 0);


}