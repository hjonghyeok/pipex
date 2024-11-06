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
			pipe/pipe.c					\
			pipe/basic_pipe.c			\

BSRCS 	= 	main_bonus.c				\
			utils/path.c				\
			utils/free_memory.c			\
			utils/print_error.c			\
			utils/pipex_split.c			\
			pipe/pipe.c					\
			pipe/basic_pipe.c			\
			bonus/bonus_pipe.c			\
			bonus/here_doc.c			\
			bonus_utils/read_std.c		\


MOBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

ifndef BONUS
	OBJS = $(SRCS:.c=.o)
else
	OBJS = $(BSRCS:.c=.o)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(OBJS) -L./ft_printf -lftprintf -o $(NAME)

bonus :	
	make BONUS=1

all : $(NAME)

clean :
	make -C $(PRINTFDIR) fclean
	$(RM) $(MOBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
