NAME = execute

CC        =     clang
CFLAGS    =    -Wall\
			-Wextra\
			-Werror\
			-D BUFFER_SIZE=42

HEADERS        =    get_next_line.h
HEADERSB    =    get_next_line_bonus.h

SRC        =     get_next_line.c\
			get_next_line_utils.c
SRCB    =     get_next_line_bonus.c\
			get_next_line_utils_bonus.c

OBJ        =    run

all: $(NAME)

$(NAME): clean $(OBJ)
	./$(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $(OBJ) $(SRC) main.c

norm: $(SRC)
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEADERS) $(SRCB) $(HEADERSB)

clean:
	rm -f $(OBJ)

re: clean all

.PHONY: all norm clean re