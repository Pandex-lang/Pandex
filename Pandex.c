// Pandex executor

int main(){
  asm("mov eax , 4"
      : "mov ebx , 1"
      : "mov ecx , 2"
      : "mov edx , 'He'"
      : "int 80h" );
  return 0;
}
