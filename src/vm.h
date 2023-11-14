#ifndef clox_vm_h
#define clox_vm_h

#include <stdint.h>
#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
    Chunk* chunk;
    uint8_t* ip; //instruction pointer
    Value stack[STACK_MAX];
    Value* stackTop;
} VM;

void init_vm();
void free_vm();

void push(Value value);
Value pop();

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

InterpretResult interpret(const char* source);

#endif
