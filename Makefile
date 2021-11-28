NAME = philo

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
HEADER = header/philo.h
SRCS = 	$(shell find . -name "*.c")

OBJ = $(@SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ)
	@echo "[Removing last version...]"
	@rm -rf philo
	@echo "[philo compilation...]"
	@$(CC) $(SRCS) $(HEADER) $(FLAGS) -o $(NAME)
	@echo "[Done!]"
	@$(MAKE) clean

all : $(NAME)

norm:
	@norminette $(FILES)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all