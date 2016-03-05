##
## Makefile for asm in /home/noboud_n/rendu/asm_minilibc
## 
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
## 
## Started on  Sat Mar  5 19:12:10 2016 Nyrandone Noboud-Inpeng
## Last update Sat Mar  5 19:12:19 2016 Nyrandone Noboud-Inpeng
##

SRC	= main.c

OBJ	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

RM	= rm -f

CC	= cc -g

NAME	= libasm.so

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I includes/

MAKEOBJ	= obj

CFLAGS	= -Wall -Wextra -Werror -ansi -fpic -shared

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(MAKEOBJ)
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:
	@make --no-print-directory $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) -R $(OBJDIR)

re: fclean all
