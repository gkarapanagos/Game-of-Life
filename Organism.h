//	Programming Assignment #6
//	George Karapanagos
//	Polymorphism (Predator-prey)


#ifndef ORGANISM_H_
#define ORGANISM_H_
#include <vector>
typedef std::vector< std::vector<int> > array;


class Organism{
public:
	virtual void breed(int x, int y, array& grid, array& steps, array& feed, array& move)=0;
	virtual void move(int x, int y, array& grid, array& steps, array& feed, array& move)=0;
private:
	int steps;
	int feed;
};

class Ant : Organism{
public:
	int breedNr;
	Ant(int ants, array& grid);
	void breed(int x, int y, array& grid, array& steps, array& feed, array& move);
	void move(int x, int y, array& grid, array& steps, array& feed, array& move);
};

class Doodlebug : Organism{
public:
	int breedNr;
	Doodlebug(int doodlebugs, array& grid);
	void breed(int x, int y, array& grid, array& steps, array& feed, array& move);
	void move(int x, int y, array& grid, array& steps, array& feed, array& move);
	void starve(int x, int y, array& grid, array& steps, array& feed);
	void eat(int x, int y, array& grid, array& steps, array& feed, array& move);

};

#endif /* ORGANISM_H_ */
