//#pragma once
//
#include "stdafx.h"
//#include "net.h"
//
////void InitZero(int** p, int tops_num)	//���������� �����, ������� ������
////{
////	for(int n=0; n<tops_num; n++)
////		for(int k=0; k<tops_num; k++)
////			*(*(p+n)+k)=0;
////}
//
////void HistoryMatrix(int** p, int tops_num)	//���������� �����, ������� ������
////{
////	for(int i=0;i<tops_num;i++)
////		for(int j=0;j<tops_num;j++)
////			if(*(*(p+i)+j) != 0)
////				*(*(p+i)+j)=j+1;
////}
//
////void WeightMatrixPlus(int** p, int tops_num)	//��������� �����, ������� ������
////{
////	for (int i=0; i<tops_num; i++)
////		//for (int j=0; j<tops_num; j++)
////			if ((*(*(p+i)+j) == 0) && (i != j)) 
////				*(*(p+i)+j) = SHRT_MAX;			//������ ��������� ������� �����
////}
//
////int* Floyd(int** p, int** ph, int t_num)	//������� ����, ������� �����, ������� ������
////{
////	double start = clock()/(CLOCKS_PER_SEC/1000); //��� ������� ���������
////	int num_of_oper = 0, time = 0; //������� ��������, ���
////	for (int a = 0; a < t_num; a++)
////		for (int b = 0; b < t_num; b++)
////			for (int c = 0; c < t_num; c++)
////				if ((*(*(p+b)+c)) > (*(*(p+b)+a)+*(*(p+a)+c))) //���� �� ������� ���� �������� ����
////				{
////					*(*(p+b)+c) = *(*(p+b)+a)+*(*(p+a)+c);
////					*(*(ph+b)+c) = *(*(ph+b)+a);
////					num_of_oper++;
////				}
////	double finish = clock()/(CLOCKS_PER_SEC/1000); //��� ����� ������ ���������
////	time = finish - start; //��� ������ ���������
////	int* arr = new int[3];
////	arr[0] = time;
////	arr[1] = t_num*t_num*t_num;
////	arr[2] = num_of_oper;
////	return arr; //��������� ����� � �������� ��� ����������� ��� ��� � ��
////}
//
////int* Danzig(int** p, int t_num)		//������� ����, ������� ������
////{
////	int time = 0, num_of_oper = 0, num_of_iter = 0;	//������� ��������, ���
////	double start = clock()/(CLOCKS_PER_SEC/1000);	//��� ������� ���������
////	for (int a = 0; a < t_num; a++)
////		for (int b = 0; b < a; b++)
////			for (int c = 0; c < a; c++)
////			{
////				num_of_iter++;
////				if (*(*(p+a)+c) + *(*(p+c)+b) < *(*(p+a)+b))	//���� �� ������� ���� �������� ����
////				{
////					*(*(p+a)+b) = *(*(p+a)+c) + *(*(p+c)+b);
////					num_of_oper++;
////				}
////			}
////	for (int a = 0; a < t_num; a++)
////		for (int b = 0; b < a; b++)
////			for (int c = 0; c < a; c++)
////			{
////				num_of_iter++;
////				if (*(*(p+b)+c) + *(*(p+c)+a) < *(*(p+b)+a))	//���� �� ������� ���� �������� ����
////				{
////					*(*(p+b)+a) = *(*(p+b)+c) + *(*(p+c)+a);
////					num_of_oper++;
////				}
////			}
////	for (int a = 0; a < t_num; a++)
////		for (int b = 0; b < a; b++)
////			for (int c = 0; c < a; c++)
////			{
////				num_of_iter++;
////				if (*(*(p+b)+a) + *(*(p+a)+c) < *(*(p+b)+c))	//���� �� ������� ���� �������� ����
////				{
////					*(*(p+b)+c) = *(*(p+b)+a) + *(*(p+a)+c);
////					num_of_oper++;
////				}
////			}
////	double finish = clock()/(CLOCKS_PER_SEC/1000);	//��� ����� ������ ���������
////	time = finish - start;	//��� ������ ���������
////	int* arr = new int[3];
////	arr[0] = time;
////	arr[1] = num_of_iter;
////	arr[2] = num_of_oper;
////	return arr;	//��������� ����� � �������� ��� ����������� ��� ��� � ��
////}