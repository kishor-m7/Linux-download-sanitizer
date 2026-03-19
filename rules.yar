rule Basic_Malware
{
    strings:
        $a = "cmd.exe"
        $b = "powershell"
        $c = "malware"
        $d = "attack"

    condition:
        any of them
}