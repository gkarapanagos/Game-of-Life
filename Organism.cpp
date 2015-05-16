//	Programming Assignment #6
//	George Karapanagos
//	Polymorphism (Predator-prey)

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Organism.h"
#include <vector>
#include <time.h>

Ant::Ant(int ants, array& grid){
//place all ants in the grid
breedNr=3;
for(int i=0; i<ants; i++){

	bool check = false; //check if the randomly
						//generated place in the grid is empty

	while(check==false){
	int a = 20 * rand()/int(RAND_MAX);	//random row
	int b = 20 * rand()/int(RAND_MAX);	//random column
	//if this random place is empty, place the ant there
	//and exit the while-loop for this ant
	if(grid[a][b]==0){
		grid[a][b]=1;	//set it to 1 = ANT
		check=true;}
	}}
}

Doodlebug::Doodlebug(int doodlebugs, array& grid){
//place all doodlebugs in the grid
	breedNr=8;
for(int i=0; i<doodlebugs; i++){

	bool check = false; //check if the randomly
						//generated place in the grid is empty

	while(check==false){
	int a = 20 * rand()/int(RAND_MAX);	//random rows
	int b = 20 * rand()/int(RAND_MAX);	//random column
	//if this random place is empty, place the bug there
	//and exit the while-loop for this doodlebug
	if(grid[a][b]==0){
		grid[a][b]=2;	//set it to 2 = DOODLEBUG
		check=true;}
	}}
}

//the move function of the ants
void Ant::move(int x, int y, array& grid, array& steps, array& feed, array& move){
	int u=0, d=0, r=0, l=0; //integers up, down, right, left
		int count=0;    //count how many of the 4 options empty
		if(x>1){if(grid[x-1][y]==0){ l=1; count++;}}
		if(y>1){if(grid[x][y-1]==0){ d=1; count++;}}
		if(y<19){if(grid[x][y+1]==0){ u=1; count++;}}
		if(x<19){if(grid[x+1][y]==0){ r=1; count++;}}


	if((count>0)&&(move[x][y]==0)){	//if the ant has any choice of where to move
		int target= 1+count*rand()/int(RAND_MAX);	//random between 1 and count
		count=0;	//set count to 0 again
		if(l==1) {
			count++;
			if(count==target){
				//if this is the randomly generated place
				//move the ant there
				grid[x-1][y]=1;
				grid[x][y]=0;
				steps[x-1][y]=steps[x][y]+1;
				steps[x][y]=0;
				feed[x-1][y]=feed[x][y]+1;
				move[x][y]=0;
				move[x-1][y]=1;
			}}
		if(d==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//move the ant there
					grid[x][y-1]=1;
					grid[x][y]=0;
					steps[x][y-1]=steps[x][y]+1;
					steps[x][y]=0;
					feed[x][y-1]=feed[x][y]+1;
					move[x][y]=0;
					move[x][y-1]=1;
				}}
		if(u==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//move the ant there
					grid[x][y+1]=1;
					grid[x][y]=0;
					steps[x][y+1]=steps[x][y]+1;
					steps[x][y]=0;
					feed[x][y+1]=feed[x][y]+1;
					move[x][y]=0;
					move[x][y+1]=1;
				}}
		if(r==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//move the ant there
					grid[x+1][y]=1;
					grid[x][y]=0;
					steps[x+1][y]=steps[x][y]+1;
					steps[x][y]=0;
					feed[x+1][y]=feed[x][y]+1;
					move[x][y]=0;
					move[x+1][y]=1;
				}}
	} //end of if-statement
}

