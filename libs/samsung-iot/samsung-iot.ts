//% color=#000080 weight=100 icon="\uf0eb" block="Samsung IoT"
namespace samsungiot {

    //% blockId=samsungiot_setTempColour block="colour temperature %colour" weight=66
    //% shim=samsungiot::setTempColour
    export function setTempColour(colourTemp:BulbTemp): number {
        return colourTemp;
    }

    //% blockId=samsungiot_setLightColour block="colour %colour" weight=66
    //% shim=samsungiot::setLightColour
    export function setLightColour(lightcolour:BulbColour): number {
        return lightcolour;
    }

    //% blockId=samsungiot_setBulbState block="turn bulb| %name |to %t" weight=60
    //% shim=samsungiot::setBulbState
    export function setBulbState(name:string, state: SwitchState): void{
        basic.showString("OK", 150);
        return;
    }

    //% blockId=samsungiot_getBulbState block="get bulb state %name" weight=64
    //% shim=samsungiot::getBulbState
    export function getBulbState(name:string): boolean {
        
        return Math.randomBoolean();
    }

    //% blockId=samsungiot_getBulbLevel block="get bulb level %name" weight=63
    //% shim=samsungiot::getBulbLevel
    export function getBulbLevel(name:string): number {
        return Math.random(101);
    }

    //% blockId=samsungiot_getBulbTemp block="get bulb colour temperature %name" weight=62
    //% shim=samsungiot::getBulbTemp
    export function getBulbTemp(name:string): number {
        return Math.random(10);
    }

    //% blockId=samsungiot_getBulbColour block="get bulb colour  %name" weight=62
    //% shim=samsungiot::getBulbColour
    export function getBulbColour(name:string): number {
        return Math.random(8);
    }

    //% blockId=samsungiot_setBulbLevel block="turn bulb| %name |to level %level" weight=59
    //% shim=samsungiot::setBulbLevel
    export function setBulbLevel(name:string, level: number): void{
        basic.showString("OK", 150);
        return;
    }

    //% blockId=samsungiot_setBulbTemp block="turn bulb| %name |to colour temperature %colour" weight=58
    //% shim=samsungiot::setBulbTemp
    export function setBulbTemp(name:string, colour: BulbTemp): void{
        basic.showString("OK", 150);
        return;
    }

    //% blockId=samsungiot_setBulbNextTemp block="turn bulb| %name |to next colour temperature" weight=58
    //% shim=samsungiot::setBulbNextTemp
    export function setBulbNextTemp(name:string): void{
        basic.showString("OK", 150);
        return;
    }

    //% blockId=samsungiot_setBulbColour block="turn bulb| %name |to colour  %colour" weight=58
    //% shim=samsungiot::setBulbColour
    export function setBulbColour(name:string, colour: BulbColour): void{
        basic.showString("OK", 150);
        return;
    }

    //% blockId=samsungiot_setBulbNextColour block="turn bulb| %name |to next colour" weight=58
    //% shim=samsungiot::setBulbNextColour
    export function setBulbNextColour(name:string): void{
        basic.showString("OK", 150);
        return;
    }

    //% blockId=samsungiot_turnSwitch block="turn switch| %name |to %t" weight=57
    //% shim=samsungiot::turnSwitch
    export function turnSwitch(name:string, state: SwitchState): void {
        basic.showString("OK", 150);
        return;
    }

    //% blockId=samsungiot_getSwitchState block="get switch state %name" weight=64
    //% shim=samsungiot::getSwitchState
    export function getSwitchState(name:string): boolean {
        return Math.randomBoolean();
    }


    //% blockId=samsungiot_getSensorState block="get sensor state| %name" weight=61
    //% shim=samsungiot::getSensorState
    export function getSensorState(name:string): boolean {
        return Math.randomBoolean();
    }

    //% blockId=samsungiot_getSensorTemp block="get sensor temperature| %name" weight=61
    //% shim=samsungiot::getSensorTemp
    export function getSensorTemp(name:string): number {
        return Math.random(25) + 10;
    }
}