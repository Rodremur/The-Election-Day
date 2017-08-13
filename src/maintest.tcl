#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}
 
#Test the program
eval spawn [lrange $argv 0 end]
 
#Put your test case here
send "3\r"
send "3\r"
send "BLANK 22\r"
send "INVALID 1000\r"
send "SimpleMinds 5\r"
send "UniqueThinking 3\r"
send "RunWithMoney 6\r"
expect "SimpleMinds 36\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
expect "UniqueThinking 21\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
expect "RunWithMoney 43\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
send "3\r"
send "BLANK 203\r"
send "INVALID 287\r"
send "Pragmatics 50\r"
send "Paradigmatics 50\r"
send "Programatics 50\r"
expect "Pragmatics 33\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
expect "Paradigmatics 34\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
expect "Programatics 33\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
send "2\r"
send "BLANK 0\r"
send "INVALID 4\r"
send "A 65\r"
send "B 35\r"
expect "A 65\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
expect "B 35\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
