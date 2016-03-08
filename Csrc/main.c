/*
** main.c for main in /home/noboud_n/rendu/asm_minilibc
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Sun Mar  6 14:32:53 2016 Nyrandone Noboud-Inpeng
** Last update Tue Mar  8 17:41:25 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void	*my_memset(void *, int, size_t);
extern size_t	my_strlen(char *);
extern int	my_strncmp(char *, char*, int);
extern int	my_strcmp(char *, char*);
extern char	*my_strchr(char *, char);
extern char	*my_strstr(char *, char *);

#define RED "\033[01;31m"
#define END "\033[m"

void	test_strstr()
{
  printf("\n%s___Testing strstr___%s\n\n", RED, END);
  printf("asm = %s -- MDRCOUCOUSALUT UT\n", my_strstr("MDRCOUCOUSALUT", "UT"));
  printf("c = %s -- MDRCOUCOUSALUT UT\n", strstr("MDRCOUCOUSALUT", "UT"));

  printf("-\n");

  printf("asm = %s -- MDRCOUCOUSALUT \"\"\n", my_strstr("MDRCOUCOUSALUT", ""));
  printf("c = %s -- MDRCOUCOUSALUT \"\"\n", strstr("MDRCOUCOUSALUT", ""));

  printf("-\n");

  printf("asm = %s -- MDRCOUCOUSALUT OU\n", my_strstr("MDRCOUCOUSALUT", "OU"));
  printf("c = %s -- MDRCOUCOUSALUT OU\n", strstr("MDRCOUCOUSALUT", "OU"));

  printf("-\n");

  printf("asm = %s -- MDRCOUCOUSALUT MDR\n", my_strstr("MDRCOUCOUSALUT", "MDR"));
  printf("c = %s -- MDRCOUCOUSALUT MDR\n", strstr("MDRCOUCOUSALUT", "MDR"));

  printf("-\n");

  printf("asm = %s -- MDRCOUCOUSALUT D\n", my_strstr("MDRCOUCOUSALUT", "D"));
  printf("c = %s -- MDRCOUCOUSALUT D\n", strstr("MDRCOUCOUSALUT", "D"));

  printf("-\n");

  printf("asm = %s -- \"\" X\n", my_strstr("", "X")); /* Si ça ne compile pas (erreur de printf sur un ptr null), c'est NORMAL ! Dans le cas contraire, le printf doit print "(null)"*/
  printf("c = POINTEUR NULL -- \"\" X\n");

  printf("-\n");

  printf("asm = %s -- MDRCOUCOUSALUT X\n", my_strstr("MDRCOUCOUSALUT", "X")); /* Si ça ne compile pas (erreur de printf sur un ptr null), c'est NORMAL ! Dans le cas contraire, le printf doit print "(null)"*/
  printf("c = POINTEUR NULL -- MDRCOUCOUSALUT X\n");
}

void	test_strchr()
{
  printf("\n%s___Testing strchr___%s\n\n", RED, END);
  printf("asm : %s -- AOIJDSCXBC D\n", my_strchr("AOIJDSCXBC", 'D'));
  printf("c   : %s -- AOIJDSCXBC D\n", strchr("AOIJDSCXBC", 'D'));
  puts("-");
  printf("asm : %s -- ABC A\n", my_strchr("ABC", 'A'));
  printf("c   : %s -- ABC A\n", strchr("ABC", 'A'));
  puts("-");
  printf("asm : %s -- ABC B\n", my_strchr("ABC", 'B'));
  printf("c   : %s -- ABC B\n", strchr("ABC", 'B'));
  puts("-");
  printf("asm : %s -- ABC C\n", my_strchr("ABC", 'C'));
  printf("c   : %s -- ABC C\n", strchr("ABC", 'C'));
}

void	test_strlen()
{
  printf("\n%s___Testing strlen___%s\n\n", RED, END);
  printf("asm %zu -- SalutLaFamille\n", my_strlen("SalutLaFamille"));
  printf("c   %zu -- SalutLaFamille\n", strlen("SalutLaFamille"));
  puts("-");
  printf("asm %zu -- \"\"\n", my_strlen(""));
  printf("c   %zu -- \"\"\n", strlen(""));
  puts("-");
  printf("asm %zu -- æ«øðæð\n", my_strlen("æ«øðæð"));
  printf("c   %zu -- æ«øðæð\n", strlen("æ«øðæð"));
  puts("-");
  printf("asm %zu -- Matuidi Charo\n", my_strlen("Matuidi Charo"));
  printf("c   %zu -- Matuidi Charo\n", strlen("Matuidi Charo"));
}

