# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 12:10:25 by ppaquet           #+#    #+#              #
#    Updated: 2023/12/20 12:37:00 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phonebook

# ****************************** MISCELLANEOUS ******************************* #

FOLDER := mkdir
REMOVE := rm -rf

# ******************************* COMPILATION ******************************** #

COMPILE := g++ -std=c++98
FLAGS := -Wall -Werror -Wextra

# ********************************* SOURCES ********************************** #

SRC_PATH := src/
SRC_FILES := \
				main.cpp \
				Contact.cpp \
				Phonebook.cpp \

# ********************************* OBJECTS ********************************** #

OBJ_PATH := obj/
OBJ_FILES := $(SRC_FILES:.cpp=.o)
OBJ := $(addprefix $(OBJ_PATH), $(OBJ_FILES))

# ********************************* INCLUDE ********************************** #

INCL_PATH := include/
INCL := -I $(INCL_PATH)

# **************************************************************************** #
# ********************************** RULES *********************************** #

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(COMPILE) $(FLAGS) $(OBJ) $(INCL) -o $(NAME)

$(OBJ_PATH):
	@$(FOLDER) $(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
	@$(COMPILE) $(FLAGS) $(INCL) -o $@ -c $<

clean:
	@$(REMOVE) $(OBJ_PATH)
	
fclean: clean
	@$(REMOVE) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
