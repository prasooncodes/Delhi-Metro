# 🛤️ **Delhi Metro Route Planner - C++ CLI Project**

A command-line Delhi Metro route simulator built in C++. Use it to explore stations, view maps, find shortest paths, estimate travel times, and calculate fares.

---

## 📌 **Features**

- ✅ View all **stations** on the map  
- ✅ Display the **complete metro map** with distances  
- ✅ Find **shortest distance** using **Dijkstra’s algorithm**  
- ✅ Find **minimum time** path considering travel & wait times  
- ✅ Display route with **interchange stations**  
- ✅ Fare calculation based on number of stations  
- ✅ Fully interactive **menu-driven CLI**  
- ✅ Station **code list helper** for easy input  

---

## 🏗️ **Tech Stack**

- **Language**: C++  
- **Algorithms**: Dijkstra’s, DFS  
- **Data Structures**: Graph (Adjacency List), Priority Queue, HashMap  
- **Compiler**: g++ (C++17 or later)  

---

## 🖥️ **CLI Menu Options**

```text
WELCOME TO THE METRO APP

1. LIST ALL STATIONS IN THE MAP  
2. SHOW THE METRO MAP  
3. GET SHORTEST DISTANCE BETWEEN TWO STATIONS  
4. GET SHORTEST TIME BETWEEN TWO STATIONS  
5. GET SHORTEST PATH (DISTANCE WISE)  
6. GET SHORTEST PATH (TIME WISE)  
7. GET FARE FOR DISTANCE-WISE SHORTEST PATH  
8. GET FARE FOR TIME-WISE SHORTEST PATH  
9. EXIT  

# 🚇 Sample Output

```text
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

# 🔄 Interchange Explanation
Stations with suffixes like ~BY, ~YO represent interchange stations.

Interchanges are highlighted in the output as:

text
Copy
Edit
Rajiv_Chowk~BY ==> New_Delhi~YO

# 🛠️ How to Run
📦 Compile:
bash
Copy
Edit
g++ -std=c++17 metro.cpp -o metro

# 🚀 Run:
bash
Copy
Edit
./metro
