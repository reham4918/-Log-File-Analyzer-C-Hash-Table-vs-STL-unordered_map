# 🚀 Log File Analyzer: Battle of the Hash Tables! 

A high-performance comparison between a Custom Hash Table and STL's unordered_map for analyzing web server logs.

## 🎯 Overview

This project implements and compares two different approaches to analyze web server log files and track the most visited web pages:
* 🔨 Custom Hash Table Implementation
* 🎁 STL's unordered_map Implementation

## ✨ Features

* 📊 Processes web server access logs
* 🏃‍♂ High-performance hash table implementations
* 📈 Tracks page visit frequencies
* 🏆 Identifies top 10 most visited pages
* ⚡ Real-time performance comparison
* 🔒 Thread-safe operations (in unordered_map implementation)

## 🏗 Implementation Details

### Custom Hash Table
* Uses linear probing for collision resolution
* Custom hash function with bit manipulation
* Fixed-size vector implementation
* Manual memory management

### STL unordered_map
* Leverages C++ Standard Template Library
* Automatic scaling and collision handling
* Thread-safe operations with mutex locks
* Modern C++ implementation

## 🚀 Usage

1. Compile the project:
bash
g++ -std=c++11 main.cpp HashTable.cpp UnorderedMap.cpp -o log_analyzer


2. Run the analyzer:
bash
./log_analyzer


The program will process the access log file and display:
* Top 10 most visited web pages for both implementations
* Performance metrics for each approach

## 📊 Performance

The program measures and compares the performance of both implementations using the C++ chrono library, providing real-time execution statistics for:
* File processing time
* Memory usage patterns
* Access pattern efficiency

## 🛠 Technical Details

### Requirements
* C++11 or higher
* Standard Template Library (STL)
* Input log file in standard web server format

### File Structure
* main.cpp - Entry point and performance comparison
* HashTable.h/cpp - Custom hash table implementation
* UnorderedMap.h/cpp - STL unordered_map wrapper implementation

## 👥 Contributors

This project was developed as part of a data structures analysis project by:
* Joudi Besaiso (2285455)
* Ryham Houari (2281222)
* Abrar Al-harazi (2106235)

## 📝 License

This project is open source and available under the MIT License.
