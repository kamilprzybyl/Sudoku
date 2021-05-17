CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
NAME 		= sudoku_solver
SRCS 		= src/sudoku_solver.c \
			  src/main.c

all: $(NAME)	

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $@

run:
	@./$(NAME)

clean:
	@/bin/rm -rf $(NAME)

re: clean all

.PHONY: all clean re