##
## Makefile for asm in /home/noboud_n/rendu/asm_minilibc
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Sat Mar  5 19:12:10 2016 Nyrandone Noboud-Inpeng
## Last update Mon Mar  7 16:35:41 2016 guillaume wilmot
##

SRC	= strlen.s 	\
	  strncmp.s	\
	  strcmp.s	\
	  memset.s	\
	  strchr.s	\

CSRC	= main.c	\

OBJ	= $(addprefix $(OBJDIR), $(SRC:.s=.o))
COBJ	= $(addprefix $(COBJDIR), $(CSRC:.c=.o))

RM	= rm -f

NASM	= nasm
CC	= gcc

NAME	= libasm.so
TEST	= test

OBJDIR	= obj/
COBJDIR	= Cobj/
SRCDIR	= src/
CSRCDIR	= Csrc/
INCDIR	= -I includes/

MAKEOBJ		= obj
MAKECOBJ	= Cobj

SFLAGS	= -f elf64
CFLAGS	= -W -Wall -Werror -shared -fPIC
TFLAGS	= -W -Wall -Werror

$(OBJDIR)%.o: $(SRCDIR)%.s
	@mkdir -p $(MAKEOBJ)
	$(NASM) $(SFLAGS) -o $@ $<

$(COBJDIR)%.o: $(CSRCDIR)%.c
	@mkdir -p $(MAKECOBJ)
	$(CC) $(TFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

$(TEST): $(OBJ) $(COBJ)
	$(CC) $(OBJ) $(COBJ) -o $(TEST) $(TFLAGS)

all:
	@make --no-print-directory $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(COBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST)
	$(RM) -R $(OBJDIR)
	$(RM) -R $(COBJDIR)

re: fclean all
