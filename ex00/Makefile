# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 12:10:22 by ppaquet           #+#    #+#              #
#    Updated: 2023/12/19 15:29:45 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex00

# ****************************** MISCELLANEOUS ******************************* #

FOLDER := mkdir
REMOVE := rm -rf

# ******************************* COMPILATION ******************************** #

COMPILE := g++ -std=c++98
FLAGS := -Wall -Werror -Wextra

# ********************************* SOURCES ********************************** #

SRC_PATH := src/
SRC_FILES := \
				megaphone.cpp \

# ********************************* OBJECTS ********************************** #

OBJ_PATH := obj/
OBJ_FILES := $(SRC_FILES:.cpp=.o)
OBJ := $(addprefix $(OBJ_PATH), $(OBJ_FILES))

# **************************************************************************** #
# ********************************** RULES *********************************** #

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(COMPILE) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	@$(FOLDER) $(OBJ_PATH)

$(OBJ_PATH)%.o:%.cpp
	@$(COMPILE) $(FLAGS) -o $@ -c $<

clean:
	@$(REMOVE) $(OBJ_PATH)
	
fclean: clean
	@$(REMOVE) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
