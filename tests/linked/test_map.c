#include "../tests.h"

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[linked_map] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

static void	*double_map_fn(void *content, int ind)
{
	int	*number;

	(void)ind;
	number = malloc(sizeof(int));
	*number = *(int *)content * 2;
	return (void *)(number);
}

void	test_linked_map(void)
{
	unsigned int numbers_qty = 50;
	int expected_numbers[numbers_qty + 1];
	unsigned int i;
	t_linked *doubled_list;
	t_linked *list;
	t_node *doubled_node;
	t_node *normal_node;

	i = 0;
	while (i++ < numbers_qty)
		expected_numbers[i - 1] = rand() / 2;
	i = 0;
	list = linked_new_list();
	while (i++ < numbers_qty)
		linked_add_back(&list, linked_new_node(&expected_numbers[i - 1]));
	char *message;

	{
		ft_printf(COLOR_BOLD BLU "\nTesting linked_map ..." REMOVE_BOLD RESET_COLOR "\n\n");
		{
			message = get_test_title("The new list must have the same elements of the old list: ");
			ft_printf(message, numbers_qty);
			free(message);
			doubled_list = linked_map(&list, double_map_fn);
			i = 0;
			doubled_node = doubled_list->head;
			normal_node = list->head;
			unsigned int count = 0;
			while (i++ < doubled_list->size)
			{
				if (*(int *)doubled_node->content
					/ 2 == *(int *)normal_node->content)
					count++;
			}
			test_print_result(count == numbers_qty);
		}
		{
			message = get_test_title("The new list must have the size of the old list: ");
			ft_printf(message, numbers_qty);
			free(message);
			test_print_result(doubled_list->size == list->size);
		}
		linked_kill_list(&list, NULL);
		linked_kill_list(&doubled_list, free);
	}
}