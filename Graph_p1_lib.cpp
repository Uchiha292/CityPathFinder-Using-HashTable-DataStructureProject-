#include "Graph_p1_lib.h"
#pragma once
void insert_edge(Node* adj_list[], int src, int dest) {
    // creating a new node for the adjacency list at the source index
    Node* newNode = new Node{ dest, adj_list[src] };

    //adding edge, src to destination
    adj_list[src] = newNode;

    // creating a new node for the adjacency list at the destination index
    newNode = new Node{ src, adj_list[dest] };

    //adding edge, destination to src
    adj_list[dest] = newNode;
}

void print_path(int parent[], int src, int dest, City cities[]) {
    int n = 10;
    int* path = new int[n];
    int path_index = 0;
    int current = dest;

    // check if a path does not exist
    if (parent[dest] == -1) {
        cout << "No path exists between " << cities[src].name << " and " << cities[dest].name << ".\n";
        return;
    }

    // Backtracking from the destination to the source using the parent array
    while (current != src) {
        path[path_index++] = current;
        current = parent[current];
    }
    path[path_index++] = src;  // Add the source city to the path

    // Output the path in the correct order
    cout << "Path between " << cities[src].name << " and " << cities[dest].name << ":\n(";
    for (int i = path_index - 1; i > 0; --i) {
        cout << cities[path[i]].name << " -> ";
    }
    cout << cities[path[0]].name << ")\n";
}

void bfs(Node* adj_list[], int src, int dest, City cities[], int n) {
    queue<int> queue;
    bool* visited = new bool[n] { false };
    int* parent = new int[n];
    fill_n(parent, n, -1);  // Initialize parent array
    bool pathFound = false;  // check if path is found or not

    // Start BFS from the source city
    visited[src] = true;
    queue.push(src);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        // Explore each adjacent city
        for (Node* temp = adj_list[current]; temp != nullptr; temp = temp->next) {
            if (!visited[temp->city]) {
                visited[temp->city] = true;
                parent[temp->city] = current;
                queue.push(temp->city);

                // If destination is found
                if (temp->city == dest) {
                    pathFound = true;   // path found
                    break;
                }
            }
        }

        // If path is found, stopping loop
        if (pathFound) {
            break;
        }
    }

    // If no path found
    if (!pathFound) {
        cout << "No Path Found\n";
    }
    //if path found
    else {
        // Print the path
        print_path(parent, src, dest, cities);
    }

    delete[] visited;
    delete[] parent;
}


int hash1(char* city1, char* city2) {
    int sum = 0;

    // Compute hash code by summing ASCII values of characters in city names
    for (int i = 0; i < strlen(city1); i++) {
        sum += city1[i];
    }
    for (int i = 0; i < strlen(city2); i++) {
        sum += city2[i];
    }
    return sum % 50;  // Using modulo to fit hash table size
}

int find_distance(double distances[], char* city1, char* city2) {
    int index = hash1(city1, city2);

    // Return the distance if found, otherwise -1
    if (distances[index] != -1) {
        return distances[index];
    }
    return -1;  // Distance not found
}

int add_distance(double distances[], char* city1, char* city2, double distance) {
    int index = hash1(city1, city2);

    // Add distance to the hash table if the slot is empty
    if (distances[index] == -1) {
        distances[index] = distance;
        return 0;  // Successfully added
    }
    return -1;  // Indicates collision or slot already occupied
}