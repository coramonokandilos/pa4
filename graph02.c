//Cora Monokandilos
//cmonokan
//CMPS 101
//main program


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
// #include "intVec.c"
#include "parseEdge.c"
#include "printAll.c"
#include "loadGraph.c"


int main(int argc, char * argv[]){

    //check the number of arguments in users input
    if(argc != 2){
        fprintf(stderr, "Form: programName, inputFile");
        exit(0);
    }

    //open the file
    FILE * openFile = fopen(argv[1], "r");

    //init an array to store the fgets
    char arrayFirstInfo[2000];
    int numberEdges = 0;

    if(openFile == NULL){
        fprintf(stderr,"Not correct file -- cannot open\n");
        exit(1);
    }

    //reading first line & getting the size of the array
    //destination, how many spaces you wanna allocate, file name
    char * first = fgets(arrayFirstInfo, 2000, openFile);
    int vert = atoi(first);         //ascii to int

    //initialize an array 
    //int to keep track of how many edges 
    IntVec array[vert];

    //initialize new edge to use for later
    Edge newE;

    //new intVec array in each of the prev array spots
    int sizeArray = sizeof(array)/sizeof(array[0]); //the number of spots there are in the array
    for(int i = 0; i < sizeArray+1; i++){
        array[i] = intMakeEmptyVec();
    }
    first = fgets(arrayFirstInfo, 2000, openFile);
    while(first == arrayFirstInfo){
        numberEdges++;
        newE = parseEdge(first, array);
        intVecPush(array[fromEdge(newE)], toEdge(newE));


        //getting next line
        first = fgets(arrayFirstInfo, 2000, openFile);
    }


    printf("number of vertices: %d\n", sizeArray);
    printf("number of edges: %d\n", numberEdges);


    printAdjVerts(array, sizeArray);

    int ** matrix = makeAdjMatrix(array, sizeArray);
    printAdjMatrix(matrix, sizeArray);

    IntVec* transpose = transposeGraph(array, sizeArray);
    printAdjVerts(transpose, sizeArray);

    int ** transposeMatrix = makeAdjMatrix(transpose, sizeArray);
    printAdjMatrix(transposeMatrix, sizeArray);




    return(0);
}
   