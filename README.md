[![Build Status](https://travis-ci.com/onyiny-ang/salmon.svg?token=6hmRNtGMeYcpom73Q3ph&branch=master)](https://travis-ci.com/onyiny-ang/salmon "Travis")
[![Image Repository on Quay](https://quay.io/repository/onyiny_ang/salmon-tsp/status "Image Repository on Quay")](https://quay.io/repository/onyiny_ang/salmon-tsp)

# The Salmon Algorithm

The Salmon Algorithm, developed by John
Orth as part of his Master’s thesis, combines
concepts from existing metaheuristics such as
Genetic Algorithms(GA) and Ant Colony Optimization (ACO),
to solve combinatorial optimization problems in a reasonable amount of
time [1]. The Salmon Algorithm was inspired
by the behaviour of salmon swimming upstream to spawn.
In the wild, salmon return to
the place they were born to spawn, suggesting
something resembling a memory of the path
their parents’ took. A salmon’s memory can be
likened to parent chromosomes in GA, since
both contain the full path of the parent. The
memory parameter determines to what degree
a salmon follows its parent’s path. Likewise,
salmon will not lay eggs if the water level is too
low. The water level can be likened to that of
the pheromone which helps direct an ant’s path
in ACO. Like many evolutionary algorithms,
the salmon algorithm involves populations of
salmon that run for several generations. The
salmon algorithm makes no claims of accurately representing real salmon,
but attempts to simulate idealized aspects of salmon’s spawning behaviour
to effectively solve computationally hard problems [1].

This repository holds the source code required to build and run several containers 
with optimization problems formatted for the Salmon Algorithm. These are:

## TSP

[Berlin52](SalmonTSP/berlin52)

TSP dataset courtesy of TSPLIB [2]

## DNA Fragment Assembly

[x60189 4](SalmonTSP/dna40)
[x60189 5](SalmonTSP/dna49)
[x60189 6](SalmonTSP/dna67)
[x60189 7](SalmonTSP/dna69)
[m15421 5](SalmonTSP/dna128)
[m15421 6](SalmonTSP/dna174)
[m15421 7](SalmonTSP/dna178)
[j02459 7](SalmonTSP/dna353)
[bx842596 4](SalmonTSP/dna443)
[bx842596 7](SalmonTSP/dna774)

Fragbench datasets courtesy of DNA ASSEMBLY PROBLEM BENCHMARK REPOSITORY [3]

[Documentation](docs/documentation.md)
---
##### 1. J. Orth, “The Salmon Algorithm-A New Population Based Search Metaheuristic,” Master’s Thesis, Brock University, 2012. [Online]. Available: [https://dr.library.brocku.ca/handle/10464/3929](https://dr.library.brocku.ca/handle/10464/392)

##### 2. Gerhard Reinelt,“TSPLIB.” [On-line]. Available: [http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/](http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/)

##### 3. G. M. Malln-Fullerton, J. A. Hughes, S. Houghten, and G.Fernndez-Anaya, “Benchmark datasets for the dna fragment assembly problem,” International Journal of Bio-Inspired Computation, vol. 5, no. 6, pp. 384–394, 2013. [Online]. Available:
http://www.inderscienceonline.com/doi/abs/10.1504/IJBIC.2013.058 [Datasets](http://www.mallen.mx/fragbench/index1.php)
