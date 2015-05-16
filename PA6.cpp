//	Programming Assignment #6
//	George Karapanagos
//	Polymorphism (Predator-prey)

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Organism.h"
#include <vector>
#include <time.h>

int rows, columns, nrA, nrD, nrS, count;
//number of Ants, Doodlebugs and Steps
int main(int argc, char *argv[]) {
	srand(time(NULL)); //the seed of rand
	//set the dimensions of the grid
	if(argc>1){
		rows	=atoi(argv[1]); //if command line argument exists
		columns	=atoi(argv[1]); //if command line argument exists
	}
	else{
		rows	=20; 	  //default value
		columns	=20;	  //default value
	}

	//set the number of doodlebugs
	if(argc>2){
		nrD=atoi(argv[2]);	//if command line argument exists
	}
	else{
		nrD=5;				//default value
	}

	//set the number of ants
	if(argc>3){
		nrA=atoi(argv[3]);	//if command line argument exists
	}
	else{
		nrA=100;			//default value
	}

	//set the number of steps
	if(argc>4){
		nrS=atoi(argv[4]);	//if command line argument exists
	}
	else{
		nrS=1000;			//default value
	}



// 2-D array of organisms
std::vector< std::vector<int> > grid;
grid.resize(rows);
for(int i=0; i<rows; 	i++){
	grid[i].resize(columns);
}

// 2-D array of number of steps of each organism
std::vector< std::vector<int> > steps;
steps.resize(rows);
for(int i=0; i<rows; 	i++){
	steps[i].resize(columns);
}

// 2-D array of feed counter of each doodlebug
std::vector< std::vector<int> > feed;
feed.resize(rows);
for(int i=0; i<rows; 	i++){
	feed[i].resize(columns);
}
// 2-D array of organisms
std::vector< std::vector<int> > move;
move.resize(rows);
for(int i=0; i<rows; 	i++){
	move[i].resize(columns);
}

//initialize all 3 2-D arrays to have values of 0
for(int i=0; i<rows; 	i++){
for(int k=0; k<columns; k++){
		grid[i][k] =0;
		steps[i][k]=0;
		feed[i][k] =0;
		move[i][k] =0;
	}}

Doodlebug D(nrD, grid);	//the object of the doodlebug derived class
Ant A(nrA, grid);		//the object of the ant derived class

while(count<nrS){
	for(int i=0; i<rows; 	i++){
	for(int k=0; k<columns; k++){
			move[i][k] =0;
		}}
	//check for doodlebugs
	for(int i=0; i<rows; 	i++){
	for(int k=0; k<columns; k++){

		//check if the doodlebug has starved
			if(grid[i][k]==2){
				D.starve(i,k, grid, steps, feed);

				//if not call its eat function
			if(grid[i][k]==2){
					D.eat(i, k, grid, steps, feed, move);
					//if the bug didn't eat an ant, move it
					//if it has a spot to move to
			if(grid[i][k]==2){
					D.move(i,k, grid, steps, feed, move);
				}
				D.breed(i, k, grid, steps, feed, move);
			}}}}

	//check for ants
	for(int i=0; i<rows; 	i++){
	for(int k=0; k<columns; k++){

		//call the ant's move function
			if(grid[i][k]==1){
				A.breed(i, k, grid, feed, steps, move);
				A.move(i,k, grid, steps, feed, move);
			    }

		}}

	count++;


}

//print the grid to the output
	for(int i=0; i<rows; 	i++){
			std::cout<<std::endl;
	for(int k=0; k<columns; k++){
		if(grid[i][k]==1){
			std::cout<<"o";
		}
		if(grid[i][k]==2){
			std::cout<<"x";
			}
		if(grid[i][k]==0){
			std::cout<<" ";
			}

		}}
	std::cout<<std::endl;

	return EXIT_SUCCESS;
}


