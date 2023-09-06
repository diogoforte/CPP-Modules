BLUE = \033[0;94m
GREEN = \e[1;92m
RED = \033[0;91m
RESET = \033[1;30m
WHITE = \033[1;97m
YELLOW = \033[1;33m

NAME = sed
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98

INC = -I ./inc/
SRC_PATH = src/
OBJ_PATH = obj/

SRC = $(wildcard $(SRC_PATH)*.cpp)

OBJ = $(SRC:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

all: $(SRC_PATH) $(INC_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp | $(OBJ_PATH) $(SRC_PATH) $(INC_PATH)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "🔨	$(BLUE)Compiling $(WHITE)$(NAME)	$(BLUE)%-33s$(WHITE)\r" $(notdir $@)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n📦	$(WHITE)$(NAME)$(RESET)		$(YELLOW)compiled$(WHITE)"

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️	$(WHITE)$(NAME)$(RESET)		$(RED)removed$(WHITE)"

re: fclean all

dir:
	@mkdir -p $(SRC_PATH)
	@mkdir -p inc/
	@echo "📁	src/			$(GREEN)created$(WHITE)"
	@echo "📁	inc/			$(GREEN)created$(WHITE)"

.PHONY: all re clean fclean dir