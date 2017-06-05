#pragma once

#include "InitZero.h"
#include "stdafx.h"

void InitZero(int** p, int tops_num)	//двовимірний масив, кількість вершин
{
	for(int n=0; n<tops_num; n++)
		for(int k=0; k<tops_num; k++)
			*(*(p+n)+k)=0;
}