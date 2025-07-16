#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

/**
 * Graph_M class represents the Delhi Metro map as a graph
 * with stations as vertices and connections as edges.
 */
class Graph_M {
public:
    /**
     * Vertex class represents a station in the metro map
     * with its neighboring stations and distances.
     */
    class Vertex {
    public:
        unordered_map<string, int> neighbours; // Station name -> distance
    };

    static unordered_map<string, Vertex> vtces; // All stations in the graph

    Graph_M() {
        vtces.clear();
    }

    // Returns the number of stations in the graph
    int numVetex() {
        return vtces.size();
    }

    // Checks if a station exists in the graph
    bool containsVertex(string vname) {
        return vtces.count(vname) > 0;
    }

    // Adds a new station to the graph
    void addVertex(string vname) {
        Vertex vtx;
        vtces[vname] = vtx;
    }

    // Removes a station from the graph and all its connections
    void removeVertex(string vname) {
        if (!containsVertex(vname)) return;

        // Remove all edges connected to this station
        Vertex vtx = vtces[vname];
        for (auto& neighbour : vtx.neighbours) {
            vtces[neighbour.first].neighbours.erase(vname);
        }

        vtces.erase(vname);
    }

    // Returns the number of connections in the graph
    int numEdges() {
        int count = 0;
        for (auto& station : vtces) {
            count += station.second.neighbours.size();
        }
        return count / 2; // Each edge is counted twice
    }

