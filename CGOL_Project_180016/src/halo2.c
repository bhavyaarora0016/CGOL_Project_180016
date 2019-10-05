/*
 ============================================================================
 Name        : halo2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CGOL in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Global function
void nexlife(int arr[100][100], int r, int c);
// Global Variable
int futlife[100][100], arr[100][100];

int main(void) {

//Used to get the print statement first while using scanf function
setbuf(stdout, NULL);
// Variables
int a,c, i, j;
int run;
printf("Enter the no of rows of the Array:\n");
scanf("%d", &a);
printf("Enter the no of columns of the Array:\n");
scanf("%d", &c);


printf("0 is the dead cell and 1 is the alive cell, so enter the elements according to it \n");
printf("Enter the CGOL Array:\n");

//Taking the input from the user
for(i = 0; i<a; i++){
for(j=0; j<c; j++){
scanf("%d", &arr[i][j]);
}
}

printf("Enter how many generations \n");
scanf("%d", &run);

for(i=0; i<run; i++){
nexlife(arr, a, c);

}


return 0;
}

//Function which contain the logic for the next generation of CGOL
void nexlife(int arr[100][100], int r, int c){


int i,j,k,l;

// Loop through every cell of the every row and column
for(i=1; i<r-1; i++){
for(j=1; j<c-1; j++){

// Find how many cells are alive
int Cell = 0;
for(k=-1; k<=1; k++)
for(l=-1; l<=1; l++)
Cell = Cell + arr[i+k][j+l];

Cell = Cell - arr[i][j];

// If cell is lonely then it dies
if((arr[i][j] == 1) && (Cell < 2)){
futlife[i][j] = 0;
}

// If cell is overpopulated, it dies
else if((arr[i][j] == 1) && (Cell > 3)){
futlife[i][j] = 0;
}

// A new cell is born as 3 adjacent cells are alive
else if((arr[i][j] == 0) && (Cell ==3)){
futlife[i][j] = 1;
}

// Nothing happens so it remains same
else{
futlife[i][j] = arr[i][j];
}
}
}

printf("\n");
printf("Next Life is: \n");

// Printing the next life
for(k=0; k<r; k++){
for(l=0; l<c; l++){
printf("%d ", futlife[k][l]);
}
printf("\n");
}

//Assigning the next life to the main array to print further generation
for (k = 0; k < r; k++) {
for (l = 0; l < c; l++) {
arr[k][l] = futlife[k][l];
}
}
}
