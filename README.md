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
```

## 📸 Screenshot

<img width="1175" height="480" alt="image" src="https://github.com/user-attachments/assets/b72f6b8e-fc45-485f-a740-6746dddef4e2" />

