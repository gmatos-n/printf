NAME			= libftprintf.a
CC				= cc
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re