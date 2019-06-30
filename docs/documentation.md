## The Salmon Algorithm Usage

The main purpose of this repo is to provide the necessary components to
containerize the Salmon algorithm for several different TSP and DNA Fragment
Assembly problems. This is a step in demonstrating a continuous integration example of
a bioinformatics workflow for an undergraduate research project in Computer
Science.

The Salmon algorithm can be used for both TSP and DNA Fragment Assembly (the DNA
Fragment Assembly problem’s likeness to a TSP problem was first recognized and then
dismissed by Parsons [1], it was later adapted and implemented by Mullen-Fullerton.[2])

### Containerized Datasets

### TSP

[Berlin52](SalmonTSP/berlin52)

TSP dataset courtesy of TSPLIB [3]

### DNA Fragment Assembly

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

Fragbench datasets courtesy of DNA ASSEMBLY PROBLEM BENCHMARK REPOSITORY [Datasets](http://www.mallen.mx/fragbench/index1.php) [2]


### Directory Configuration

In the [SalmonTSP](../SalmonTSP) directory, `berlin52` provides all of the
necessary files for a TSP like problem and the `dna` directories provide all of
the necessary files for a DNA Fragment Assembly like problem. For any new
instances to be containerized, the `Global.h` parameters will need to be adjusted appropriately and
a text file with the Euclidean distances will need to be added. The
`MatrixBuilder.cpp` file differs for TSP and DNA Fragment Assembly and for
usability/readability, it may have been better to indicate: `DNA-MatrixBuilder`
and `TSP-MatrixBuilder` but for ease of build, the appropriate file has been
placed in each directory. Copy the appropriate file for your instance.

### Parameter Configuration

The `Global.h` files for each container use the best parameters found from
earlier research using Param-ILS--an automated parameter tuning and algorithm configuration
tool that was developed by Frank Hutter, Holger Hoos,
Thomas Sttzle, Kevin Leyton-Brown, to address the often tedious problem of finding
performance-optimizing parameters, to tune parameters for the Salmon Algorithm[3][4].

The parameters that require tuning are outlined in detail in John Orth's Master's thesis[5].
I have briefly described them below:

```
GENERATIONS:  The number of iterations the algorithm will perform

SURVIVAL: The number of salmon that survive to spawn each generation

MEMORY: The salmon will select this proportion of vertices from memory aka &phi;

POPULATION: The number of salmon that will spawn each generation

BEST_KNOWN: The best known result for the problem. This is a negative number
for DNA Fragment Assembly problems

BETA:  Exponent for flow in roulette selection aka &alpha;

IN_FILE_NAME: The name of the text file with Euclidean distances between points
```

### Image build script

Within the `SalmonTSP` directory there is an `imagebuild.sh` script that builds all containers in the `SalmonTSP` directory. If a new container is added to the registry, the name of the directory should appended in quotations to the end of line `8`:
```
declare -a TSPArray=. . .
```

### Dockerfile and Travis

No changes to the Dockerfile or .travis.yml are required if the steps above are
followed. The Dockerfile is generic for any salmon code that is moved by the
imagebuild script into a temporary folder `SalmonTSP/temp` and the .travis.yml
build calls the imagebuild script on each directory it is provided within
`SalmonTSP`.



---
##### 1. R.J.Parsons, S.Forrest, and C.Burks, “Genetic algorithms, operators, and DNA fragment assembly,” Machine Learning, vol. 21, no. 1, pp. 11–33, 1995. [Online]. Available: [http://www.springerlink.com/index/P892188783H43M04.pdf](http://www.springerlink.com/index/P892188783H43M04.pdf)

#### 2. G.M. Mallen-Fullerton and G. Fernandez-Anaya, "Dna fragment assembly using optimization", in 2013 IEEE Congress on Evolutionary Computation CEC. IEEE, 2013, pp. 1570-1577.[Datasets](http://www.mallen.mx/fragbench/index1.php)

##### 3. Gerhard Reinelt,“TSPLIB.” [On-line]. Available: [http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/](http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/)

##### 4. L. Tulloch and S. Houghten, "The Salmon Algorithm, Return of the Parameters" 3P99 Project F/W 2016-2017, Brock University, August 2017.

##### 5. F. Hutter, H.H. Hoos, K. LeytonBrown , T. Stuzle, “ParamILS: An Automatic Algorithm Configuration Framework,” Journal of Artificial Intelligence Research, vol. 36, pp. 267–306, Oct. 2009. [Online]. Available: [http://www.cs.ubc.ca/labs/beta/Projects/ParamILS/papers/09-JAIR-ParamILS.pdf](http://www.cs.ubc.ca/labs/beta/Projects/ParamILS/papers/09-JAIR-ParamILS.pdf)

##### 6. J. Orth, “The Salmon Algorithm-A New Population Based Search Metaheuristic,” Master’s Thesis, Brock University, 2012. [Online]. Available: [https://dr.library.brocku.ca/handle/10464/3929](https://dr.library.brocku.ca/handle/10464/3929)
