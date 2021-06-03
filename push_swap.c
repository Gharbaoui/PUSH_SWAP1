#include "push_swap.h"

int main(int argc, char **argv)
{
    t_all *bs; // both stacks info
 
    if (argc > 1)
    {
        if (!collect_numbers(argc, argv, &bs))
            write(1, "Error\n", 6);
        start_sort(bs);
        display_stack(bs->a, 1);
    }
}
