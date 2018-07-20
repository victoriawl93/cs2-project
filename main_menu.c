/*
 * main_menu.c : A Source file of main function
 */
#include <stdio.h>
#include "item.h"
#include "database.h"

void insert_item(void);
void print_all_items(void);

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
      // case 's': search();
      //   break;
      // case 'u': update();
      //   break;
      case 'q': return 0;
      default: printf("Illegal code\n");
    }
    printf("\n");
  }
    return 0;
}
