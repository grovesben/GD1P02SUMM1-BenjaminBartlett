#include<iostream>
#include"conio.h"
#include"QuickSort.h"


using namespace std;


int main(int args, char* arg[])
{
	cout << "Quick Sort Algorithm" << endl;
	cout << "**********************" << endl << endl;


	CQuickSortAlgo<int> array(5);
	array.push(80);
	array.push(64);
	array.push(99);
	array.push(76);
	array.push(5);


	cout << "Before sort:";

	for (int i = 0; i < 5; i++)
	{
		cout << " " << array[i];
	}
	cout << endl;


	array.QuickSort(0,4);


	cout << "After sort:";

	for (int i = 0; i < 5; i++)
	{
		cout << " " << array[i];
	}
	cout << endl << endl;


	_getch();
	return 0;
}