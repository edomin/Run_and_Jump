#include "specification/sdl2.h"

void SpecificationInit(void)
{
    Specification.LogicalCPUCoresCount = SDL_GetCPUCount();
    Specification.L1CashLineSize = SDL_GetCPUCacheLineSize();
    Specification.RDTSC = SDL_HasRDTSC();
    Specification.AltiVec = SDL_HasAltiVec();
    Specification.MMX = SDL_HasMMX();
    Specification._3DNow = SDL_Has3DNow();
    Specification.SSE = SDL_HasSSE();
    Specification.SSE2 = SDL_HasSSE2();
    Specification.SSE3 = SDL_HasSSE3();
    Specification.SSE41 = SDL_HasSSE41();
    Specification.SSE42 = SDL_HasSSE42();
    Specification.AVX = SDL_HasAVX();
    Specification.RAMMiB = SDL_GetSystemRAM();
    Specification.platform = SDL_GetPlatform();
}

void SpecificationReport(void)
{
    LogWrite("Reporting specification", 0, MT_INFO, NULL);
    LogWrite("Platform:", 1, MT_INFO, (char *)Specification.platform);
    LogWrite2("Logical CPU cores count:", 1, MT_INFO, Specification.LogicalCPUCoresCount);
    LogWrite2("L1 Cash line size (Bytes):", 1, MT_INFO, Specification.L1CashLineSize);
    if (Specification.RDTSC)
    {
        LogWrite("RDTSC instruction:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("RDTSC instruction:", 1, MT_INFO, "Not Supported");
    }
    if (Specification.AltiVec)
    {
        LogWrite("AltiVec instruction set:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("AltiVec instruction set:", 1, MT_INFO, "Not Supported");
    }
    if (Specification.MMX)
    {
        LogWrite("MMX:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("MMX:", 1, MT_INFO, "Not Supported");
    }
    if (Specification._3DNow)
    {
        LogWrite("3DNow!:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("3DNow!:", 1, MT_INFO, "Not Supported");
    }
    if (Specification.SSE)
    {
        LogWrite("SSE:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("SSE:", 1, MT_INFO, "Not Supported");
    }
    if (Specification.SSE2)
    {
        LogWrite("SSE2:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("SSE2:", 1, MT_INFO, "Not Supported");
    }
    if (Specification.SSE3)
    {
        LogWrite("SSE3:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("SSE3:", 1, MT_INFO, "Not Supported");
    }
    if (Specification.SSE41)
    {
        LogWrite("SSE4.1:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("SSE4.1:", 1, MT_INFO, "Not Supported");
    }
    if (Specification.SSE42)
    {
        LogWrite("SSE4.2:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("SSE4.2:", 1, MT_INFO, "Not Supported");
    }
    if (Specification.AVX)
    {
        LogWrite("AVX:", 1, MT_INFO, "Supported");
    }
    else
    {
        LogWrite("AVX:", 1, MT_INFO, "Not Supported");
    }
    LogWrite2("System physical memory (MiB):", 1, MT_INFO, Specification.RAMMiB);
}

