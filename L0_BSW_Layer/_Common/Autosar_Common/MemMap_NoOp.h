/*
 * PC simulation MemMap adapter.
 *
 * AUTOSAR MemMap section pragmas and MPU placement rules are target/linker
 * concerns. The Windows GCC simulation build keeps all objects in the default
 * host sections, so MemMap includes intentionally become no-ops here.
 *
 * No include guard: AUTOSAR MemMap headers are included repeatedly.
 */

#ifdef MEMMAP_ERROR
# undef MEMMAP_ERROR
#endif

#ifdef MEMMAP_SECTION_OPEN
# undef MEMMAP_SECTION_OPEN
#endif
