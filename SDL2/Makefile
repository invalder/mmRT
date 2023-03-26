NAME = sdltest
CC = gcc
CFLAGS	= -g -Wall -Wextra -Werror

RM = rm -rf

SRC_DIR	= srcs/
OBJ_DIR	= objs/
INC_DIR	= includes/SDL2
FRM_DIR	= /Users/nnakarac/Library/Frameworks/

INCS	= -I$(INC_DIR)\

FRMS	= -F$(FRM_DIR) -framework SDL2

SRCS	= test.c \

OBJS	= $(SRCS:.c=.o)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJS))
	@$(CC) $(CFLAGS) $(FRMS) $(addprefix $(OBJ_DIR),$(OBJS)) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< $(INCS) -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(RM) "$(NAME).dSYM"

fclean: clean

re: fclean all

.PHONY: fclean all clean re sdltest
