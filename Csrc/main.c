/*
** main.c for main in /home/noboud_n/rendu/asm_minilibc
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Sun Mar  6 14:32:53 2016 Nyrandone Noboud-Inpeng
** Last update Mon Mar  7 14:10:02 2016 guillaume wilmot
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*my_memset(void *, int, size_t);
size_t	my_strlen(char *);
int	my_strncmp(char *, char*, int);

void	test_strlen()
{
  printf("asm %zu\n", my_strlen("SalutLaFamille"));
  printf("c   %zu\n", strlen("SalutLaFamille"));
}

void	test_strncmp()
{
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
}

void	test_memset()
{
  char	*str1;
  char	*str2;
  int	k;

  str1 = malloc(5);
  str2 = malloc(5);
  str1 = memset(str1, 42, 5);
  str2 = my_memset(str2, 42, 5);
  printf("asm : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str2[k]);
  printf("\nc   : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str1[k]);
  puts("");
}

int	main()
{
  /* test_strlen(); */
  /* test_strncmp(); */
  test_memset();
  return (0);
}
