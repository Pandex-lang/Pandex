# The Pandex programming langauge

code example :

1- Hello , World
```
main:
```	puts "Hello , World"
```
2- if
```
main:
	if $0 == $1 : function

function:
	puts "Hello , World"
```
3- if else
```
main:
	if $0 == $1 : func : else_func
	
func:
	puts "0 == 1"
else_func:
	puts "0 is not equal 1"
```
4- comments
```
; this is a comment
main:
	puts "Hello , World!" ; I am a comment
```
5- passing arguments to functions
```
main:
	function "argument 1" , "argument 2"
	
function:
	puts $0 ; the function name
	puts $1 ; argument one
	puts $2 ; argument two
```

6 - variables
```
main:
	var [name] : "Hello , World" ; constant variables
	var name : "Hello World ; variable
	; access variables
	; constants
	puts $name ; print variables
```

	





 
```
print_if_path_eq_slash:
	if path eq "/":do

	if $path == "/":do
	```