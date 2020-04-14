#include <stddef.h>
#include <stddef.h>
#include <stdio.h>
#include <dlfcn.h>

void (*hello_Ariel)(const char *);

_Bool init_library() {

    void *hdl = dlopen("./libHello.so", RTLD_LAZY);
    if (NULL == hdl)
        return 0;
    hello_Ariel = (void (*)(const char *)) dlsym(hdl, "hello_Ariel");
    if (NULL == hello_Ariel)
        return 0;
    return 1;

}

int main() {

    if (init_library())
        hello_Ariel("hello_Ariel");
    else
        printf("not loaded \n");
    return 0;
}

