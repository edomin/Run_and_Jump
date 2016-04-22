#ifndef RNJ_SPECIFICATION_SDL2_H
#define RNJ_SPECIFICATION_SDL2_H

#include <bool.h>
#include <SDL2/SDL_cpuinfo.h>
#include <SDL2/SDL_platform.h>

#include "utils.h"
#include "log.h"

struct {
    int LogicalCPUCoresCount;
    int L1CashLineSize;
    bool RDTSC;
    bool AltiVec;
    bool MMX;
    bool _3DNow;
    bool SSE;
    bool SSE2;
    bool SSE3;
    bool SSE41;
    bool SSE42;
    bool AVX;
    int RAMMiB;
    const char *platform;
} Specification;

void SpecificationInit(void);
void SpecificationReport(void);

#endif
