//Cora Monokandilos
//cmonokan
//CMPS 101
//pa02
//implementation for loadGraph.h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
// #include "intVec.c"

//#include "intVec.c"
//#include "parseEdge.c"


IntVec* transposeGraph(IntVec* origGraph, int n){

	// IntVec *tempGraph = (IntVec*)calloc(n+1, sizeof(IntVec));
	// int edge;
	// while(intTop(origGraph[i]) != -1){
	// 		//printf("%d ", intTop(array[i]));
	// 	tempGraph[i] = origGraph[i];
	// 	intVecPop(origGraph[i]);

	if(origGraph == NULL){
		printf("calling transposeGraph() on a NULL Graph!\n");
		exit(1);
	}


	IntVec* newGraph = (IntVec*)calloc(n+1, sizeof(IntVec));;

    for(int i = 1; i < n+1; i++){
        newGraph[i] = intMakeEmptyVec();
    }

    int new;

	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < intSize(origGraph[i]); j++){
			new = intData(origGraph[i], j);
			intVecPush(newGraph[new], i);
		}
	}

	return newGraph;
	printAdjVerts(newGraph, n);
}

int** makeAdjMatrix(IntVec array[], int n){

	if(n > 20){
		printf("Matrix is too large");
		exit(1);
	}
	else{
		int r = n+1;
		int c = n+1;

		int ** adjMatrix = (int**)malloc(r*sizeof(int*));
		for(int i = 0; i<r;i++){
			adjMatrix[i] = (int*)malloc(c*sizeof(int));

			int top = intTop(array[i]);
			if( top == -1){
				adjMatrix[i][intTop(array[i])] = 0;
				continue; 
			}

			int sz = intSize(array[i]);

			//while there are still elements in the array, print the element and pop (decrease the size)
			while(intTop(array[i]) != -1){
				adjMatrix[i][intTop(array[i])] = 1;
				intVecPop(array[i]);
			}
			setSize(array[i], sz);
		
		}
		return adjMatrix;
	}

}





