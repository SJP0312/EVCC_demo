# EVCC_demo

Standalone C/C++ Makefile project generated under:

```text
D:\workspace\C_project\EVCC_demo
```

## Layered Architecture

```text
src/                  Top-level startup entry
include/              Top-level public interface
L0_BSW_Layer/         Simulated low-level driver/config libraries
L1_RTE_Layer/         Per-App RTE interfaces and pthread-backed OS abstraction
L2_APP_Layer/         Application components
tests/                PC-side smoke tests
```

## Build Commands

```powershell
mingw32-make all
mingw32-make run
mingw32-make clean
mingw32-make rebuild
```

## PC FreeRTOS-Style Simulation

This project uses a pthread-based OS abstraction. On this PC, Windows Device Guard
allows the dynamic `winpthread` build and blocks statically linked `winpthread`
executables, so the default build is the runnable dynamic pthread mode.

Run the project:

```powershell
mingw32-make run
```

Optional static `winpthread` build, for machines whose application-control policy
allows it:

```powershell
mingw32-make THREAD_LINK=static rebuild
```

Terminal commands while the program is running:

```text
1    Start or resume task execution
0    Stop or pause task execution
```

Expected heartbeat behavior:

- `App_1`: 1s task period, prints every 5s with `I am Lib_1`.
- `App_2`: 1s task period, prints every 10s with `I am Lib_2`.
- `App_3`: 1s task period, prints every 15s with `I am Lib_3`.

This verifies the intended RTE routing:

```text
App_1 -> Rte_App_1 -> Lib_1
App_2 -> Rte_App_2 -> Lib_2
App_3 -> Rte_App_3 -> Lib_3
```

Each App has its own RTE interface file. App code must not include any `Lib_x`
header directly, and shared generic RTE getters are intentionally not used.

## Verification

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\run_layer_decoupling_check.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\run_evcc_os_smoke.ps1
```

## VSCode

Open this folder directly in VSCode:

```powershell
code .
```

Use `Ctrl + mouse left click` for definitions and headers. Use right-click commands for references, definition peek, and call hierarchy.
