##
## Makefile for asm in /home/noboud_n/rendu/asm_minilibc
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Sat Mar  5 19:12:10 2016 Nyrandone Noboud-Inpeng
## Last update Sun Mar  6 14:56:08 2016 Nyrandone Noboud-Inpeng
##

SRC	= strlen2.s

OBJ	= $(addprefix $(OBJDIR), $(SRC:.s=.o))

RM	= rm -f

NASM	= nasm
CC	= gcc

NAME	= libasm.so

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I includes/

MAKEOBJ	= obj

SFLAGS	= -f elf64
CFLAGS	= -W -Wall -Werror

$(OBJDIR)%.o: $(SRCDIR)%.s
	@mkdir -p $(MAKEOBJ)
	$(NASM) $(SFLAGS) -o $@ $<

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
