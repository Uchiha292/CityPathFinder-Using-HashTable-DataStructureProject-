#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct {
    char name[50];
    int index;
} City;

typedef struct node {
    int city;
    struct node* next;
} Node;

/*
Function: insert_edge
Process: Inserts an edge between two nodes in the adjacency list
Input data (parameter): adj_list (array of Node pointers), src (source city index), dest (destination city index)
Output data (parameter): adj_list (modified with new node)
Dependencies: None
Complexity: O(1)
*/
void insert_edge(Node* adj_list[], int src, int dest);

/*
Function: print_path
Process: Prints the path from source to destination city using backtracking from the parent array
Input data (parameter): parent (array of parent indices), src (source city index), dest (destination city index), cities (array of City structs)
Output data (parameter): None
Dependencies: None
Complexity: O(n) where n is the number of nodes in the path
*/
void print_path(int parent[], int src, int dest, City cities[]);

/*
Function: bfs
Process: Performs Breadth-First Search on the graph to find a path from source to destination
Input data (parameter): adj_list (graph represented as an adjacency list), src (source city index), dest (destination city index), cities (array of City structs), n (total number of cities)
Output data (parameter): parent (array to store the path)
Dependencies: print_path
Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph
*/
void bfs(Node* adj_list[], int src, int dest, City cities[], int n);

/*
Function: hash
Process: Calculates a hash code for a pair of city names
Input data (parameter): city1 (name of the first city), city2 (name of the second city)
Output data (return): Index for the hash table
Dependencies: None
Complexity: O(n) where n is the length of the string
*/
int hash(char* city1, char* city2);

/*
Function: find_distance
Process: Finds the distance between two cities using a hash table
Input data (parameter): distances (array of distances), city1 (first city's name), city2 (second city's name)
Output data (return): Distance between the two cities, or -1 if not found
Dependencies: hash
Complexity: O(1) assuming no collisions
*/
int find_distance(double distances[], char* city1, char* city2);

/*
Function: add_distance
Process: Adds a distance between two cities to the hash table
Input data (parameter): distances (array of distances), city1 (first city's name), city2 (second city's name), distance (distance to add)
Output data (return): 0 if added successfully, -1 on collision or error
Dependencies: hash
Complexity: O(1) assuming no collisions
*/
int add_distance(double distances[], char* city1, char* city2, double distance);
