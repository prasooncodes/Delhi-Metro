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
<img width="605" height="533" alt="image" src="https://github.com/user-attachments/assets/1a67106f-0fb8-46bf-8d54-68bf51363853" />
<img width="484" height="523" alt="image" src="https://github.com/user-attachments/assets/45b92445-73cf-4cf8-a588-2d8eb4b34ac2" />
<img width="536" height="684" alt="image" src="https://github.com/user-attachments/assets/ceed1d09-8f79-4ce2-99a8-05138e16dafb" />
<img width="523" height="565" alt="image" src="https://github.com/user-attachments/assets/7b4125fc-0d24-443f-a046-01412204066e" />
<img width="575" height="521" alt="image" src="https://github.com/user-attachments/assets/7b542615-3786-49ab-a61b-a56a44c4eeec" />
<img width="639" height="419" alt="image" src="https://github.com/user-attachments/assets/0e2a18a5-a318-46d1-9dc1-ef7a19bd4878" />







