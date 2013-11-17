glPrint
========

Prettyprints openGL vectors and matrices
    
    
Examples:

A simple 2D vector
  
    vector *test = init2Dv(-3, -2);

    print_p(test, VECTOR);
    
Output:

    [-3]
    [-2]

3D vector
  
    vector *a = alloc_vec(3);
	
You can use push_back with vectors
  
    push_back(a, 4);
    push_back(a, -7);
    push_back(a, 229);

Print it:

    print_p(a, VECTOR);
	
Make a matrix
	
    matrix *matr = alloc_mat(3, 3, FLOAT);

    setValueCoord(matr, 0, 0, 3.1415926);
    setValueCoord(matr, 0, 1, 		  45);
    setValueCoord(matr, 0, 2, 	   2003);
	
    setValueCoord(matr, 1, 0, 		  1);
    setValueCoord(matr, 1, 1, 	  20555);
    setValueCoord(matr, 1, 2, 	    255);

    setValueCoord(matr, 2, 0, 	  25.55);
    setValueCoord(matr, 2, 1, 		  9);
    setValueCoord(matr, 2, 2, 	  85550);
	
    print_p(matr, MATRIX);

Output:

    [ 3.14159     45   2003 ]
    [       1  20555    255 ]
    [   25.55      9  85550 ]

Free your stuff with free_object

    free_object(test, VECTOR);
    free_object(a, VECTOR);
    free_object(matr, MATRIX);

