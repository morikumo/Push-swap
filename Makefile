SRCS		= 	./srcs/action_stack_a_b.c ./srcs/action_stack_a.c \
				./srcs/action_stack_b.c ./srcs/ft_manual-tri.c \
				./srcs/algo.c ./srcs/error.c ./srcs/ft_split.c ./srcs/utils_error.c \
				./srcs/parsing.c ./srcs/utils_algo.c ./srcs/utils_manual_tri.c \
				./srcs/utils_action.c ./srcs/utils_libft.c ./srcs/push_swap.c \

OBJS			= $(SRCS:.c=.o)

NAME			= push_swap

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 


$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.

all:			$(NAME)

clean:
				@$(RM) $(OBJS)

fclean:			clean

re:				fclean all

normin:			
	norminette	./srcs

wnormin: 		
	watch norminette	./srcs

.PHONY:			all clean fclean c.o re

-fsanitize=address -g3