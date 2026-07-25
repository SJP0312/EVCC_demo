$ErrorActionPreference = 'Stop'

$projectRoot = Split-Path -Parent $PSScriptRoot

function Read-ProjectFile {
    param(
        [Parameter(Mandatory = $true)]
        [string]$RelativePath
    )

    return Get-Content -Raw (Join-Path $projectRoot $RelativePath)
}

function Assert-ContainsText {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Text,

        [Parameter(Mandatory = $true)]
        [string]$Pattern,

        [Parameter(Mandatory = $true)]
        [string]$Message
    )

    if ($Text -notmatch $Pattern) {
        throw $Message
    }
}

function Assert-NotContainsText {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Text,

        [Parameter(Mandatory = $true)]
        [string]$Pattern,

        [Parameter(Mandatory = $true)]
        [string]$Message
    )

    if ($Text -match $Pattern) {
        throw $Message
    }
}

$requiredFiles = @(
    'L1_RTE_Layer\Interface\include\Rte_App_1.h',
    'L1_RTE_Layer\Interface\include\Rte_App_2.h',
    'L1_RTE_Layer\Interface\include\Rte_App_3.h',
    'L1_RTE_Layer\Interface\source\Rte_App_1.c',
    'L1_RTE_Layer\Interface\source\Rte_App_2.c',
    'L1_RTE_Layer\Interface\source\Rte_App_3.c'
)

foreach ($relativePath in $requiredFiles) {
    if (-not (Test-Path (Join-Path $projectRoot $relativePath))) {
        throw "missing decoupled RTE file: $relativePath"
    }
}

$forbiddenFiles = @(
    'L1_RTE_Layer\Interface\include\Rte_Interface.h',
    'L1_RTE_Layer\Interface\source\Rte_Interface.c'
)

foreach ($relativePath in $forbiddenFiles) {
    if (Test-Path (Join-Path $projectRoot $relativePath)) {
        throw "generic shared RTE file must be removed: $relativePath"
    }
}

$allSourceText = (Get-ChildItem -Path $projectRoot -Recurse -Include *.c,*.h |
    Where-Object { $_.FullName -notmatch '\\build\\' } |
    ForEach-Object { Get-Content -Raw $_.FullName }) -join "`n"

Assert-NotContainsText -Text $allSourceText -Pattern '\bRte_Init\b|\bRte_GetLib[123]Info\b|\bRte_Lib2_MainFunction\b' -Message 'generic RTE APIs are still referenced'
Assert-NotContainsText -Text $allSourceText -Pattern 'Rte_Interface\.h' -Message 'generic Rte_Interface.h is still referenced'

for ($index = 1; $index -le 3; $index++) {
    $libHeader = Read-ProjectFile "L0_BSW_Layer\Lib_$index\include\Lib_$index.h"
    $libSource = Read-ProjectFile "L0_BSW_Layer\Lib_$index\source\Lib_$index.c"

    Assert-ContainsText -Text $libHeader -Pattern "void Lib$index`_Init\(void\);" -Message "Lib_$index header is missing Lib${index}_Init"
    Assert-ContainsText -Text $libHeader -Pattern "void Lib$index`_MainFunction\(void\);" -Message "Lib_$index header is missing Lib${index}_MainFunction"
    Assert-ContainsText -Text $libHeader -Pattern "const char \*Lib$index`_GetInfo\(void\);" -Message "Lib_$index header is missing Lib${index}_GetInfo"
    Assert-ContainsText -Text $libSource -Pattern "void Lib$index`_Init\(void\)" -Message "Lib_$index source is missing Lib${index}_Init"
    Assert-ContainsText -Text $libSource -Pattern "void Lib$index`_MainFunction\(void\)" -Message "Lib_$index source is missing Lib${index}_MainFunction"
    Assert-ContainsText -Text $libSource -Pattern "const char \*Lib$index`_GetInfo\(void\)" -Message "Lib_$index source is missing Lib${index}_GetInfo"

    $rteHeader = Read-ProjectFile "L1_RTE_Layer\Interface\include\Rte_App_$index.h"
    $rteSource = Read-ProjectFile "L1_RTE_Layer\Interface\source\Rte_App_$index.c"
    $appSource = Read-ProjectFile "L2_APP_Layer\App_$index\source\App_$index.c"

    Assert-ContainsText -Text $rteHeader -Pattern "void Rte_App${index}_Init\(void\);" -Message "Rte_App_$index header is missing init API"
    Assert-ContainsText -Text $rteHeader -Pattern "void Rte_App${index}_MainFunction\(void\);" -Message "Rte_App_$index header is missing main API"
    Assert-ContainsText -Text $rteHeader -Pattern "const char \*Rte_App${index}_GetLibInfo\(void\);" -Message "Rte_App_$index header is missing get-info API"
    Assert-ContainsText -Text $rteSource -Pattern "Lib${index}_Init\(\);" -Message "Rte_App_$index does not route init to Lib_$index"
    Assert-ContainsText -Text $rteSource -Pattern "Lib${index}_MainFunction\(\);" -Message "Rte_App_$index does not route main to Lib_$index"
    Assert-ContainsText -Text $rteSource -Pattern "Lib${index}_GetInfo\(\);" -Message "Rte_App_$index does not route info to Lib_$index"
    Assert-ContainsText -Text $appSource -Pattern "#include `"Rte_App_$index\.h`"" -Message "App_$index does not include its own RTE header"
    Assert-ContainsText -Text $appSource -Pattern "Rte_App${index}_MainFunction\(\);" -Message "App_$index does not call its own RTE main API"
    Assert-ContainsText -Text $appSource -Pattern "Rte_App${index}_GetLibInfo\(\)" -Message "App_$index does not call its own RTE get-info API"
    Assert-NotContainsText -Text $appSource -Pattern '#include "Lib_[123]\.h"' -Message "App_$index includes a BSW Lib header directly"
}

Write-Host 'Layer decoupling check passed.'
