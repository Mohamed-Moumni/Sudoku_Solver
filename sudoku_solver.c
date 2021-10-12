int	find_empty(char **board,int N, int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (board[i][j] == '.')
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	UsedInrow(char **board, int N, char num, int row, int col)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (board[row][i] == num && i != col)
			return (0);
		i++;
	}
	return (1);
}
int	UsedIncol(char **board,int N, char num, int row, int col)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (board[i][col] == num && i != row)
			return (0);
		i++;
	}
	return (1);
}
int	UsedInbox(char **board, char num, int Rowstartbox, int Colstartbox)
{
	int	row;
	int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (board[row + Rowstartbox][col + Colstartbox] == num)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
int	is_safe(char **board,int N, char num, int row, int col)
{
	if (UsedInrow(board,N , num, row, col) != 0 && UsedIncol(board,N , num, row, col) != 0 && UsedInbox(board, num, row - row % 3, col - col % 3) != 0)
		return (1);
	return (0);
}
int	solve(char **board, int N)
{
	int	row;
	int	col;
	char	num;

	num = '1';
	if (!find_empty(board,N , &row, &col))
		return (1);
	while (num <= '9')
	{
		if (is_safe(board,N , num, row, col) != 0)
		{
			board[row][col] = num;
			if (solve(board,N))
				return (1);
			board[row][col] = '.';
		}
		num++;
	}
	return (0);
}
