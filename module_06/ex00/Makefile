# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 14:40:51 by ppaquet           #+#    #+#              #
#    Updated: 2024/02/19 12:41:33 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#********************************* COMPILATION ********************************#

NAME		:=		Cast
NAME_MAJ	:=		CAST

COMPILER	:=		c++
WARNINGS	:=		-Wall -Werror -Wextra
STD_LANG	:=		-std=c++98
STD_CPP		:=		-pedantic
OUTPUT_NAME	:=		-o
OBJ_BUILD	:=		-c
DEBUG		:=		-g

#******************************** MISCELLANEOUS *******************************#

FOLDER		:=		mkdir
REMOVE		:=		rm -rf

#********************************** SOURCE.S **********************************#

SRC_PATH	:=	src/
SRC_FILES	:=	\
				main.cpp \
				CastConversion.cpp \

#********************************** OBJECT.S **********************************#

OBJ_PATH	:=	obj/
OBJ_FILES	:=	$(SRC_FILES:.cpp=.o)
OBJ			:=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

#*********************************** INCLUDE **********************************#

INCL_PATH	:=	include/
INCL		:=	-I $(INCL_PATH)

#*********************************** COLOR.S **********************************#

C_RST		:=	\033[0m#			RESET COLOR
C_BLD		:=	\033[1m#			BOLD

C_RED		:=	\033[31m#			RED
C_B_RED		:=	\033[1;31m#			BOLD RED
C_GRN		:=	\033[32m#			GREEN
C_B_GRN		:=	\033[1;32m#			BOLD GREEN
C_ORN		:=	\033[38;5;208m#		ORANGE
C_B_ORN		:=	\033[1;38;5;208m#	BOLD ORANGE

#************************************ STYLE ***********************************#

CHECKBOX_OK	:=	[$(C_B_GRN)  OK  $(C_RST)]	
CHECKBOX_KO	:=	[$(C_B_RED)  KO  $(C_RST)]	
BUILDBOX	:=	[$(C_B_ORN)  .o  $(C_RST)]	
COMPILEBOX	:=	[$(C_B_ORN)  ./  $(C_RST)]	
SINGLE_TAB	:=	\t
DOUBLE_TAB	:=	\t\t
UPCUT		:=	\033[1A\033[K

#******************************************************************************#
#************************************ RULES ***********************************#

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@	clear
	@	echo	"$(UPCUT)$(SINGLE_TAB)$(COMPILEBOX)"\
				"$(C_B_ORN)Compiling \`$@\`$(C_RST)"
	@	$(COMPILER)		$(WARNINGS)	\
		$(STD_LANG)		$(STD_CPP)	\
		$(INCL)			$(OBJ)		\
		$(OUTPUT_NAME)	$@
	@	echo	"$(SINGLE_TAB)$(CHECKBOX_OK)"\
				"$(C_B_GRN)./$(NAME) executable ready!$(C_RST)"

$(OBJ_PATH):
	@	$(FOLDER)	$(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
	@	echo	"$(SINGLE_TAB)$(BUILDBOX)$(C_B_ORN)"\
				"Building $@ from $<$(C_RST)"
	@	$(COMPILER)		$(WARNINGS)	\
		$(STD_LANG)		$(STD_CPP)	\
		$(INCL)						\
		$(OBJ_BUILD)	$<			\
		$(OUTPUT_NAME)	$@
	@sleep 1
	@echo	"$(UPCUT)"

clean:
	@	clear
	@	if	[ -d $(OBJ_PATH) ]; then\
			$(REMOVE) $(OBJ_PATH);\
			echo	"$(SINGLE_TAB)$(CHECKBOX_OK)$(C_B_GRN)"\
					"$(OBJ_PATH) directory deleted.$(C_RST)";\
		else\
			echo	"$(SINGLE_TAB)$(CHECKBOX_KO)$(C_B_RED)"\
					"$(OBJ_PATH) directory does not exists.$(C_RST)";\
		fi;

fclean: clean
	@	if	[ -f $(NAME) ]; then\
			$(REMOVE) $(NAME);\
			echo "$(SINGLE_TAB)$(CHECKBOX_OK)$(C_B_GRN)"\
			"\`$(NAME)\` executable deleted.$(C_RST)";\
		else\
			echo "$(SINGLE_TAB)$(CHECKBOX_KO)$(C_B_RED)"\
			"\`$(NAME)\` executable does not exists.$(C_RST)";\
		fi;

re: fclean all

debug: COMPILER += -g -Wno-unused
debug: WARNINGS += -Wno-unused-variable
debug: fclean $(OBJ_PATH) $(OBJ)
	@	clear
	@	echo	"$(UPCUT)$(SINGLE_TAB)$(COMPILEBOX)"\
				"$(C_B_ORN)Compiling in debug mode \`$@\`$(C_RST)"
	@	$(COMPILER)		$(WARNINGS)	\
		$(STD_LANG)		$(STD_CPP)	\
		$(INCL)			$(OBJ)		\
		$(OUTPUT_NAME)	$@
	@	echo	"$(SINGLE_TAB)$(CHECKBOX_OK)"\
				"$(C_B_GRN)./$@ executable ready!$(C_RST)"

pdf:
	@	open https://cdn.intra.42.fr/pdf/pdf/58239/fr.subject.pdf

doc:
	@	open https://www.gnu.org/software/make/manual/make.html#Suffix-Rules

.PHONY: all clean fclean re
