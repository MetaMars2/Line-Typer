#pragma once

enum exitCode
{
	FAILURE = -1,
	SUCCESS = 0
};

int get_line_input(char** line, int size);
int append_line_to_file(char* line, char* fileName, int size);
int line_reader();
int get_line_count(const char* fileName);