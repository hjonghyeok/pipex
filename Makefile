NAME		= pipex
PRINTFDIR	= ./ft_printf
PRINTFFILE	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	= 	main.c						\
			utils/path.c				\
			utils/free_memory.c			\
			utils/print_error.c			\
			utils/pipex_split.c			\
			pipe/pipe.c

BSRCS	=

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(OBJS) -L./ft_printf -lftprintf -o $(NAME)

bonus :

all : $(NAME)

clean :
	make -C $(PRINTFDIR) fclean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
