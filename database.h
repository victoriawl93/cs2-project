/*
 * database.h : A header file to share function prototype for database accesses
 */
#ifndef DATABASE_H
#define DATABASE_H

/* this header file depends on item.h */
#include "item.h"

/*
 * Macro defitions related to database
 */

/* Macro definition for the maximum size of database */
#define MAX_ITEM_SIZE 100

/* Macro definition for the maximum length of file path (loading/saving) */
#define MAX_FILE_PATH_LENGTH 30


/*
 * Function prototypes related to database
 */

/* function prototype for insertion of a new data item */
void insert_item();
/* function prototype for printing all data items */
void print_all_items();
/* function prototype for loading items from a file */
void load_items();
/* function prototype for saving items into a file */
void save_items();
/* function prototype for finding items based on name */
void find_items_by_name();
/* function prototype for finding items based on category */
void find_items_by_category();
/* function prototype for finding items based on range */
void find_items_by_range();
/* function prototype for nearest neighbor items */
void find_nearest_neighbor();

void how_far();
#endif
