//% color=#1a3300 weight=100 icon="\uf275" block="energy"
namespace energy {

 /*   //% blockId=energy_queryEnergyText block="get text energy level|for %t |for other school %schoolid" weight=83
    //% shim=energy::queryEnergyText
    export function queryEnergyText(t: EnergyType, schoolid:string): string {
        return "33";
    } */

    //% blockId=energy_queryEnergy block="get energy level|for %t |for other school %schoolid" weight=83
    //% shim=energy::queryEnergy
    export function queryEnergy(t: EnergyType, schoolid:string): number {
        return 33;
    }

    
 /*   //% blockId=energy_querySchoolEnergyText block="get text energy level|for %t |for my school" weight=84
    //% shim=energy::querySchoolEnergyText
    export function querySchoolEnergyText(t: EnergyType): string {
        return "124";
    } */

    //% blockId=energy_querySchoolEnergy block="get energy level|for %t |for my school" weight=84
    //% shim=energy::querySchoolEnergy
    export function querySchoolEnergy(t: EnergyType): number {
        return 124;
    }
}