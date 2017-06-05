#pragma once

#include "WeightMatrixPlus.h"
#include "stdafx.h"

void WeightMatrixPlus(int** p, int tops_num)	//двовимірній масив, кількість вершин
{
	for (int i=0; i<tops_num; i++)
		for (int j=0; j<tops_num; j++)
		{
			if ((*(*(p+i)+j) == 0) && (i != j)) 
				*(*(p+i)+j) = SHRT_MAX;	
			if (*(*(p+i)+j) == -1) 
				*(*(p+i)+j) = 0;		//ознака відсутності прямого шляху
		}
}