#pragma once

#include "HistoryMatrix.h"
#include "stdafx.h"

void HistoryMatrix(int** p, int tops_num)	//двовимірний масив, кількість вершин
{
	for(int i=0;i<tops_num;i++)
		for(int j=0;j<tops_num;j++)
			if(*(*(p+i)+j) != 0)
				*(*(p+i)+j)=j+1;
}