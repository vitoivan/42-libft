#include "./tests.h"

int	main(void)
{
	ft_printf("\n\n-------------------------------\n\n");
	test_lkd_lst_add_back();
	ft_printf("\n\n-------------------------------\n\n");
	test_lkd_lst_add_front();
	ft_printf("\n\n-------------------------------\n\n");
	test_lkd_lst_kill_list();
	ft_printf("\n\n-------------------------------\n\n");
	test_lkd_lst_map();
	ft_printf("\n\n-------------------------------\n\n");
	test_lkd_lst_filter();
	ft_printf("\n\n-------------------------------\n\n");
	test_lkd_lst_pop_first();
	ft_printf("\n\n-------------------------------\n\n");
	test_lkd_lst_pop_last();
	ft_printf("\n\n-------------------------------\n\n");
	test_lkd_lst_pop_at();
	ft_printf("\n\n-------------------------------\n\n");
}