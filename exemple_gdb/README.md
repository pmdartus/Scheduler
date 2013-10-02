# First observations

## Stack pointer

Break on foo, stack pointer `0x7fffff0`.
Enter in foo method (l. 16 to 18) `0x7ffffd8`.
Enter in bar method (l. 5 to 7) `0x7ffffc8`. (pile décrémente)
Back to the previous context ( main method ) `0x7fffff0`.

When we focus on the bar function call, we can see the order of parameters instanciation
```
	(gdb) p    &param1
	$1 = (int *) 0x7ffffcc
	(gdb) p &param2
	$2 = (int *) 0x7ffffc8
	(gdb) p &result
	$3 = (int *) (int *) 0x7ffffc8

```
So as we can see the stack is growing by the tail.

----------
----------
|        | 
|        |
----------
| result |  0x7ffffc8
----------
| param1 |  0x7ffffcc
----------
| param2 |  0x7ffffc8
----------

The `lr` register allows the program to store the next instruction, that you want to execute. When you call a function the 'lr', is stored into the stack, and during the return the stored address is pop out of the stack and store into de 'sp' register, to continue the previous context function.

 