#include "user.h"

int main(int argc, char *argv[]) {
    printf("memsize: %d\n", memsize());
    void *memory = malloc(20000);
    printf("memsize: %d\n", memsize());
    free(memory);
    printf("memsize: %d\n", memsize());
    return 0;
}

// my answers:
// 1. system calls are diffrent from user space functions calls because
//    syscalls are executed in kernel mode and user space functions are executed in user mode.
//    systemcalls require a context switch to the kernel mode and user space functions do not.
//
// 2. parameters are passed to a system call using registers and stack.
//    usually, the system call number is passed in register a7 and the parameters are passed in a0-a6.
//    if more than 6 parameters are needed, the parameters are passed on the stack.
//
// 3. the purpose of usys.pl file is to create stubs for system calls, the stubs are used to call the system calls from user space.
//    and also to pass the system call number and parameters to the system call handler and return the result.
//
// 4. the struct proc is a data structure that represents a process in the xv6 operating system.
//    the struct proc contains information about the process such as its state, stack, page table, file descriptors, and other process-related data.
//    it is used in the real world usually under the concept of process control block (PCB).
//
// 5. our program used 16384 bytes of memory (16KB).
//    this is the default memory size for a process in xv6.
//    after the allocation of 20,000 bytes the program used 81920 bytes of memory
//     this is due to two reasons:
//     1. xv6 allocates memory in pages each page is 4096 bytes (4KB) in size.
//     so we need to allocate 5 pages to store 20,000 bytes and this is 20480 bytes.
//     2. xv6 probably allocated more memory then requested to reduce the number of system calls needed in future allocations.
//
// 6. the size after the release is still 81920 bytes.
//
// 7. the memory is not released back to the system after the call to free.
//    but it is marked as free in the memory allocatot and can be reused in future allocations.
//    this optimization is done to reduce the nmber of system calls needed for memory allocations.
