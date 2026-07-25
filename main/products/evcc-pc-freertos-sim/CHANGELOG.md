# Changelog

## v0.1.0 - 2026-07-25

- Added PC-side FreeRTOS-style task simulation using MinGW-w64 pthread/winpthreads.
- Kept `src` as top-level entry source directory.
- Added L0 BSW layer with Lib1, Lib2, and Lib3.
- Added L1 RTE layer with interface and OS abstraction.
- Added L2 APP layer with App1, App2, and App3 frameworks.
- Added terminal command control: `1` starts/resumes task execution, `0` stops/pauses execution.
- Added RTE-routed heartbeats for App1->Lib1, App2->Lib2, and App3->Lib3.
- Replaced the generic RTE interface with per-App RTE files so each App owns its own init/main/get-info route to its matching Lib.
- Kept the pthread OS backend and added selectable `THREAD_LINK=dynamic|static`; dynamic is the runnable default on this PC because Device Guard blocks static `winpthread` executables.
- Extended Makefile and VSCode IntelliSense include paths.
- Added automated smoke test for build, RUN command, heartbeat output, STOP command, and post-STOP pause behavior.
