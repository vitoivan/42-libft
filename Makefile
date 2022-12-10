CC = clang
AR = ar -crs
CFLAGS = -Wall -Wextra -Werror -c -g
LFLAGS = -L. -lft
NAME = libft.a

TARGET = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strcmp.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

PRINTF_TARGET = ft_printf/ft_helpers.c ft_printf/ft_itohex.c ft_printf/ft_print_arg.c ft_printf/ft_print_char.c  ft_printf/ft_print_conversion.c ft_printf/ft_print_hex.c ft_printf/ft_print_ptr.c ft_printf/ft_print_signed_digit.c ft_printf/ft_print_str.c ft_printf/ft_print_udigit.c ft_printf/ft_printf.c ft_printf/ft_uitoa.c

LINKED_TARGET = linked_add_back.c linked_add_front.c linked_new_node.c linked_new_list.c __linked_del_node.c linked_kill_list.c linked_map.c linked_filter.c linked_foreach.c utils.c linked_pop_first.c linked_pop_last.c

TESTS_TARGET = tests.c test_utils.c linked/test_add_back.c linked/test_add_front.c linked/test_kill_list.c linked/test_map.c linked/test_filter.c linked/test_pop_first.c linked/test_pop_last.c

LINKED = $(addprefix src/linked/,$(LINKED_TARGET:%.c=%.o))
SRC = $(addprefix src/,$(TARGET:%.c=%.o))
PRINTF = $(addprefix src/,$(PRINTF_TARGET:%.c=%.o))
TESTS = $(addprefix tests/,$(TESTS_TARGET:%.c=%.o))


DIR = dist

OBJS = $(addprefix ./$(DIR)/,$(SRC:%.c=%.o))
PRINTF_OBJS = $(addprefix ./$(DIR)/,$(PRINTF:%.c=%.o))
LINKED_OBJS = $(addprefix ./$(DIR)/,$(LINKED:%.c=%.o))
TESTS_OBJS = $(addprefix ./$(DIR)/,$(TESTS:%.c=%.o))

TEST_DIR = $(DIR)/tests

all: $(NAME)


test: $(NAME) $(TESTS_OBJS) $(TEST_DIR)
	$(CC) $(TESTS_OBJS) $(LFLAGS) -o test
	clear && valgrind --leak-check=full ./test
	@rm -f ./test

$(TEST_DIR)/%.o: ./tests/%.c
	$(CC) $(CFLAGS) $< -o $@

$(TEST_DIR)/linked/%.o: ./tests/linked/%.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(PRINTF_OBJS) $(LINKED_OBJS)
	$(AR) $(NAME) $(OBJS) $(PRINTF_OBJS) $(LINKED_OBJS)

$(DIR)/src/%.o: ./src/%.c $(DIR)
	$(CC) $(CFLAGS) $< -o $@

$(DIR)/ft_printf/%.o: ./src/ft_printf/%.c $(DIR) 
	$(CC) $(CFLAGS) $< -o $@

$(DIR)/src/linked/%.o: ./src/linked/%.c $(DIR) 
	$(CC) $(CFLAGS) $< -o $@

$(DIR):
	mkdir -p $(DIR)
	mkdir -p $(DIR)/src/ft_printf
	mkdir -p $(DIR)/src/linked
	mkdir -p $(DIR)/tests/linked

clean:
	rm -rf $(DIR)

fclean: clean
	rm -f  $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all bonus re test