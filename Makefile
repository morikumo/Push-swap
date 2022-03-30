SRCS		= 	./srcs/action_stack_a_b.c ./srcs/action_stack_a.c \
				./srcs/action_stack_b.c ./srcs/ft_manual-tri.c \
				./srcs/algo.c ./srcs/error.c ./srcs/ft_split.c \
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
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L. -g
				@echo -ne '\033[32m                            (0%)\r'
				@sleep 1
				@echo -ne '#####                      (33%)\r'
				@sleep 1
				@echo -ne '#############              (66%)\r'
				@sleep 1
				@echo -ne '#######################   (100%)\r'
				@echo -ne '\n'
				@echo "\033[33mC'est compilé !"

all:			$(NAME)

clean:
				@$(RM) $(OBJS)
				@echo -ne '\033[36m#######################   (100%)\r'
				@sleep 1
				@echo -ne '#############              (66%)\r'
				@sleep 1
				@echo -ne '#####                      (33%)\r'
				@sleep 1
				@echo -ne '                            (0%)\r'
				@echo -ne '\n'
				@echo "\033[33mC'est clean !"

fclean:			clean
				@$(RM) $(NAME) 
				@echo -ne '\033[34m#######################   (100%)\r'
				@sleep 1
				@echo -ne '#############              (66%)\r'
				@sleep 1
				@echo -ne '#####                      (33%)\r'
				@sleep 1
				@echo -ne '                            (0%)\r'
				@echo -ne '\n'
				@echo "\033[33mC'est fclean !"

re:				fclean all

normin:			
	norminette	./srcs

wnormin: 		
	watch norminette	./srcs

.PHONY:			all clean fclean c.o re