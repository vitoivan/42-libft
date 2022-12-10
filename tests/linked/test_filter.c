#include "../tests.h"

#define NUMBERS_QTY 50

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[linked_filter] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

static int	even_filter_fn(void *content)
{
	int	number;

	number = *(int *)content;
	return (number % 2 == 0);
}

void	test_linked_filter(void)
{
	unsigned int numbers_qty;
	unsigned int i;
	t_linked *even_list;
	t_linked *list;
	char *message;
	t_node *current_node;
	int expected_numbers[NUMBERS_QTY];

	numbers_qty = NUMBERS_QTY;
	i = 0;
	while (i++ < numbers_qty)
		expected_numbers[i - 1] = i;
	i = 0;
	list = linked_new_list();
	while (i++ < numbers_qty)
		linked_add_back(&list, linked_new_node(&expected_numbers[i - 1]));
	even_list = linked_filter(&list, even_filter_fn);
	{
		ft_printf(COLOR_BOLD BLU "\nTesting linked_filter ..." REMOVE_BOLD RESET_COLOR "\n\n");
		{
			message = get_test_title("The size of the second list must be the half of the first: ");
			ft_printf(message, numbers_qty);
			free(message);
			test_print_result(even_list->size == list->size / 2);
		}
		{
			message = get_test_title("The filtered list must have only even numbers: ");
			ft_printf(message, numbers_qty);
			free(message);
			i = 0;
			current_node = even_list->head;
			unsigned int count = 0;
			while (i++ < even_list->size)
			{
				if (*(int *)current_node->content % 2 == 0)
					count++;
			}
			test_print_result(count == even_list->size);
		}
	}
	linked_kill_list(&list, NULL);
	linked_kill_list(&even_list, NULL);
}