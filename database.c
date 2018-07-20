/*
 * database.h : A header file to share function prototype for database accesses
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "database.h"
#include "page.h"


/*
 * the definition of array variable to store items
 */
 static Item[MAX_ITEM_SIZE] ItemsArray;


/*
 * Integer variable to store the number of stored items
 */
static int numberOfStoredItems;


/*
 * Functions
 */

 /* function for insertion of a new data item */
 void insert_item() {
   char *newName;
   char *newCategory;
   int *newX;
   int *newY;

    printf("Enter the name of item: \n");
    scanf("%s\n", newName);
    printf("Enter the category of item: \n");
    scanf("%s\n", newCategory);
    printf("Enter the x-coordinate: \n");
    scanf("%d\n", newX);
    printf("Enter the y-coordinate: \n");
    scanf("%d\n", newY);
    // insert these 4 into ItemsArray
 }

 /* function for printing all data items */
  void print_all_items() {
    printf("|Item name |Category |Position |\n");
    printf("+----------+---------+---------+\n");
    for (int i = 0 ;i < sizeof(ItemsArray) ;i++ ) {
      printf("|%s|%s|(%d,%d)|\n", ItemsArray[i].name, ItemsArray[i].category, ItemsArray[i].x, ItemsArray[i].y);
    }
    printf("+----------+---------+---------+\n");
  }

/* function for loading items from a file */

/* function for saving items into a file */

/* function for finding items based on name */

/* function for finding items based on category */

/* function for finding items based on range */

/* function for nearest neighbor items */
