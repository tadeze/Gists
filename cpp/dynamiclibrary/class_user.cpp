#include <dlfcn.h>
#include <iostream>
#include "myclass.h"

using namespace std;

int main(int argc, char **argv)
{
  /* on Linux, use "./myclass.so" */
  void* handle = dlopen("./myclass.so", RTLD_LAZY);

  MyClass* (*create)();
  void (*destroy)(MyClass*);

  create = (MyClass* (*)())dlsym(handle, "create_object");
  destroy = (void (*)(MyClass*))dlsym(handle, "destroy_object");

  MyClass* myClass = (MyClass*)create();
  myClass->DoSomething();
  destroy( myClass );
}

/*
Compiling and attaching the dynamic library 


g++ -fPIC -shared myclass.cpp -o myclass.so
g++ class_user.cpp -ldl -o class_user



*/
