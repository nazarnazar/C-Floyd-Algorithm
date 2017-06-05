#pragma once

#include "Floyd.h"
#include "stdafx.h"

int* Danzig(int** p, int t_num)		//������� ����, ������� ������
{
	int time = 0, num_of_oper = 0, num_of_iter = 0;	//������� ��������, ���
	double start = clock()/(CLOCKS_PER_SEC/1000);	//��� ������� ���������
	for (int b = 0; b < t_num-1; b++)
		for (int a = 0; a < t_num; a++)
			for (int c = 0; c < t_num-1; c++)
			{
				num_of_iter++;
				if (*(*(p+a)+b) + *(*(p+b)+c) < *(*(p+a)+c))	//���� �� ������� ���� �������� ����
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
				if (*(*(p+b)+c) + *(*(p+c)+a) < *(*(p+b)+a))	//���� �� ������� ���� �������� ����
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
				if (*(*(p+b)+a) + *(*(p+a)+c) < *(*(p+b)+c))	//���� �� ������� ���� �������� ����
				{
					*(*(p+b)+c) = *(*(p+b)+a) + *(*(p+a)+c);
					num_of_oper++;
				}
			}
	double finish = clock()/(CLOCKS_PER_SEC/1000);	//��� ����� ������ ���������
	time = finish - start;	//��� ������ ���������
	int* arr = new int[3];
	arr[0] = time;
	arr[1] = num_of_iter;
	arr[2] = num_of_oper;
	return arr;	//��������� ����� � �������� ��� ����������� ��� ��� � ��
}