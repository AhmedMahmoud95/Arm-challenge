

/**
 * main.c
 */
#include "utils/processor/processor.h"
#include "mcal/SysCtr/SysCtr.h"
int main(void)
{
    PROCESSOR_enableGlobalInt();
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    /*
     * Takes specific value from table 5-4, PYBASS = 0.
     */
    SysCtr_init();
	return 0;
}
