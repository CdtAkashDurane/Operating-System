#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_function(void *ptr) {
    char *message;
    message = (char *)ptr;
    printf("%s\n", message);
    return NULL;  // Missing return statement
}

int main() {
    pthread_t thread1, thread2, thread3;  // Fixed typo: ptread_t → pthread_t

    char *message1 = "From Thread 1";
    char *message2 = "From Thread 2";   // All message variables need to be different
    char *message3 = "From Thread 3";

    int ret1, ret2, ret3;

    ret1 = pthread_create(&thread1, NULL, print_function, (void *)message1);
    ret2 = pthread_create(&thread2, NULL, print_function, (void *)message2);
    ret3 = pthread_create(&thread3, NULL, print_function, (void *)message3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Thread 1 Returns: %d\n", ret1);
    printf("Thread 2 Returns: %d\n", ret2);
    printf("Thread 3 Returns: %d\n", ret3);

    return 0;
}
/*
Output:- 
──(kali㉿kali)-[~/Desktop/Testing Program]
└─$ gcc -pthread Test4.c -o ./Thread
                                                                                                                                                                      
┌──(kali㉿kali)-[~/Desktop/Testing Program]
└─$ ./Thread                        
From Thread 1
From Thread 3
From Thread 2
Thread 1 Returns: 0
Thread 2 Returns: 0
Thread 3 Returns: 0
                                                                                                                                                                      
┌──(kali㉿kali)-[~/Desktop/Testing Program]
└─$ ./Thread
From Thread 1
From Thread 2
From Thread 3
Thread 1 Returns: 0
Thread 2 Returns: 0
Thread 3 Returns: 0
*/
