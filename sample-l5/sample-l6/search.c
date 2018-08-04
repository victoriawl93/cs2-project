#include <stdio.h>
#include <stdbool.h>

#define N 10


bool search(const int a[], int n, int key)
{
    const int *p;


	//TODO
	
    return false;
}


int main(void)
{
    int array[N];
    int *p, key;

    printf("Please enter %d numbers: ", N);
    for(p = array; p < array+N; p++)
        scanf("%d", p);

    printf("Please enter a search key:");
    scanf("%d", &key);


    if(search(array, N, key))
        printf("key %d was found.\n", key);
    else
        printf("key %d was not found.\n", key);

    return 0;
}
