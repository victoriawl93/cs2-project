/*
 * page.h : A header file to share function prototypes for page viewing
 */
#ifndef PAGE_H
#define PAGE_H

/* this file depends on item.h */
#include "item.h"


/*
 * Macro definitions related to page viewing
 */
 #define RESULT_PAGE "result.html"

/*
 * Function prototypes related to page viewing
 */

/* function prototype to show query result pages */
void print_page(Item *result[], int size);


#endif
