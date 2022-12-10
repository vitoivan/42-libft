#include "./tests.h"

int	main(void)
{
	ft_printf("\n\n-------------------------------\n\n");
	test_linked_add_back();
	ft_printf("\n\n-------------------------------\n\n");
	test_linked_add_front();
	ft_printf("\n\n-------------------------------\n\n");
	test_linked_kill_list();
	ft_printf("\n\n-------------------------------\n\n");
	test_linked_map();
	ft_printf("\n\n-------------------------------\n\n");
	test_linked_filter();
	ft_printf("\n\n-------------------------------\n\n");
}