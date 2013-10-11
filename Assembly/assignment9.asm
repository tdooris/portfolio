



              .data

arr           dword          0
n             dword          0
nstring       byte           11 dup(?), 0
originalarr   byte           "Original Array", 0
changedarr    byte           "Changed Array", 0
printval      byte           11 dup(?), 0


	      .code

		input         nstring,11                          ;head method to read values into the array
		atod          nstring                     
		mov           n, eax                              ;puts header value into n
		mov           ecx, eax                            ;ecx counter reg
		sub           edi,edi                             ;edi index reg

readin:       input           nstring, 11
		atod          nstring
		mov           [arr+edi], eax			;fill in array with value of eax
                add           edi, 4                            
		loop          readin 

		output        originalarr
		mov           ecx, n                            ;store n in ecx
		mov           ebx, arr                          ;store array in ebx

printarray     proc
	
		sub           edi,edi                           ;clear index erg
		mov           ecx, n                            ;store n in ecx

printtop:	mov           eax, [arr+edi]                    ;move value stored in array to eax
                add           edi, 4            
		dtoa          printval, eax                   
		output        printval
		loop          printtop
		ret
print array     end


		call         printarray


Extrn          make_pos:near32

		lea         ebx,arr                             ;load address of arr into ebx
		mov         ecx, n                              ;load number of values into ecx

		call        make_pos
		
		call        printarray




TO BE PUT IN SEPARATE FILE

public 	make_pos
make_pos proc

	.data



		.code

		push ebx  					;push onto stack the address of arr
		push ecx					;push onto stack number of elements in arr

		sub	edi,edi					;clear index erg
		
top:		mov     eax, dword ptr[ebx+edi]			;I think this may be correct?  trying to move first value of first element into eax

		not	eax					;negating value
		inc     eax
		mov     [ebx+edi], eax

		add	edi, 4
		loop	top

		pop ecx
		pop ebx

		ret
make_pos	endp

