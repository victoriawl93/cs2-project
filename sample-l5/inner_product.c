#include <stdio.h>

#define N 3

double inner_product(const double *a, const double *b, int n);

int main(void)
{
    double a[N], b[N], value;
    int i;

    printf("Enter %d numbers for the first vector: ", N);
    for(i=0; i < N; i++)
        scanf("%lf", a + i);

    printf("Enter %d numbers for the second vector: ", N);
    for(i=0; i < N; i++)
        scanf("%lf", b + i);

    value = inner_product(a, b, N);

    printf("Result: %lf\n", value);

    return 0;
}

/*
double inner_product(const double *a, const double *b, int n)
{
    double *p, *q, result=0;
    for(p=a, q=b; p < a + n && q < b + n; p++, q++)
         result += (*p) * (*q);
    return result;
}
*/

double inner_product(const double *a, const double *b, int n)
{
    double result=0;
	int i;
    for(i=0; i < n ; i++)
         result += (*(a+i)) * (*(b+i));
    return result;
}

