#include "Graph_p1_lib.cpp"
#include <cstdlib>

using namespace std;


//Function to Add City
void addCity(City cities[], int& num_cities, const int max) {
    if (num_cities < max) {
        bool exists = false;    //city exists or not
        char city[50];  //user input city

        cout << "Enter the name of the city: ";
        cin >> city;

        // Checking if city already exists
        for (int i = 0; i < num_cities; ++i) {
            if (strcmp(cities[i].name, city) == 0) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            strcpy_s(cities[num_cities].name, city);
            cities[num_cities].index = num_cities;
            num_cities++;
            cout << "City added\n";
        }

        else 
            cout << "City already exists.\n";        
    }
    else
        cout << "No space for more cities\n";    
}

//Function to Find Distance Between 2 Cities
void findDistance(double distances[], City cities[], int num_cities) {    
    char city1[50]; //user input cities
    char city2[50];
    bool city1_exist = false;   //city1 exists or not
    bool city2_exist = false;   //city2 exists or not
    int distance;   //stores distance between the 2 cities

    cout << "Enter name of 1st City: ";
    cin >> city1;

    cout << "Enter name of 2nd City: ";
    cin >> city2;

    if (strcmp(city1, city2) != 0) {
        // Checking if cities exists
        for (int i = 0; i < num_cities; ++i) {
            if (strcmp(cities[i].name, city1) == 0)
                city1_exist = true;
            
            if (strcmp(cities[i].name, city2) == 0)
                city2_exist = true;            
        }

        //If 1 or both cities do not exist
        if (!city1_exist || !city2_exist) {
            cout << "One or both cities donot exist\n";
            return;
        }
    }

    //City1 and City2 are same
    else
    {
        cout << "Same city input\n";
        cout << "Distance calculation not possible\n";
        return;
    }

    //If Both City Exist and are Different
    if (city1_exist && city2_exist) {
        distance = find_distance(distances, city1, city2);

        if (distance != -1) {
            cout << "Distance from " << city1 << " to " << city2 << ": " << distance << " miles\n";
        }
        else {
            cout << "Distance not found\n";
        }
    }
}

//Finding Path between 2 Cities
void findPath(Node* adj_list[], City cities[], int num_cities) {   
    char city1[50]; //user input cities
    char city2[50];
    // Initializing source and destination indices
    // Also a check if city1 and city2 exist or not
    int src = -1, dest = -1;    

    cout << "Enter name of 1st City: ";
    cin >> city1;

    cout << "Enter name of 2nd City: ";
    cin >> city2;

    if (strcmp(city1, city2) == 0) {
        cout << "Same city input\n";
        cout << "Can't find Path\n";
        return;
    }

    // Find source and destination indices in the cities array
    for (int i = 0; i < num_cities; ++i) {
        if (strcmp(cities[i].name, city1) == 0) {
            src = cities[i].index;
        }
        if (strcmp(cities[i].name, city2) == 0) {
            dest = cities[i].index;
        }
    }

    // Check if both sourc and destination cities are found.
    if (src != -1 && dest != -1) {        
        //Finding Path
        bfs(adj_list, src, dest, cities, num_cities);
    }
    else {
        cout << "Source or destination city not found.\n";
    }
}

//Insering Path Between 2 Cities
void insertPath(Node* adj_list[], City cities[], int num_cities) {
    char city1[50]; //user input cities
    char city2[50];
    // Initializing cities indices
    // Also a check if city1 and city2 exist or not
    int city1_index = -1;
    int city2_index = -1;

    cout << "Enter name of 1st City: ";
    cin >> city1;

    cout << "Enter name of 2nd City: ";
    cin >> city2;

    //if same cities
    if (strcmp(city1, city2) == 0) {
        cout << "Same city input\n";
        cout << "Path insertion not possible\n";
        return;
    }

    //checking if cities exist
    //storing their index
    for (int i = 0; i < num_cities; ++i) {
        if (strcmp(cities[i].name, city1) == 0) {
            city1_index = i;
        }
        if (strcmp(cities[i].name, city2) == 0) {
            city2_index = i;
        }
    }

    //if 1 or both cities do not exist
    if (city1_index==-1 || city2_index==-1) {
        cout << "One or both cities do not exist\n";
        return;
    }

    //inserting path/edge
    insert_edge(adj_list, city1_index, city2_index);
    cout << "Path inserted\n";
}

