# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 09:39:25 by ppaquet           #+#    #+#              #
#    Updated: 2024/01/11 13:03:36 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	Harl

# ****************************** MISCELLANEOUS ******************************* #

FOLDER	:=	mkdir
REMOVE	:=	rm -rf

# ******************************* COMPILATION ******************************** #

COMPILE			:=	g++
FLAGS			:=	-std=c++98 -Wall -Werror -Wextra
OUTPUT_FILENAME	:=	-o
BUILD_OBJECT	:=	-c

EXECUTABLE_COMPILED	:= 	0
EXECUTABLE_STATUS	:=	0

# ********************************* SOURCES ********************************** #

SRC_PATH	:=	src/
SRC_FILES	:=	\
				main.cpp \
				Harl.cpp \

# ********************************* OBJECTS ********************************** #

OBJ_PATH	:=	obj/
OBJ_FILES	:=	$(SRC_FILES:.cpp=.o)
OBJ			:=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

# ********************************* INCLUDE ********************************** #

INCL_PATH	:=	include/
INCL		:=	-I $(INCL_PATH)

# **************************************************************************** #
# ********************************** RULES *********************************** #

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "\tCompiling..."
	@$(COMPILE) $(FLAGS) $(INCL) $(OUTPUT_FILENAME) $@ $(OBJ)
	@echo "\t./$@ ready."

$(OBJ_PATH):
	@$(FOLDER) $(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
	@echo "\tCreating $@ from $<"
	@$(COMPILE) $(FLAGS) $(INCL) $(OUTPUT_FILENAME) $@ $(BUILD_OBJECT) $<
	@printf "\033[1A\033[K"

clean:
	@$(REMOVE) $(OBJ_PATH)
	@echo "\tObjects removed."

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "\t$(NAME) executable removed."

re: fclean all

.PHONY: all re clean fclean
