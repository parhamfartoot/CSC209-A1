#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_image(int num_rows, int num_cols, 
                int arr[num_rows][num_cols], FILE *fp);
                
void print_image(int num_rows, int num_cols, int arr[num_rows][num_cols]);

// Remember to include the function prototype for count_cells

int count_cells(int num_rows, int num_cols,
                int arr[num_rows][num_cols]);


int main(int argc, char **argv) {
    // Print a message to stderr and exit with an argument of 1 if there are
    // not the right number of parameters, or the second argument is not -p

    if ((argc-1 != 2) || strcmp(argv[2], "-p") != 0){
        fprintf( stderr,"Usage: count_cells <imagefile.txt> [-p]\n");
        exit(1);
    }

    int p, q; // assume p and q have valid values
    FILE *fp; // assume fp holds a valid open file pointer

    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Could not open file ");
        return 0;
    }
    fscanf(fp, "%d", &p);
    fscanf(fp, "%d", &q);

    int a[p][q];
    read_image(p, q, a, fp);

    fprintf( stdout, "Number of Cells is %d\n",count_cells(p,q,a) );
    print_image(p,q,a);


    return 0;
}