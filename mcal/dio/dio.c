/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
/*TODO: include the header file that contains register definitions */
#include "../mcu_hw.h"
#include "dio.h"


#define MAX_NUM_OF_PORTS        6
static volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};
Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Std_levelType ret;
    volatile PORT_RegType* BaseAddr;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    BaseAddr = BaseAddrArr[PortId];

    /*TODO: Return the level value of given Channel */
    //GET_BIT(BaseAddr->GPIODATA[ChannelPos],ChannelPos);
    ret=(BaseAddr->GPIODATA[1<<ChannelPos])>>ChannelPos;
    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* BaseAddr;

    BaseAddr = BaseAddrArr[PortId];

    /*TODO: Write the input value in the corresponding ChannelId */
    BaseAddr->GPIODATA[1<<ChannelPos]=Level<<ChannelPos;

}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;
    volatile PORT_RegType* BaseAddr;
    BaseAddr = BaseAddrArr[PortId];

    /*TODO: Return the Port Value*/
    ret=BaseAddr->GPIODATA[255];

    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    volatile PORT_RegType* BaseAddr;
    BaseAddr = BaseAddrArr[PortId];

    /*TODO: Write the input value in the corresponding PortId */
    BaseAddr->GPIODATA[255]=value;
}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* BaseAddr;

    BaseAddr = BaseAddrArr[PortId];
    /* TODO: toggle the corresponding ChannelId */

    BaseAddr->GPIODATA[1<<ChannelPos] ^=1<<ChannelPos;


}
void Dio_FlipPort(Dio_PortType PortId)
{
    volatile PORT_RegType* BaseAddr;

    BaseAddr = BaseAddrArr[PortId];

    /*TODO: toggle the port value */
    BaseAddr->GPIODATA[255] ^=0xff;


}



