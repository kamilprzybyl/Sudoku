CC 			= gcc
CFLAGS 		= -c -Wall -Wextra -Werror
NAME 		= sudoku.a
SRCS 		= src/sudoku_solver.c

OBJS 		= $(SRCS:.s=.o)
BUILT 		= echo "\033[32m$@ built!\033[0m"

all: $(NAME)	# if library $(NAME) doesn't exist - create!

%.o: %.c
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME): $(OBJS)	# $(OBJS) stands for all the files with .o extension
	@ar -rc $@ $^
	@$(BUILT)
	
test:
	@$(CC) src/main.c -L. $(NAME) -o $@

clean:
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME) test

re: fclean all

.PHONY: all clean fclean re