//Adding Distance Between 2 Cities
void addDistance(double distances[], City cities[], int num_cities) {
    char city1[50]; //user input cities
    char city2[50];
    bool city1_exist = false;   //city1 exists or not
    bool city2_exist = false;   //city2 exists or not
    int distance;   //stores distance between the 2 cities

    cout << "Enter name of 1st City: ";
    cin >> city1;

    cout << "Enter name of 2nd City: ";
    cin >> city2;

    //if same cities
    if (strcmp(city1, city2) == 0) {
        cout << "Same city input\n";
        cout << "Distance addition not possible\n";
        return;
    }

    //checking if cities exist
    for (int i = 0; i < num_cities; ++i) {
        if (strcmp(cities[i].name, city1) == 0)
            city1_exist = true;

        if (strcmp(cities[i].name, city2) == 0)
            city2_exist = true;
    }

    //if cities do not exist
    if (!city1_exist || !city2_exist) {
        cout << "One or both cities do not exist\n";
        return;
    }

    //enter distance
    cout << "Enter distance between " << city1 << " and " << city2 << ": ";
    cin >> distance;

    //Adding Distance
    add_distance(distances, city1, city2, distance);
    cout << "Distance added\n";
}


//Main Menu
void mainMenu(City cities[], Node* adj_list[], double distances[], int& num_cities, const int maxCities) {
    int input = 0;  //User input for MainMenu
    while (true) {
        cout << "\n---------MainMenu---------\n";
        cout << "1. Find Path Between 2 Cities\n";
        cout << "2. Find Distance Between 2 Cities\n";
        cout << "3. Add City\n";
        cout << "4. Insert Path\n";
        cout << "5. Add Distance\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> input;

        switch (input) {
        case 1:
            system("cls");
            findPath(adj_list, cities, num_cities);
            break;
        case 2:
            system("cls");
            findDistance(distances, cities, num_cities);
            break;
        case 3:
            system("cls");
            addCity(cities, num_cities, maxCities);
            break;
        case 4:
            system("cls");
            insertPath(adj_list, cities, num_cities);
            break;
        case 5:
            system("cls");
            addDistance(distances, cities, num_cities);
            break;
        case 6:
            system("cls");
            cout << "Exiting the program.\n";
            exit(0);
        default:
            system("cls");
            cout << "Invalid input, try again\n";
        }
    }
}



int main() {
    double distances[50];  // hash table of size 50
    // Number of cities in the example
    const int maxCities = 10;
    int num_cities = 5;
    City cities[maxCities] = {
        {"Flagstaff", 0},
        {"Sedona", 1},
        {"Phoenix", 2},
        {"Williams", 3},
        {"Prescott", 4}
    };

    // Initialize adjacency list for the graph
    Node* adj_list[maxCities] = { nullptr };

    // Insert edges between cities
    insert_edge(adj_list, 0, 1);  // Flagstaff to Sedona
    insert_edge(adj_list, 1, 2);  // Sedona to Phoenix
    insert_edge(adj_list, 0, 3);  // Flagstaff to Williams
    insert_edge(adj_list, 3, 4);  // Williams to Prescott
    insert_edge(adj_list, 4, 2);  // Prescott to Phoenix

    // Hash table for distances
    // Initialize all distances to -1 using a loop
    for (int i = 0; i < 50; i++) {
        distances[i] = -1;
    }

    // Add distances between cities
    add_distance(distances, cities[0].name, cities[1].name, 30);  // Flagstaff to Sedona
    add_distance(distances, cities[1].name, cities[2].name, 120); // Sedona to Phoenix
    add_distance(distances, cities[0].name, cities[3].name, 35);  // Flagstaff to Williams
    add_distance(distances, cities[3].name, cities[4].name, 60);  // Williams to Prescott
    add_distance(distances, cities[4].name, cities[2].name, 100); // Prescott to Phoenix

    mainMenu(cities, adj_list, distances, num_cities, maxCities);
    
    return 0;
}