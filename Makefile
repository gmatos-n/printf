NAME			= libftprintf.a
CC				= cc
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re