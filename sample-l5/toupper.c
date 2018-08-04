#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char input = 'a', output;

	output = toupper(input);

    printf("input is %c, output is %c\n", input, output);

    return 0;
}
