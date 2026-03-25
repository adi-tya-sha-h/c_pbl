# Online Food Monitoring System
A food tracking system to monitor food orders,restaurant inventory and customer feedback.


## Problem Statement
Design a food tracking system in C to monitor food orders, restaurant
inventory, and customer feedback. The system should ensure timely order
processing and secure data storage.

## Problem Description
In today's fast-paced world, managing a restaurant manually leads to many problems — lost orders, incorrect billing, poor inventory tracking, and no proper way to collect customer feedback. Small and medium restaurants often rely on paper-based systems which are slow, error-prone, and hard to maintain.

The Online Food Monitoring System solves these problems by providing a simple digital solution to manage the core operations of a restaurant. It allows staff to add and track food items in inventory, place and view customer orders, and collect feedback — all stored securely in files so data is never lost between sessions.

In real life, systems like this are the foundation of platforms like Zomato and Swiggy. When you place an order online, the restaurant's system checks inventory, confirms the order, and logs your details — exactly what this program simulates on a smaller scale.

This project demonstrates how basic programming concepts like structures, arrays, functions, and file handling can be combined to solve a real-world business problem.
It provides a foundation for understanding how larger food-tech systems are designed and operated.

## Proposed Modules
The system is divided into three main modules, each handling a specific aspect of restaurant management:
### 1. Inventory Management Module
This module allows restaurant staff to add food items to the system along with their price and available stock quantity. Staff can view the complete inventory at any time. When an order is placed, stock is automatically reduced, ensuring the inventory always reflects the current situation.
### 2. Order Management Module
This module handles the core functionality of the system — placing and viewing customer orders. The customer selects an item from the inventory, enters the quantity, and the system calculates the total price automatically. All orders are assigned a unique ID and saved to a file for future reference.
### 3. Customer Feedback Module
This module allows customers to submit their experience after placing an order. They can give a rating between 1 to 5 and leave a short comment. All feedback is stored in a file and can be viewed by the restaurant staff to improve service quality.
### Data Storage (File Handling)
All three modules save their data to text files — orders.txt, inventory.txt, and feedback.txt — so that no data is lost when the program is closed. Data is automatically loaded back when the program starts again.


## Authors

| Role | Name |
|---|---|
| Team Lead | Aditya Shah |
| Team Member | Chandan Singh Rawat |

- **College:** Graphic Era Hill University, Dehradun  
- **Course:** Programming for Problem Solving (B.Tech CSE)  
- **Assignment:** Project Based Learning – Semester Project
