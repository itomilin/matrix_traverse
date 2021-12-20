#include <stdio.h>

int main()
{
    int size = 0;

    printf( "%s", "Input size of matrix: " );
    scanf( "%i", &size );
    if ( size < 2 )
    {
        printf( "%s\n", "Size must be >= 2." );
        return 1;
    }

    // Init matrix.
    int matrix[size][size];

    printf( "%s\n", "OK. Fill the matrix:" );
    for( int row = 0; row < size; ++row )
        for ( int column = 0; column < size; ++column )
            scanf( "%i", &matrix[row][column] );

    printf( "%s\n", "Input matrix:" );
    for( int i = 0; i < size; ++i )
    {
        for ( int j = 0; j < size; ++j )
        {
            printf( "%i\t", matrix[i][j] );
        }
        printf("\n");
    }
    printf( "%s\n", "Output:" );

    int column = 0;
    int row    = size - 1;
    int rGtC   = size - 1;
    int rLwC   = 0;

    while ( rGtC >= 0 )
    {
        if ( row > column )
        {
            column = 0;
            for ( row = rGtC; row >= 0; --row )
            {
                printf("%i ", matrix[row][column]);
                column++;
            }
            rGtC--;
        }
        else if ( row < column )
        {
            rLwC++;
            column = size - 1;
            for ( row = rLwC; row < size; ++row )
            {
                printf("%i ", matrix[row][column]);
                column--;
            }
        }
    }

    return 0;
}

