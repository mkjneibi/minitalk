
NAME = libft.a

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= is to mem str put lst int printf gnl

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

INCLUDES	= -Iincludes

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM		= /bin/rm -f


$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: ${NAME}

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "\nLibft is READY!"

clean:
			@echo "${BIRed}Libft Cleaned!${Color_Off}"
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

norme:
	norminette -R CheckForbiddenSourceHeader ${wildcard srcs/*.c} ${wildcard srcs/*.h}

wh:
	@echo 	"\033[0;31m                 ┊┊┊┊┊╭╭╭╮╮╮┊┊┊┊\n\
			 ┊┊┊┊┊╰╰╲╱╯╯┊┊┊┊\n\
			 ┊┏╮╭┓╭━━━━━━╮┊┊\n\
			 ┊╰╮╭╯┃┈┈┈┈┈┈┃┊┊\n\
			 ┊┊┃╰━╯┈┈╰╯┈┈┃┊┊\n\
			 ┊┊┃┈┈┈┈┈┈┈╰━┫┊┊\n\
			 ╲╱╲╱╲╱╲╱╲╱╲╱╲╱╲"


whale:
	@echo 	"             __   __       "
	@echo	"            __ \ / __      "
	@echo	"           /  \ | /  \     "
	@echo	"               \|/         "
	@echo	"          _,.---v---._     "
	@echo	" /\__/\  /            \    "
	@echo	" \_  _/ /              \   "
	@echo	"  \ \_ /          @  __|   "
	@echo	"   \                 \_    "
	@echo	"    \     ,__/        /    "
	@echo	"  ~~~~~~~~~~~~~~~~~~~~~    "
