NAME     =	push_swap

DIR 	 =  src/

SRC	     =	src/add_value_to_stack_a.c \
			src/algo_oper.c src/algo_spe.c \
			src/algo_utils.c\
			src/algo.c \
			src/algo2.c \
			src/check_parsing.c src/free_exit.c src/ft_printf_utils_2.c src/ft_printf_utils.c \
			src/ft_printf.c src/main.c src/operations_p.c src/operations_s.c src/operations_r.c \
			src/operations_rr.c src/remap_stack.c src/utils.c 


CC       =	    cc

CFLAGS   =	    -Wall -Wextra -Werror -g3 -I./inc 

OBJ_DIR	 =	    obj/

SRCS     =      $(SRC)

OBJ 	 =      $(patsubst src/%.c, $(OBJ_DIR)%.o, $(SRCS))

MAKE_DIR =      mkdir -p

SMAKE	 =      make --no-print-directory

$(OBJ_DIR)%.o:  src/%.c
				@$(MAKE_DIR) $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@

all:	        $(NAME)

$(NAME):        $(OBJ)
				@$(CC) $(CFLAGS) $(OBJ) -o $@ -lreadline
				@echo "\033[1;92m======== project compiled ========\033[0m"

clean:
				@rm -rf $(OBJ_DIR)
				@echo "\033[1;35m======== object files removed ========\033[0m"

fclean:         clean
				@$(RM) $(NAME)
				@echo "\033[1;36m======== executable removed  =======\033[0m"

re:             fclean all

.PHONY: clean fclean all re