    // Checks if a direct connection exists between two stations
    bool containsEdge(string vname1, string vname2) {
        if (!containsVertex(vname1) return false;
        if (!containsVertex(vname2)) return false;
        return vtces[vname1].neighbours.count(vname2) > 0;
    }

    // Adds a connection between two stations with given distance
    void addEdge(string vname1, string vname2, int value) {
        if (!containsVertex(vname1) return;
        if (!containsVertex(vname2)) return;
        if (containsEdge(vname1, vname2)) return;

        vtces[vname1].neighbours[vname2] = value;
        vtces[vname2].neighbours[vname1] = value;
    }

    // Removes a connection between two stations
    void removeEdge(string vname1, string vname2) {
        if (!containsEdge(vname1, vname2)) return;

        vtces[vname1].neighbours.erase(vname2);
        vtces[vname2].neighbours.erase(vname1);
    }

    // Displays the complete metro map
    void display_Map() {
        cout << "\t Delhi Metro Map" << endl;
        cout << "\t------------------" << endl;
        cout << "----------------------------------------------------" << endl;
        
        for (auto& station : vtces) {
            string key = station.first;
            string str = key + " =>\n";
            Vertex vtx = station.second;
            
            for (auto& neighbour : vtx.neighbours) {
                str += "\t" + neighbour.first + "\t";
                if (neighbour.first.length() < 16) str += "\t";
                if (neighbour.first.length() < 8) str += "\t";
                str += to_string(neighbour.second) + "\n";
            }
            cout << str << endl;
        }
        
        cout << "\t------------------" << endl;
        cout << "---------------------------------------------------" << endl;
    }

    // Displays all stations in the metro
    void display_Stations() {
        cout << "\n***********************************************************************\n";
        cout << "*                      STATIONS IN THE MAP                            *\n";
        cout << "***********************************************************************\n";
        
        int i = 1;
        for (auto& station : vtces) {
            cout << i << ". " << station.first << endl;
            i++;
        }
        
        cout << "***********************************************************************\n";
    }

    // Checks if a path exists between two stations using DFS
    bool hasPath(string vname1, string vname2, unordered_map<string, bool>& processed) {
        if (containsEdge(vname1, vname2)) {
            return true;
        }

        processed[vname1] = true;
        Vertex vtx = vtces[vname1];
        
        for (auto& neighbour : vtx.neighbours) {
            string nbr = neighbour.first;
            if (!processed.count(nbr) {
                if (hasPath(nbr, vname2, processed)) {
                    return true;
                }
            }
        }

        return false;
    }

    /**
     * DijkstraPair class used for Dijkstra's algorithm implementation
     * to find shortest path (distance or time).
     */
    class DijkstraPair {
    public:
        string vname;   // Station name
        string psf;     // Path so far
        int cost;       // Total cost (distance or time)

        // Operator overloading for priority queue
        bool operator<(const DijkstraPair& other) const {
            return cost > other.cost; // Min-heap based on cost
        }
    };

    /**
     * Dijkstra's algorithm to find shortest distance or time between stations
     * @param src Source station
     * @param des Destination station
     * @param nan If true, calculates time; if false, calculates distance
     * @return Minimum cost (distance in km or time in minutes)
     */
    int dijkstra(string src, string des, bool nan) {
        unordered_map<string, DijkstraPair> map;
        priority_queue<DijkstraPair> pq;

        // Initialize all stations with infinity cost
        for (auto& station : vtces) {
            DijkstraPair np;
            np.vname = station.first;
            np.cost = INT_MAX;

            if (station.first == src) {
                np.cost = 0;
                np.psf = station.first;
            }

            pq.push(np);
            map[station.first] = np;
        }

        while (!pq.empty()) {
            DijkstraPair rp = pq.top();
            pq.pop();

            if (rp.vname == des) {
                return rp.cost;
            }

            if (map.count(rp.vname) == 0) continue;
            map.erase(rp.vname);

            Vertex v = vtces[rp.vname];
            for (auto& neighbour : v.neighbours) {
                string nbr = neighbour.first;
                if (map.count(nbr)) {
                    int oc = map[nbr].cost;
                    int nc;
                    
                    // Calculate new cost based on distance or time
                    if (nan) {
                        // Time calculation: 2 minutes per km + 2 minutes per station
                        nc = rp.cost + 120 + 40 * v.neighbours[nbr];
                    } else {
                        // Distance calculation
                        nc = rp.cost + v.neighbours[nbr];
                    }

                    if (nc < oc) {
                        DijkstraPair& gp = map[nbr];
                        gp.psf = rp.psf + " " + nbr;
                        gp.cost = nc;
                        pq.push(gp);
                    }
                }
            }
        }
        return INT_MAX;
    }

    /**
     * Pair class used for path finding algorithms
     * to store path information.
     */
    class Pair {
    public:
        string vname;       // Station name
        string psf;         // Path so far
        int min_dis;        // Minimum distance
        int min_time;       // Minimum time
    };

    /**
     * Finds the path with minimum distance between two stations
     * using a stack-based DFS approach.
     */
    string Get_Minimum_Distance(string src, string dst) {
        int min = INT_MAX;
        string ans = "";
        unordered_map<string, bool> processed;
        stack<Pair> st;

        // Initialize with source station
        Pair sp;
        sp.vname = src;
        sp.psf = src + "  ";
        sp.min_dis = 0;
        sp.min_time = 0;
        st.push(sp);

        while (!st.empty()) {
            Pair rp = st.top();
            st.pop();

            if (processed.count(rp.vname)) continue;
            processed[rp.vname] = true;

            // If destination reached, check if it's the shortest path
            if (rp.vname == dst) {
                if (rp.min_dis < min) {
                    ans = rp.psf;
                    min = rp.min_dis;
                }
                continue;
            }

            Vertex rpvtx = vtces[rp.vname];
            for (auto& neighbour : rpvtx.neighbours) {
                string nbr = neighbour.first;
                if (!processed.count(nbr)) {
                    Pair np;
                    np.vname = nbr;
                    np.psf = rp.psf + nbr + "  ";
                    np.min_dis = rp.min_dis + rpvtx.neighbours[nbr];
                    st.push(np);
                }
            }
        }
        ans = ans + to_string(min);
        return ans;
    }

    /**
     * Finds the path with minimum time between two stations
     * using a stack-based DFS approach.
     */
    string Get_Minimum_Time(string src, string dst) {
        int min = INT_MAX;
        string ans = "";
        unordered_map<string, bool> processed;
        stack<Pair> st;

        // Initialize with source station
        Pair sp;
        sp.vname = src;
        sp.psf = src + "  ";
        sp.min_dis = 0;
        sp.min_time = 0;
        st.push(sp);

        while (!st.empty()) {
            Pair rp = st.top();
            st.pop();

            if (processed.count(rp.vname)) continue;
            processed[rp.vname] = true;

            // If destination reached, check if it's the fastest path
            if (rp.vname == dst) {
                if (rp.min_time < min) {
                    ans = rp.psf;
                    min = rp.min_time;
                }
                continue;
            }

            Vertex rpvtx = vtces[rp.vname];
            for (auto& neighbour : rpvtx.neighbours) {
                string nbr = neighbour.first;
                if (!processed.count(nbr)) {
                    Pair np;
                    np.vname = nbr;
                    np.psf = rp.psf + nbr + "  ";
                    // Time calculation: 2 minutes per km + 2 minutes per station
                    np.min_time = rp.min_time + 120 + 40 * rpvtx.neighbours[nbr];
                    st.push(np);
                }
            }
        }
        // Convert seconds to minutes
        double minutes = ceil((double)min / 60);
        ans = ans + to_string(minutes);
        return ans;
    }

    /**
     * Parses the path string to identify interchanges between metro lines.
     * @param str Path string containing stations and distances/times
     * @return Vector containing stations and interchange information
     */
    vector<string> get_Interchanges(string str) {
        vector<string> arr;
        vector<string> tokens;
        stringstream ss(str);
        string token;
        
        // Split the path string into tokens
        while (getline(ss, token, ' ')) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        
        if (tokens.empty()) return arr;
        
        arr.push_back(tokens[0]);
        int interchange_count = 0;

        for (size_t i = 1; i < tokens.size() - 1; i++) {
            size_t index = tokens[i].find('~');
            if (index == string::npos) continue;
            
            string line = tokens[i].substr(index + 1);
            
            if (line.length() == 2) {
                // Check if this is an interchange station
                string prev_line = tokens[i-1].substr(tokens[i-1].find('~') + 1);
                string next_line = tokens[i+1].substr(tokens[i+1].find('~') + 1);
                
                if (prev_line != next_line) {
                    // Add interchange information
                    arr.push_back(tokens[i] + " ==> " + tokens[i + 1]);
                    i++; // Skip next station as we've already processed it
                    interchange_count++;
                } else {
                    arr.push_back(tokens[i]);
                }
            } else {
                arr.push_back(tokens[i]);
            }
        }
        
        arr.push_back(tokens.back());
        arr.push_back(to_string(interchange_count));
        return arr;
    }

    /**
     * Calculates the fare based on number of stations traveled.
     * @param src Source station
     * @param dst Destination station
     * @param x 7 for distance-wise, 8 for time-wise
     * @return Vector containing number of stations and fare
     */
    vector<int> Get_Minimum_Fare(string src, string dst, int x) {
        int stations = 0;
        int fare = 0;
        
        // Get the number of stations in the path
        if (x == 7) {
            stations = get_Interchanges(Get_Minimum_Distance(src, dst)).size() - 1;
        } else {
            stations = get_Interchanges(Get_Minimum_Time(src, dst)).size() - 1;
        }

        // Calculate fare based on number of stations
        if (stations <= 3) {
            fare = 10;
        } else if (stations <= 7) {
            fare = 20;
        } else if (stations <= 11) {
            fare = 30;
        } else if (stations <= 20) {
            fare = 40;
        } else {
            fare = 40 + (stations - 20) * 10;
        }

        return {stations, fare};
    }

    /**
     * Creates the Delhi Metro map with stations and connections.
     */
    static void Create_Metro_Map(Graph_M &g) {
        // Add all stations
        vector<string> stations = {
            "Noida_Sector_62~B", "Botanical_Garden~B", "Yamuna_Bank~B", 
            "Rajiv_Chowk~BY", "Vaishali~B", "Moti_Nagar~B", 
            "Janak_Puri_West~BO", "Dwarka_Sector_21~B", "Huda_City_Center~Y", 
            "Saket~Y", "AIIMS~Y", "Rajiv_Chowk~BY", "New_Delhi~YO", 
            "Chandni_Chowk~Y", "Vishwavidyalaya~Y", "Shivaji_Stadium~O", 
            "DDS_Campus~O", "IGI_Airport~O", "Rajouri_Garden~BP", 
            "Netaji_Subhash_Place~PR", "Punjabi_Bagh_West~P"
        };
        
        for (const auto& station : stations) {
            g.addVertex(station);
        }

        // Add all connections
        vector<tuple<string, string, int>> connections = {
            {"Noida_Sector_62~B", "Botanical_Garden~B", 8},
            {"Botanical_Garden~B", "Yamuna_Bank~B", 10},
            {"Yamuna_Bank~B", "Vaishali~B", 8},
            {"Yamuna_Bank~B", "Rajiv_Chowk~BY", 6},
            {"Rajiv_Chowk~BY", "Moti_Nagar~B", 9},
            {"Moti_Nagar~B", "Janak_Puri_West~BO", 7},
            {"Janak_Puri_West~BO", "Dwarka_Sector_21~B", 6},
            {"Huda_City_Center~Y", "Saket~Y", 15},
            {"Saket~Y", "AIIMS~Y", 6},
            {"AIIMS~Y", "Rajiv_Chowk~BY", 7},
            {"Rajiv_Chowk~BY", "New_Delhi~YO", 1},
            {"New_Delhi~YO", "Chandni_Chowk~Y", 2},
            {"Chandni_Chowk~Y", "Vishwavidyalaya~Y", 5},
            {"New_Delhi~YO", "Shivaji_Stadium~O", 2},
            {"Shivaji_Stadium~O", "DDS_Campus~O", 7},
            {"DDS_Campus~O", "IGI_Airport~O", 8},
            {"Moti_Nagar~B", "Rajouri_Garden~BP", 2},
            {"Punjabi_Bagh_West~P", "Rajouri_Garden~BP", 2},
            {"Punjabi_Bagh_West~P", "Netaji_Subhash_Place~PR", 3}
        };
        
        for (const auto& conn : connections) {
            g.addEdge(get<0>(conn), get<1>(conn), get<2>(conn));
        }
    }
};

// Initialize static member
unordered_map<string, Graph_M::Vertex> Graph_M::vtces;

/**
 * Prints the list of stations with their codes.
 * @return Array of station codes
 */
vector<string> printCodelist() {
    cout << "\n***********************************************************************\n";
    cout << "*                STATION CODES IN THE MAP                             *\n";
    cout << "***********************************************************************\n";
    
    vector<string> codes;
    int i = 1;
    
    for (auto& station : Graph_M::vtces) {
        string key = station.first;
        string code;
        
        // Generate code from station name
        for (char c : key) {
            if (isalpha(c)) {
                code += toupper(c);
                break;
            }
        }
        
        // Add numbers from station name
        for (char c : key) {
            if (isdigit(c)) {
                code += c;
            }
        }
        
        // If code is too short, add more characters
        if (code.length() < 2) {
            for (char c : key) {
                if (isalpha(c)) {
                    code += toupper(c);
                    if (code.length() >= 2) break;
                }
            }
        }
        
        codes.push_back(code);
        
        // Format output
        cout << i << ". " << key;
        if (key.length() < 22) cout << "\t";
        if (key.length() < 14) cout << "\t";
        if (key.length() < 6) cout << "\t";
        cout << code << endl;
        i++;
    }
    
    cout << "***********************************************************************\n";
    return codes;
}

/**
 * Displays the application menu and handles user input.
 */
void displayMenu() {
    Graph_M g;
    Graph_M::Create_Metro_Map(g);

    cout << "\n\n\t***********************************************************************\n";
    cout << "\t*                   WELCOME TO DELHI METRO APP                         *\n";
    cout << "\t***********************************************************************\n";

    while (true) {
        cout << "\n\t=======================================================================\n";
        cout << "\t*                         MAIN MENU                                   *\n";
        cout << "\t*   1. List all stations                                              *\n";
        cout << "\t*   2. Show metro map                                                 *\n";
        cout << "\t*   3. Get shortest distance between two stations                     *\n";
        cout << "\t*   4. Get shortest time between two stations                         *\n";
        cout << "\t*   5. Get shortest path (distance-wise)                              *\n";
        cout << "\t*   6. Get shortest path (time-wise)                                  *\n";
        cout << "\t*   7. Get fare for shortest path (distance-wise)                     *\n";
        cout << "\t*   8. Get fare for shortest path (time-wise)                         *\n";
        cout << "\t*   9. Exit                                                          *\n";
        cout << "\t=======================================================================\n";

        int choice;
        cout << "\nEnter your choice (1-9): ";
        cin >> choice;

        if (choice == 9) {
            cout << "\nThank you for using Delhi Metro App!\n";
            break;
        }

        switch (choice) {
            case 1:
                g.display_Stations();
                break;

            case 2:
                g.display_Map();
                break;

            case 3: {
                vector<string> codes = printCodelist();
                string src, dest;
                
                cout << "\nEnter source station: ";
                cin.ignore();
                getline(cin, src);
                
                cout << "Enter destination station: ";
                getline(cin, dest);

                unordered_map<string, bool> processed;
                if (!g.containsVertex(src) || !g.containsVertex(dest) || !g.hasPath(src, dest, processed)) {
                    cout << "\nInvalid stations or no path exists!\n";
                } else {
                    cout << "\nShortest distance: " << g.dijkstra(src, dest, false) << " KM\n";
                }
                break;
            }

            case 4: {
                vector<string> codes = printCodelist();
                string src, dest;
                
                cout << "\nEnter source station: ";
                cin.ignore();
                getline(cin, src);
                
                cout << "Enter destination station: ";
                getline(cin, dest);

                unordered_map<string, bool> processed;
                if (!g.containsVertex(src) || !g.containsVertex(dest) || !g.hasPath(src, dest, processed)) {
                    cout << "\nInvalid stations or no path exists!\n";
                } else {
                    int time = g.dijkstra(src, dest, true);
                    cout << "\nShortest time: " << time / 60 << " minutes (" << time % 60 << " seconds)\n";
                }
                break;
            }

            case 5: {
                vector<string> codes = printCodelist();
                string src, dest;
                
                cout << "\nEnter source station: ";
                cin.ignore();
                getline(cin, src);
                
                cout << "Enter destination station: ";
                getline(cin, dest);

                unordered_map<string, bool> processed;
                if (!g.containsVertex(src) || !g.containsVertex(dest) || !g.hasPath(src, dest, processed)) {
                    cout << "\nInvalid stations or no path exists!\n";
                } else {
                    vector<string> path = g.get_Interchanges(g.Get_Minimum_Distance(src, dest));
                    if (path.size() < 2) {
                        cout << "\nNo path found!\n";
                        break;
                    }
                    
                    cout << "\n===============================================================\n";
                    cout << "   Shortest Path (Distance-wise) from " << src << " to " << dest;
                    cout << "\n===============================================================\n";
                    cout << "Total distance: " << path.back() << " KM\n";
                    cout << "Number of interchanges: " << path[path.size()-2] << "\n";
                    cout << "Route:\n";
                    
                    for (size_t i = 0; i < path.size()-2; i++) {
                        cout << i+1 << ". " << path[i] << "\n";
                    }
                    
                    cout << "===============================================================\n";
                }
                break;
            }

            case 6: {
                vector<string> codes = printCodelist();
                string src, dest;
                
                cout << "\nEnter source station: ";
                cin.ignore();
                getline(cin, src);
                
                cout << "Enter destination station: ";
                getline(cin, dest);

                unordered_map<string, bool> processed;
                if (!g.containsVertex(src) || !g.containsVertex(dest) || !g.hasPath(src, dest, processed)) {
                    cout << "\nInvalid stations or no path exists!\n";
                } else {
                    vector<string> path = g.get_Interchanges(g.Get_Minimum_Time(src, dest));
                    if (path.size() < 2) {
                        cout << "\nNo path found!\n";
                        break;
                    }
                    
                    cout << "\n===============================================================\n";
                    cout << "   Shortest Path (Time-wise) from " << src << " to " << dest;
                    cout << "\n===============================================================\n";
                    cout << "Estimated time: " << path.back() << " minutes\n";
                    cout << "Number of interchanges: " << path[path.size()-2] << "\n";
                    cout << "Route:\n";
                    
                    for (size_t i = 0; i < path.size()-2; i++) {
                        cout << i+1 << ". " << path[i] << "\n";
                    }
                    
                    cout << "===============================================================\n";
                }
                break;
            }

            case 7: {
                vector<string> codes = printCodelist();
                string src, dest;
                
                cout << "\nEnter source station: ";
                cin.ignore();
                getline(cin, src);
                
                cout << "Enter destination station: ";
                getline(cin, dest);

                unordered_map<string, bool> processed;
                if (!g.containsVertex(src) || !g.containsVertex(dest) || !g.hasPath(src, dest, processed)) {
                    cout << "\nInvalid stations or no path exists!\n";
                } else {
                    vector<int> fareInfo = g.Get_Minimum_Fare(src, dest, 7);
                    cout << "\n===============================================================\n";
                    cout << "   Fare Information (Distance-wise) from " << src << " to " << dest;
                    cout << "\n===============================================================\n";
                    cout << "Number of stations: " << fareInfo[0] << "\n";
                    cout << "Total fare: Rs. " << fareInfo[1] << "\n";
                    cout << "===============================================================\n";
                }
                break;
            }

            case 8: {
                vector<string> codes = printCodelist();
                string src, dest;
                
                cout << "\nEnter source station: ";
                cin.ignore();
                getline(cin, src);
                
                cout << "Enter destination station: ";
                getline(cin, dest);

                unordered_map<string, bool> processed;
                if (!g.containsVertex(src) || !g.containsVertex(dest) || !g.hasPath(src, dest, processed)) {
                    cout << "\nInvalid stations or no path exists!\n";
                } else {
                    vector<int> fareInfo = g.Get_Minimum_Fare(src, dest, 8);
                    cout << "\n===============================================================\n";
                    cout << "   Fare Information (Time-wise) from " << src << " to " << dest;
                    cout << "\n===============================================================\n";
                    cout << "Number of stations: " << fareInfo[0] << "\n";
                    cout << "Total fare: Rs. " << fareInfo[1] << "\n";
                    cout << "===============================================================\n";
                }
                break;
            }

            default:
                cout << "\nInvalid choice! Please enter a number between 1-9.\n";
                break;
        }
    }
}

int main() {
    displayMenu();
    return 0;
}