void	test_strncmp()
{
  printf("\n%s___Testing strncmp___%s\n\n", RED, END);
  printf("asm %d -- CATR PRET 4\n", my_strncmp("CATR", "PRET", 4));
  printf("c   %d -- CATR PRET 4\n", strncmp("CATR", "PRET", 4));
  puts("-");
  printf("asm %d -- CATR PRET 1\n", my_strncmp("CATR", "PRET", 1));
  printf("c   %d -- CATR PRET 1\n", strncmp("CATR", "PRET", 1));
  puts("-");
  printf("asm %d Caza Caaa 4\n", my_strncmp("Caza", "Caaa", 4));
  printf("c   %d Caza Caaa 4\n", strncmp("Caza", "Caaa", 4));
  puts("-");
  printf("asm %d Colo Colo 5\n", my_strncmp("Colo", "Colo", 5));
  printf("c   %d Colo Colo 5\n", strncmp("Colo", "Colo", 5));
  puts("-");
  printf("asm %d -- PILD Caso 4\n", my_strncmp("PILD", "Cado", 4));
  printf("c   %d -- PILD Caso 4\n", strncmp("PILD", "Cado", 4));
  puts("-");
  printf("asm %d -- \"\" \"\" 1\n", my_strncmp("", "", 1));
  printf("c   %d -- \"\" \"\" 1\n", strncmp("", "", 1));
  puts("-");
  printf("asm %d -- a z 0\n", my_strncmp("a", "z", 0));
  printf("c   %d -- a z 0\n", strncmp("a", "z", 0));
  puts("-");
  printf("asm %d -- zab zeb 2\n", my_strncmp("zab", "zeb", 2));
  printf("c   %d -- zab zeb 2\n", strncmp("zab", "zeb", 2));
}

void	test_strcmp()
{
  printf("\n%s___Testing strcmp___%s\n\n", RED, END);
  printf("asm %d -- CATR PRET\n", my_strcmp("CATR", "PRET"));
  printf("c   %d -- CATR PRET\n", strcmp("CATR", "PRET"));
  puts("-");
  printf("asm %d -- CATR PRET\n", my_strcmp("CATR", "PRET"));
  printf("c   %d -- CATR PRET\n", strcmp("CATR", "PRET"));
  puts("-");
  printf("asm %d Caza Caaa\n", my_strcmp("Caza", "Caaa"));
  printf("c   %d Caza Caaa\n", strcmp("Caza", "Caaa"));
  puts("-");
  printf("asm %d Colo Colo\n", my_strcmp("Colo", "Colo"));
  printf("c   %d Colo Colo\n", strcmp("Colo", "Colo"));
  puts("-");
  printf("asm %d -- PILD Caso\n", my_strcmp("PILD", "Cado"));
  printf("c   %d -- PILD Caso\n", strcmp("PILD", "Cado"));
  puts("-");
  printf("asm %d -- \"\" \"\"\n", my_strcmp("", ""));
  printf("c   %d -- \"\" \"\"\n", strcmp("", ""));
  puts("-");
  printf("asm %d -- a z\n", my_strcmp("a", "z"));
  printf("c   %d -- a z\n", strcmp("a", "z"));
  puts("-");
  printf("asm %d -- zab zeb\n", my_strcmp("zab", "zeb"));
  printf("c   %d -- zab zeb\n", strcmp("zab", "zeb"));
}


void	test_memset()
{
  char	*str1;
  char	*str2;
  int	k;

  printf("\n%s___Testing memset___%s\n\n", RED, END);
  str1 = malloc(5);
  str2 = malloc(5);
  str1 = my_memset(str2, 42, 5);
  str2 = memset(str1, 42, 5);
  printf("asm : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str1[k]);
  printf(" -- str2, 42, 5\nc   : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str2[k]);
  puts(" -- str2, 42, 5\n-");
  str1 = my_memset(str1, -12, 3);
  str2 = memset(str2, -12, 3);
  printf("asm : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str1[k]);
  printf(" -- str2 -12 3\nc   : ");
  for (k = 0; k < 5; k++)
    printf("%d ", str2[k]);
  puts(" -- str2 -12 3");
}

int	main()
{
  test_strlen();
  test_strncmp();
  test_strcmp();
  test_strchr();
  test_memset();
  test_strstr();
  return (0);
}
