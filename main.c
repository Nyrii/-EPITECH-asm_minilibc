/*
** main.c for main in /home/noboud_n/rendu/asm_minilibc
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Sun Mar  6 19:16:20 2016 Nyrandone Noboud-Inpeng
** Last update Mon Mar  7 16:16:13 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <string.h>

char	*my_strchr(char *, char);

int	cmpp(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str2[i] != '\0')
    {
      if (str[i] != str2[i])
	return (str[i] - str2[i]);
      ++i;
    }
  if (str[i] != str2[i])
    return (str[i] - str2[i]);
  return (0);
}


int	main()
{
  /* STRCHR */
  printf("%s -- DSCXBC\n", my_strchr("AOIJDSCXBC", 'D'));
  /* printf("%s\n", my_strchr("AOIJDSCXBC", '')); /\* Compile paaaas (normal) *\/ */
  printf("%s -- ABC\n", my_strchr("ABC", 'A'));
  printf("%s -- BC\n", my_strchr("ABC", 'B'));
  printf("%s -- C\n", my_strchr("ABC", 'C'));


  /* STRCMP */
  printf("%d -- 0\n", my_strcmp("ABC", "ABC"));
  printf("%d -- -1\n", my_strcmp("ABC", "BBC"));
  printf("%d -- -1\n", my_strcmp("ABC", "ACC"));
  printf("%d -- 0\n", my_strcmp("", ""));
  printf("%d -- 75\n", my_strcmp("K", ""));
  return (0);
}

