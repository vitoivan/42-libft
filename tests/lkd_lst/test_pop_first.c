#include "../tests.h"

static char	*get_test_title(char *message)
{
	char	*prefix;

	prefix = COLOR_BOLD BLU "\t[lkd_lst_pop_first] " RESET_COLOR REMOVE_BOLD;
	return (ft_strjoin(prefix, message));
}

void	test_lkd_lst_pop_first(void)
{
	t_lkd_lst *list;
	int first_insert = 5123;
	int second_insert = 345;
	char *message;
	int numbers[5] = {123, 124, 5612, 213, 512};

	list = lkd_lst_new_list();
	lkd_lst_add_back(&list, lkd_lst_new_node(&first_insert));
	lkd_lst_add_back(&list, lkd_lst_new_node(&second_insert));
	{
		ft_printf(COLOR_BOLD BLU "\nTesting lkd_lst_pop_first " REMOVE_BOLD RESET_COLOR "\n\n");

		ft_printf(COLOR_BOLD MAG "\tTesting with two items list" REMOVE_BOLD RESET_COLOR "\n\n");
		{
			lkd_lst_pop_first(&list, NULL);
			message = get_test_title("The list must decrease the size in 1 after pop: ");
			ft_printf(message);
			free(message);
			test_print_result(list->size == 1);
		}
		{
			message = get_test_title("The second item of the list next and prev pointers must appoint to NULL: ");
			ft_printf(message);
			free(message);
			test_print_result(list->tail->next == NULL
					&& list->tail->prev == NULL);
		}
		{
			message = get_test_title("The content of the first item must be \"%d\": ");
			ft_printf(message, second_insert);
			free(message);
			test_print_result(second_insert == *(int *)list->head->content);
		}
		{
			lkd_lst_pop_first(&list, NULL);
			message = get_test_title("The size must be zero after the second pop: ");
			ft_printf(message);
			free(message);
			test_print_result(list->size == 0);
		}
		{
			lkd_lst_pop_first(&list, NULL);
			message = get_test_title("The head and tail must appoint to NULL: ");
			ft_printf(message);
			free(message);
			test_print_result(list->head == NULL && list->tail == NULL);
		}
		lkd_lst_kill_list(&list, NULL);
	}
	{
		list = lkd_lst_new_list();
		lkd_lst_add_back(&list, lkd_lst_new_node((void *)&numbers[0]));
		lkd_lst_add_back(&list, lkd_lst_new_node((void *)&numbers[1]));
		lkd_lst_add_back(&list, lkd_lst_new_node((void *)&numbers[2]));
		lkd_lst_add_back(&list, lkd_lst_new_node((void *)&numbers[3]));
		lkd_lst_add_back(&list, lkd_lst_new_node((void *)&numbers[4]));
		ft_printf(COLOR_BOLD MAG "\n\n\tTesting with five items list" REMOVE_BOLD RESET_COLOR "\n\n");
		{
			unsigned int old_size = list->size;
			lkd_lst_pop_first(&list, NULL);
			message = get_test_title("The list must decrease the size in 1 after pop: ");
			ft_printf(message);
			free(message);
			test_print_result(list->size == old_size - 1);
		}
		{
			message = get_test_title("The first item of the list must be \"%d\": ");
			ft_printf(message, numbers[1]);
			free(message);
			test_print_result(*(int *)list->head->content == numbers[1]);
		}
		{
			lkd_lst_pop_first(&list, NULL);
			message = get_test_title("The first item of the list aflter the second pop must be \"%d\": ");
			ft_printf(message, numbers[2]);
			free(message);
			test_print_result(*(int *)list->head->content == numbers[2]);
		}
		{
			message = get_test_title("The size of the list must be 3: ");
			ft_printf(message);
			free(message);
			test_print_result(list->size == 3);
		}
		{
			message = get_test_title("Access the first item from the last one: ");
			ft_printf(message);
			free(message);
			test_print_result(*(int *)list->tail->next->content == numbers[2]);
		}
		{
			message = get_test_title("Access the last item from the first one: ");
			ft_printf(message);
			free(message);
			test_print_result(*(int *)list->head->prev->content == numbers[4]);
		}
		lkd_lst_kill_list(&list, NULL);
	}
}