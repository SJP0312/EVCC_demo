$ErrorActionPreference = 'Stop'

$projectRoot = Split-Path -Parent $PSScriptRoot
$buildDir = Join-Path $projectRoot 'build'
$exePath = Join-Path $buildDir 'evcc_check_tmp.exe'

$sourceFiles = @(
    'tests\os_api_boundary_test.c',
    'L1_RTE_Layer\OS\source\Evcc_Os.c',
    'L1_RTE_Layer\OS\source\Evcc_Os_Queue.c',
    'L1_RTE_Layer\OS\source\Evcc_Os_Semaphore.c',
    'L1_RTE_Layer\OS\source\Evcc_Os_EventGroup.c',
    'L1_RTE_Layer\OS\source\Evcc_Os_Interrupt.c'
)

Push-Location $projectRoot
try {
    if (-not (Test-Path $buildDir)) {
        New-Item -ItemType Directory -Path $buildDir | Out-Null
    }

    gcc -std=c17 -Wall -Wextra -g -O0 -pthread -IL1_RTE_Layer/OS/include $sourceFiles -pthread -o $exePath | Out-Host
    if ($LASTEXITCODE -ne 0) {
        throw "OS API boundary test build failed with exit code $LASTEXITCODE"
    }

    & $exePath | Out-Host
    if ($LASTEXITCODE -ne 0) {
        throw "OS API boundary test failed with exit code $LASTEXITCODE"
    }
} finally {
    Pop-Location
}
