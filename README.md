# high-performance-tcp-sever
A high-performance, Multi-Threaded TCP server built with C++20, Optimized for scalability and low latency.

# Key FesturresBenchmarking with Google Benchmark & Profiling with Valgrind
✅ Optional: Load balancer to distribute client connections

🛠️ Tech Stack
Programming: C++20, STL, Multithreading, Boost.Asio
Networking: Sockets, epoll (Linux), kqueue (MacOS)
DevOps: Docker, CI/CD (GitHub Actions)
Testing & Benchmarking: Google Test (gtest), Google Benchmark, Valgrind
🚀 Getting Started
1️⃣ Prerequisites
C++20 Compiler (g++-11 or clang++-11)
CMake (sudo apt install cmake)
Boost.Asio (sudo apt install libboost-all-dev)
2️⃣ Build & Run
sh
Copy
Edit
git clone https://github.com/yourusername/high-performance-tcp-server.git  
cd high-performance-tcp-server  
mkdir build && cd build  
cmake .. && make  
./tcp_server  
3️⃣ Run Tests
sh
Copy
Edit
./run_tests
📌 Project Roadmap
🔹 Phase 1: Basic TCP Server (✅ Done)
🔹 Phase 2: Multi-threading (🛠 In Progress)
🔹 Phase 3: Non-blocking I/O (epoll/kqueue)
🔹 Phase 4: Performance Optimization & Profiling
🔹 Phase 5: Load Balancer & Documentation

📸 Benchmarks & Results (To be added later)
Response time vs. Java/Python servers
CPU & Memory profiling results
Multi Threaded handling for Concurrent client connections
Non-blocking I/O using epoll/kqueue for high throughput
Optimized memory allocation and low latency processing
Thread Pool implementation for efficient resource usage
