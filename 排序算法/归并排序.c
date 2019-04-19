#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include<stdlib.h>
#include "genlib.h"
#include "gcalloc.h"
#include "exception.h"

#define MAXSIZE 100
#define NewArray(n, type) ((type *) GetBlock((n) * sizeof (type)))

_GCControlBlock _acb = NULL;

/* Memory allocation implementation */

void *GetBlock(size_t nbytes)
{
    void *result;

    if (_acb == NULL) {
        result = malloc(nbytes);
    } else {
        result = _acb->allocMethod(nbytes);
    }
    if (result == NULL) printf("No memory available");
    return (result);
}

void FreeBlock(void *ptr)
{
    if (_acb == NULL) {
        free(ptr);
    } else {
        _acb->freeMethod(ptr);
    }
}
//core
void Merge (int array[], int arr1[], int n1, int arr2[], int n2) 
{ 
     int p, p1, p2;  
     p = p1 = p2 = 0; 
     while (p1 < n1 && p2 < n2) { 
           if (arr1[p1] < arr2[p2])  
                 array[p++] = arr1[p1++]; 
           else  
                 array[p++] = arr2[p2++]; 
    } 
    while (p1 < n1) array[p++] = arr1[p1++]; 
    while (p2 < n2) array[p++] = arr2[p2++]; 
} 
void SortIntegerArray (int array[], int n) 
{ 
    int i, n1, n2, *arr1, *arr2; 
    if (n > 1) { 
         n1 = n / 2; 
         n2 = n - n1; 
         arr1 = NewArray (n1,int); 
         arr2 = NewArray (n2, int); 
         for (i = 0; i < n1; i++) arr1[i] = array[i]; 
         for (i = 0; i < n2; i++) arr2[i] = array[n1 + i]; 
         SortIntegerArray (arr1, n1); 
         SortIntegerArray (arr2, n2); 
         Merge (array, arr1, n1, arr2, n2); 
         
         
         
         FreeBlock (arr1); 
         FreeBlock (arr2); 
    } 
} 
main(){
	int a[MAXSIZE],i,n; 
	printf("\t\t--Merge-sort--\nEnter a number less than %d:",MAXSIZE);
	scanf("%d",&n);
	if(n>MAXSIZE||n<0){
		printf("Invalid input!\n");
		goto end;
	}
	//generate random numbers
	for(i=0;i<n;i++){
	         	a[i]=rand();
			 }
			 
//show the original data
	printf("\nbefore:\n");
	for(i=0;i<n;i++){
	         	printf("%d ",a[i]);
			 }
	//process
	SortIntegerArray (a,n);
	
//show the sorted data
	printf("\nafter sorted:\n");
	         for(i=0;i<n;i++){
	         	printf("%d ",a[i]);
			 }
		end:	 
printf("\nThanks for using!\n\t\t-- Copyright@Johnzchgrd--\n");
	return 0;
}
