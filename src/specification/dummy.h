#ifndef RNJ_SPECIFICATION_DUMMY_H
#define RNJ_SPECIFICATION_DUMMY_H

#include BOOLLIB

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
} Specification;

void SpecificationInit(void);
void SpecificationReport(void);

#endif
