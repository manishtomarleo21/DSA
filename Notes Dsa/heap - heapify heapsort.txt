#include<stdio.h>
#include<stdlib.h>

#define MAX 100


void heapify(int arr[MAX], int n){
    int i, j, k, v, flag;

    for (i = n/2; i > 1; i--)
    {
        k = i;
        v = arr[k];
        flag = 0;
        while (!flag && 2*k <= n)
        {
            j = 2*k;
            if(i<n){
                if (arr[j]<arr[j+1])
                {
                    j = j+1;
                }
                
            }
            if (v >= arr[j])
            {
                flag = 1;
            }
            else{
                arr[k] = arr[j];
                k = j;
            }
            
        }
        arr[k] = v;
        
    }
    
}

void heapsort(int arr[MAX], int n){
    int temp;
    for (int i = n; i > 1; i--)
    {
       temp = arr[1];
       arr[1] = arr[i];
       arr[i] = temp;
       heapify(arr, i-1);
    }
    
}





int main()
{
    //1.
    //First we take input from the user the array which we convert into tree a ACBT - almost complete binary tree

    int n, arr[MAX];

    printf("Read value for n:  ");
    scanf("%d", &n);

    printf("\n Read array elemets\n ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapify(arr, n);
    heapsort(arr, n);

    printf("\n Sorted elements are elemets\n ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", arr[i]);
    }
    

    return 0;
}
