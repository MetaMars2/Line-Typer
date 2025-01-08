#include "App.h"
// Line saver

int main()
{
    char *line = 0;
    int size = 100;
    char file_name[12] = "Saved_Lines";

    if (append_line_to_file(line, file_name, get_line_input(&line, size)) == SUCCESS)
    {
        printf("You entered: %s\n", line);
        free(line);
    }
    line_reader(file_name);

    return 0;
}