void Ant::breed(int x, int y, array& grid, array& steps, array& feed, array& move){
	int u=0, d=0, r=0, l=0; //integers up, down, right, left
		int count=0;    //count how many of the 4 options empty
		if(steps[x][y]>breedNr){
		if(x>1){if(grid[x-1][y]==0){ l=1; count++;}}
		if(y>1){if(grid[x][y-1]==0){ d=1; count++;}}
		if(y<19){if(grid[x][y+1]==0){ u=1; count++;}}
		if(x<19){if(grid[x+1][y]==0){ r=1; count++;}}
		if(count>0){	//if the ant has any choice of where to breed
			int target= 1+count*rand()/int(RAND_MAX);	//random between 1 and count
			count=0;	//set count to 0 again
			if(l==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//breed the ant there
					grid[x-1][y]=1;
					move[x-1][y]=1;
					steps[x-1][y]=0;
					steps[x][y]=0;
				}}
			if(d==1) {
					count++;
					if(count==target){
						//if this is the randomly generated place
						//breed the ant there
						grid[x][y-1]=1;
						move[x][y-1]=1;
						steps[x][y-1]=0;
						steps[x][y]=0;
					}}
			if(u==1) {
					count++;
					if(count==target){
						//if this is the randomly generated place
						//eat the ant there
						grid[x][y+1]=1;
						move[x][y+1]=1;
						steps[x][y+1]=1;
						steps[x][y]=0;
					}}
			if(r==1) {
					count++;
					if(count==target){
						//if this is the randomly generated place
						//breed the ant there
						grid[x+1][y]=1;
						move[x+1][y]=1;
						steps[x+1][y]=0;
						steps[x][y]=0;
					}}
		} //end of if-statement



		}
	}

void Doodlebug::breed(int x, int y, array& grid, array& steps, array& feed, array& move){
	int u=0, d=0, r=0, l=0; //integers up, down, right, left
	int count=0;    //count how many of the 4 options empty
	if(steps[x][y]>breedNr){
	if(x>1){if(grid[x-1][y]==0){ l=1; count++;}}
	if(y>1){if(grid[x][y-1]==0){ d=1; count++;}}
	if(y<19){if(grid[x][y+1]==0){ u=1; count++;}}
	if(x<19){if(grid[x+1][y]==0){ r=1; count++;}}
	if(count>0){	//if the doodlebug has any choice of where to breed
		int target= 1+count*rand()/int(RAND_MAX);	//random between 1 and count
		count=0;	//set count to 0 again
		if(l==1) {
			count++;
			if(count==target){
				//if this is the randomly generated place
				//breed the bug there
				grid[x-1][y]=2;
				move[x-1][y]=1;
				steps[x-1][y]=0;
				steps[x][y]=0;
			}}
		if(d==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//breed the bug there
					grid[x][y-1]=2;
					move[x][y-1]=1;
					steps[x][y-1]=0;
					steps[x][y]=0;
				}}
		if(u==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//breed the bug there
					grid[x][y+1]=2;
					move[x][y+1]=1;
					steps[x][y+1]=0;
					steps[x][y]=0;
				}}
		if(r==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//breed the bug there
					grid[x+1][y]=2;
					move[x+1][y]=1;
					steps[x+1][y]=0;
					steps[x][y]=0;
				}}
	} //end of if-statement



	}
}
//the starve function of the doodlebug
void Doodlebug::starve(int x, int y, array& grid, array& steps, array& feed){
	if(feed[x][y]>2){
		steps[x][y]=0;
		grid[x][y]=0;
		feed[x][y]=0;
	}
}
//the move function of the doodlebug
void Doodlebug::move(int x, int y, array& grid, array& steps, array& feed, array& move){
	int u=0, d=0, r=0, l=0; //integers up, down, right, left
	int count=0;    //count how many of the 4 options empty
	if(x>1){if(grid[x-1][y]==0){ l=1; count++;}}
	if(y>1){if(grid[x][y-1]==0){ d=1; count++;}}
	if(y<19){if(grid[x][y+1]==0){ u=1; count++;}}
	if(x<19){if(grid[x+1][y]==0){ r=1; count++;}}

//if(count==0){feed[x][y]=feed[x][y]+1;}
if((count>0)&&(move[x][y]==0)){	//if the doodlebug has any choice of where to move
	int target= 1+count*rand()/int(RAND_MAX);	//random between 1 and count
	count=0;	//set count to 0 again
	if(l==1) {
		count++;
		if(count==target){
			//if this is the randomly generated place
			//move the bug there
			grid[x-1][y]=2;
			grid[x][y]=0;
			steps[x-1][y]=steps[x][y]+1;
			steps[x][y]=0;
			feed[x-1][y]=feed[x][y]+1;
			feed[x][y]=0;
			move[x-1][y]=1;
			move[x][y]=0;
		}}
	if(d==1) {
			count++;
			if(count==target){
				//if this is the randomly generated place
				//move the bug there
				grid[x][y-1]=2;
				grid[x][y]=0;
				steps[x][y-1]=steps[x][y]+1;
				steps[x][y]=0;
				feed[x][y-1]=feed[x][y]+1;
				feed[x][y]=0;
				move[x][y-1]=1;
				move[x][y]=0;
			}}
	if(u==1) {
			count++;
			if(count==target){
				//if this is the randomly generated place
				//move the bug there
				grid[x][y+1]=2;
				grid[x][y]=0;
				steps[x][y+1]=steps[x][y]+1;
				steps[x][y]=0;
				feed[x][y+1]=feed[x][y]+1;
				feed[x][y]=0;
				move[x][y+1]=1;
				move[x][y]=0;
			}}
	if(r==1) {
			count++;
			if(count==target){
				//if this is the randomly generated place
				//move the bug there
				grid[x+1][y]=2;
				grid[x][y]=0;
				steps[x+1][y]=steps[x][y]+1;
				steps[x][y]=0;
				feed[x+1][y]=feed[x][y]+1;
				feed[x][y]=0;
				move[x+1][y]=1;
				move[x][y]=0;
			}}
} //end of if-statement
}

