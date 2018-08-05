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
void find_items_by_range() {
  Item *result[MAX_ITEM_SIZE];
  int num_result = 0;

  float user_x, user_y, threshold, distance;
  float squareSize = 40.0;
  printf("Enter your x coordinate: \n");
  scanf("%f", &user_x);
  printf("Enter your y coordinate: \n");
  scanf("%f", &user_y);
  printf("Enter distance threshold: \n");
  scanf("%f", &threshold);
  strcpy(result[0]->name, "You");
  strcpy(result[0]->category, "your position");
  result[0]->x = user_x;
  result[0]->y = user_y;
  num_result++;

  for (int i = 0; i < currentNum; i++) {
    int x = (float)ItemsArray[i].x;
    int y = (float)ItemsArray[i].y;
    distance = sqrt(powf((user_x - x),2)+powf((user_y - y),2))*squareSize;
    if (distance <= threshold) {
      result[num_result] = &(ItemsArray)[i];
      num_result++;
    }
  }
  if (num_result > 1) {
    printf("%d records were found within %f meters of you\n", num_result, threshold);
    print_page(result, num_result);
  }
  else {
    printf("Nothing found within %d meters of you\n", (int)threshold);
  }
}
/* function for nearest neighbor items */
void find_nearest_neighbor() {
  Item *result[2];
  int num_result = 2;

  float user_x, user_y;
  float distance;
  int init = 0;
  float distanceCurrent;
  float squareSize = 40.0;
  printf("Enter your x coordinate: \n");
  scanf("%f", &user_x);
  printf("Enter your y coordinate: \n");
  scanf("%f", &user_y);
  strcpy(result[0]->name, "You");
  strcpy(result[0]->category, "your position");
  result[0]->x = user_x;
  result[0]->y = user_y;

  for (int i = 0; i < currentNum; i++) {
    int x = (float)ItemsArray[i].x;
    int y = (float)ItemsArray[i].y;
    distanceCurrent = sqrt(powf((user_x - x),2)+powf((user_y - y),2))*squareSize;
    if (init == 0) {
      distance = distanceCurrent;
      init = 1;
      result[1] = &(ItemsArray)[i];
    }
    else {
      if (distance > distanceCurrent) {
        distance = distanceCurrent;
        result[1] = &(ItemsArray)[i];
      }
    }
  }
  printf("%s\n", result[1]->name);
  print_page(result, num_result);
}
/* function for how far am i from */
void how_far() {
  float user_x, user_y;
  float distance;
  float squareSize = 40.0;
  char item_name[30];
  int found = 0;
  printf("Enter your x coordinate: \n");
  scanf("%f", &user_x);
  printf("Enter your y coordinate: \n");
  scanf("%f", &user_y);
  printf("Enter an item name: \n");
  scanf("%s", item_name);


  for (int i = 0; i < currentNum; i++) {
    if (strcmp(item_name, ItemsArray[i].name) == 0) {
      found = 1;
      int x = (float)ItemsArray[i].x;
      int y = (float)ItemsArray[i].y;
      distance = sqrt(powf((user_x - x),2)+powf((user_y - y),2))*squareSize;
      break;
    }
  }
  if (found == 1) {
    printf("You are %.0f metres away from %s\n", distance, item_name);
  }
  else {
    printf("%s was not found on the map\n", item_name);
  }
}
