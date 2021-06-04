#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4

int get_next_line(char **line);
int complete(char **line, char **rest, char **current, int index);
int validate(char **line, char **rest, char **current);
int last_line(char **line, char **rest, char **current);
int error(char **line, char **rest, char **current);
int  ft_strlen(char *str);
int nlindex(char *str, char c);
char *split(char *current, int val, int index);
char *ft_strjoin(char **rest, char *current);
