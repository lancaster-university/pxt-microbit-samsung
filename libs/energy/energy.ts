//% color=#006f00 weight=100 icon="\uf275" block="School Energy"
namespace energy {



    //% blockId=energy_querySchoolEnergy block="get energy level|for %t |for my school" weight=89
    //% shim=energy::querySchoolEnergy
    export function querySchoolEnergy(t: EnergyType): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_querySchoolEnergyHour block="get energy level|for %t |for hour %d|for my school" weight=89
    //% shim=energy::querySchoolEnergyHour
    export function querySchoolEnergyHour(t: EnergyType, d: HourType): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_querySchoolEnergyDay block="get energy level|for %t |for day %d|for my school" weight=88
    //% shim=energy::querySchoolEnergyDay
    export function querySchoolEnergyDay(t: EnergyType, d: DayType): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_querySchoolEnergyWeek block="get energy level|for %t |for week %w|for my school" weight=87
    //% shim=energy::querySchoolEnergyWeek
    export function querySchoolEnergyWeek(t: EnergyType, w: WeekType): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_querySchoolEnergyMonth block="get energy level|for %t |for month %m|for my school" weight=86
    //% shim=energy::querySchoolEnergyMonth
    export function querySchoolEnergyMonth(t: EnergyType, m: MonthType): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_queryEnergy block="get energy level|for %t |for other school %schoolid" weight=85
    //% shim=energy::queryEnergy
    export function queryEnergy(t: EnergyType, schoolid:string): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_queryEnergyHour block="get energy level|for %t |for hour %d |for other school %schoolid" weight=84
    //% shim=energy::queryEnergyHour
    export function queryEnergyHour(t: EnergyType, d: HourType, schoolid:string): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_queryEnergyDay block="get energy level|for %t |for day %d |for other school %schoolid" weight=83
    //% shim=energy::queryEnergyDay
    export function queryEnergyDay(t: EnergyType, d: DayType, schoolid:string): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_queryEnergyWeek block="get energy level|for %t |for week %w |for other school %schoolid" weight=82
    //% shim=energy::queryEnergyWeek
    export function queryEnergyWeek(t: EnergyType, w: WeekType, schoolid:string): number
    {
        return Math.random(900) + 100;
    }

    //% blockId=energy_queryEnergyMonth block="get energy level|for %t |for month %m |for other school %schoolid" weight=81
    //% shim=energy::queryEnergyMonth
    export function queryEnergyMonth(t: EnergyType, m: MonthType, schoolid:string): number
    {
        return Math.random(900) + 100;
    }
}