#include "./tests.h"

void	test_print_result(int result)
{
	if (!result)
		ft_printf(COLOR_BOLD RED "KO\n" RESET_COLOR REMOVE_BOLD);
	else
		ft_printf(COLOR_BOLD GREEN "OK\n" RESET_COLOR REMOVE_BOLD);
}