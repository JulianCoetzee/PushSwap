# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 11:43:17 by jcoetzee          #+#    #+#              #
#    Updated: 2019/08/28 10:10:12 by jcoetzee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker

NAME_2 = push_swap

LIB_PATH = ./libft/

FLAGS = -Wall -Werror -Wextra

SRCS_PATH = ./srcs/

OBJS_PATH = ./objs/

OBJS_DIR = objs

CHECKER_SRCS = $(NAME_1).c\
			   apply_instruct_check.c\
			   apply_revrot_check.c\
			   apply_rot_check.c\
			   build_stacks.c\
			   sort_free.c\

PUSH_SWAP_SRCS = $(NAME_2).c\
				 apply_instruct.c\
				 apply_revrot.c\
				 apply_rot.c\
				 build_stacks.c\
				 find_rot.c\
				 large_sort.c\
				 least_moves.c\
				 sort_free.c\
				 sort_help.c\

CHECKER_C = $(addprefix $(OBJS_PATH), $(CHECKER_SRC))

PUSH_SWAP_C = $(addprefix $(OBJS_PATH), $(PUSH_SWAP__SRCS))

CHECKER_O = $(patsubst %.c, %.o, $(CHECKER_C))

PUSH_SWAP_O = $(patsubst %.c, %.o, $(PUSH_SWAP_C))

all: $(NAME_1) $(NAME_2)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

libft:
	@$(MAKE) -C $(LIB_PATH)/

$(NAME_1): $(OBJS_DIR) $(CHECKER_O) libft
	@gcc $(FLAGS) $(CHECKER_O) -L $(LIB_PATH) -lft -o $(NAME_1)
	@echo "NAME_1 created"
	
$(NAME_2): $(OBJS_DIR) $(PUSH_SWAP_O) libft
	@gcc $(FLAGS) $(PUSH_SWAP_O) -L $(LIB_PATH) -lft -o $(NAME_2)
	@echo "NAME_2 created"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB_PATH)/ clean
	@rm -rf $(OBJS_DIR)
	@echo "objs deleted"

fclean:
	@$(MAKE) -C $(LIB_PATH)/ fclean
	@rm -rf $(OBJS_DIR)
	@echo "objs deleted"
	@rm -f $(NAME_1) $(NAME_2)
	@echo "$(NAME_1) & $(NAME_2) deleted"

re: fclean all

.PHONY: all clean fclean libft re
