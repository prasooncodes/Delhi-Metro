🛤️ Delhi Metro Route Planner - C++ CLI Project
A command-line-based Delhi Metro route simulator that helps users explore metro stations, view maps, find shortest paths, estimate travel times, and calculate fares — built using C++ and Dijkstra’s algorithm.

📌 Features
✅ View all available stations on the Delhi Metro map

✅ Display the entire metro network with distances between stations

✅ Find the shortest distance (in kilometers) between any two stations using Dijkstra's Algorithm

✅ Calculate the fastest travel time between two stations based on estimated wait and travel durations

✅ Display the path with shortest distance or minimum time, including interchange information

✅ Fare calculator based on number of stations covered

✅ Handle interchange stations and visualize them clearly in the path

✅ Fully interactive CLI menu with station code helper

🏗️ Tech Stack
Language: C++

Algorithms: Dijkstra’s Algorithm, DFS (for path detection)

Data Structures: Graph (Adjacency List), Priority Queue, Deque, Hash Maps

Build System: g++ / any C++17 compliant compiler

🖥️ Sample Menu (CLI)

WELCOME TO THE METRO APP

1. LIST ALL THE STATIONS IN THE MAP
2. SHOW THE METRO MAP
3. GET SHORTEST DISTANCE FROM A SOURCE TO DESTINATION STATION
4. GET SHORTEST TIME TO REACH FROM A SOURCE TO DESTINATION STATION
5. GET SHORTEST PATH (DISTANCE WISE)
6. GET SHORTEST PATH (TIME WISE)
7. GET FARE FOR SHORTEST PATH (DISTANCE WISE)
8. GET FARE FOR SHORTEST PATH (TIME WISE)
9. EXIT THE MENU

🚇 Sample Output

SOURCE STATION : Huda_City_Center~Y
DESTINATION STATION : IGI_Airport~O
DISTANCE : 27
NUMBER OF INTERCHANGES : 2

THE PATH IS AS FOLLOWS:
Huda_City_Center~Y
Saket~Y
AIIMS~Y
Rajiv_Chowk~BY ==> New_Delhi~YO
Shivaji_Stadium~O
DDS_Campus~O
IGI_Airport~O
💡 Interchange Logic
Stations like Rajiv_Chowk~BY are junctions with multiple lines.

The program identifies if the journey requires interchanging lines and where.

Interchanges are clearly marked like:
Rajiv_Chowk~BY ==> New_Delhi~YO

💰 Fare Calculation Logic
Based on number of stations traversed in the shortest route:

Stations Covered	Fare (INR)
1 - 3	₹10
4 - 7	₹20
8 - 11	₹30
12 - 20	₹40
21+	₹40 + ₹10 per station beyond 20

🛠️ How to Run
✅ Compile the project:
bash
Copy
Edit
g++ -std=c++17 metro.cpp -o metro
🚀 Run the executable:
bash
Copy
Edit
./metro
Replace metro.cpp with your actual file name if different.

📁 Folder Structure
bash
Copy
Edit
/DelhiMetroRoutePlanner
│
├── metro.cpp        # Main application logic
├── README.md        # You're here!
🙋‍♂️ Contributions
This is a single-developer CLI project, but contributions for expanding the map, improving path logic, or adding GUI are welcome!

📜 License
This project is released under the MIT License.
