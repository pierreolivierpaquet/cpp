# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 13:47:44 by ppaquet           #+#    #+#              #
#    Updated: 2024/01/09 17:52:47 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= Weapon

# ****************************** MISCELLANEOUS ******************************* #

FOLDER	:= mkdir
REMOVE	:= rm -rf

# ******************************* COMPILATION ******************************** #

COMPILE	:= g++
FLAGS	:= -Wall -Werror -Wextra -std=c++98

# ********************************* SOURCES ********************************** #

SRC_PATH	:=  src/
SRC_FILES	:= \
				HumanA.cpp \
				HumanB.cpp \
				main.cpp \
				Weapon.cpp \

# ********************************* OBJECTS ********************************** #

OBJ_PATH	:= obj/
OBJ_FILES	:= $(SRC_FILES:.cpp=.o)
OBJ			:= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

# ********************************* INCLUDE ********************************** #

INCL_PATH	:= include/
INCL 		:= -I $(INCL_PATH)

# **************************************************************************** #
# ********************************** RULES *********************************** #

all: $(NAME)
	@echo "\t./$< ready."

$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "\tCompiling"
	@$(COMPILE) $(FLAGS) $(INCL) $(OBJ) -o $@

$(OBJ_PATH):
	@$(FOLDER) $(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
	@echo "\t$@ created."
	@$(COMPILE) $(FLAGS) $(INCL) -o $@ -c $<
	@printf "\033[1A\033[K"

clean:
	@$(REMOVE) $(OBJ_PATH)
	@echo "\tObjects removed."

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "\t$(NAME) executable removed."
	
re: fclean all

.PHONY: all re clean fclean