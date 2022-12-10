#include "../tests.h"

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[linked_kill_list] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

void	test_linked_kill_list(void)
{
	int first_insert = 321;
	int second_insert = 22;
	int third_insert = 4135;
	int fourth_insert = 3566;
	int insert_five = 54361;
	// int *content;
	char *message;

	t_linked *linked = linked_new_list();
	linked_add_back(&linked, linked_new_node(&first_insert));
	linked_add_back(&linked, linked_new_node(&second_insert));
	linked_add_back(&linked, linked_new_node(&third_insert));
	linked_add_back(&linked, linked_new_node(&fourth_insert));
	linked_add_back(&linked, linked_new_node(&insert_five));

	// Testing kill list with 5 items
	{
		ft_printf(COLOR_BOLD BLU "\nTesting linked_kill_list ..." REMOVE_BOLD RESET_COLOR "\n\n");
		{
			linked_kill_list(&linked, NULL);
			message = get_test_title("Testing with 5 items (need to use valgrind)\n\n");
			ft_printf(message);
			free(message);
		}
		{
			linked_kill_list(NULL, NULL);
			message = get_test_title("Testing with NULL list (need to use valgrind)\n\n");
			ft_printf(message);
			free(message);
		}
		{
			linked = linked_new_list();
			linked_kill_list(&linked, NULL);
			message = get_test_title("Testing with head and tail NULL (need to use valgrind)\n\n");
			ft_printf(message);
			free(message);
		}
		{
			linked = linked_new_list();
			linked_add_back(&linked, linked_new_node(&second_insert));
			linked_kill_list(&linked, NULL);
			message = get_test_title("Testing with one item (need to use valgrind)\n\n");
			ft_printf(message);
			free(message);
		}
		{
			linked = linked_new_list();
			linked_add_back(&linked, linked_new_node(&second_insert));
			linked_add_back(&linked, linked_new_node(&third_insert));
			linked_kill_list(&linked, NULL);
			message = get_test_title("Testing with two items (need to use valgrind)\n\n");
			ft_printf(message);
			free(message);
		}
		{
			linked = linked_new_list();
			linked_add_back(&linked, linked_new_node(&second_insert));
			linked_add_back(&linked, linked_new_node(&third_insert));
			linked_kill_list(&linked, NULL);
			message = get_test_title("Testing with three items (need to use valgrind)\n\n");
			ft_printf(message);
			free(message);
		}
		{
			linked = linked_new_list();
			linked_add_back(&linked,
							linked_new_node(ft_strdup("Some random strimg")));
			linked_kill_list(&linked, free);
			message = get_test_title("Testing with strings\n\n");
			ft_printf(message);
			free(message);
		}
		{
			linked = linked_new_list();
			linked_add_back(&linked,
							linked_new_node(ft_strdup("")));
			linked_kill_list(&linked, free);
			message = get_test_title("Testing with empty string\n\n");
			ft_printf(message);
			free(message);
		}
	}
}