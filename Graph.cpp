//
//  Graph.cpp
//
//  Created by Auon Muhammad Akhtar on 2016-12-28.
//  Copyright © 2016 Auon Muhammad Akhtar. All rights reserved.
//
#include "Graph.h"

/****************************************************************************
* Overloading Constructor
*****************************************************************************
*
* Generates 20 nodes which are uniformly distributed
*
****************************************************************************/
Graph::Graph()
{
    size_graph = 20;
    source_node = 10;
    for (int i = 0; i < size_graph; ++i)
    {
        std::uniform_int_distribution<int> distribution(1,100);
        vertex_x.push_back(distribution(generator));
        vertex_y.push_back(distribution(generator));
    }
}


/****************************************************************************
* Constructor
*****************************************************************************
*
* Generates user specified numer of nodes which are uniformly distributed 
*
****************************************************************************/
Graph::Graph(int sg, int sn)
{
    size_graph = sg;
    source_node = sn;
    for (int i = 0; i < size_graph; ++i)
    {
        std::uniform_int_distribution<int> distribution(1,100);
        vertex_x.push_back(distribution(generator));
        vertex_y.push_back(distribution(generator));
    }
}
/****************************************************************************
* Function: draw_graph()
*****************************************************************************
*
* Draws the graph showing all vertices and edges. Invokes Python and 
* utilizes matplotlib.pyplot for plotting the graph. 
* IMPORTANT: An edge exists between two vertices if the Euclidean distance
* between them is no larger than 50.
*
****************************************************************************/
void Graph::draw_graph()
{
    Py_Initialize();   
    PyRun_SimpleString("import matplotlib.pyplot as plt");
    std::string command;


/*****************************************************************************
* Add vertices to the graph. Source node will be shown in red 
*****************************************************************************/
    for (int i = 0; i < size_graph; ++i)
    {
        std::cout << "(" << vertex_x[i] << ", " << vertex_y[i] << ")" << std::endl;
        command.append("plt.scatter(");
        command.append(std::to_string(vertex_x[i]));
        command.append(", ");
        command.append(std::to_string(vertex_y[i]));
        command.append(", s = 100");
        if (i == source_node)
        {
            command.append(", facecolor = \"red\", edgecolor = \"red\"");
        }
        command.append(")");
        PyRun_SimpleString(command.c_str());
        command = {};
        command.append("plt.annotate(");
        command.append(std::to_string(i));
        command.append(", (");
        command.append(std::to_string(vertex_x[i]));
        command.append(", ");
        command.append(std::to_string(vertex_y[i]));
        command.append("))");
        PyRun_SimpleString(command.c_str());
        command = {};
    }


/*****************************************************************************
* Add edges to the graph
*****************************************************************************/
    for (int j = 0; j < size_graph; ++j)
    {
        for (int i = j; i < size_graph; ++i)
        {
            distance = sqrt(pow((vertex_x[j] - vertex_x[i]),2) + pow((vertex_y[j] - vertex_y[i]),2));
            if ((i != j) && distance <= 50)
            {
                command.append("plt.plot([");
                command.append(std::to_string(vertex_x[j]));
                command.append(", ");
                command.append(std::to_string(vertex_x[i]));
                command.append("], [");
                command.append(std::to_string(vertex_y[j]));
                command.append(", ");
                command.append(std::to_string(vertex_y[i]));
                command.append("], color = \"grey\")");
                PyRun_SimpleString(command.c_str());
                command = {};
            }
        }
    } 
    PyRun_SimpleString("plt.show()");  
    Py_Exit(0);
}


/****************************************************************************
* Destructor
*****************************************************************************
*
* 
*
****************************************************************************/
Graph::~Graph()
{
}