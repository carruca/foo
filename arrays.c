#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int	main()
{	
	char	line[] = "echo hello world";//line needs to free
	int		i;
	int		tokens_num;
	char 	**tokens_array;

	//find spaces and tabs in the string and mark position
	tokens_num = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			tokens_num++;
		}
		i++;
	}
	tokens_num++;
	if (!(tokens_array = malloc(sizeof(char) * tokens_num)))
		return (-1);
	printf("%d\n", tokens_num);
	printf("%s\n", tokens_array[1]);


}
