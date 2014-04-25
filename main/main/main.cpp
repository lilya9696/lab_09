#include <iostream>

using namespace std;

void main()
{
int n, res;
cin>>n;

_asm
{
sub ebx, ebx  
mov ecx, 0 
xor esi, esi
cycle_start:
inc ecx
cmp ecx, n 
jg cycle_end 
mov eax, n
cdq 
div ecx 
cmp edx, 0
jne cycle_start
mov esi, 2
jmp prostoe
prostoe :
cmp ecx, 1
je cycle_start
cmp esi, ecx
je cycle_pr
mov eax, ecx 
xor edx, edx
div esi
cmp edx, 0
je cycle_start 
inc esi
jmp prostoe
cycle_pr:
inc ebx
jmp cycle_start
cycle_end :
mov res, ebx

}
cout<<"resut="<<res;

}