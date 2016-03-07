/*
** main.c for main in /home/noboud_n/rendu/asm_minilibc
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Sun Mar  6 14:32:53 2016 Nyrandone Noboud-Inpeng
** Last update Mon Mar  7 01:28:27 2016 guillaume wilmot
*/

#include <stdio.h>
#include <string.h>

int	main()
{
  /* printf("asm %d\n", my_strlen("SalutLaFamille")); */
  /* printf("c   %d\n", strlen("SalutLaFamille")); */

  printf("asm %d\n", my_strncmp("Caca", "Pipi", 4));
  printf("c   %d\n", strncmp("Caca", "Pipi", 4));

  printf("asm %d\n", my_strncmp("Caca", "Pipi", 1));
  printf("c   %d\n", strncmp("Caca", "Pipi", 1));

  printf("asm %d\n", my_strncmp("Caza", "Caaa", 4));
  printf("c   %d\n", strncmp("Caza", "Caaa", 4));

  printf("asm %d\n", my_strncmp("Caca", "Caca", 5));
  printf("c   %d\n", strncmp("Caca", "Caca", 5));

  printf("asm %d\n", my_strncmp("Caca", "Cado", 4));
  printf("c   %d\n", strncmp("Caca", "Cado", 4));

  printf("asm %d\n", my_strncmp("", "", 1));
  printf("c   %d\n", strncmp("", "", 1));

  printf("asm %d\n", my_strncmp("a", "z", 0));
  printf("c   %d\n", strncmp("a", "z", 0));

  printf("asm %d\n", my_strncmp("zab", "zob", 2));
  printf("c   %d\n", strncmp("zab", "zob", 2));

  return (0);
}
