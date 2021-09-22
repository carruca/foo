#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STDOUT 1
#define STDIN 0

typedef struct s_draw
{
	int		width;
	int		height;
	char	bg;
	char	r;
	float	x;
	float	y;
	float	wRectangle;
	float	hRectangle;
	char	c;
	char	*zone;
}			t_draw;

size_t	ft_strlen( char *str )
{
	size_t	len;

	len = 0;
	while ( str[len] )
		len++;
	return len;
}

int	error( char *msg )
{
	write( STDOUT, msg, ft_strlen(msg) );
	return 1;
}

int	parseDrawZone( int nbItems, char endChar, t_draw *draw )
{
	if ( nbItems != 4 || endChar != '\n'
		|| draw->width <= 0 || draw->width > 300 || draw->height <= 0 || draw->height > 300 )
		return 1;
	return 0;
}

int	extractDrawZone( FILE *fstream, t_draw *draw )
{
	int		nbItems;
	char	endChar;

	nbItems = fscanf( fstream, "%d %d %c%c", &draw->width, &draw->height, &draw->bg, &endChar );
	if ( parseDrawZone( nbItems, endChar, draw ) )
		return 1;
	draw->zone = malloc( sizeof( char ) * draw->width * draw->height );
	if (!draw->zone)
		return 1;
	memset( draw->zone, draw->bg, draw->width * draw->height );
	return 0;
}

int	parseRectangle( int nbItems, char endChar, t_draw *draw )
{
	if ( nbItems != 7
		|| ( endChar != '\0' && endChar != '\n' ) || ( draw->r != 'r' && draw->r != 'R' )
		|| ( draw->wRectangle <= 0 || draw->hRectangle <= 0 ) )
		return 1;
	return 0;
}

int	isBorder( int X, int Y, t_draw *draw )
{
	if ( ( draw->x + draw->wRectangle - X ) < 1 || ( draw->y + draw->hRectangle - Y ) < 1
		|| ( X - draw->x ) < 1 || ( Y - draw->y ) < 1 )
		return 1;
	return 0;
}

int	isInside( int X, int Y, t_draw *draw )
{
	if ( X >= draw->x && X <= ( draw->x + draw->wRectangle ) && Y >= draw->y && Y <= ( draw->y + draw->hRectangle ) )
		return 1;
	return 0;
}

void	drawRectangle( t_draw *draw )
{
	int	X;
	int	Y;

	Y = 0;
	while ( Y < draw->height )
	{
		X = 0;
		while ( X < draw->width )
		{
			
			if ( isInside( X, Y, draw ) )
			{
				if ( draw->r == 'R' || isBorder( X, Y, draw ) )
					draw->zone[ X + Y * draw->width ] = draw->c;
			}
			X++;
		}
		Y++;
	}
	return ;
}

int	extractRectangle( FILE *fstream, t_draw *draw )
{
	int		nbItems;
	char	endChar;

	while ( 1 )
	{
		nbItems = fscanf( fstream, "%c %a %a %a %a %c%c", &draw->r, &draw->x, &draw->y, &draw->wRectangle, &draw->hRectangle, &draw->c, &endChar );
		if ( nbItems == EOF || draw->r == '\n' )
			break;
		if ( parseRectangle( nbItems, endChar, draw ) )
			return 1;
		drawRectangle( draw );
	}
	return 0;
}

void	printDraw( t_draw *draw )
{
	int	X;
	int Y;

	Y = 0;
	while ( Y < draw->height )
	{
		X = 0;
		while ( X < draw->width )
		{
			write(STDOUT, &draw->zone[ X + Y * draw->width ], 1);
			X++;
		}
		write(STDOUT, "\n", 1); 
		Y++;
	}
	return ;
}

void	leaks_check( void )
{
	system( "leaks micro" );
	//system( "lsof -c micro" );
	return ;
}

int	main( int argc, char **argv )
{
	FILE	*fstream;
	t_draw	*draw;

	//atexit( leaks_check );
	if ( argc != 2 )
		return error( "Error: argument\n" );
	fstream = fopen( argv[1], "r" );
	if ( !fstream )
		return error( "Error: Operation file corrupted\n" );
	draw = calloc( sizeof( t_draw ), 1 );
	if ( !draw )
		return 1;
	if ( extractDrawZone( fstream, draw ) )
	{
		fclose( fstream );
		free( draw );
		return error( "Error: Operation file corrupted\n" );
	}
	if ( extractRectangle( fstream, draw ) )
	{
		fclose( fstream );
		free( draw->zone );
		free( draw );
		return error( "Error: Operation file corrupted\n" );
	}
	printDraw( draw );
	fclose( fstream );
	free( draw->zone );
	free( draw );
	return 0;
}
