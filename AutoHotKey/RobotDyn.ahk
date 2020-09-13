#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

F13::
IfWinExist, ahk_class MozillaWindowClass
{   WinActivate
    Send ^t
    Send 192.168.0.4/api/v1/commands/?cmd=play
    Send {Enter}
} else run firefox
return

F14::
IfWinExist, ahk_class MozillaWindowClass
{   WinActivate
    Send ^t
    Send 192.168.0.5:8123
    Send {Enter}
} else run firefox
return

F15::
IfWinExist, ahk_class MozillaWindowClass
{   WinActivate
    Send ^t
    Send https://www.youtube.com/watch?v=TdrL3QxjyVw&list=RDTdrL3QxjyVw&start_radio=1&t=1
    Send {Enter}
    Sleep, 5000 
    Send {Space}
} else run firefox
return