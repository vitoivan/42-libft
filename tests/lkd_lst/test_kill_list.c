#include "../tests.h"

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[lkd_lst_kill_list] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

void	test_lkd_lst_kill_list(void)
{
	int first_insert = 321;
	int second_insert = 22;
	int third_insert = 4135;
	int fourth_insert = 3566;
	int insert_five = 54361;
	// int *content;
	char *message;

	t_lkd_lst *linked = lkd_lst_new_list();
	lkd_lst_add_back(&linked, lkd_lst_new_node(&first_insert));
	lkd_lst_add_back(&linked, lkd_lst_new_node(&second_insert));
	lkd_lst_add_back(&linked, lkd_lst_new_node(&third_insert));
	lkd_lst_add_back(&linked, lkd_lst_new_node(&fourth_insert));
	lkd_lst_add_back(&linked, lkd_lst_new_node(&insert_five));

	// Testing kill list with 5 items
	{
		ft_printf(COLOR_BOLD BLU "\nTesting lkd_lst_kill_list ..." REMOVE_BOLD RESET_COLOR "\n\n");
		{
			lkd_lst_kill_list(&linked, NULL);
			message = get_test_title("Testing with 5 items (need to use valgrind): ");
			ft_printf(message);
			free(message);
			test_print_result(linked == NULL);
		}
		{
			lkd_lst_kill_list(NULL, NULL);
			message = get_test_title("Testing with NULL list (need to use valgrind)\n");
			ft_printf(message);
			free(message);
		}
		{
			linked = lkd_lst_new_list();
			lkd_lst_kill_list(&linked, NULL);
			message = get_test_title("Testing with head and tail NULL (need to use valgrind): ");
			ft_printf(message);
			free(message);
			test_print_result(linked == NULL);
		}
		{
			linked = lkd_lst_new_list();
			lkd_lst_add_back(&linked, lkd_lst_new_node(&second_insert));
			lkd_lst_kill_list(&linked, NULL);
			message = get_test_title("Testing with one item (need to use valgrind)\n");
			ft_printf(message);
			free(message);
		}
		{
			linked = lkd_lst_new_list();
			lkd_lst_add_back(&linked, lkd_lst_new_node(&second_insert));
			lkd_lst_add_back(&linked, lkd_lst_new_node(&third_insert));
			lkd_lst_kill_list(&linked, NULL);
			message = get_test_title("Testing with two items (need to use valgrind): ");
			ft_printf(message);
			free(message);
			test_print_result(linked == NULL);
		}
		{
			linked = lkd_lst_new_list();
			lkd_lst_add_back(&linked, lkd_lst_new_node(&second_insert));
			lkd_lst_add_back(&linked, lkd_lst_new_node(&third_insert));
			lkd_lst_kill_list(&linked, NULL);
			message = get_test_title("Testing with three items (need to use valgrind): ");
			ft_printf(message);
			free(message);
			test_print_result(linked == NULL);
		}
		{
			linked = lkd_lst_new_list();
			lkd_lst_add_back(&linked,
								lkd_lst_new_node(ft_strdup("Some random strimg")));
			lkd_lst_kill_list(&linked, free);
			message = get_test_title("Testing with strings: ");
			ft_printf(message);
			free(message);
			test_print_result(linked == NULL);
		}
		{
			linked = lkd_lst_new_list();
			lkd_lst_add_back(&linked,
								lkd_lst_new_node(ft_strdup("")));
			lkd_lst_kill_list(&linked, free);
			message = get_test_title("Testing with empty string: ");
			ft_printf(message);
			free(message);
			test_print_result(linked == NULL);
		}
	}
}