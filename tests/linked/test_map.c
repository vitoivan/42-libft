#include "../tests.h"

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[linked_map] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

static void	*map_fn(void *content)
{
	int	*number;

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
	int *doubled_content;
	int *normal_content;
	char *message;

	{
		ft_printf(COLOR_BOLD BLU "\nTesting linked_map ..." REMOVE_BOLD RESET_COLOR "\n\n");
		{
			message = get_test_title("testing with an list of %d numbers: ");
			ft_printf(message, numbers_qty);
			free(message);
			doubled_list = linked_map(&list, map_fn);
			i = 0;
			doubled_node = doubled_list->head;
			normal_node = list->head;
			while (i++ < doubled_list->size)
			{
				doubled_content = (int *)doubled_node->content;
				normal_content = (int *)normal_node->content;
				test_print_result_multiple(*doubled_content
						/ 2 == *normal_content);
			}
		}
		linked_kill_list(&list, NULL);
		linked_kill_list(&doubled_list, free);
	}
}