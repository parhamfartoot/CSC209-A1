#include <stdio.h>
#include <stdbool.h>
    
/* Reads the image from the open file fp into the two-dimensional array arr 
 * num_rows and num_cols specify the dimensions of arr
 */
void read_image(int num_rows, int num_cols, 
                int arr[num_rows][num_cols], FILE *fp) {

    for(int i=0; i < num_rows; i++)
        for(int j=0; j < num_cols; j++)
            fscanf(fp, "%d", &arr[i][j]);

    fclose(fp);



}

/* Print to standard output the contents of the array arr */
void print_image(int num_rows, int num_cols, int arr[num_rows][num_cols]) {

    for(int i=0; i < num_rows; i++){
        for(int j=0; j < num_cols; j++){
            printf("%d",arr[i][j]);}
        printf("\n");}
}

/* TODO: Write the count_cells function */

void traverse(int i, int j,int num_rows, int num_cols,int arr[num_rows][num_cols],int val,int pass) {

    bool canUp = (i - 1 >= 0);
    bool canDown = (i + 1 < num_rows);
    bool canRight = (j + 1 < num_cols);
    bool canLeft = (j - 1 >= 0);

    arr[i][j] = pass;

        if (canRight && arr[i][j + 1] == val) {
            traverse(i, j + 1, num_rows, num_cols, arr, val,0);
        }
        if (canDown && arr[i + 1][j] == val ) {
            traverse(i + 1, j, num_rows, num_cols, arr, val,0);
        }
        if (canLeft && arr[i][j - 1] == val) {
            traverse(i, j - 1, num_rows, num_cols, arr, val,0);
        }

        if (canUp && arr[i - 1][j] == val) {
            traverse(i - 1, j, num_rows, num_cols, arr, val,0);
        }

}
int count_cells(int num_rows, int num_cols,
                int arr[num_rows][num_cols]){

    for(int i=0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if(arr[i][j] != 0) {
                int val =  arr[i][j];
                traverse(i, j, num_rows, num_cols, arr, val,val);
                arr[i][j] = val;
            }
        }
    }
    int count = 0;
    for(int i=0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (arr[i][j] !=0 )
                count= count+1;
        }
    }
    return  count;


}