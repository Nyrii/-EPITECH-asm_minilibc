/*
** main.c<2> for main in /home/noboud_n/rendu/asm_minilibc
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Tue Mar  8 18:13:54 2016 Nyrandone Noboud-Inpeng
** Last update Tue Mar  8 21:56:50 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <string.h>

char *my_strpbrk(char *, char *);

int	main()
{
  printf("c = %s -- abcde2fghi3jk4l 34\n", strpbrk("abcde2fghi3jk4l", "34"));
  printf("asm = %s -- abcde2fghi3jk4l 34\n", my_strpbrk("abcde2fghi3jk4l", "34"));

  printf("c = %s -- abcde2fghi3jk4l 2\n", strpbrk("abcde2fghi3jk4l", "2"));
  printf("asm = %s -- abcde2fghi3jk4l 2\n", my_strpbrk("abcde2fghi3jk4l", "2"));

  printf("c = %s -- abcdee2fghi3jk4l e\n", strpbrk("abcdee2fghi3jk4l", "e"));
  printf("asm = %s -- abcdee2fghi3jk4l e\n", my_strpbrk("abcdee2fghi3jk4l", "e"));

  printf("c = %s -- abcdee2fghi3jk4l l\n", strpbrk("abcdee2fghi3jk4l", "l"));
  printf("asm = %s -- abcdee2fghi3jk4l l\n", my_strpbrk("abcdee2fghi3jk4l", "l"));

  printf("c = %s -- abcdee2fghi3jk4l 2ci\n", strpbrk("abcdee2fghi3jk4l", "2ci"));
  printf("asm = %s -- abcdee2fghi3jk4l 2ci\n", my_strpbrk("abcdee2fghi3jk4l", "2ci"));

  printf("c = %s -- abcdee2fghi3jk4l 43\n", strpbrk("abcdee2fghi3jk4l", "43"));
  printf("asm = %s -- abcdee2fghi3jk4l 43\n", my_strpbrk("abcdee2fghi3jk4l", "43"));

  printf("c = POINTEUR NULL\n");
  printf("asm = %s -- abcde2fghi3jk4l \"\"\n", my_strpbrk("abcde2fghi3jk4l", ""));

  printf("c = POINTEUR NULL\n");
  printf("asm = %s -- \"\"  2\n", my_strpbrk("", "2"));

  printf("c = POINTEUR NULL\n");
  printf("asm = %s -- abcde2fghi3jk4l \"\"\n", my_strpbrk("", ""));

  return (0);
}
