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

    //% blockId=samsungiot_setBulbState block="turn bulb| %name |to %t" weight=65
    //% shim=samsungiot::setBulbState
    export function setBulbState(name:string, state: boolean){
    }

    //% blockId=samsungiot_setBulbLevel block="turn bulb| %name |to level %level" weight=64
    //% shim=samsungiot::setBulbLevel
    export function setBulbLevel(name:string, level: number){
    }

    //% blockId=samsungiot_setBulbColour block="turn bulb| %name |to colour %colour" weight=63
    //% shim=samsungiot::setBulbColour
    export function setBulbColour(name:string, colour: number){
    }

    //% blockId=samsungiot_turnSwitch block="turn switch| %name |to %t" weight=62
    //% shim=samsungiot::turnSwitch
    export function turnSwitch(name:string, state: boolean) {
    }


    //% blockId=samsungiot_getSensorState block="get sensor state| %name" weight=61
    //% shim=samsungiot::getSensorState
    export function getSensorState(name:string): string {
        return "active";
    }
}