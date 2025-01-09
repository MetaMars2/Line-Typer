#include "tui.h"
#include "App.h"
#include <stdio.h>

void print_choices_input(char* choice, char **line) {
	printf("################################");
	printf("1. Add a line\n");
	printf("2. Edit a line\n");
	printf("3. Delete a line\n");
	printf("4. Exit\n");
	printf("Choice: ");
	fgets(choice, 2, stdin);
	printf("################################");

    switch (*choice) {
	case 1:
		get_line_input(&line);
		break;

    default:
        return FAILURE;
    }
}

int line_reader(const char* file_name)
{
    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open file\n");
        return FAILURE;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(file);
    return SUCCESS;
}