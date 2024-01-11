# Solution of Lab 01 on code obfuscation
The solution include some of the disassabled code. It is sufficient to follow the instruction for Ghidra or objdump to get a similar result.

## crackme0

First it is necessary to make all the crackme files executable with the following command:

```bash
sudo chmod +x ./crackme*
```
Then after a couple of trials we can use Ghira to disassable and analyze the compiled code. It is straght forward and the solution is evident from the decompiled version of the code.

Here is the output code:

```c
undefined4 main(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 2) {
    iVar1 = strcmp(*(char **)(param_2 + 4),"Amazing!");
    if (iVar1 == 0) {
      puts("Congratz ! ");
    }
    else {
      puts("try again");
    }
  }
  else {
    puts("Usage : ./crackme CODE");
  }
  return 0;
}
```
## crackme2

Here is the code to solve the exercise:

```c
undefined4 main(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  byte bVar5;
  char local_28 [20];
  int local_14;
  
  bVar5 = 0;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == 2) {
    strncpy(local_28,*(char **)(param_2 + 4),10);
    magic((int)local_28);
    uVar3 = 0xffffffff;
    pcVar4 = &key;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + (uint)bVar5 * -2 + 1;
    } while (cVar1 != '\0');
    iVar2 = strncmp(local_28,&key,~uVar3 - 1);
    if (iVar2 == 0) {
      puts("Congratz ! ");
    }
    else {
      puts("try again");
    }
  }
  else {
    puts("Usage : ./crackme CODE");
  }
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}
```
