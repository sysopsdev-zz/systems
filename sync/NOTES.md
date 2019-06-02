# Critical Section

Block of code where shared data is accessed

### Semaphores
ADT used to access shared data/resources. 
- Semaphore count

Two methods:
- signal()
- wait()

# Problems
Bounded Buffer
Reader - Writers
Dining - Philosophers
Sleeping - Barber


### Bounded Buffer
Proudcer: Produce one "item" each iteration
Consumer: Consumes one item each iteration

Restriction: Buffer holds N items; Semaphores

One producer and five consumers? Cannot access shared buffer at the same time. 



### Signal
Sends argument to buffer. 

### Wait
Receives buffer.
