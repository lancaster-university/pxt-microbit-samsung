//% color=#800000 weight=100 icon="\uf019" block="Initialise"
namespace initialize {

    //% blockId=initialize_setInitType block=" type %idtype" weight=95
    //% shim=initialize::setInitType
    export function setInitType(idtype:InitType): number {
        return idtype;
    }

    //% blockId=initialize_initUnit block="init raspberry pi to| %name |as id for %t" weight=94
    //% shim=initialize::initUnit
    export function initUnit(id:string, t: number) {
    }
}