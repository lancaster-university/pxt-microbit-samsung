//% color=#800000 weight=100 icon="\uf019" block="Initialise"
namespace initialize {


    //% blockId=initialize_initUnit block="init raspberry pi to| %name |as id for %t" weight=94
    //% shim=initialize::initUnit
    export function initUnit(id:string, t: InitType) {
    }

    //% blockId=initialize_resetUnit block="clear initialisation" weight=93
    //% shim=initialize::resetUnit
    export function resetUnit() {
    }
}