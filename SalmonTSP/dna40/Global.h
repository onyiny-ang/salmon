#ifndef GLOBAL_H
#define GLOBAL_H

#define RESTARTS 1   // run the entire algorithm this many times
#define GENERATIONS 425
#define SURVIVAL 39 // The number of salmon that survive to spawn each generation
#define MEMORY .79   // The salmon will select this proportion of vertices from memory (theta)
#define POPULATION 650
#define BIG_NUMBER 1000000
#define SMALL_NUMBER .00001
#define BEST_KNOWN 388522
#define TOTAL_DNA 400000
#define BETA 1.36   // exponent for flow in roulette selection
#define ELITE 'Y'  // set to Y for elite salmon and N for no elite


//#define BEST_KNOWN 668729.00 //for dna69 - best this algorithm has done
//#define BEST_KNOWN 651699.00 //for dna67
//#define BEST_KNOWN 475839.00 //for dna49

// file parameters
#define OUT_FILE_NAME "salmon1.txt"
#define SEED_FILE_NAME "randomseed.txt"
//#define IN_FILE_NAME "dna67.txt"
#define IN_FILE_NAME "dna40.txt"
//#define IN_FILE_NAME "dna49.txt"


#endif
