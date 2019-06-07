#include "MatrixBuilder.h"

using namespace std;

MatrixBuilder::MatrixBuilder() {
};

MatrixBuilder::~MatrixBuilder() {
};

double** MatrixBuilder::buildAdjacencyMatrix(ifstream* inFile, int& size) {
    double ** vertexPoints; // The array of x,y coordinates of the points
    char currentLine[20]; // For file input
    int i, j;
    int index;
    double temp;
    double** adjMatrix; // The adjacency matrix
    double xDif, yDif;

    // Read the first line of the file. ie the number of vertices in
    // the graph.

    if (!inFile->eof()) *inFile >> currentLine;
    else {
        cout << "Premature EOF reached. Program aborted.\n";
        return NULL;
    }

    size = atoi(currentLine); // convert to an integer
    if (size == 0) {
        cout << "Invalid number of vertices. Program aborted!\n";
        return NULL;
    }

    //    // Build the dynamic array to hold the set of points
    //
    //    vertexPoints = new double*[size];
    //    for (i = 0; i < size; i++) vertexPoints[i] = new double[2];
    //
    //    // Read the set of points into the array vertexPoints[n][2]
    //    // Note: None of the points can be zero, since inFile returns
    //    // a zero on a read failure.
    //
    //    for (i = 0; i < size; i++) {

    //        *inFile >> currentLine; // We are not using the index number
    //        index = atoi(currentLine); // Just read it and throw it away
    //        if ((index < SMALL_NUMBER) || (index > BIG_NUMBER)) {
    //            cout << "Invalid data in line number "
    //                    << i + 1 << ". Program aborted.\n";
    //            return NULL;
    //        }

    //        *inFile >> currentLine;
    //        temp = atof(currentLine);
    //        if ((temp < SMALL_NUMBER) || (temp > BIG_NUMBER)) {
    //            cout << "Invalid data in line number "
    //                    << i + 1 << ". Program aborted.\n";
    //            return NULL;
    //        } else vertexPoints[i][0] = temp;
    //        *inFile >> currentLine;
    //        temp = atof(currentLine);
    //        if ((temp < SMALL_NUMBER) || (temp > BIG_NUMBER)) {
    //            cout << "Invalid data in line number "
    //                    << i + 1 << ". Program aborted.\n";
    //            return NULL;
    //        } else vertexPoints[i][1] = temp;
    //    }

    adjMatrix = new double*[size];
    for (i = 0; i < size; i++) adjMatrix[i] = new double[size];

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            *inFile >> currentLine; // We are not using the index number
            index = atoi(currentLine); // Just read it and throw it away
            if ((index < SMALL_NUMBER) || (index > BIG_NUMBER)) {
                cout << "Invalid data in line number "
                        << i + 1 << ". Program aborted.\n";
                return NULL;
            }
            adjMatrix[i][j] = index;
        }
    }

    inFile->close();
    //    for (i = 0; i < size; i++) delete[] vertexPoints[i];
    //    delete[] vertexPoints;

    return adjMatrix;

} // end of buildAdjacencyMatrix()


