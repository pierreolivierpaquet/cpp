# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:35:18 by ppaquet           #+#    #+#              #
#    Updated: 2024/01/30 11:12:38 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:=	AAnimal
NAME_MAJ	:=	AANIMAL

#******************************* MISCELLANEOUS ********************************#

FOLDER	:=	mkdir
REMOVE	:=	rm -rf

#******************************** COMPILATION *********************************#

COMPILER	:=	c++
FLAGS		:=	-Wall -Werror -Wextra -std=c++98

OUTPUT_NAME		:=	-o
BUILD_OBJECT	:=	-c

#********************************** SOURCES ***********************************#

SRC_PATH	:=	src/
SRC_FILES	:=	\
				main.cpp \
				AAnimal.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \
				Brain.cpp \

#********************************** OBJECTS ***********************************#

OBJ_PATH	:=	obj/
OBJ_FILES	:=	$(SRC_FILES:.cpp=.o)
OBJ			:=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

#********************************** INCLUDE ***********************************#

INCL_PATH	:=	include/
INCL		:=	-I $(INCL_PATH)

#*********************************** COLORS ***********************************#

RESET		:=	\033[0m

RED			:=	\033[31m
GREEN		:=	\033[32m
ORANGE		:=	\033[38;5;208m

BOLD		:= \033[1m

#*********************************** RULES ************************************#

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "\t$(ORANGE)Compiling...$(RESET)"
	@$(COMPILER) $(FLAGS) $(INCL) $(OBJ) $(OUTPUT_NAME) $@ 
	@echo "$(GREEN)\t$@ ready!$(RESET)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
	@echo "$@ object built with $<"
	@$(COMPILER) $(FLAGS) $(INCL) $(BUILD_OBJECT) $< $(OUTPUT_NAME) $@
	@printf "\033[1A\033[K"
	
$(OBJ_PATH):
	@$(FOLDER) $(OBJ_PATH)

clean:
	@if [ -d $(OBJ_PATH) ]; then\
		$(REMOVE) $(OBJ_PATH);\
		echo "\t$(GREEN)$(OBJ_PATH) directory deleted.$(RESET)";\
	else\
		echo "\t$(RED)$(OBJ_PATH) directory does not exist.$(RESET)";\
	fi;

fclean: clean
	@if [ -f $(NAME) ]; then\
		$(REMOVE) $(NAME);\
		echo "\t$(GREEN)$(NAME) executable deleted.$(RESET)";\
	else\
		echo "\t$(RED)$(NAME) executable does not exist.$(RESET)";\
	fi;

re: fclean all

.PHONY: all clean fclean re
