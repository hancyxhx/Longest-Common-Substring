#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ************************ */
/* Longest Common Substring */
/* ************************ */



static int **_matrix;
static int _matrix_row_size = 0;
static int _matrix_collumn_size = 0;


static void init(int s1_length, int s2_length){
    if (s1_length+1 > _matrix_row_size || s2_length+1 > _matrix_collumn_size){
	/* free matrix */
	for (int i = 0; i < _matrix_row_size; i++)
	    free(_matrix[i]);
	free(_matrix);
	
	/* malloc matrix */
	_matrix = (int **)malloc((s1_length+1) * sizeof(int*));
	for (int i = 0; i < s1_length+1; i++)
	    _matrix[i] = (int *)malloc((s2_length+1) * sizeof(int));

	_matrix_row_size = s1_length+1;
	_matrix_collumn_size = s2_length+1;
    }

    for (int i = 0; i < s1_length; i++)
	_matrix[i][s2_length] = 0;
    for (int j = 0; j < s2_length; j++)
	_matrix[s1_length][j] = 0;
}


int LCS(char *s1, char *s2, char **longest_common_substring){
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);

    init(s1_length, s2_length);

    int max_len = 0, max_index_i = -1, max_index_j = -1;
    for (int i = s1_length-1; i >= 0; i--){
    	for (int j = s2_length-1; j >= 0; j--){
    	    if (s1[i] != s2[j]){
    		_matrix[i][j] = 0;
    		continue;
    	    }

    	    _matrix[i][j] = _matrix[i+1][j+1] + 1;
    	    if (_matrix[i][j] > max_len){
    		max_len = _matrix[i][j];
    		max_index_i = i;
    		max_index_j = j;
    	    }
    	}
    }

    return max_len;
}


int main(int argc, char *argv[]){
    char *s1 = "abcdefg";
    char *s2 = "cde";
    

    printf("%d\n", LCS(s1, s2, NULL));

    return 0;
}
