; Assignment 8 - Program Reads in a series of numbers.  If number is greater than 100 or less than -100, the number is rejected.  If the number is 
; zero, the program is terminated.  Upon termination, the program outputs the number of positive numbers, the number of negative numbers, and the sum of the positive numbers.
; Tim Dooris
; 4/22/2012

    .386
    .MODEL FLAT
ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD
Include io.h

cr        equ 0dh
Lf        equ 0ah

          .STACK 4096
          .DATA
          
prompt    byte "Enter number: ",0
posvalues byte "The number of positive numbers: ",0
negvalues byte "The number of negative numbers: ",0
sumposstr byte "The sum of the positive numbers: ",0
rejectmsg byte "Rejected.", 0
posvalch  byte 11 dup(?), 0
negvalch  byte 11 dup(?), 0
sumposch  byte 11 dup(?), 0
instring  byte 40 dup(?), 0
newline   byte  13,10,0



          .code
_start:
         
          sub     ebx, ebx                              ; ebx will hold the sum of the positive numbers
	  sub     ecx, ecx                              ; ecx will count the number of positive numbers
	  sub     edx, edx                              ; edx will count the number of negative numbers
 	
top:	  output  prompt
          input   instring,11
	  atod    instring
          cmp     eax, 0
	  je	  done


          cmp     eax, 100
          jg	  rejected

    
          cmp     eax, -100
          jl	  rejected

	  cmp     eax, 0

	  jl      ifneg

          inc     ecx                               ;increment the positive number carrier
    
          add     ebx, eax                        ;add to sum of positive numbers
          jmp     bottom

ifneg:    inc     edx
	  jmp     bottom

rejected: output  rejectmsg
          output  newline


bottom:   jmp     top

done:     output  posvalues
	  dtoa    posvalch, ecx
	  output  posvalch
	  output  newline

	  output  negvalues
	  dtoa    negvalch, edx
	  output  negvalch
	  output  newline

	  output  sumposstr
	  dtoa    sumposch, ebx
	  output  sumposch
	  output  newline


          INVOKE ExitProcess, 0

PUBLIC    _start

          END
