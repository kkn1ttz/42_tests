#include <unistd.h>
#include <stdlib.h>

int input_error_check(char *input);
int	**extrac_sides(char *input);
int	**initialize_results(void);
int result_errors_check(int **results);
int	result_check(int **results, int **inputs);
void	result_print(int **tab);

// int	main(void)
int	main(int argc, char **argv)
{
	int	**inputs;
	int	**result;
	int	i;

	if (argc < 2)
	{
		write(1, "Error", 5);
		return (0);
	}
	if (input_error_check(argv[1]) == 0)
	{
		write(1, "Error", 5);
		return (0);
	}

	/*int **result = malloc(sizeof(int*) * 4);
	result[0] = malloc(sizeof(int) * 4);
	result[0][0] = 1;
	result[0][1] = 2;
	result[0][2] = 3;
	result[0][3] = 4;

	result[1] = malloc(sizeof(int) * 4);
	result[1][0] = 2;
	result[1][1] = 3;
	result[1][2] = 4;
	result[1][3] = 1;
	
	result[2] = malloc(sizeof(int) * 4);
	result[2][0] = 3;
	result[2][1] = 4;
	result[2][2] = 1;
	result[2][3] = 2;
	
	result[3] = malloc(sizeof(int) * 4);
	result[3][0] = 4;
	result[3][1] = 1;
	result[3][2] = 2;
	result[3][3] = 3;*/

	result = initialize_results();
	result_print(result);
	inputs = extrac_sides(argv[1]);
	result_check(result, inputs);
	result_errors_check(result);
	i = 0;
	while (i < 4)
	{
		free(result[i]);
		free(inputs[i]);
	}
	free(result);
	free(inputs);

	return (0);
}