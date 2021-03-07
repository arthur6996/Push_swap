#***********
#**GENERAL**
#***********
CC				=	gcc

FLAGS			=	-Wall -Werror -Wextra  -g3 -fsanitize=address

PATH_OBJ		=	obj

PATH_SRC		=	src

#INCLUDE
SRC_INC			=	lib_tools.h checker.h push_swap.h

PATH_INC		=	include

INCLUDE			=	$(addprefix $(PATH_INC)/, $(SRC_INC))

#CHECKER
SRC_CHECKER			=	$(SRC_TOOLS) checker.c checker_main.c stack_function.c

OBJ_CHECKER		=	$(addprefix $(PATH_OBJ)/, $(SRC_CHECKER:.c=.o))

#TOOLS

SRC_TOOLS		=	is_int.c ft_fdputstr.c

#TEST
SRC_TEST		=	$(SRC_TOOLS) main_of_test.c

OBJ_TEST		=	$(addprefix $(PATH_OBJ)/, $(SRC_TEST:.c=.o))

#PUSH_SWAP
SRC_PUSH_SWAP	=



#************
#**COMMANDS**
#************

all			:	#$(OBJ) $(INCLUDE)
				@echo all cmd

checker		:	$(OBJ_CHECKER) $(INCLUDE)
				$(CC) $(FLAGS) -I$(PATH_INC) $(OBJ_CHECKER) -o $@
				@#echo $(OBJ_CHECKER)

#push_swap	:	$(OBJ) $(INCLUDE)

exec_test		:	$(OBJ_TEST) $(INCLUDE)
					$(CC) $(FLAGS) -I$(PATH_INC) $(OBJ_TEST) -o $@

$(PATH_OBJ)/%.o	:	$(PATH_SRC)/%.c $(INCLUDE)
					$(CC) $(FLAGS) -I$(PATH_INC)/ -c $< -o $@

clean		:
				rm -rf $(PATH_OBJ)/*.o

fclean		:	clean
				rm -rf exec_test checker

re			:	fclean all
