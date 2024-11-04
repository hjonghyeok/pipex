NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= ft_printf.c ft_printf_util.c ft_printf_addr.c

BSRCS	=

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $(SRCS) -I.

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR) bonus
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $@ $?

bonus :

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
