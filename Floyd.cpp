#pragma once

#include "Floyd.h"
#include "stdafx.h"

int* Floyd(int** p, int** ph, int t_num)	//матриц€ ваги, матриц€ ≥стор≥њ, к≥льк≥сть вершин
{
	double start = clock()/(CLOCKS_PER_SEC/1000); //час початку алгоритму
	int num_of_oper = 0, time = 0; //к≥льк≥сть операц≥й, час
	for (int a = 0; a < t_num; a++)
		for (int b = 0; b < t_num; b++)
			for (int c = 0; c < t_num; c++)
				if ((*(*(p+b)+c)) > (*(*(p+b)+a)+*(*(p+a)+c))) //€кщо ми знайшли б≥льш короткий шл€х
				{
					*(*(p+b)+c) = *(*(p+b)+a)+*(*(p+a)+c);
					*(*(ph+b)+c) = *(*(ph+b)+a);
					num_of_oper++;
				}
	double finish = clock()/(CLOCKS_PER_SEC/1000); //час к≥нец€ роботи алгоритму
	time = finish - start; //час роботи алгоритму
	int* arr = new int[3];
	arr[0] = time;
	arr[1] = t_num*t_num*t_num;
	arr[2] = num_of_oper;
	return arr; //повертаЇмо масив з потр≥бною нам ≥нформац≥Їю про час ≥ тп
}
