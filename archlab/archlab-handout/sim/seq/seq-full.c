char simname[] = "Y86-64 Processor: seq-full.hcl";
#include <stdio.h>
#include "isa.h"
#include "sim.h"
int sim_main(int argc, char *argv[]);
word_t gen_pc(){return 0;}
int main(int argc, char *argv[])
  {plusmode=0;return sim_main(argc,argv);}
long long gen_icode()
{
    return ((imem_error) ? (I_NOP) : (imem_icode));
}

long long gen_ifun()
{
    return ((imem_error) ? (F_NONE) : (imem_ifun));
}

long long gen_instr_valid()
{
    return ((icode) == (I_NOP) || (icode) == (I_HALT) || (icode) == 
      (I_RRMOVQ) || (icode) == (I_IRMOVQ) || (icode) == (I_RMMOVQ) || 
      (icode) == (I_MRMOVQ) || (icode) == (I_ALU) || (icode) == (I_JMP) || 
      (icode) == (I_CALL) || (icode) == (I_RET) || (icode) == (I_PUSHQ) || 
      (icode) == (I_POPQ) || (icode) == (I_IADDQ));
}

long long gen_need_regids()
{
    return ((icode) == (I_RRMOVQ) || (icode) == (I_ALU) || (icode) == 
      (I_PUSHQ) || (icode) == (I_POPQ) || (icode) == (I_IRMOVQ) || (icode)
       == (I_RMMOVQ) || (icode) == (I_MRMOVQ) || (icode) == (I_IADDQ));
}

long long gen_need_valC()
{
    return ((icode) == (I_IRMOVQ) || (icode) == (I_RMMOVQ) || (icode) == 
      (I_MRMOVQ) || (icode) == (I_JMP) || (icode) == (I_CALL) || (icode)
       == (I_IADDQ));
}

long long gen_srcA()
{
    return (((icode) == (I_RRMOVQ) || (icode) == (I_RMMOVQ) || (icode) == 
        (I_ALU) || (icode) == (I_PUSHQ)) ? (ra) : ((icode) == (I_POPQ) || 
        (icode) == (I_RET)) ? (REG_RSP) : (REG_NONE));
}

，