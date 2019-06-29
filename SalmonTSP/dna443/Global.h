#ifndef GLOBAL_H
#define GLOBAL_H

#define RESTARTS 1   // run the entire algorithm this many times
#define GENERATIONS 1500
#define SURVIVAL 55 // The number of salmon that survive to spawn each generation
#define MEMORY .98   // The salmon will select this proportion of vertices from memory
#define POPULATION 1500
#define BIG_NUMBER 5000000
#define SMALL_NUMBER .00001
#define BEST_KNOWN 4202080
#define TOTAL_DNA 4430000
#define BETA 1   // exponent for flow in roulette selection
#define ELITE 'Y'  // set to Y for elite salmon and N for no elite

// file parameters
#define OUT_FILE_NAME "salmon1.txt"
#define SEED_FILE_NAME "randomseed.txt"
#define IN_FILE_NAME "dna443.txt"


#endif
