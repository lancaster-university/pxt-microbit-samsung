//% color=#000080 weight=100 icon="\uf0eb" block="Samsung IoT"
namespace samsungiot {


    //% blockId=samsungiot_setSwitchState block="on / off state %status" weight=67
    //% shim=samsungiot::setSwitchState
    export function setSwitchState(status:SwitchState): boolean {
        if(status == SwitchState.off)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    //% blockId=samsungiot_setLightColour block="colour %colour" weight=66
    //% shim=samsungiot::setLightColour
    export function setLightColour(lightcolour:BulbColour): number {
        return lightcolour;
    }

    //% blockId=samsungiot_setBulbState block="turn bulb| %name |to %t" weight=60
    //% shim=samsungiot::setBulbState
    export function setBulbState(name:string, state: boolean){
    }

    //% blockId=samsungiot_getBulbState block="get bulb state %name" weight=64
    //% shim=samsungiot::getBulbState
    export function getBulbState(name:string): boolean {
        return true;
    }

    //% blockId=samsungiot_getBulbLevel block="get bulb level %name" weight=63
    //% shim=samsungiot::getBulbLevel
    export function getBulbLevel(name:string): number {
        return 30;
    }

    //% blockId=samsungiot_getBulbColour block="get bulb colour %name" weight=62
    //% shim=samsungiot::getBulbColour
    export function getBulbColour(name:string): number {
        return 3;
    }

    //% blockId=samsungiot_setBulbLevel block="turn bulb| %name |to level %level" weight=59
    //% shim=samsungiot::setBulbLevel
    export function setBulbLevel(name:string, level: number){
    }

    //% blockId=samsungiot_setBulbColour block="turn bulb| %name |to colour %colour" weight=58
    //% shim=samsungiot::setBulbColour
    export function setBulbColour(name:string, colour: number){
    }

    //% blockId=samsungiot_turnSwitch block="turn switch| %name |to %t" weight=57
    //% shim=samsungiot::turnSwitch
    export function turnSwitch(name:string, state: boolean) {
    }

    //% blockId=samsungiot_getSwitchState block="get switch state %name" weight=64
    //% shim=samsungiot::getSwitchState
    export function getSwitchState(name:string): boolean {
        return true;
    }


    //% blockId=samsungiot_getSensorState block="get sensor state| %name" weight=61
    //% shim=samsungiot::getSensorState
    export function getSensorState(name:string): boolean {
        return true;
    }
}