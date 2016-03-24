##
## Makefile for  in /home/wilmot_g/Rendu/asm_minilibc
##
## Made by guillaume wilmot
## Login   <wilmot_g@epitech.net>
##
## Started on  Sat Mar  5 19:12:10 2016 Nyrandone Noboud-Inpeng
## Last update Thu Mar 24 14:18:16 2016 guillaume wilmot
##

SRC	= strlen.S 	\
	  strncmp.S	\
	  strcmp.S	\
	  strcasecmp.S	\
	  memset.S	\
	  memcpy.S	\
	  memmove.S	\
	  putchar.S	\
	  putstr.S	\
	  strchr.S	\
	  strstr.S	\
	  rindex.S	\
	  strcspn.S	\
	  strpbrk.S

CSRC	= main.c

OBJ	= $(addprefix $(OBJDIR), $(SRC:.S=.o))
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

$(OBJDIR)%.o: $(SRCDIR)%.S
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
