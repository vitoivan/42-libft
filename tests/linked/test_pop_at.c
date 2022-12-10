#include "../tests.h"

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[linked_pop_at] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

void	test_linked_pop_at(void)
{
	t_linked *list;
	char *message;
	int numbers[5] = {123, 124, 5612, 213, 512};

	list = linked_new_list();
	linked_add_back(&list, linked_new_node(&numbers[0]));
	linked_add_back(&list, linked_new_node(&numbers[1]));
	linked_add_back(&list, linked_new_node(&numbers[2]));
	linked_add_back(&list, linked_new_node(&numbers[3]));
	linked_add_back(&list, linked_new_node(&numbers[4]));
	{
		ft_printf(COLOR_BOLD BLU "\nTesting linked_pop_at ..." REMOVE_BOLD RESET_COLOR "\n\n");
		{
			linked_pop_at(&list, 3, NULL);
			message = get_test_title("The list must decrease the size in 1 after pop: ");
			ft_printf(message);
			free(message);
			test_print_result(list->size == 4);
		}
		{
			message = get_test_title("The list must have the number \"%d\" in fourth position: ");
			ft_printf(message, numbers[4]);
			free(message);
			test_print_result(*(int *)list->head->next->next->next->content == numbers[4]);
		}
		{
			message = get_test_title("Looping throught the list starting from the head and returning to head: ");
			ft_printf(message);
			free(message);
			test_print_result(*(int *)list->head->next->next->next->next->content == *(int *)list->head->content);
		}
		{
			message = get_test_title("Looping throught the list starting from the tail and returning to tail: ");
			ft_printf(message);
			free(message);
			test_print_result(*(int *)list->tail->prev->prev->prev->prev->content == *(int *)list->tail->content);
		}
		{
			message = get_test_title("popping_at until the head and tail of the list be NULL: ");
			linked_pop_at(&list, 2, NULL);
			linked_pop_at(&list, 2, NULL);
			linked_pop_at(&list, 0, NULL);
			linked_pop_at(&list, 0, NULL);
			ft_printf(message);
			free(message);
			test_print_result(list->head == NULL && list->tail == NULL);
		}
		{
			message = get_test_title("popping_at out of index: ");
			linked_pop_at(&list, 1232, NULL);
			linked_pop_at(&list, -123, NULL);
			linked_pop_at(&list, 2, NULL);
			linked_pop_at(&list, 0, NULL);
			ft_printf(message);
			free(message);
			test_print_result(list->head == NULL && list->tail == NULL);
		}
		linked_kill_list(&list, NULL);
	}
}