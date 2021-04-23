#include "comment.c"

int main(){
    char str[] = "main ; comment \nfn ; new comment \n";
    // you can don't insert \n at last of string
    comment(str);
    printf("%s\n",str);
}
/*
main:
    puts "Hello , World!" ; this is comment
    var [name] = "Hello , World Too"
    var nm = "Hello , World New"
    var [like,js] = ["like let in","JavaScript"] 
    puts $js
    mov js , "node.js"
    puts $js
    mov [name,nm,like] , ["name is name","name is nm","like"]
*/