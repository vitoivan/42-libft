#include "../tests.h"

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[linked_pop_last] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

void	test_linked_pop_last(void)
{
	t_linked *list;
	int first_insert = 5123;
	int second_insert = 345;
	char *message;
	int numbers[5] = {123, 124, 5612, 213, 512};

	list = linked_new_list();
	linked_add_back(&list, linked_new_node(&first_insert));
	linked_add_back(&list, linked_new_node(&second_insert));
	{
		ft_printf(COLOR_BOLD BLU "\nTesting linked_pop_last ..." REMOVE_BOLD RESET_COLOR "\n\n");
		{
			linked_pop_last(&list, NULL);
			message = get_test_title("The list must decrease the size in 1 after pop: ");
			ft_printf(message);
			free(message);
			test_print_result(list->size == 1);
		}
		{
			message = get_test_title("The first item of the list next and prev pointers must appoint to NULL: ");
			ft_printf(message);
			free(message);
			test_print_result(list->head->next == NULL
					&& list->head->prev == NULL);
		}
		{
			message = get_test_title("The content of the first item must be \"%d\": ");
			ft_printf(message, first_insert);
			free(message);
			test_print_result(first_insert == *(int *)list->head->content);
		}
		{
			linked_pop_last(&list, NULL);
			message = get_test_title("The size must be zero after the second pop: ");
			ft_printf(message);
			free(message);
			test_print_result(list->size == 0);
		}
		{
			linked_pop_last(&list, NULL);
			message = get_test_title("The head and tail must appoint to NULL: ");
			ft_printf(message);
			free(message);
			test_print_result(list->head == NULL && list->tail == NULL);
		}
		linked_kill_list(&list, NULL);
	}

	{
		list = linked_new_list();
		linked_add_back(&list, linked_new_node((void *)&numbers[0]));
		linked_add_back(&list, linked_new_node((void *)&numbers[1]));
		linked_add_back(&list, linked_new_node((void *)&numbers[2]));
		linked_add_back(&list, linked_new_node((void *)&numbers[3]));
		linked_add_back(&list, linked_new_node((void *)&numbers[4]));
		ft_printf(COLOR_BOLD MAG "\n\n\tTesting with five items list" REMOVE_BOLD RESET_COLOR "\n\n");
		{
			linked_pop_last(&list, NULL);
			linked_pop_last(&list, NULL);
			message = get_test_title("The size of the list must be 3: ");
			ft_printf(message);
			free(message);
			test_print_result(list->size == 3);
		}
		{
			message = get_test_title("The first item of the list must be \"%d\": ");
			ft_printf(message, numbers[0]);
			free(message);
			test_print_result(*(int *)list->head->content == numbers[0]);
		}
		{
			message = get_test_title("The last item of the list must be \"%d\": ");
			ft_printf(message, numbers[2]);
			free(message);
			test_print_result(*(int *)list->tail->content == numbers[2]);
		}
		{
			message = get_test_title("Access the first item from the last one: ");
			ft_printf(message);
			free(message);
			test_print_result(*(int *)list->tail->next->content == numbers[0]);
		}
		{
			message = get_test_title("Access the last item from the first one: ");
			ft_printf(message);
			free(message);
			test_print_result(*(int *)list->head->prev->content == numbers[2]);
		}
		linked_kill_list(&list, NULL);
	}
}