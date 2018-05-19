/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Raell
 *
 * Created on May 18, 2018, 6:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Graph.h"
#include "Edge.h"
#include "Dijkstra.h"

using namespace std;

// Function declaration
int readFile(string, string);
void generateGraph(Graph&, const string&);
void split(const string&, const string&, vector<string>&);
Dijkstra parseHeader(Graph&, string, string);

/*
 * 
 */
int main(int argc, char** argv) {
    // Takes in two parameter, input filepath and output filepath   
    if(argc == 3) {
        return readFile(argv[1], argv[2]);    
    }
    else {
      cout << "Usage: ." << argv[0] << " InputFile OutputFile\n";
      return 1;
    }
}

// I/O Handler
int readFile(string in, string out) {
    ifstream input;
    input.open(in);
    ofstream output;
    output.open(out);

    if(!(input.good() && output.good())) {
        cout << "Invalid input/output file!";
        return 1;
    }
    
    // Read first two lines
    string line, header1, header2;
    getline(input, header1); 
    getline(input, header2);
    
    Graph g = Graph();
    
    //Handles edges initialization
    while(getline(input, line)) {
        generateGraph(g, line);
    }
    
    input.close();
    
    // Call Dijkstra algorithm and output result
    Dijkstra dij = parseHeader(g, header1, header2);
    output << dij.getShortestPath();
    output.close();
    
    return 0;
}

// Instantiate Dijkstra algorithm
Dijkstra parseHeader(Graph& g, string line1, string line2) {
    vector<string> header;
    split(line1, ", ", header);
    g.addNodes(stoi(header[0]));
    header.clear();
    
    //Handle second line
    split(line2, ", ", header);
    unsigned start = stoi(header[0]);
    unsigned end = stoi(header[1]);
    return Dijkstra(start, end, g);
}

// Taken from https://stackoverflow.com/questions/599989/
// Delimited string split function
void split(const string& str, const string& delimiters , vector<string>& tokens)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

// Generate two-way edges from adjacency list
void generateGraph(Graph& g, const string& edgesStr) {
    vector<string> edgeParam;
    split(edgesStr, ", ", edgeParam);
    Edge e = Edge(stoi(edgeParam[0]), 
                  stoi(edgeParam[1]), 
                  stof(edgeParam[2])
                 );
    
    g.addEdge(e);
    g.addEdge(e.swap());
}


