#pragma once

#include "Floyd.h"
#include "stdafx.h"

int* Floyd(int** p, int** ph, int t_num)	//������� ����, ������� �����, ������� ������
{
	double start = clock()/(CLOCKS_PER_SEC/1000); //��� ������� ���������
	int num_of_oper = 0, time = 0; //������� ��������, ���
	for (int a = 0; a < t_num; a++)
		for (int b = 0; b < t_num; b++)
			for (int c = 0; c < t_num; c++)
				if ((*(*(p+b)+c)) > (*(*(p+b)+a)+*(*(p+a)+c))) //���� �� ������� ���� �������� ����
				{
					*(*(p+b)+c) = *(*(p+b)+a)+*(*(p+a)+c);
					*(*(ph+b)+c) = *(*(ph+b)+a);
					num_of_oper++;
				}
	double finish = clock()/(CLOCKS_PER_SEC/1000); //��� ����� ������ ���������
	time = finish - start; //��� ������ ���������
	int* arr = new int[3];
	arr[0] = time;
	arr[1] = t_num*t_num*t_num;
	arr[2] = num_of_oper;
	return arr; //��������� ����� � �������� ��� ����������� ��� ��� � ��
}
