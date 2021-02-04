RT_SECURE_NO_WARNINGS 1


#include"sort.h"
//直接插入排序
void inserSort(int* array, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
	    int key = array[end + 1];
	    while (end >= 0 && array[end] > key)
	   {
		   array[end + 1] = array[end];
		   --end;

	    }
	    array[end + 1] = key;

	}
	
}
//希尔排序
void ShellSort(int* array, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
	    for (int i = 0; i < n - gap; ++i)
	   {
       int end = i;
	   int key = array[end + gap];
         while (end >= 0 && array[end] > key)
	     {
		  array[end + gap] = array[end];
	  	   end -= gap;
	       }
	    array[end + gap] = key;
	    }

	}
	
	
}
//选择排序
//void Swap(int* array, int n, int k)
//{
//	
//}
void  SelectSort(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int start = i;
		int min = start;
		for (int j = start + 1; j < n; ++j)
		{
			if (array[j] < array[min])
				min = j;
			swap(array, start, min);
		}
	}
}
//冒泡排序
void BulleSort(int* array, int n)
{
	while (n > 0)
	{
		int flag = 1;
		int end = n;
		for (int i = 0; i < end - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				Swap(array, i, i + 1);
				flag = 0;
			}
			if (flag == 0)
				break;
			--n;
		}
	}
}
//堆排序
void shiftDown(int* array, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child] < array[child + 1])
			child++;
		if (array[parent] < array[child])
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
	}
}
void heapSort(int* array, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(array, n, i);
	}
	while (n)
	{
		Swap(array, 0, n - 1);
		--n;
	}

}
//快排
//霍尔hora
int partion(int* array, int begin, int end)
{
	int key = array[begin];
	int start = begin;
	while (begin < end)
	{
		while (begin < end && array[end] >= key)
			--end;
		while (begin < end && array[begin] <= key)
			++begin;
		Swap(array, begin, end);
	}
	Swap(array, start, end);//(array,start,begin)
	return end;
	//return begin;
}
void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	//划分当前区间
	int keyPos = partion(array, begin, end);
	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}
//挖坑法
int partion2(int* array, int begin, int end)
{
	int key = array[begin];
	while (begin < end)
	{
		while (begin < end && array[end] > key)
			--end;
		array[begin] = array[end];
		while (begin < end && array[begin] <= key)
			++begin;
		array[end] = array[begin];
	}
	array[begin] = key;
	return begin;
}
void quickSort2(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	//划分当前区间
	int keyPos = partion2(array, begin, end);
	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}
//第三种前后指针
int partion3(int* array, int begin, int end)
{
	int prev = begin;
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end)
	{//新发现的小数据和尾指针指向的位置不连续，
		
		if (array[cur] < key && prev + 1 != cur)
			++prev;
		//上俩行的简化if (array[cur] < key && ++prev != cur)
		Swap(array, prev, cur);
	}
}

