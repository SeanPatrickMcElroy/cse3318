#include "hw1_student.h"  // .h extenssion, not .c

// You do not need to change this print_1D function. It is included here for 
// your convenience, in case you need to call it while debugging.
void print_1D(int sz, int * arr){
	for(int k = 0; k< sz; k++){
		printf("%8d", arr[k]);
	}
	printf("\n");
}


/* dynamically allocates an array and populates it with all values from arr 
	that are strictly smaller than thresh. 
	Returns:
		- the pointer to the dynamically allocated array.
		- NULL if all elements of arr are greater or equal to thres. In this case it does not allocate any memory, and sets content of sz_res to 0.
*/
int* get_scores_below(int thresh, int sz_arr, int * arr, int* sz_res){
	for(int i=0;i<sz_arr;i++){
		if(arr[i] > thresh)
			arr[i]=arr[i+1]; 
	}
	if(sizeof(arr)==NULL)
		return sz_arr=0;
	size_t sz_arr =sizeof(arr)/sizeof(int);
	int *dynamicArr = (int *)malloc(*sz_res * sizeof(int));
	return dynamicArr;
}


void update_min_max(int num_rows, int num_cols, int* arr2D[], int* arr_min, int* arr_max){
	int r,c;
	
	for (r = 0; r<num_rows; r++){
		for(c=0; c<num_cols; c++){
			if(arr2D[r][c]>*arr_max)
				*arr_max=arr2D[r][c];
			else if(arr2D[r][c]<*arr_min)
				*arr_min=arr2D[r][c];
		}
	}
}


// improve this code to print as required in the homework
void print_2D(int num_rows, int num_cols, int* arr2D[]){	
	int r,c;
	int *arr_min,*arr_max;
	printf("\n");
	for (r = 0; r<num_rows; r++){
		printf("%8d|",r);
		for(c=0; c<num_cols; c++){
			printf("\t%8d|", arr2D[r][c]);
		}
		printf("\n");
	}
	update_min_max(num_rows,num_cols,&arr2D,&arr_min,&arr_max);
	printf("min value: %8d, max value: %8d",arr_min,arr_max);	
}

