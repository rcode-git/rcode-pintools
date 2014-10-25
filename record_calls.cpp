#include "../../include/pin/pin.H"
#include <cstdio>
#include <cstdlib>

FILE *file = NULL;
KNOB<string> KnobOutputFile(KNOB_MODE_WRITEONCE, "pintool", "o", "isolate.out", "specify output file name");


VOID record_calls(INS ins, VOID *v)
{
    if (INS_IsCall(ins))
    {
        fprintf(file,"%lx\n",INS_Address(ins));
    }
}

void usage()
{
    printf("Pass proper args damnit!\n");
    exit(1);
}

VOID finish(INT32 code, VOID *v)
{
    fclose(file);
}


int main(int argc, char **argv)
{
    if (PIN_Init(argc,argv))  usage();

    file = fopen(KnobOutputFile.Value().c_str(),"w");

    INS_AddInstrumentFunction(record_calls,0);

    PIN_AddFiniFunction(finish,0);

    PIN_StartProgram();

    return 0;

}
