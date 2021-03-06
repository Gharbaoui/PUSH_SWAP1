#include "checker.h"

int	main(int argc, char **argv)
{
	t_all	*bs;

	if (argc > 1)
	{
		collect_numbers(argc, argv, &bs);
		play_mode(bs);
		if (check_if_sorted(bs))
		{
			write(1, "OK\n", 3);
			free_all(bs);
			exit(0);
		}
		write(1, "KO\n", 3);
		free_all(bs);
		exit(1);
	}
}
