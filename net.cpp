//#pragma once
//
#include "stdafx.h"
//#include "net.h"
//
////void InitZero(int** p, int tops_num)	//двовим≥рний масив, к≥льк≥сть вершин
////{
////	for(int n=0; n<tops_num; n++)
////		for(int k=0; k<tops_num; k++)
////			*(*(p+n)+k)=0;
////}
//
////void HistoryMatrix(int** p, int tops_num)	//двовим≥рний масив, к≥льк≥сть вершин
////{
////	for(int i=0;i<tops_num;i++)
////		for(int j=0;j<tops_num;j++)
////			if(*(*(p+i)+j) != 0)
////				*(*(p+i)+j)=j+1;
////}
//
////void WeightMatrixPlus(int** p, int tops_num)	//двовим≥рн≥й масив, к≥льк≥сть вершин
////{
////	for (int i=0; i<tops_num; i++)
////		//for (int j=0; j<tops_num; j++)
////			if ((*(*(p+i)+j) == 0) && (i != j)) 
////				*(*(p+i)+j) = SHRT_MAX;			//ознака в≥дсутност≥ пр€мого шл€ху
////}
//
////int* Floyd(int** p, int** ph, int t_num)	//матриц€ ваги, матриц€ ≥стор≥њ, к≥льк≥сть вершин
////{
////	double start = clock()/(CLOCKS_PER_SEC/1000); //час початку алгоритму
////	int num_of_oper = 0, time = 0; //к≥льк≥сть операц≥й, час
////	for (int a = 0; a < t_num; a++)
////		for (int b = 0; b < t_num; b++)
////			for (int c = 0; c < t_num; c++)
////				if ((*(*(p+b)+c)) > (*(*(p+b)+a)+*(*(p+a)+c))) //€кщо ми знайшли б≥льш короткий шл€х
////				{
////					*(*(p+b)+c) = *(*(p+b)+a)+*(*(p+a)+c);
////					*(*(ph+b)+c) = *(*(ph+b)+a);
////					num_of_oper++;
////				}
////	double finish = clock()/(CLOCKS_PER_SEC/1000); //час к≥нец€ роботи алгоритму
////	time = finish - start; //час роботи алгоритму
////	int* arr = new int[3];
////	arr[0] = time;
////	arr[1] = t_num*t_num*t_num;
////	arr[2] = num_of_oper;
////	return arr; //повертаЇмо масив з потр≥бною нам ≥нформац≥Їю про час ≥ тп
////}
//
////int* Danzig(int** p, int t_num)		//матриц€ ваги, к≥льк≥сть вершин
////{
////	int time = 0, num_of_oper = 0, num_of_iter = 0;	//к≥льк≥сть операц≥й, час
////	double start = clock()/(CLOCKS_PER_SEC/1000);	//час початку алгоритму
////	for (int a = 0; a < t_num; a++)
////		for (int b = 0; b < a; b++)
////			for (int c = 0; c < a; c++)
////			{
////				num_of_iter++;
////				if (*(*(p+a)+c) + *(*(p+c)+b) < *(*(p+a)+b))	//€кщо ми знайшли б≥льш короткий шл€х
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
////				if (*(*(p+b)+c) + *(*(p+c)+a) < *(*(p+b)+a))	//€кщо ми знайшли б≥льш короткий шл€х
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
////				if (*(*(p+b)+a) + *(*(p+a)+c) < *(*(p+b)+c))	//€кщо ми знайшли б≥льш короткий шл€х
////				{
////					*(*(p+b)+c) = *(*(p+b)+a) + *(*(p+a)+c);
////					num_of_oper++;
////				}
////			}
////	double finish = clock()/(CLOCKS_PER_SEC/1000);	//час к≥нец€ роботи алгоритму
////	time = finish - start;	//час роботи алгоритму
////	int* arr = new int[3];
////	arr[0] = time;
////	arr[1] = num_of_iter;
////	arr[2] = num_of_oper;
////	return arr;	//повертаЇмо масив з потр≥бною нам ≥нформац≥Їю про час ≥ тп
////}