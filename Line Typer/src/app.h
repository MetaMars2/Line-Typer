#pragma once

enum exit_code
{
	FAILURE = -1,
	SUCCESS = 0
};

int get_line_input(char** line, int size);
int append_line_to_file(char* line, char* file_name, int size);
int line_reader(const char *file_name);
int get_line_count(const char* file_name);
char *get_line(FILE* file);