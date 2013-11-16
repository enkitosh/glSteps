#include "prettyprinter.h"

/*
*	Pretty Printer implemenation
*
*/

/*Extra helpers*/
char **cnvrt_double_Array(double **x_i, int n, int m) {
    
/*
  Takes in 2D double array, n * m dimension
  returns char array with double elements
  converted to strings
*/

		int elements = n * m;
		char **str_array = malloc(sizeof(char *) * elements);
		
		if(str_array == NULL) 
			perror("Malloc error");
		
		int i,j;
		int idx = 0;

		for(i = 0; i < elements; i++) {

				str_array[i] = malloc(sizeof(char) * 15);
		}


		for(i = 0; i < m; i++) {
			for(j = 0; j < n; j++) {

				sprintf(str_array[idx], "%g", x_i[j][i]);
		
				idx++;
			
			}
		}

  
        return str_array;
    
    
}

char **cnvrt_float_Array(float **f_i, int n, int m) {

	
		int elements = n * m;
		char **str_array = malloc(sizeof(char *) * elements);
		
		if(str_array == NULL) 
			perror("Malloc error");
		
		int i,j;
		int idx = 0;

		for(i = 0; i < elements; i++) {

				str_array[i] = malloc(sizeof(char) * 15);
		}


		for(i = 0; i < m; i++) {
			for(j = 0; j < n; j++) {

				sprintf(str_array[idx], "%g", f_i[j][i]);
		
				idx++;
			
			}
		}

  
        return str_array;


}

//Converts a single float array
char **cnrt_sFloat_Array(float *f_s, int n, int m) {

	int elements = n * m;
	char **str_array = malloc(sizeof(char *) *elements);
	
	if(str_array == NULL) 
		perror("Malloc error");

	int i,j;
	int idx = 0;

	for(i = 0; i < elements; i++) {

			str_array[i] = malloc(sizeof(char) * 15);
	}

	for(i = 0; i < elements; i++) {
			sprintf(str_array[i], "%f", f_s[i]);
	}


	return str_array;

}

/*END helpers*/
/*********************************************************************/

void 
ms(int space, char symbol) 
{
    
    while(space-- > 0)
        printf("%c", symbol);

}

int 
return_biggest(int *list, size_t size) 
{
    int     i;
    int     j;
    int     max_width;
  

    max_width = list[0];
    
    for(j = 0; j < size; j++) {
        
            if(list[j] > max_width) {
                
                    max_width = list[j];
                
            }
        
        }
    

    return max_width;
    
}

/*Return biggest cell of type Matrix*/
/*Takes in a matrix, returns an array with
  Biggest cell of all rows in each column			*/
int *
return_biggestM(int *list, int n, int m) 
{
	int *biggest_per_column = malloc(sizeof(int) * m);
	
	if(biggest_per_column == NULL)
		perror("Malloc error");

	int  big_frst;
	int keep_t = 0;
	int tracker = 0;
	int 	i,j;
	

	int index_m = m;

	/*COLS*/
	for(i = 0; i < m; i++) {
		/*At each column, it stores the width
		  of the first row/column for comparing*/
		big_frst = list[keep_t];

	/*ROWS*/
		for(j = 0; j < n; j++) {
			if(big_frst < list[keep_t]) {
				
					big_frst = list[keep_t];
				}

				keep_t++;
				
			}	
					biggest_per_column[i] = big_frst;
		}
		
	return biggest_per_column;

}

