

Part 1 - Self-modifying code
=============================

* Exercise 1 : 

 Modify the file foo-add.c such that the 2nd call to function foo prints i-- (instead of i++)


* Exercise 2 : 

 complete the file foo-shell.c such that the 2nd call to function foo executes the shell code 
  (given in the file). 

 Indication: you just need to copy the shell code at foo() address !


Part 2 - Code Obfuscation
==========================

* Exercise 3

   Write two or three short code examples from your own :
      factorial computation, password checking, etc. 

   Try to "obfuscate" them by hand using the techniques presented during the course 
    (opaque predicate, CFG flattening, constant transformations, etc.) 

    See how much it is "difficult" to decompile the original code with Ghidra ; try also when 
     the code is compile with "-O2" options 
		(you can share obfuscated codes with other students to make this part more realistic !)


* Exercise 4

     Using Tigress, have a look to the source/binary code produced after obfuscation steps on 
     the code examples you used in Exercise 3.
