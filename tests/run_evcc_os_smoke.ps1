$ErrorActionPreference = 'Stop'

$projectRoot = Split-Path -Parent $PSScriptRoot
$exePath = Join-Path $projectRoot 'build\EVCC_demo.exe'

function Assert-Contains {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Text,

        [Parameter(Mandatory = $true)]
        [string]$Pattern
    )

    if ($Text -notmatch $Pattern) {
        throw "missing expected output pattern '$Pattern'. Current output:`n$Text"
    }
}

Push-Location $projectRoot
try {
    mingw32-make clean | Out-Host
    if ($LASTEXITCODE -ne 0) {
        throw "mingw32-make clean failed with exit code $LASTEXITCODE"
    }

    mingw32-make all | Out-Host
    if ($LASTEXITCODE -ne 0) {
        throw "mingw32-make all failed with exit code $LASTEXITCODE"
    }

    if (-not (Test-Path $exePath)) {
        throw "missing executable: $exePath"
    }

    $process = New-Object System.Diagnostics.Process
    $process.StartInfo.FileName = $exePath
    $process.StartInfo.WorkingDirectory = $projectRoot
    $process.StartInfo.UseShellExecute = $false
    $process.StartInfo.RedirectStandardInput = $true
    $process.StartInfo.RedirectStandardOutput = $true
    $process.StartInfo.RedirectStandardError = $true
    $process.StartInfo.CreateNoWindow = $true

    if (-not $process.Start()) {
        throw 'failed to start EVCC smoke process'
    }

    Start-Sleep -Milliseconds 500
    $process.StandardInput.WriteLine('1')
    $process.StandardInput.Flush()

    Start-Sleep -Seconds 18
    $process.StandardInput.WriteLine('0')
    $process.StandardInput.Flush()

    Start-Sleep -Seconds 7
    if (-not $process.HasExited) {
        $process.Kill()
        $process.WaitForExit()
    }

    $output = $process.StandardOutput.ReadToEnd()
    $stderr = $process.StandardError.ReadToEnd()
    if ($stderr.Trim()) {
        Write-Host "stderr:`n$stderr"
    }

    Assert-Contains -Text $output -Pattern '\[OS\] System state changed: RUN'
    Assert-Contains -Text $output -Pattern '\[App_1\]\[Heartbeat=5s\] I am Lib_1'
    Assert-Contains -Text $output -Pattern '\[App_1\]\[Heartbeat=10s\] I am Lib_1'
    Assert-Contains -Text $output -Pattern '\[App_2\]\[Heartbeat=10s\] I am Lib_2'
    Assert-Contains -Text $output -Pattern '\[App_1\]\[Heartbeat=15s\] I am Lib_1'
    Assert-Contains -Text $output -Pattern '\[App_3\]\[Heartbeat=15s\] I am Lib_3'
    Assert-Contains -Text $output -Pattern '\[OS\] System state changed: STOP'

    $stopIndex = $output.LastIndexOf('[OS] System state changed: STOP')
    if ($stopIndex -lt 0) {
        throw "STOP output not found. Current output:`n$output"
    }

    $afterStop = $output.Substring($stopIndex)
    if ($afterStop -match '\[(App_1|App_2|App_3)\]\[Heartbeat=') {
        throw "heartbeat continued after STOP. Output after STOP:`n$afterStop"
    }

    Write-Host 'EVCC OS smoke test passed.'
    Write-Host $output
} finally {
    Pop-Location
}
