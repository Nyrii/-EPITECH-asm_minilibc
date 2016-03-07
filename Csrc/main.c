/*
** main.c for main in /home/noboud_n/rendu/asm_minilibc
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Sun Mar  6 14:32:53 2016 Nyrandone Noboud-Inpeng
** Last update Mon Mar  7 16:20:22 2016 guillaume wilmot
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void	*my_memset(void *, int, size_t);
extern size_t	my_strlen(char *);
extern int	my_strncmp(char *, char*, int);

void	test_strlen()
{
  puts("\n___Testing strlen___\n");
  printf("asm %zu\n", my_strlen("SalutLaFamille"));
  printf("c   %zu\n", strlen("SalutLaFamille"));
  puts("-");
  printf("asm %zu\n", my_strlen(""));
  printf("c   %zu\n", strlen(""));
  puts("-");
  printf("asm %zu\n", my_strlen("æ«øðæð"));
  printf("c   %zu\n", strlen("æ«øðæð"));
  puts("-");
  printf("asm %zu\n", my_strlen("Matuidi Charo"));
  printf("c   %zu\n", strlen("Matuidi Charo"));
}

void	test_strncmp()
{
  puts("\n___Testing strncmp___\n");
  printf("asm %d\n", my_strncmp("CATR", "PRET", 4));
  printf("c   %d\n", strncmp("CATR", "PRET", 4));
  puts("-");
  printf("asm %d\n", my_strncmp("CATR", "PRET", 1));
  printf("c   %d\n", strncmp("CATR", "PRET", 1));
  puts("-");
  printf("asm %d\n", my_strncmp("Caza", "Caaa", 4));
  printf("c   %d\n", strncmp("Caza", "Caaa", 4));
  puts("-");
  printf("asm %d\n", my_strncmp("Colo", "Colo", 5));
  printf("c   %d\n", strncmp("Colo", "Colo", 5));
  puts("-");
  printf("asm %d\n", my_strncmp("PILD", "Cado", 4));
  printf("c   %d\n", strncmp("PILD", "Cado", 4));
  puts("-");
  printf("asm %d\n", my_strncmp("", "", 1));
  printf("c   %d\n", strncmp("", "", 1));
  puts("-");
  printf("asm %d\n", my_strncmp("a", "z", 0));
  printf("c   %d\n", strncmp("a", "z", 0));
  puts("-");
  printf("asm %d\n", my_strncmp("zab", "zeb", 2));
  printf("c   %d\n", strncmp("zab", "zeb", 2));
}

void	test_memset()
{
  char	*str1;
  char	*str2;
  int	k;

  puts("\n___Testing memset___\n");
  str1 = malloc(5);
  str2 = malloc(5);
  str1 = my_memset(str2, 42, 5);
  str2 = memset(str1, 42, 5);
  printf("asm : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str1[k]);
  printf("\nc   : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str2[k]);
  puts("\n-");
  str1 = my_memset(str1, -12, 3);
  str2 = memset(str2, -12, 3);
  printf("asm : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str1[k]);
  printf("\nc   : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str2[k]);
  puts("");
}

int	main()
{
  test_strlen();
  test_strncmp();
  test_memset();
  return (0);
}
