
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>

void foo(void);
int change_page_permissions_of_address(void *addr);

int main(void) {
    void *foo_addr = (void*)foo;

    // Change the permissions of the page that contains foo() to read, write, and execute
    // This assumes that foo() is fully contained by a single page
    if(change_page_permissions_of_address(foo_addr) == -1) {
        fprintf(stderr, "Error while changing page permissions of foo(): %s\n", strerror(errno));
        return 1;
    }

    // Call the unmodified foo()
    puts("Calling foo...");
    foo();

    // Change the immediate value in the addl instruction in foo() to 42
    // According to the machine code, we need to change the byte at address <foo+15> (little endian !)
    unsigned char *instruction = (unsigned char*)foo_addr + 15;
    *instruction = 0x2a;

    // Call the modified foo()
    puts("Calling foo...");
    foo();

    return 0;
}

void foo(void) {
    int i=0;
    i++;
    printf("i: %d\n", i);
}

int change_page_permissions_of_address(void *addr) {
    // Move the pointer to the page boundary
    int page_size = getpagesize();
    addr -= (unsigned long)addr % page_size;

    if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1;
    }

    return 0;
}
