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
	(*sz_res)++;
	if(arr == NULL || sz_res == NULL)
		return NULL;
	int correctArr[sz_arr];
	for(int i=0;i<sz_arr;i++){
		if(arr[i]<=thresh){
			correctArr[*sz_res]=arr[i];
			(*sz_res)++;
		}
 	}
	if(correctArr == NULL)
		return NULL;
	int *dynamicArr  = (int *)malloc(*sz_res * sizeof(int));
	for(int i=0;i<*sz_res;i++){
		dynamicArr[i]=correctArr[i];
	}
	return dynamicArr;
}


void update_min_max(int num_rows, int num_cols, int* arr2D[], int* arr_min, int* arr_max){
	int r,c;
	*arr_min=arr2D[0][0];
	*arr_max=arr2D[0][0];
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
	printf("\n");
	for (r = 0; r<num_rows; r++){
		printf("%8d|",r);
		for(c=0; c<num_cols; c++){
			printf("\t%8d|", arr2D[r][c]);
		}
		printf("\n");
	}
}
