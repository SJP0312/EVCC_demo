# EVCC PC FreeRTOS-Style Simulation Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Implement a PC-side FreeRTOS-style multitask simulation framework for `EVCC_demo`.

**Architecture:** Keep `src` as the top-level entry source directory. Add L0/L1/L2 component modules and use a pthread-backed OS abstraction in `L1_RTE_Layer/OS` so application code stays separated from the PC threading implementation.

**Tech Stack:** C17, MinGW-w64 GCC, GNU Make via `mingw32-make`, pthread/winpthreads, VSCode C/C++ extension.

---

### Task 1: Regression Smoke Test

- [x] Create `tests/run_evcc_os_smoke.ps1`.
- [x] Verify the test fails against the old single-print program.

### Task 2: L0 BSW Libraries

- [x] Add Lib1/Lib2/Lib3 include/source modules.
- [x] Implement Lib2 10s heartbeat from a 1s main function.

### Task 3: L1 RTE Interface And OS

- [x] Add RTE interface functions.
- [x] Add pthread-backed OS abstraction.
- [x] Add terminal `1`/`0` RUN/STOP command input.

### Task 4: L2 APP Components

- [x] Add App1/App2/App3 include/source modules.
- [x] Implement App1 5s heartbeat and App2 10s heartbeat.

### Task 5: Top-Level Entry And Build

- [x] Keep `src` as top-level source entry.
- [x] Update `src/main.c`, `include/main.h`, `Makefile`, and VSCode include paths.

### Task 6: Verification And Archive

- [x] Run build and smoke verification.
- [ ] Archive final source summary, test result, and version record.

