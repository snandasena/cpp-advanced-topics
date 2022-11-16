#parameters
param([string]$dir = "/home/sajith/CLionProjects/cpp-advanced-topics/cmake-build-debug")

#functions

function Get-DirInfo($dir)
{
    $res = Get-ChildItem $dir -Recurse | Measure-Object -Property Length -Sum
    return [Math]::Round(($res).Sum/1MB, 2)
}

# main processing
Get-DirInfo $dir