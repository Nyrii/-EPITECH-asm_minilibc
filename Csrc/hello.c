#include <stdio.h>

int	hello()
{
  printf("Hello world !\n");
  return (42);
}

int	main()
{
  int	i;

  i = hello();
  printf("%d\n", i);
}
