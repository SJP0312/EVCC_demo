$ErrorActionPreference = 'Stop'

$projectRoot = Split-Path -Parent $PSScriptRoot

function Read-ProjectFile {
    param([Parameter(Mandatory = $true)][string]$RelativePath)
    return Get-Content -Raw (Join-Path $projectRoot $RelativePath)
}

function Assert-ContainsText {
    param(
        [Parameter(Mandatory = $true)][string]$Text,
        [Parameter(Mandatory = $true)][string]$Pattern,
        [Parameter(Mandatory = $true)][string]$Message
    )

    if ($Text -notmatch $Pattern) {
        throw $Message
    }
}

function Assert-FileExists {
    param([Parameter(Mandatory = $true)][string]$RelativePath)
    if (-not (Test-Path (Join-Path $projectRoot $RelativePath))) {
        throw "missing expected file: $RelativePath"
    }
}

$cfgHeader = Read-ProjectFile 'L1_RTE_Layer\OS\include\Evcc_Os_Cfg.h'
$cfgSource = Read-ProjectFile 'L1_RTE_Layer\OS\source\Evcc_Os_Cfg.c'
$osHeader = Read-ProjectFile 'L1_RTE_Layer\OS\include\Evcc_Os.h'
$osSource = Read-ProjectFile 'L1_RTE_Layer\OS\source\Evcc_Os.c'
$makefile = Read-ProjectFile 'Makefile'

Assert-ContainsText -Text $cfgHeader -Pattern '#define\s+EVCC_OS_TICK_RATE_HZ\s+100U' -Message 'missing 100Hz OS tick rate config'
Assert-ContainsText -Text $cfgHeader -Pattern '#define\s+EVCC_OS_TICK_PERIOD_MS\s+\(1000U / EVCC_OS_TICK_RATE_HZ\)' -Message 'missing OS tick period config'
Assert-ContainsText -Text $cfgHeader -Pattern '#define\s+EVCC_OS_MS_TO_TICKS\(ms\)' -Message 'missing ms-to-ticks macro'
Assert-ContainsText -Text $osHeader -Pattern 'typedef\s+unsigned\s+int\s+EvccOs_TickType;' -Message 'missing OS tick type'
Assert-ContainsText -Text $osHeader -Pattern 'EvccOs_TickType\s+periodTicks;' -Message 'task config must use periodTicks'
Assert-ContainsText -Text $osHeader -Pattern 'EvccOs_TickType\s+EvccOs_GetTickCount\(void\);' -Message 'missing tick count API'
Assert-ContainsText -Text $osSource -Pattern 'EvccOs_TickThread' -Message 'missing OS tick thread implementation'

Assert-ContainsText -Text $cfgHeader -Pattern '#define\s+EVCC_OS_APP1_TASK_PERIOD_MS\s+10U' -Message 'App_1_Task period macro must be 10ms'
Assert-ContainsText -Text $cfgHeader -Pattern '#define\s+EVCC_OS_APP2_TASK_PERIOD_MS\s+20U' -Message 'App_2_Task period macro must be 20ms'
Assert-ContainsText -Text $cfgHeader -Pattern '#define\s+EVCC_OS_APP3_TASK_PERIOD_MS\s+50U' -Message 'App_3_Task period macro must be 50ms'
Assert-ContainsText -Text $cfgHeader -Pattern '#define\s+EVCC_OS_APP4_TASK_PERIOD_MS\s+100U' -Message 'App_4_Task period macro must be 100ms'
Assert-ContainsText -Text $cfgHeader -Pattern '#define\s+EVCC_OS_APP5_TASK_PERIOD_MS\s+200U' -Message 'App_5_Task period macro must be 200ms'
Assert-ContainsText -Text $cfgSource -Pattern '"App_1_Task"[\s\S]*EVCC_OS_MS_TO_TICKS\(EVCC_OS_APP1_TASK_PERIOD_MS\)' -Message 'App_1_Task must use configured period macro'
Assert-ContainsText -Text $cfgSource -Pattern '"App_2_Task"[\s\S]*EVCC_OS_MS_TO_TICKS\(EVCC_OS_APP2_TASK_PERIOD_MS\)' -Message 'App_2_Task must use configured period macro'
Assert-ContainsText -Text $cfgSource -Pattern '"App_3_Task"[\s\S]*EVCC_OS_MS_TO_TICKS\(EVCC_OS_APP3_TASK_PERIOD_MS\)' -Message 'App_3_Task must use configured period macro'
Assert-ContainsText -Text $cfgSource -Pattern '"App_4_Task"[\s\S]*EVCC_OS_MS_TO_TICKS\(EVCC_OS_APP4_TASK_PERIOD_MS\)' -Message 'App_4_Task must use configured period macro'
Assert-ContainsText -Text $cfgSource -Pattern '"App_5_Task"[\s\S]*EVCC_OS_MS_TO_TICKS\(EVCC_OS_APP5_TASK_PERIOD_MS\)' -Message 'App_5_Task must use configured period macro'

foreach ($index in 4, 5) {
    Assert-FileExists "L2_APP_Layer\App_$index\include\App_$index.h"
    Assert-FileExists "L2_APP_Layer\App_$index\source\App_$index.c"
    Assert-FileExists "L1_RTE_Layer\Interface\include\Rte_App_$index.h"
    Assert-FileExists "L1_RTE_Layer\Interface\source\Rte_App_$index.c"
    Assert-ContainsText -Text $makefile -Pattern "L2_APP_Layer/App_$index/source" -Message "Makefile must include App_$index source directory"
}

Write-Host 'EVCC OS tick config check passed.'
