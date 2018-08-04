#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int item, mm, dd, yyyy;
    float price;

    if(argc != 2){
        printf("Usage ./columns  filename\n");
        exit(EXIT_FAILURE);
    }

    if( (fp = fopen(argv[1], "r")) == NULL){
        printf("Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
	
	//TODO
	
    fclose(fp);

    return 0;
}
