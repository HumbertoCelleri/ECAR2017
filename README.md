# ECAR 2017

User/Pass: clinux01

## Module 1: Markus Rampp


### Day 1

- Hybrid parallelization
MPI: $N*(N-1)/2$
	- First touch problem
	- Examples
- Programming challenges
	1. Memory wall
	2. heterogeneous nodes
	3. Hardware reliability
- data-driven computations
	1. Dursi 2015 "HPC is dying ..."
	2. Baidu research 2017 " Bringing HPC techniques ..."
	3. Awan 2017 "Optimized broadcast for deep lear ..."
- HPC Architectures:
	1. Codes should be; memory-bound, SIMD aware, hydrid MPI/OpenMP, memory scalable

### Day 2

1. Oarallelism on multiple levels
gprof: tool for serial perfomance.
likwid: OPen source performance tools.
ITAC(Intel Trace Analyzer and Collector)

- TIP: Ojo con la medida de lo paralelo, quizás es el trabajo del proceso y no el colectivo.
- COmunication routines: blocking and non blocking.
	
weak scaling: cambiar el tamaño de problema según el numero de procesadores


## Module 4: Programming with parallel Objects

Esteban Emeneses Rojas
ecar2017.slack.com

### Day 2: CHarm: Adaptative runtime system
Cada llamada a método se traduce en un mensaje.
El orden de ejecución de las llamadas no están garantizadas, y no se pueden interrumpir.

Modelo BSP: Genera mucho stress en la red. (CUello de botella)
Charm genera más objetos que procesadores (Sobredescomposición)

