# EVCC PC FreeRTOS-Style Simulation Design

## Goal

Build a PC-side embedded software framework inside `EVCC_demo` that simulates a FreeRTOS-like multitask runtime while preserving a strict layered architecture for future EVCC development.

## Target User

An embedded C developer using VSCode, MinGW-w64 GCC, Makefile, and Git to prototype EVCC software structure on a PC before moving toward target hardware.

## Architecture

The project keeps `src` as the top-level entry source directory. Component code is separated into:

- `L0_BSW_Layer`: low-level simulated driver/config libraries.
- `L1_RTE_Layer`: runtime environment interfaces and OS abstraction.
- `L2_APP_Layer`: application components and service logic.

`L1_RTE_Layer/OS` wraps `pthread`/MinGW-w64 winpthreads behind FreeRTOS-style APIs such as task creation, scheduler start, delay, and run/stop state control. Application and library tasks do not call pthread directly.

## Runtime Behavior

On startup, the program creates all configured task threads and starts a scheduler monitor loop. Tasks are created once and remain alive.

- Input `1`: set system state to RUN, allowing task main functions to execute.
- Input `0`: set system state to STOP, pausing task main function execution without destroying threads.

Expected heartbeats:

- `App_1`: task period 1s, heartbeat print every 5s with `I am Lib_1`.
- `App_2`: task period 1s, heartbeat print every 10s with `I am Lib_2`.
- `App_3`: task period 1s, heartbeat print every 15s with `I am Lib_3`.

## Acceptance Criteria

- Project builds with `mingw32-make all`.
- `src` remains the top-level entry source directory.
- L0/L1/L2 folders contain separated include/source module files.
- Input `1` starts heartbeat output.
- Input `0` pauses heartbeat output while process remains alive.
- Build uses mainstream MinGW-w64 pthread support.
- The Windows build keeps the pthread OS backend. Dynamic `winpthread` is the default on this PC because Device Guard blocks statically linked `winpthread` executables; static mode remains available through `THREAD_LINK=static` for machines that allow it.
