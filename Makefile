NAME = execute

CC        =     clang
CFLAGS    =    -Wall\
			-Wextra\
			-Werror\
			-D BUFFER_SIZE=42

HEADERS    =    get_next_line.h

SRC        =     get_next_line.c\
			get_next_line_utils.c

OBJ        =    a.out

all: $(NAME)

$(NAME): clean $(OBJ)
	./$(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $(OBJ) $(SRC) main.c

norm: $(SRC)
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEADERS)

clean:
	rm -f $(OBJ)

re: clean all

.PHONY: all norm clean re