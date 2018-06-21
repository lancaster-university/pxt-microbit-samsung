//% color=#1a3300 weight=100 icon="\uf275" block="energy"
namespace energy {

    //% blockId=energy_setEnergyType block="energyType %energyType" weight=85
    //% shim=energy::setEnergyType
    export function setEnergyType(energyType:EnergyType): number {
        return energyType;
    }

    //% blockId=energy_queryEnergy block="query Energy Level|for %t |for other school %schoolid" weight=84
    //% shim=energy::queryEnergy
    export function queryEnergy(t: number, schoolid:string): string {
        return "224.34";
    }

    //% blockId=energy_querySchoolEnergy block="query Energy Level|for %t |for my school" weight=83
    //% shim=energy::querySchoolEnergy
    export function querySchoolEnergy(t: number): string {
        return "124.56";
    }
}