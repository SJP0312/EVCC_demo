# Changelog

## v0.3.0 - 2026-07-25

- Changed the PC simulation tick configuration to 100Hz for a more realistic Windows user-mode cadence.
- Changed task scheduling from millisecond sleep periods to tick-based release periods.
- Added elapsed-time tick compensation so Windows user-mode sleep granularity does not slow App task execution.
- Configured App1/App2/App3/App4/App5 task periods as 10ms, 20ms, 50ms, 100ms, and 200ms.
- Added empty App4/App5 APP and RTE interfaces for future expansion.
- Kept App1/App2/App3 RTE-routed heartbeat behavior, now printing actual task call counts.
- Kept test C files outside the normal Makefile project source directories.

## v0.2.0 - 2026-07-25

- Added OS abstraction status codes and wait constants.
- Added static-pool Queue APIs for copied message passing.
- Added binary and counting Semaphore APIs.
- Added EventGroup APIs for bit-based task synchronization.
- Added simulated Interrupt APIs with register, enable, disable, and trigger behavior.
- Added OS API test that compiles only OS sources.
- Kept priority as a configuration/migration field without Windows real-time preemption.
- Preserved existing App1/App2/App3 heartbeat behavior and OS/ASW decoupling.

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
