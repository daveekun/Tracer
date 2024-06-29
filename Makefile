NAME = tracer

LIB_DIR = libs/
LIB = $(addprefix $(LIB_DIR), glad.c)
LIB_OBJ = $(addprefix $(LIB_DIR), $(notdir $(LIB:.c=.o)))
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), App.cpp DemoApp.cpp main.cpp)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.cpp=.o)))

FLAGS = -Iinclude --std=c++20 #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB_OBJ) $(OBJ) 
	c++ $(FLAGS) $(OBJ) $(LIB_OBJ) -ldl -lglfw -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	c++ $(FLAGS) -c $< -o $@

$(LIB_DIR)%.o: $(LIB_DIR)%.c
	c++ $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all