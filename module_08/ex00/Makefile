# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 08:14:02 by ppaquet           #+#    #+#              #
#    Updated: 2024/03/01 10:59:34 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ------------------------------------------------------------ @category NAME.S
NAME				:=		easyfind
NAME_MAJ			:=		EASYFIND

DEBUG				:=		easyfind_debug

## ----------------------------------------------------- @category MISCELLANEOUS

DIR					:=		mkdir
DEL					:=		rm -rf

## ------------------------------------------------------- @category COMPILATION
COMPILER			:=		c++
BUILD_FLAG			:=		-c
OUTPUT_NAME_FLAG	:=		-o
WARNINGS_FLAG		:=		-Wall -Werror -Wextra
STD_LANG			:=		-std=c++98
STD_CPP				:=		-pedantic
INCL_FLAG			:=		-I
DEBUG_FLAG			:=		-g
WNOU_VAR_FLAG		:=		-Wno-unused-variable
WNOU_PAR_FLAG		:=		-Wno-unused-parameter

COMPILATION			:=		$(COMPILER)		$(WARNINGS_FLAG)\
							$(STD_CPP)		$(STD_LANG)

## ---------------------------------------------------------- @category SOURCE.S
SRC_PATH			:=		src/
SRC_FILES			:=	\
							main.cpp \

## ---------------------------------------------------------- @category OBJECT.S
OBJ_PATH			:=		obj/
OBJ_FILES			:=		$(SRC_FILES:.cpp=.o)
OBJ					:=		$(addprefix $(OBJ_PATH), $(OBJ_FILES))

## --------------------------------------------------------- @category INCLUDE.S
INCL_PATH				:=		include/
INCL					:=		$(INCL_FLAG)$(INCL_PATH)

## ----------------------------------------------------------- @category COLOR.S
ESC_SEQ				:=		\033[#		ESCAPE SEQUENCE CHARACTER
C_RST				:=		$(ESC_SEQ)0m#		RESETS COLOR.S
C_BLD				:=		$(ESC_SEQ)1m#		BOLD
C_RED				:=		$(ESC_SEQ)31m#			RED
C_B_RED				:=		$(ESC_SEQ)1;31m#		BOLD RED
C_GRN				:=		$(ESC_SEQ)32m#			GREEN
C_B_GRN				:=		$(ESC_SEQ)1;32m#		BOLD GREEN
C_ORN				:=		$(ESC_SEQ)38;5;208m#	ORANGE
C_B_ORN				:=		$(ESC_SEQ)1;38;5;208m#	BOLD ORANGE

## ------------------------------------------------------------- @category STYLE
STAB	:=	\t
DTAB	:=	$(STAB)$(STAB)
TTAB	:=	$(STAB)$(DTAB)
UP		:=	$(ESC_SEQ)1A
CUT		:=	$(ESC_SEQ)K
UPCUT	:=	$(UP)$(CUT)

OK_BOX	:=	[$(C_B_GRN)  OK  $(C_RST)]
KO_BOX	:=	[$(C_B_RED)  KO  $(C_RST)]
BUILD_BOX	:=	[$(C_B_ORN)  .o  $(C_RST)]
EXEC_BOX	:=	[$(C_B_ORN)  ./  $(C_RST)]

# **************************************************************************** #
# ********************************** RULE.S ********************************** #

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@	echo	"$(STAB)$(EXEC_BOX)"\
				"$(C_B_GRN)Compiling \`$@\`...$(C_RST)"
	@	$(COMPILATION)		$(INCL)	$(OBJ)\
		$(OUTPUT_NAME_FLAG)	$@
	@	if	[ -f $(NAME) ];													\
		then																\
			echo	"$(STAB)$(OK_BOX)"										\
					"$(C_B_GRN)./$(NAME) executable ready!$(C_RST)";		\
		else																\
			echo	"$(STAB)$(KO_BOX) something happened: try again.";		\
		fi;

$(OBJ_PATH):
	@	$(DIR)	$(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
	@	echo	"$(STAB)$(BUILD_BOX)$(C_B_ORN)"\
				"Building $@ from $<$(C_RST)";
	@	$(COMPILATION)		$(INCL)\
		$(BUILD_FLAG)		$<\
		$(OUTPUT_NAME_FLAG)	$@

clean:
	@	if	[ -d $(OBJ_PATH) ]; then										\
			$(DEL) $(OBJ_PATH);												\
			echo	"$(STAB)$(OK_BOX)$(C_B_GRN)"							\
					"$(OBJ_PATH) directory deleted.$(C_RST)";				\
		else																\
			echo	"$(STAB)$(KO_BOX)$(C_B_RED)"							\
					"$(OBJ_PATH) directory does not exists.$(C_RST)";		\
		fi;

fclean: clean
	@	if	[ -f $(NAME) ]; then											\
			$(DEL) $(NAME);													\
			echo "$(STAB)$(OK_BOX)$(C_B_GRN)"								\
			"\`$(NAME)\` executable deleted.$(C_RST)";						\
		else																\
			echo "$(STAB)$(KO_BOX)$(C_B_RED)"								\
			"\`$(NAME)\` executable does not exists.$(C_RST)";				\
		fi;
	@	if [	-f $(DEBUG)	]; then											\
			$(DEL)	$(DEBUG);												\
			echo	"$(STAB)$(OK_BOX)$(C_B_GRN)"							\
					"\`$(DEBUG)\` executable deleted.$(C_RST)";				\
	fi;

re: fclean all

debug: $(DEBUG)

$(DEBUG): COMPILATION += -g
$(DEBUG): COMPILATION += -Wno-unused-variable
$(DEBUG): COMPILATION += -Wno-unused-parameter
$(DEBUG): fclean $(OBJ_PATH) $(OBJ)
	@	echo	"$(STAB)$(EXEC_BOX)"\
				"$(C_B_ORN)Compiling in debug mode \`$@\`$(C_RST)"
	@	$(COMPILATION)	$(INCL)	$(OBJ)\
		$(OUTPUT_NAME_FLAG)	$@
	@	echo	"$(STAB)$(OK_BOX)"\
				"$(C_B_GRN)./$@ executable ready!$(C_RST)"

pdf:
	@	open https://cdn.intra.42.fr/pdf/pdf/66962/fr.subject.pdf

doc:
	@	open https://www.gnu.org/software/make/manual/make.html#Suffix-Rules

.PHONY: all clean fclean re

