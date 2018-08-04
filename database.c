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
Item ItemsArray[MAX_ITEM_SIZE];


/*
 * Integer variable to store the number of stored items
 */
static int currentNum = 0;


/*
 * Functions
 */

 /* function for insertion of a new data item */
 void insert_item() {
  printf("Enter the name of item: \n");
  scanf("%s", ItemsArray[currentNum].name);
  printf("Enter the category of item: \n");
  scanf("%s", ItemsArray[currentNum].category);
  printf("Enter the x-coordinate: \n");
  scanf("%d", &ItemsArray[currentNum].x);
  printf("Enter the y-coordinate: \n");
  scanf("%d", &ItemsArray[currentNum].y);

  currentNum++;

 }

 /* function for printing all data items */
  void print_all_items() {
        printf("curr: %d\n", currentNum);
    printf("|Item name |Category |Position |\n");
    printf("+----------+---------+---------+\n");
    for (int i = 0 ;i < currentNum ;i++ ) {
      printf("|%s|%s|(%d,%d)|\n", ItemsArray[i].name, ItemsArray[i].category, ItemsArray[i].x, ItemsArray[i].y);
    }
    printf("+----------+---------+---------+\n");
  }

/* function for loading items from a file */
void load_items() {

    FILE * fp;
    char buffer[1024];
    if ((fp = fopen("data.csv", "r")) == NULL) {
         fprintf(stderr, "Cannot open file %s.\n");
     }

    int line = 1;
    printf("|Item name |Category |Position |\n");
    printf("+----------+---------+---------+\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (!(sscanf(buffer, "%s %s %d %d", ItemsArray[currentNum].name, ItemsArray[currentNum].category, &ItemsArray[currentNum].x, &ItemsArray[currentNum].y))) {
          fprintf(stderr, "Error processing line %d, ignored.\n", line);
          ++line;
          continue;
      }
      printf("|inserted |\n");
      printf("curr: %d\n", currentNum);
      ++line;
      currentNum++;
    }
    fclose(fp);
}
/* function for saving items into a file */
void save_items(){

    FILE * fp;
    if ((fp = fopen("test.csv", "w")) == NULL) {
         fprintf(stderr, "Cannot open file %s.\n");
     }
     // for (int i = 0; i < currentNum; i++) {
       fwrite (ItemsArray, sizeof(ItemsArray), 1, fp);

       printf("ok |\n");
       fclose(fp);
     // }
}
/* function for finding items based on name */

/* function for finding items based on category */

/* function for finding items based on range */

/* function for nearest neighbor items */
