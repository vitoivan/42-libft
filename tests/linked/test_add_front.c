#include "../tests.h"

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[linked_add_front] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

void	test_linked_add_front(void)
{
	int first_insert = 32312;
	int second_insert = 123;
	int third_insert = 45;
	int *content;
	char *message;

	t_linked *linked = linked_new_list();
	// Testing one item on list
	{
		linked_add_front(&linked, linked_new_node((void *)&first_insert));

		ft_printf(COLOR_BOLD BLU "\nTesting linked_add_front ..." REMOVE_BOLD RESET_COLOR "\n\n");

		ft_printf(COLOR_BOLD MAG "\tTesting with one item" REMOVE_BOLD RESET_COLOR "\n\n");
		{
			message = get_test_title("should increase size of list in one: ");
			ft_printf(message);
			free(message);
			test_print_result(linked->size == 1);
		}
		{
			message = get_test_title("The content of the first item of the list must be \"%d\": ");
			ft_printf(message, first_insert);
			free(message);
			content = (int *)linked->head->content;
			test_print_result(*content == first_insert);
		}
		{
			message = get_test_title("The content of the last item of the list must be \"%d\": ");
			ft_printf(message, first_insert);
			free(message);
			content = (int *)linked->tail->content;
			test_print_result(*content == first_insert);
		}
	}

	// Testing two items on list
	{
		linked_add_front(&linked, linked_new_node((void *)&second_insert));
		ft_printf(COLOR_BOLD MAG "\n\n\tTesting with two items" REMOVE_BOLD RESET_COLOR "\n\n");
		{
			message = get_test_title("should have the size of two: ");
			ft_printf(message);
			free(message);
			test_print_result(linked->size == 2);
		}
		{
			message = get_test_title("The content of the first item of the list must be \"%d\": ");
			ft_printf(message, second_insert);
			free(message);
			content = (int *)linked->head->content;
			test_print_result(*content == second_insert);
		}
		{
			message = get_test_title("The content of the second item of the list must be \"%d\": ");
			content = (int *)linked->head->next->content;
			ft_printf(message, first_insert);
			free(message);
			test_print_result(*content == first_insert);
		}
		{
			message = get_test_title("The content of the tail of the list must be \"%d\": ");
			ft_printf(message, first_insert);
			free(message);
			content = (int *)linked->tail->content;
			test_print_result(*content == first_insert);
		}
		{
			message = get_test_title("The last item of the list must appoint to the first using the next pointer: ");
			ft_printf(message);
			free(message);
			content = (int *)linked->tail->next->content;
			test_print_result(*content == second_insert);
		}
		{
			message = get_test_title("The last item of the list must appoint to the first using the previous pointer: ");
			ft_printf(message);
			free(message);
			content = (int *)linked->tail->prev->content;
			test_print_result(*content == second_insert);
		}
	}
	// Test with three items
	{
		ft_printf(COLOR_BOLD MAG "\n\n\tTesting with three items" REMOVE_BOLD RESET_COLOR "\n\n");
		linked_add_front(&linked, linked_new_node((void *)&third_insert));
		{
			message = get_test_title("The list must have size of three: ");
			ft_printf(message);
			free(message);
			test_print_result(linked->size == 3);
		}
		{
			message = get_test_title("The first item of the list must be \"%d\": ");
			ft_printf(message, third_insert);
			free(message);
			content = (int *)linked->head->content;
			test_print_result(*content == third_insert);
		}
		{
			message = get_test_title("The second item of the list must be \"%d\": ");
			ft_printf(message, second_insert);
			free(message);
			content = (int *)linked->head->next->content;
			test_print_result(*content == second_insert);
		}
		{
			message = get_test_title("The last item of the list must be \"%d\": ");
			ft_printf(message, third_insert);
			free(message);
			content = (int *)linked->tail->content;
			test_print_result(*content == first_insert);
		}
		{
			message = get_test_title("The next pointer of the third item of the list must appoint to the first item of the list: ");
			ft_printf(message);
			free(message);
			content = (int *)linked->tail->next->content;
			test_print_result(*content == third_insert);
		}
		{
			message = get_test_title("The prev pointer of the first item of the list must appoint to the third item of the list: ");
			ft_printf(message);
			free(message);
			content = (int *)linked->head->prev->content;
			test_print_result(*content == first_insert);
		}
		{
			message = get_test_title("Getting the third item of the list starting from head: ");
			ft_printf(message);
			free(message);
			content = (int *)linked->head->next->next->content;
			test_print_result(*content == first_insert);
		}
		{
			message = get_test_title("Getting the first item of the list starting from tail: ");
			ft_printf(message);
			free(message);
			content = (int *)linked->tail->prev->prev->content;
			test_print_result(*content == third_insert);
		}
		{
			message = get_test_title("Looping the entire list starting from the head and stopping in the head: ");
			ft_printf(message);
			free(message);
			content = (int *)linked->head->next->next->next->content;
			test_print_result(*content == third_insert);
		}
	}
	linked_kill_list(&linked, NULL);
}