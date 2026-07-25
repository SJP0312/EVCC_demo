$ErrorActionPreference = 'Stop'

$projectRoot = Split-Path -Parent $PSScriptRoot
$osSource = Get-Content -Raw (Join-Path $projectRoot 'L1_RTE_Layer\OS\source\Evcc_Os.c')

if ($osSource -notmatch 'EvccOs_GetHostTimeMs') {
    throw 'OS tick must use host elapsed time instead of adding only one tick per sleep wakeup.'
}

if ($osSource -notmatch 'elapsedTicks') {
    throw 'OS tick thread must accumulate elapsed ticks when the host scheduler wakes late.'
}

if ($osSource -notmatch 'evcc_os_tick_count\s*\+=\s*elapsedTicks') {
    throw 'OS tick count must advance by elapsedTicks, not fixed one-tick increments.'
}

Write-Host 'EVCC OS elapsed tick check passed.'