//the eat function of the doodlebug
void Doodlebug::eat(int x, int y, array& grid, array& steps, array& feed, array& move){
	int u=0, d=0, r=0, l=0; //integers up, down, right, left
	int count=0;    //count how many of the 4 options empty
	if(x>1){if(grid[x-1][y]==1){ l=1; count++; }}
	if(y>1){if(grid[x][y-1]==1){ d=1; count++; }}
	if(y<19){if(grid[x][y+1]==1){ u=1; count++;}}
	if(x<19){if(grid[x+1][y]==1){ r=1; count++;}}

	if((count>0)&&(move[x][y]==0)){

		//if the doodlebug has any choice of what to eat
		int target= 1+count*rand()/int(RAND_MAX);	//random between 1 and count
		count=0;	//set count to 0 again
		if(l==1) {
			count++;
			if(count==target){
				//if this is the randomly generated place
				//eat the ant there
				grid[x-1][y]=2;
				grid[x][y]=0;
				steps[x-1][y]=steps[x][y]+1;
				steps[x][y]=0;
				feed[x-1][y]=0;
				move[x-1][y]=1;
				move[x][y]=0;
			}}
		if(d==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//eat the ant there
					grid[x][y-1]=2;
					grid[x][y]=0;
					steps[x][y-1]=steps[x][y]+1;
					steps[x][y]=0;
					feed[x][y-1]=0;
					move[x][y-1]=1;
					move[x][y]=0;
				}}
		if(u==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//eat the ant there
					grid[x][y+1]=2;
					grid[x][y]=0;
					steps[x][y+1]=steps[x][y]+1;
					steps[x][y]=0;
					feed[x][y+1]=0;
					move[x][y+1]=1;
					move[x][y]=0;
				}}
		if(r==1) {
				count++;
				if(count==target){
					//if this is the randomly generated place
					//eat the ant there
					grid[x+1][y]=2;
					grid[x][y]=0;
					steps[x+1][y]=steps[x][y]+1;
					steps[x][y]=0;
					feed[x+1][y]=0;
					move[x+1][y]=1;
					move[x][y]=0;
				}}
	} //end of if-statement
}
