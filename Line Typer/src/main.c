#include "App.h"
#include "tui.h"

#include <stdbool.h>
// Line saver

int main()
{
    char *line = 0;
    int size = 100;
    char file_name[12] = "Saved_Lines";
	bool running = true;

    while (running) {
		get_line_input(&line);
		append_line_to_file(line, file_name, size);
		line_reader(file_name);
		
    }

    return 0;
}