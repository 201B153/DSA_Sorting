#include <iostream>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
int* fun(int n){
	srand(time(0));
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		arr[i] = rand()%99;
	}
	return arr;
}