# LibFila
This project implements a queue library in C, supporting basic operations such as enqueueing and dequeueing.

## Introduction
This project focuses on the development of a queue data structure library in C, designed to handle integer elements. A queue ("fila", in Portuguese) operates on the FIFO (First In, First Out) principle, where the first element added is the first to be removed. The library provides fundamental queue operations such as insertion (enqueue), removal (dequeue), checking if the queue is empty, and return the queue's size. In addition to the library, a test suite is implemented to ensure the correctness and robustness of the functions, aiming for effective memory management without leaks.

### Implemented Functions
1. fila_t *cria_fila(): This function creates an empty queue.
2. fila_t *destroi_fila(fila_t *f): This function destroys the queue and frees the associated memory.
3. int fila_vazia(fila_t *f): This function checks if the queue is empty.
4. int tamanho_fila(fila_t *f): This function returns the current size of the queue, which represents the number of elements it contains.
5. int insere_fila(fila_t *f, int elemento): This function inserts a new element at the end of the queue.
6. int retira_fila(fila_t *f, int *elemento): This function removes the first element from the queue and stores its value in the provided pointer.

## Results
The queue library passed all unit tests, demonstrating that the enqueue and dequeue operations work correctly, and the structure handles memory allocation and deallocation without errors. Memory management was verified through a tool called Valgrind.

## Conclusion
This project successfully implements a queue library in C, offering essential queue operations while maintaining efficient memory handling. The tests confirmed that the library functions as intended, and the methodology used ensures a reliable and reusable codebase for future applications.
