#include "linear.h"

/*linear.h implementation*/


/*
* Vectors
*/


vector *
alloc_vec(size_t n) {
/*
Allocate space for new vector, returns the new initialized
struct of type vector.
*/
	vector *new_vec = (vector*)malloc(sizeof(vector));
	if(new_vec == NULL)
		perror("Malloc error");
	
	new_vec -> data = (double*)calloc(n,sizeof(double));
	if(new_vec -> data == NULL)
		perror("Calloc error within vector structure");
	
		new_vec -> size = n;
		new_vec -> index = 0;

	return new_vec;
}

void 
push_back(vector *vec, double x) {
/*
Push a new element to the vector
*/
	vec -> data[vec -> index] = x;
		vec -> index += 1;
}


void 
vector_clear(vector *vec) {
    int i;

    for(i = 0; i < vec -> size; i++) {
        vec -> data[i] = 0.0;    
    }

    /*reset the index*/
    vec -> index = 0;
}


vector *
init2Dv(double x, double y) 
{
    vector *vec;

    vec = alloc_vec(2);
    vec -> data[0] = x;
    vec -> data[1] = y;   
    
    
    return vec; 
    
}

vector *
zeroVector(size_t size) 
{
    int i;
    vector *n_zero_v;

    n_zero_v = alloc_vec(size);

    memset(n_zero_v, 0, size);

        return n_zero_v;
        
}

vector *
baseVector(vector *vec_1, vector *vec_2) 
{
    int     i;
    vector  *base;
    
    if(vec_1 -> size != vec_2 -> size) 
        printf("Vector unequal\n");

    base = alloc_vec(vec_1 -> size);
        
    for(i = 0; i < vec_1 -> size; i++) {
            
                base -> data[i] = (vec_2 -> data[i] - vec_1 -> data[i]);
        
        }
        
    return base;
}


/*
* Matrices*
*/

matrix *
alloc_mat(size_t n, size_t m, varType v) {

    int i;
    
	matrix *new_matrix = malloc(sizeof(matrix));
	
	if(new_matrix == NULL)
		perror("Malloc error");

    new_matrix -> m_x = n;
    new_matrix -> m_y = m;
	new_matrix -> vType = v;

	if(new_matrix -> vType == DOUBLE)
    	new_matrix -> data = malloc(n * sizeof(double *));
	
	else
		new_matrix -> fmatrix = malloc(n * sizeof(float *));

	if(new_matrix -> data == NULL)
		perror("Malloc error within matrix structure");
    
    for(i = 0; i < n; i++) {
        
		if(new_matrix -> vType == DOUBLE) 
            new_matrix -> data[i] = malloc(m * sizeof(double));

		else
			new_matrix -> fmatrix[i] = malloc(m * sizeof(float));
        }


        return new_matrix;
}

int 
initialize(matrix *mat, double element) 
{
    int i;
    int j;
    
    for(i = 0; i < mat -> m_x; i++) {
        for(j = 0; j < mat -> m_y; j++) {
             
                mat -> data[i][j] = element;
            }
        }    
    
    return 0;
}

void 
setValueCoord(matrix *mat, int x, int y, double v) 
{
    
    /*Check for boundaries*/
    if(x <= mat -> m_x && y <= mat -> m_y)
        mat -> data[x][y] = v;
}

void 
setValueCoordF(matrix *mat, int x, int y, float v) 
{
    
    /*Check for boundaries*/
    if(x <= mat -> m_x && y <= mat -> m_y)
        mat -> fmatrix[x][y] = v;
}


// Fill matrix with float numbers
void setMatrixF(matrix *mat, float *arr) {

	int i,j, p = 0;

	for(i = 0; i < mat -> m_x; i++) {
		for(j = 0; j < mat -> m_y; j++) {
			mat -> fmatrix[i][j] = arr[p];
			p++;
		}
	}
	

}


double 
getValueCoord(matrix *mat, int x, int y) 
{

    double value;

    if(x <= mat -> m_x || y <= mat -> m_y)
        value = mat -> data[x][y];


        return value;
}

void 
free_object(void *ptr, ContainerType type) 
{
	int		i;
	vector *free_vec;
	matrix *free_mat;
	
    if(type == VECTOR) {

        free_vec = (vector*)ptr;				
        free(free_vec -> data);
        free(free_vec);
    }
    else if(type == MATRIX) {	

        free_mat = (matrix*)ptr;
        for(i = 0; i < free_mat -> m_x; i++) {
            if(free_mat -> vType == DOUBLE) {
				free(free_mat -> data[i]);
            }
			else {
				free(free_mat -> fmatrix[i]);
            }
        }
	
        if(free_mat -> vType == DOUBLE)
            free(free_mat -> data);
		
        else
            free(free_mat -> fmatrix);

        free(free_mat);

	}
    
}




