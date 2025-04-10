NAME = templates

CC					=	c++
CC_STRICT 			=	$(CC) $(CCF_STRICT)
DB_FLAGS			=	-g
OBJ_DIR				=	./obj
SRC_DIR				=	.

CCF_STRICT			=	-std=c++17 -Wall -Wextra -Werror -g

SRCS				=	 \
						main.cpp \

OBJECTS				=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

vpath %.cpp $(SRC_DIR)

################################################################################
# REQUIRED
################################################################################

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC_STRICT) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC_STRICT) -c $< -o $@

re: fclean all

################################################################################
# TEST
################################################################################

test: $(NAME)
	@echo "$(BLUE)Running tests... $(RESET)"
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: converting integer 0 $(RESET)"
	@./$(NAME) 0
	@echo "$(GREEN)Test: converting integer -42 $(RESET)"
	@./$(NAME) -42
	@echo "$(GREEN)Test: converting integer 167 $(RESET)"
	@./$(NAME) 167
	@echo "$(GREEN)Test: converting char c $(RESET)"
	@./$(NAME) \'c\'
	@echo "$(GREEN)Test: converting float 42.0f $(RESET)"
	@./$(NAME) 42.0f
	@echo "$(GREEN)Test: converting float -4.2f $(RESET)"
	@./$(NAME) -4.2f
	@echo "$(GREEN)Test: converting double -138.456 $(RESET)"
	@./$(NAME) -138.456
	@echo "$(GREEN)Test: converting double 111.544 $(RESET)"
	@./$(NAME) 111.544
	@echo "$(GREEN)Test: converting int 23434621 (float inaccuracy showing) $(RESET)"
	@./$(NAME) 23434621
	@echo "$(GREEN)Test: converting int max 2147483647 $(RESET)"
	@./$(NAME) 2147483647
	@echo "$(GREEN)Test: converting int min -2147483648 $(RESET)"
	@./$(NAME) -2147483648
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: converting double nan $(RESET)"
	@./$(NAME) nan
	@echo "$(GREEN)Test: converting double +inf $(RESET)"
	@./$(NAME) +inf
	@echo "$(GREEN)Test: converting double -inf $(RESET)"
	@./$(NAME) -inf
	@echo "$(GREEN)Test: converting double +inff $(RESET)"
	@./$(NAME) +inf
	@echo "$(GREEN)Test: converting double -inff $(RESET)"
	@./$(NAME) -inf
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 2147483648 (INT_MAX overflow) $(RESET)"
	@./$(NAME) 2147483648
	@echo "$(GREEN)Test: -2147483649 (INT_MIN underflow)$(RESET)"
	@./$(NAME) -2147483649
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 4.9e38 (FLT_MAX 3.4e+38 overflow)$(RESET)"
	@./$(NAME) 490000000000000000000000000000000000000.0f
	@echo "$(GREEN)Test: -4.9e38 (FLT_MAX -3.4e+38 underflow)$(RESET)"
	@./$(NAME) -490000000000000000000000000000000000000.0f
	@echo "$(GREEN)Test: 2.2e-38 (FLT_MIN 1.17e-38 underflow)$(RESET)"
	@./$(NAME) 2.2e-38
	@echo "$(GREEN)Test: -2.2e-38 (FLT_MIN -1.17e-38 underflow)$(RESET)"
	@./$(NAME) -2.2e-38
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 2.1e308 (DBL_MAX 1.79e+308 overflow)$(RESET)"
	@./$(NAME) 2.1e308
	@echo "$(GREEN)Test: -2.1e308 (DBL_MAX -1.79e+308 underflow)$(RESET)"
	@./$(NAME) -2.1e308
	@echo "$(GREEN)Test: 2.1e-308 (DBL_MIN 2.22e-308 underflow)$(RESET)"
	@./$(NAME) 2.1e-308
	@echo "$(GREEN)Test: -2.1e-308 (DBL_MIN -2.22e-308 underflow)$(RESET)"
	@./$(NAME) -2.1e-308
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: INVALID CASES $(RESET)"
	@echo "$(GREEN)Test: Invalid Integer Literal: 1.ab $(RESET)"
	@./$(NAME) 1.ab
	@echo "$(GREEN)Test: Invalid Double Literal: .123 $(RESET)"
	@./$(NAME) .123
	@echo "$(GREEN)Test: Invalid Float Literal: .123f $(RESET)"
	@./$(NAME) .123f
	@echo "$(GREEN)Test: Invalid Float Literal: .f $(RESET)"
	@./$(NAME) .f
	@echo "$(GREEN)Test: Invalid Float Literal with Characters: 1.fab $(RESET)"
	@./$(NAME) 1.fab
	@echo "$(GREEN)Test: Invalid Negative Float Literal: -0f $(RESET)"
	@./$(NAME) -0f
	@echo "$(GREEN)Test: Invalid Negative Float Literal: -0.f $(RESET)"
	@./$(NAME) -0.f

	@echo "--------------------------------------------"

################################################################################
# CLEAN
################################################################################

clean:
	rm -rf ./obj

fclean: clean
	rm -rf $(NAME)

################################################################################
# PHONY
################################################################################

.PHONY: all re clean fclean run

GREEN = \033[0;32m
RESET = \033[0m
BLUE = \033[34m
