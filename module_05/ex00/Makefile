# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 10:13:05 by ppaquet           #+#    #+#              #
#    Updated: 2024/02/06 17:32:52 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	Bureaucrat
NAME_MAJ		:=	Bureaucrat

#******************************** COMPILATION *********************************#

COMPILER		:=	c++
FLAGS			:=	-Wall -Werror -Wextra -std=c++98 -pedantic

#******************************* MISCELLANEOUS ********************************#

FOLDER			:=	mkdir
REMOVE			:=	rm -rf

OUTPUT_NAME		:=	-o
BUILD_OBJECT	:=	-c

#********************************** SOURCES ***********************************#

SRC_PATH	:=	src/
SRC_FILES	:=	\
				main.cpp	\
				Bureaucrat.cpp	\

#********************************** OBJECTS ***********************************#

OBJ_PATH	:=	obj/
OBJ_FILES	:=	$(SRC_FILES:.cpp=.o)
OBJ			:=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

#********************************** INCLUDE ***********************************#

INCL_PATH	:=	include/
INCL		:=	-I $(INCL_PATH)

#*********************************** COLORS ***********************************#

RESET		:=		\033[0m
BOLD		:=		\033[1m

RED			:=		\033[31m
GREEN		:=		\033[32m
ORANGE		:=		\033[38;5;208m

INDENT		:=		\t

#*********************************** RULES ************************************#

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "$(ORANGE)$(INDENT)Compiling $@...$(RESET)"
	@$(COMPILER) $(FLAGS) $(INCL) $(OBJ) $(OUTPUT_NAME) $@
	@echo "$(GREEN)$(INDENT)$@ ready!$(RESET)"

$(OBJ_PATH):
	@$(FOLDER) $(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
	@$(COMPILER) $(FLAGS) $(INCL) $(OUTPUT_NAME) $@ $(BUILD_OBJECT) $<

clean:
	@if [ -d $(OBJ_PATH) ];\
		then $(REMOVE) $(OBJ_PATH);\
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

debug: FLAGS += -g
debug: fclean $(OBJ_PATH) $(OBJ)
	@$(COMPILER) $(FLAGS) $(INCL) $(OBJ) $(OUTPUT_NAME) $@

pdf:
	@open 'https://cdn.intra.42.fr/pdf/pdf/95639/fr.subject.pdf'

.PHONY: all clean fclean re
