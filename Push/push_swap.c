#include "push_swap.h"

int main(int argc, char **argv)
{
    t_all *bs; // both stacks info
 
    if (argc > 1)
    {
        if (!collect_numbers(argc, argv, &bs))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        start_sort(bs);
        free_all(bs);
    }
}

