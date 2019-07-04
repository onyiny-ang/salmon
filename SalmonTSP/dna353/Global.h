#ifndef GLOBAL_H
#define GLOBAL_H

#define RESTARTS 1   // run the entire algorithm this many times
#define GENERATIONS 2000
#define SURVIVAL 35 // The number of salmon that survive to spawn each generation
#define MEMORY 1   // The salmon will select this proportion of vertices from memory
#define POPULATION 2000
#define BIG_NUMBER 4000000
#define SMALL_NUMBER .00001
#define BEST_KNOWN 3413300
#define TOTAL_DNA 3530000
#define BETA 1.2   // exponent for flow in roulette selection
#define ELITE 'Y'  // set to Y for elite salmon and N for no elite

// file parameters
#define OUT_FILE_NAME "salmon1.txt"
#define SEED_FILE_NAME "randomseed.txt"
#define IN_FILE_NAME "dna353.txt"


#endif
