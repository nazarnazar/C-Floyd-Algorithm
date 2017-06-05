#pragma once

#include "Floyd.h"
#include "stdafx.h"

int* Danzig(int** p, int t_num)		//матриц€ ваги, к≥льк≥сть вершин
{
	int time = 0, num_of_oper = 0, num_of_iter = 0;	//к≥льк≥сть операц≥й, час
	double start = clock()/(CLOCKS_PER_SEC/1000);	//час початку алгоритму
	for (int b = 0; b < t_num-1; b++)
		for (int a = 0; a < t_num; a++)
			for (int c = 0; c < t_num-1; c++)
			{
				num_of_iter++;
				if (*(*(p+a)+b) + *(*(p+b)+c) < *(*(p+a)+c))	//€кщо ми знайшли б≥льш короткий шл€х
				{
					*(*(p+a)+c) = *(*(p+a)+b) + *(*(p+b)+c);
					num_of_oper++;
				}
			}
	for (int c = 0; c < t_num-1; c++)
		for (int b = 0; b < t_num-1; b++)
			for (int a = 0; a < t_num; a++)
			{
				num_of_iter++;
				if (*(*(p+b)+c) + *(*(p+c)+a) < *(*(p+b)+a))	//€кщо ми знайшли б≥льш короткий шл€х
				{
					*(*(p+b)+a) = *(*(p+b)+c) + *(*(p+c)+a);
					num_of_oper++;
				}
			}
	for (int a = 0; a < t_num; a++)
		for (int b = 0; b < t_num-1; b++)
			for (int c = 0; c < t_num-1; c++)
			{
				num_of_iter++;
				if (*(*(p+b)+a) + *(*(p+a)+c) < *(*(p+b)+c))	//€кщо ми знайшли б≥льш короткий шл€х
				{
					*(*(p+b)+c) = *(*(p+b)+a) + *(*(p+a)+c);
					num_of_oper++;
				}
			}
	double finish = clock()/(CLOCKS_PER_SEC/1000);	//час к≥нец€ роботи алгоритму
	time = finish - start;	//час роботи алгоритму
	int* arr = new int[3];
	arr[0] = time;
	arr[1] = num_of_iter;
	arr[2] = num_of_oper;
	return arr;	//повертаЇмо масив з потр≥бною нам ≥нформац≥Їю про час ≥ тп
}