/*Collect with of vector elements*/
int *
getWidthV(vector *vec) 
{

    //char ** m_values;
    char ** v_values;
    int  *  vec_elem_length;
    int  *  vec_elem_spacing;
    int     i;
    int     max_vec;


            vec_elem_length = malloc(sizeof(int) * vec -> size);
		
			if(vec_elem_length == NULL)
				perror("Malloc error");

            vec_elem_spacing = malloc(sizeof(int) * vec -> size);
			
			if(vec_elem_spacing == NULL)
				perror("Malloc error");
            
			v_values = malloc(sizeof(char *) * vec -> size);

			
			if(v_values == NULL)
				perror("Malloc error");
	

            for(i = 0; i < vec -> size; i++) {
                
                    v_values[i] = malloc(sizeof(char) * 15);
           	}
            
            for(i = 0; i < vec -> size; i++) {
                     sprintf(v_values[i], "%g", vec -> data[i]);  
            }
            
            for(i = 0; i < vec -> size; i++) {
                 vec_elem_length[i] = strlen(v_values[i]);              
           	}
            
            max_vec = return_biggest(vec_elem_length, vec -> size);
            
            for(i = 0; i < vec -> size; i++) {
				vec_elem_spacing[i] = (max_vec - vec_elem_length[i]);
            }

            for(i = 0; i < vec -> size; i++) {
                    free(v_values[i]);
                }
           
            free(v_values);
            free(vec_elem_length);
            return vec_elem_spacing;
}

/*Get width of elements in matrix*/
int **getWidthM(matrix *m) {

	int		   i;
	int 	   j;
	int		   dim_x = m -> m_x;
	int		   dim_y = m -> m_y;
	int 	   malloc_dimension 	 = (dim_x * dim_y);
	int		   ix_track 			 = 0;
	char 	** str_cont;	
	int 	** spacePerCell 		 = malloc(sizeof(int*) * dim_x);
	int		*  originalWidthString   = malloc(sizeof(int) * malloc_dimension);
	int		*  bigCont;

	/*Check allocation*/
	
	if(spacePerCell == NULL)
		perror("Malloc error");

	if(originalWidthString == NULL)
		perror("Malloc error");


	/*Convert elements to string number spacing*/
	if(m -> vType == DOUBLE)
		str_cont = cnvrt_double_Array(m -> data, dim_x, dim_y);
	
	else
		str_cont = cnvrt_float_Array(m -> fmatrix, dim_x, dim_y);

	for(i = 0; i < dim_x; i++) {
		spacePerCell[i] = malloc(sizeof(int) * dim_y);
	}

	/*Get original width of all elements in Matrix*/	
	for(i = 0; i < malloc_dimension; i++) 
		originalWidthString[i] = strlen(str_cont[i]);
	
	/*Helper function to find width of the biggest element in a given cell*/
	bigCont = return_biggestM(originalWidthString, dim_x, dim_y);

	for(i = 0; i < dim_y ;i++) {
			for(j = 0; j < dim_x; j++) {
				spacePerCell[j][i] = bigCont[i] - originalWidthString[ix_track];
				ix_track++;
		}			
	}	
	
	/*Free all containers we won't use anymore*/
	
	free(originalWidthString);
	free(bigCont);

	for(i = 0; i < malloc_dimension; i++) {
			free(str_cont[i]);
		}
			free(str_cont);
			

	return spacePerCell;
	
}

/*One print function, detect types*/
void print_p(void *ptr, ContainerType type) {
    
    int     i,j;
    int     *vec_elem;
    int     **mat_elem;
	vector	*v;
	matrix	*mat;

    if(type ==  VECTOR) {
        v = (vector*)ptr;
        vec_elem = getWidthV(v);
        printf("\n");

        for(i = 0; i < v -> size; i++) {
            printf("[");
            ms(vec_elem[i],' ');
            printf("%g", v -> data[i]);
            printf("]\n");              
        }

        free(vec_elem);
    }

    else if(type == MATRIX) {
        mat = (matrix*)ptr;
        mat_elem = getWidthM(mat);
        printf("\n");	
		
        for(i = 0; i < mat -> m_x; i++) {
            printf("[");
            for(j = 0; j < mat -> m_y; j++) {
                ms(mat_elem[i][j], ' ');

                if(mat -> vType == DOUBLE)
                    printf(" %g ", mat -> data[i][j]);

                else 
                    printf(" %g ", mat -> fmatrix[i][j]);
            }

            printf("]\n");
        }
        printf("\n");
        free(mat_elem);	
    }
}

