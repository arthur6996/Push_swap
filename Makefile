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
SRC_CHECKER			=	$(SRC_TOOLS) checker_main.c checker_stack_fct.c \
						checker_s_and_p.c checker_r.c checker_rr.c\
						checker_rx_instr.c checker_gni.c

OBJ_CHECKER		=	$(addprefix $(PATH_OBJ)/, $(SRC_CHECKER:.c=.o))

#TOOLS

SRC_TOOLS		=	ft_is_int.c ft_string.c ft_list.c

#TEST
SRC_TEST		=	$(SRC_TOOLS) main_of_test.c

OBJ_TEST		=	$(addprefix $(PATH_OBJ)/, $(SRC_TEST:.c=.o))

#PUSH_SWAP
SRC_PUSH_SWAP	=	$(SRC_TOOLS) ps_sw_main.c ps_sw_yt_algo.c \
					ps_sw_clist_creation.c ps_sw_clist_operation.c

OBJ_PUSH_SWAP	=	$(addprefix $(PATH_OBJ)/, $(SRC_PUSH_SWAP:.c=.o))

#************
#**COMMANDS**
#************

all				:	$(INCLUDE) checker push_swap

checker			:	$(OBJ_CHECKER) $(INCLUDE)
					$(CC) $(FLAGS) -I$(PATH_INC) $(OBJ_CHECKER) -o $@

push_swap		:	$(OBJ_PUSH_SWAP) $(INCLUDE)
					$(CC) $(FLAGS) -I$(PATH_INC) $(OBJ_PUSH_SWAP) -o $@

exec_test		:	$(OBJ_TEST) $(INCLUDE)
					$(CC) $(FLAGS) -I$(PATH_INC) $(OBJ_TEST) -o $@

$(PATH_OBJ)/%.o	:	$(PATH_SRC)/%.c $(INCLUDE)
					$(CC) $(FLAGS) -I$(PATH_INC) -c $< -o $@

clean		:
				rm -rf $(PATH_OBJ)/*.o

fclean		:	clean
				rm -rf exec_test checker push_swap

re			:	fclean all
