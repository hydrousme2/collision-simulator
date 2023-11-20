### Problem Statement:

**Original Statement:**
Our project addresses the challenge of designing and implementing a multithreaded collision simulation system using C++ and Rust. The primary goal is to explore and compare the performance of the two languages. This was done by implementing a collision simulation in both languages and comparing the performance of the two implementations. The secondary goal is to explore the differences in language features and how they affect the design and implementation of the simulation. This was done by comparing the design and implementation of the two implementations.

### Software Architecture:

**Architecture Overview:**
The software architecture follows a modular design with separate components for physics simulation and multithreading management. Both C++ and Rust implementations share a common architecture to facilitate a direct performance comparison. Pure functions are used to implement the physics simulation logic, while multithreading is managed by a separate component. The multithreading component is responsible for spawning threads, managing thread lifecycles, and synchronizing threads. The multithreading component is implemented using the C++ standard library in the C++ implementation and using Rust's standard library in the Rust implementation.

**Testing Component:**
The testing component is integrated locally within the project, allowing for comprehensive unit testing and performance benchmarking. Test cases cover various collision scenarios and multithreading scenarios.

**Diagram:**
*(Include a simple diagram here)*

### POPL Aspects:

1. **Concurrency Management:**
   - C++: Utilizes std::thread for managing threads.
   - Rust: Applies Rust's ownership system to ensure safe concurrency without data races.

2. **Functional Programming in Rust:**
   - Rust employs functional programming concepts such as immutability and functional transformations in collision logic.

3. **Thread Safety and Shared Mutable State:**
   - Both implementations use mutexes (C++: std::mutex, Rust: std::sync::Mutex) to ensure thread safety when accessing shared mutable state, preventing race conditions.

4. **Ownership and Borrowing (Rust):**
   - Rust's ownership system ensures memory safety, preventing dangling references and enforcing a disciplined approach to memory management.

5. **Parallel Algorithms (C++):**
   - C++ implementation uses parallel algorithms from the Standard Library (e.g., std::for_each) to parallelize certain operations.

### Results:
*(Include a table of results here)*

### Potential for future work:
1. Sweep and prune algorithm for collision detection would reduce compute time from O(n^2) to O(n log n). This would be a significant improvement for large numbers of particles. But this would require mutex locks to be held for longer periods of time, which could potentially reduce performance.
2. Perform iterative separation of particles after collision to prevent particles from overlapping. This would require a more complex collision detection algorithm, but would improve the accuracy of the simulation for faster moving particles.
3. Compare performance with respect to Pure and Impure functions. This would require a more complex implementation of the simulation logic, but would provide a more comprehensive comparison of the two languages.