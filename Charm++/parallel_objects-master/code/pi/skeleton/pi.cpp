#include "pi.decl.h"

CProxy_Master mainProxy; // readonly

/* Master (main chare) class */
class Master : public CBase_Master {
public:
	// Atributes:
	// - count:
	// - totalInside
	// - totalNumTrials
	int count, totalInside, totalNumTrials;

	// Constructor
	Master(CkArgMsg* m) { // CkArgMsg conteins the Argv, Argc
		if (m->argc < 3) {
			ckout << "ERROR, usage " << m->argv[0] << " <number of trials> <number of chares>" << endl;
			CkExit();
		}
		int numTrials = atoi(m->argv[1]); // number of points of MCarlo
		int numChares = atoi(m->argv[2]); // number of subdivisions
		if (numTrials % numChares) { 
			ckout << "ERROR, number of trials need to be divisible by number of chares" << endl;
			CkExit();
		}
		else{
			ckout << "\nEl número de MCarlo trials: " << numTrials << " and the number of CHares: " << numChares << "\n" << endl;
		}
		/* TO DO: create numChares objects type Worker, each with numTrials/numChares as parameter */	  
		//======= Que pasa con la doble repetición de nombres???
		for(int i=0; i<numChares; i++){
			CProxy_Worker numCharesObj = CProxy_Worker::ckNew(numTrials/numChares);
		}

		count = numChares; // wait for count responses.
		ckout << "The initial count is: " << count << endl;
		mainProxy= thisProxy;
		totalInside = 0;
		totalNumTrials = 0;
	};
	
	// Methods
	void addContribution(int numInside, int numTrials) {
		//ckout << "Entro en addContribution"  << endl;
		totalInside += numInside;
		totalNumTrials += numTrials;
		count--;
		//ckout << "The number of current count is: " << count << endl;
		if (count == 0) {
			double myPi = 4.0* ((double) (totalInside))
				/ ((double) (totalNumTrials));
			ckout << "Approximated value of pi is:" << myPi << endl;
			CkExit();
		}
	}

};

/* Worker class */
class Worker : public CBase_Worker {
public:
	float y;

	Worker(int numTrials) {
		int inside = 0;
		double x, y;
		ckout << "Hello from a simple chare running on " << CkMyPe() << endl;

		/* TO DO: get numTrials random (x,y) points using drand48() function, inside variable counts how many fall into the unit circle */
		for(int i = 0; i < numTrials; i++){
			x = drand48(); // Get random numbers
			y = drand48(); // Get random numbers
			if (x*x + y*y < 1) inside++; // pi*R^2
		}
		ckout << "numTrials, inside:  " << numTrials<< " "<< inside << endl;
		/* TO DO: call addContribution entry method from mainchare and pass inside and numTrials as parameters */
		// COMO LLAMAR A METODOS de MASTER? 
		// SI es un proxy, proxy.foo()
		// Si es una clase, class.foo()
		mainProxy.addContribution(inside,numTrials);
	}

};

#include "pi.def.h"
