NAME = pipex
CC = gcc
CFLAGC = -Wall -Wextra -Werror
SRC_PATH = src
HEADER = includes
OBJ_PATH = objs
SOURCES = errors.c\
          free.c\
		  main.c\
		  pipex_utils.c
SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all: lib tmp $(NAME)

lib: 
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C ./$(HEADER)/libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGC) -L./$(HEADER)/libft -o $@ $^ -lft
	@echo "$(GREEN)Project successfully compiled"

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/pipex.h
	@$(CC) $(CFLAGC) -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)rm .o files$(CYAN)"
	@make -C $(HEADER)/libft clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_PATH)
	@make -C $(HEADER)/libft fclean
	@echo "$(RED)rm perfoming file$(CYAN)"

re: fclean all

.PHONY: re, clean, fclean
