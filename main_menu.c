/*
 * main_menu.c : A Source file of main function
 */
#include <stdio.h>
#include "item.h"
#include "database.h"

void insert_item(void);
void print_all_items(void);
void load_items(void);
void save_items(void);
void find_items_by_name(void);
void find_items_by_category(void);
void find_items_by_range(void);
void find_nearest_neighbor(void);
void how_far(void);
/* main function */
int main(void)
{
    // printf("This is a skelton of the spatial database.\n");
    char code;
    for(;;) {
      printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')
    ;
    switch(code) {
      case 'i': insert_item();
        break;
      case 'p': print_all_items();
        break;
      case 'l': load_items();
        break;
      case 's': save_items();
        break;
      case 'f': find_items_by_name();
        break;
      case 'c': find_items_by_category();
        break;
      case 'r': find_items_by_range();
        break;
      case 'n': find_nearest_neighbor();
        break;
      case 'h': how_far();
        break;
      case 'q': return 0;
      default: printf("Illegal code\n");
    }
    printf("\n");
  }
    return 0;
}
