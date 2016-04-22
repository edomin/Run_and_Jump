#include "dialogs/native.h"

#define THREAD_STACK_SIZE 4096
//
//int kos_CreateThread(void *proc, void *data)
//{
//   uint8_t *stack = malloc(THREAD_STACK_SIZE);
//   if (!stack)
//      return -1;
//   uint32_t *new_esp = (uint32_t *)&stack[THREAD_STACK_SIZE-sizeof(size_t)*2];
//   new_esp[0] = (uint32_t)kos_ExitApp;
//   new_esp[1] = (uint32_t)data;
//   return syscall4(51, 1, (unsigned)proc, (unsigned)new_esp);
//}

void kolibrios_DialogThread(void)
{
    __asm__ __volatile__(
    "int $0x40"
    :
    :"a"(63),"b"(1),"c"((uint32_t)('a'))
    :"memory");


}

void kolibrios_DialogExitThread(void)
{
	__asm__ __volatile__(
    "int $0x40"
    :
    :"a"(-1)
    :"memory");
}

void DialogsShowSimpleMessageBox(int type, char *title, char *message)
{
    unsigned char *dialogStack;
    uint32_t *new_esp;
    dialogStack = malloc(THREAD_STACK_SIZE);
    new_esp = (uint32_t *)&dialogStack[THREAD_STACK_SIZE-sizeof(size_t)*2];

	new_esp[0] = (uint32_t)kolibrios_DialogExitThread;
//	new_esp[1] = (uint32_t)data;

    __asm__ __volatile__(
    "int $0x40"
    :
    :"a"(51),"b"(1),"c"((uint32_t)kolibrios_DialogThread),"d"((uint32_t)(new_esp))
    :"memory");


}

bool DialogsShowYesNoMessageBox(char *title, char *message)
{
    return false;
}

