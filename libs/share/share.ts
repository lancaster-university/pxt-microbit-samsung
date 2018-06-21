//% color=#004d00 weight=100 icon="\uf3fd" block="carbon"
namespace share {


    //% blockId=share_setShareLevel block="Share Level %ShareLevel" weight=54
    //% shim=share::setShareLevel
    export function setShareLevel(sharelevel:ShareLevel): number {
        return sharelevel;
    }

    //% blockId=share_shareData block="Share Data %data |called %name |with %level" weight=53
    //% shim=share::shareData
    export function shareData(data:string, name:string, level:number) {
    }

    //% blockId=share_fetchData block="fetch shared data called %name |from school %targetSchool" weight=52
    //% shim=share::fetchData
    export function fetchData(name:string, targetSchool:string): string {
        return "123.45";
    }

    //% blockId=share_fetchSchoolData block="fetch shared data called %name |from my school" weight=51
    //% shim=share::fetchSchoolData
    export function fetchSchoolData(name:string): string {
        return "126.25";
    }



    
}