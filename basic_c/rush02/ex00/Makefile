NAME = rush-02

MY_SOURCES =	handle_error.c \
				handle_file.c \
				handle_nb.c \
				main.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS) #norminette
	cc $(CFLAGS) -o $(NAME) $(MY_SOURCES)

norminette:
	norminette -R CheckForbiddenSourceHeader *.c

fc_clean:
	rm -f $(MY_OBJECTS)
