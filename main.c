#include<unistd.h>

int	find_empty(char **board,int N, int *row, int *col);
int	UsedInrow(char **board, int N, char num, int row, int col);
int	UsedIncol(char **board, int N, char num, int row, int col);
int	UsedInbox(char **board, char num, int Rowstartbox, int Colstartbox);
int	is_safe(char **board,int N, char num, int row, int col);
int	solve(char **board, int N);

void	print_board(char **board, int N)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			write(1, &board[i][j], 1);
			if (i <= N - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_arguments(int argc, char **argv)
{
	int	i;
	int	j;
	int	N;

	N = argc - 1;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) != N)
			return (0);
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] == '.' || (argv[i][j] >= '0' && argv[i][j] <= '9')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 4)
	{
		if (!check_arguments(argc, argv))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else
		{
			solve(&argv[1], argc - 1);
			print_board(&argv[1],argc - 1);
		}
	}
	return (0);
}
