
//% color=#1a3300 weight=100 icon="\uf1e6" block="Energy Metering"
namespace energymeter {

    /**
      * Sends the current energy reading to the cloud.
      */
    //% help=none
    //% weight=96
    //% blockId=send_meter_reading block="send power level (watts) of my|%APPLIANCE_TYPE| called|%name to the cloud" blockGap=8
    //% shim=energyMeter::sendEnergyMeterReading
    export function sendEnergyMeterReading(type:ApplianceType, name:string)
    {
        let p = 0;
    }

    /**
     * Returns the on/off status of the electrical power.
     */
    //% blockId=get_electrical_power_state block="electrical power status" blockGap=8
    //% weight=99
    //% shim=energyMeter::getElectricalPowerStatus
    export function getElectricalPowerStatus() : number
    {
        return 0
    }

    /**
     * Returns the on/off status of the electrical power.
     */
    //% blockId=get_electrical_power_usage block="get energy consumption (watts)" blockGap=8
    //% weight=99
    //% shim=energyMeter::getEnergyUsage
    export function getEnergyUsage() : number
    {
        return Math.random(50);
    }
}