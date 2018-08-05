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
 // TODO change this to *ItemsArray
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
    char fileName[30]="data.csv";
    if ((fp = fopen("data.csv", "r")) == NULL) {
         fprintf(stderr, "Cannot open file %s.\n");
     }
     int res = 0;
    int line = 1;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      if (!(sscanf(buffer, "%s %s %d %d", ItemsArray[currentNum].name, ItemsArray[currentNum].category, &ItemsArray[currentNum].x, &ItemsArray[currentNum].y))) {
          fprintf(stderr, "Error processing line %d, ignored.\n", line);
          ++line;
          continue;
      }
      res++;
      ++line;
      currentNum++;
    }
    fclose(fp);
    printf("Copied and saved %d records from %s\n", res, fileName);
}
/* function for saving items into a file */
void save_items(){
    int num_saved = 0;
    FILE * fp;
    char fileName[30] = "text.csv";
    if ((fp = fopen("test.csv", "w")) == NULL) {
      fprintf(stderr, "Cannot open file %s.\n");
    }
    for (int i = 0; i < currentNum; i++) {
      fprintf(fp, "%s,%s,%d,%d\n", ItemsArray[i].name, ItemsArray[i].category, ItemsArray[i].x, ItemsArray[i].y);
      num_saved++;
    }
    printf("Saved %d records into %s\n", num_saved, fileName);
    fclose(fp);
}
/* function for finding items based on name */
void find_items_by_name() {
  Item *result[MAX_ITEM_SIZE];
  int num_result = 0;

  char item_name[30];
   printf("Enter an item name for searching: \n");
   scanf("%s", item_name);
   printf("Searching for: %s\n", item_name);
   for (int i = 0; i < currentNum; i++) {
     if (strcmp(item_name, ItemsArray[i].name) == 0) {
       result[num_result] = &(ItemsArray)[i];
       num_result++;
     }
   }
   if (num_result > 0) {
     printf("%d records were found.\n", num_result);
     print_page(result, num_result);
   }
   else {
     printf("No records found matching your query\n");
 }
}
/* function for finding items based on category */
void find_items_by_category() {
  Item *result[MAX_ITEM_SIZE];
  int num_result = 0;
  char category[30];
   printf("Enter a category for searching: \n");
   scanf("%s", category);
   printf("Searching for: %s\n", category);
   for (int i = 0; i < currentNum; i++) {
     if (strcmp(category, ItemsArray[i].category) == 0) {
       result[num_result] = &(ItemsArray)[i];
       num_result++;
     }
   }
   if (num_result > 0) {
     printf("%d records were found.\n", num_result);
     print_page(result, num_result);
   }
   else {
     printf("No records found matching your query\n");
   }
}
/* function for finding items based on range */

/* function for nearest neighbor items */
