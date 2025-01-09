#include "App.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_line_input(char** line, int size)
{
    *line = (char*)malloc(size * sizeof(char));

    if (*line == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return FAILURE;
    }

    printf("Enter a line: ");
    if (fgets(*line, size, stdin) == NULL)
    {
        fprintf(stderr, "Error reading input\n");
        free(*line);
        return FAILURE;
    }

    // Optionally, remove the newline character if present
    size_t lenght = strlen(*line);
    if (lenght > 0 && (*line)[lenght - 1] == '\n')
    {
        (*line)[lenght - 1] = '\0';
    }

    return lenght;
}

int append_line_to_file(char* line, char* file_name, int size)
{
    int line_count = get_line_count(file_name);

    FILE *file = fopen(file_name, "a");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open file\n");
        return FAILURE;
    }

    fprintf(file, "%d: %s\n",line_count + 1 , line);
    fclose(file);

    return SUCCESS;
}

int get_line_count(const char* file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        return 0;
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
    }

    fclose(file);
    return count;
}

size_t get_line_size(FILE* file, int line_index)
{
    int current_line = 1;
    size_t size = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (current_line == line_index)
        {
			while (ch != '\n' && ch != EOF)
			{
				size++;
				ch = fgetc(file);
			}
        }
		current_line++;
    }

    if (current_line < line_index)
    {
        fprintf(stderr, "Line number %d does not exist in the file\n", line_index);
        return -1;
    }

    return size;
}

char *get_line(FILE* file)
{
	int line_count = get_line_count(file);
    int choice = 0;

    printf("What line whould you like to edit: \n");
	fgets(choice, line_count, stdin);

	if (choice > line_count)
	{
		fprintf(stderr, "Invalid line number\n");
		return NULL;
	}

	fopen(file, "r");
	if (file == NULL)
	{
		return NULL;
	}

    char ch;

	for (int i = 0; (ch = fgetc(file)) != EOF; i++)
	{
		if (ch == (char)i)
		{
            size_t size = get_line_size(file, i);
			char* line = (char*)malloc(size * sizeof(char));
			if (line == NULL)
			{
				fprintf(stderr, "Memory allocation failed\n");
				return NULL;
			}
			fgets(line, size, file);
			fclose(file);
			return line;
		}
	}


	fclose(file);
    return NULL;
}


int line_reader(const char *file_name)
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
