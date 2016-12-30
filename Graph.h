//
//  Graph.h
//
//  Created by Auon Muhammad Akhtar on 2016-12-28.
//  Copyright © 2016 Auon Muhammad Akhtar. All rights reserved.
//

#ifndef Graph_h
#define Graph_h
#include "Python.h"
#include <iostream>
#include <vector>
#include <random>


class Graph
{
    std::random_device rd; //seed generator
    std::default_random_engine generator{rd()}; //Default random engine based on the initialized seed 
    float distance; //Will temporarily store the Euclidean distance between two vertices
    
public:

	std::vector<int> vertex_x; // Vector contains x-components of all vertices (nodes)
    std::vector<int> vertex_y; // Vector contains y-components of all vertices (nodes)
    int size_graph; // Size of the Graph in terms of numbers of nodes
    int source_node; // Source node


/*****************************************************************************
* Overloading Constructor
*****************************************************************************/
    Graph();


/*****************************************************************************
* Overloading Constructor
*****************************************************************************/    
    Graph(int, int);


/*****************************************************************************
* Destructor
*****************************************************************************/    
    ~Graph();
    
    
/*****************************************************************************
* Draws the graph showing all vertices and edges.
*****************************************************************************/    
    void draw_graph();
};

#endif /* Graph_h */
