/*
 * page.c : A source file including functions for page viewing
 */
#include <stdio.h>
#include "item.h"
#include "page.h"


/*
 * Functions
 */

/* a function to show query result pages */

void print_page(Item *result[], int size) {
  FILE *f;
  int i,j,k;

  if( (f = fopen(RESULT_PAGE, "w")) == NULL) {
  	printf("cannot open file %s.", RESULT_PAGE);
  	return;
  }

  /* printing HTML header */
	fprintf(f, "<html>\n");
	fprintf(f, "<head>\n");
	fprintf(f, "<title>result page</title>\n");
	fprintf(f, "<style type=\"text/css\">\n");
	fprintf(f, "table { background-image: url(\"nagoya.gif\"); }\n");
	fprintf(f, "td { padding: 0px; border: 1px; width: 16px; height: 14px; font-size: 10px; text-aligh: center; color: #ff00ff; } \n");
	fprintf(f, "</style>\n");
	fprintf(f, "</head>\n");
	fprintf(f, "<body>\n");

	/* printing HTML table */
	fprintf(f, "<table>\n");
	for(i = 0; i < MAX_X_COORDINATE; i++){

		/* printing table row */
		fprintf(f, "<tr>\n");
		for(j = 0; j < MAX_Y_COORDINATE; j++){

			/* printing table column */
			fprintf(f,"<td>");

			/* printing item label corresponding to X=j, Y=i */
        for (int k=0; k<size; k++) {
          if(j == result[k]->x && i == result[k]->y)
            fprintf(f, "%d", k); /* item label1 on X=1,Y=1 */
        }

			fprintf(f,"</td>\n");
		}
		fprintf(f, "</tr>\n");
	}
	fprintf(f, "</table>\n");

	/* printing HTML list */
	fprintf(f, "<ul>\n");

	/* printing list items */
    for (int k=0; k<size; k++) {
      fprintf(f, "<li>%d : %s</li>\n", k, result[k]->name);
    }

	fprintf(f, "</ul>\n");


	fprintf(f, "</body>\n");
	fprintf(f, "</html>\n");

	fclose(f);

	printf("Search result is written to the file %s.\n", RESULT_PAGE);
	return;

}
