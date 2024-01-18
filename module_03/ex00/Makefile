# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:28:28 by ppaquet           #+#    #+#              #
#    Updated: 2024/01/18 16:54:51 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ClapTrap
NAME_MAJ	:=	CLAPTRAP

#******************************** COMPILATION *********************************#

COMPILER		:=	c++
FLAGS			:=	-Wall -Werror -Wextra -std=c++98

BUILD_OBJECT	:=	-c
OUTFILE_NAME	:=	-o

#******************************* MISCELLANEOUS ********************************#

REMOVE	:=	rm -rf
FOLDER	:=	mkdir

#********************************** INCLUDE ***********************************#

INCL_PATH	:=	./include/
INCL		:=	-I $(INCL_PATH)

#********************************** SOURCES ***********************************#

SRC_FILES	:=	\
				main.cpp \
				ClapTrap.cpp \

SRC_PATH	:=	src/

#********************************** OBJECTS ***********************************#

OBJ_PATH	:=	obj/
OBJ_FILES	:=	$(SRC_FILES:.cpp=.o)
OBJ			:=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

#*********************************** COLORS ***********************************#

RESET		:=	\033[0m

RED			:=	\033[5;91m
GREEN		:=	\033[32m
ORANGE		:=	\033[38;5;208m

#******************************************************************************#
#*********************************** RULES ************************************#

all: $(NAME)
	
$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "\t$(ORANGE)Compiling...$(RESET)"
	@$(COMPILER) $(FLAGS) $(INCL) $(OBJ) $(OUTFILE_NAME) $@
	@echo "$(GREEN)\t$@ ready!$(RESET)"

$(OBJ_PATH):
	@$(FOLDER) $(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
	@echo "$@ object built with $<"
	@$(COMPILER) $(FLAGS) $(INCL) $(OUTFILE_NAME) $@ $(BUILD_OBJECT) $<
	@printf "\033[1A\033[K"

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
