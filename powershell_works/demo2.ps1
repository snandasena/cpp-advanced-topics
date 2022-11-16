param([string]$source, [string]$destination)

function Check-Folder([string]$path, [switch]$create)
{
    $exits = Test-Path $path

    if (!$exits -and $create)
    {
        mkdir $path | Out-Null
        $exits = Test-Path $path
    }

    return $exits
}

Check-Folder "/tmp/source" -create
Check-Folder "/tmp/destination" -create


function Display-FolderStats([string]$path)
{
    $files = dir $path -Recurse | where { !$_.PSIsContainer }
    $totals = $files | Measure-Object -Property Length -Sum
    $stats = ""|Select path, count, size
    $stats.path = $path
    $stats.count = $totals.count
    $stats.size = $totals.Sum

    return $stats
}

Display-FolderStats "/tmp"