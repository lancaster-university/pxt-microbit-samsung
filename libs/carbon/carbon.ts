//% color=#004d00 weight=90 icon="\uf3fd" block="carbon"
namespace carbon {


    //% blockId=carbon_setGenerationMixType block="GenerationMixType %mixType" weight=75
    //% shim=carbon::setGenerationMixType
    export function setGenerationMixType(mixType:GenerationMixType): number {
        return mixType;
    }

    //% blockId=carbon_setCarbonIndexValueType block="carbonIndex %index" weight=75
    //% shim=carbon::setCarbonIndexValueType
    export function setCarbonIndexValueType(index:CarbonIndex): number {
        return index;
    }

    //% blockId=carbon_queryCarbonValue block="query Carbon Value" weight=74
    //% shim=carbon::queryCarbonValue
    export function queryCarbonValue(): string {
        return "224.34";
    }

    //% blockId=carbon_queryCarbonIndex block="get carbon index" weight=73
    //% shim=carbon::queryCarbonIndex
    export function queryCarbonIndex(): number {
        return 1;
    }

    //% blockId=carbon_queryCarbonIndexText block="get carbon index as text" weight=72
    //% shim=carbon::queryCarbonIndexText
    export function queryCarbonIndexText(): string {
        return "moderate";
    }

    //% blockId=carbon_queryCarbonGenerationMix block="query Carbon Generation Mix|for type %mix" weight=71
    //% shim=carbon::queryCarbonGenerationMix
    export function queryCarbonGenerationMix(mix : number): string {
        return "22.49";
    }
}