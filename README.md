# 🚇 Delhi Metro Route Planner

A command-line C++ application to plan metro routes in Delhi. This tool allows users to explore metro stations, view maps, find shortest paths (distance/time), and calculate fares between any two stations.

---

## 📌 Features

- 📍 List all metro stations
- 🗺️ Display a metro map with connected stations and distances
- 📏 Calculate shortest distance between two stations
- ⏱️ Calculate shortest time to reach destination
- 🧭 Show shortest path (distance wise)
- ⌛ Show shortest path (time wise)
- 💰 Calculate fare based on stations traveled
- 🔁 Interchange station detection and display
- ✅ Validates station names and routes

---

## 🚀 How It Works

The metro system is modeled using a **graph** where:

- Each **station** is a vertex
- Each **connection** is an undirected, weighted edge (distance in km)
- **Interchange stations** have suffixes like `~BY`, `~YO` to denote lines

Pathfinding is handled by:

- 🧠 Dijkstra's Algorithm for shortest distance/time
- 🔁 Interchange detection through path parsing
- 🎫 Fare calculation using number of stations in the path

---

# 💰 Fare Calculation
# 📌 Fare Slabs Based on Number of Stations
Stations Covered	Fare (INR)
1 – 3	₹10
4 – 7	₹20
8 – 11	₹30
12 – 20	₹40
>20	₹40 + ₹10 per station

## 🧪 Sample Output

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
