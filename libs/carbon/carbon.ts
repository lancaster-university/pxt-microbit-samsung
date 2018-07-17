//% color=#004d00 weight=90 icon="\uf3fd" block="carbon"
namespace carbon {


    //% blockId=carbon_setGenerationMixType block="generation mix type %mixType" weight=75
    //% shim=carbon::setGenerationMixType
    export function setGenerationMixType(mixType:GenerationMixType): number {
        return mixType;
    }

    //% blockId=carbon_setCarbonIndexValueType block="carbon index level %index" weight=75
    //% shim=carbon::setCarbonIndexValueType
    export function setCarbonIndexValueType(index:CarbonIndex): number {
        return index;
    }

    //% blockId=carbon_queryCarbonValue block="get carbon value" weight=74
    //% shim=carbon::queryCarbonValue
    export function queryCarbonValue(): number {
        return Math.random(200) + 120;
    }

    //% blockId=carbon_queryCarbonIndex block="get carbon index level" weight=73
    //% shim=carbon::queryCarbonIndex
    export function queryCarbonIndex(): number {
        return Math.random(200) + 120;
    }

    //% blockId=carbon_queryCarbonIndexText block="get carbon index as text" weight=72
    //% shim=carbon::queryCarbonIndexText
    export function queryCarbonIndexText(): string {
        let n = Math.random(5);
        
        switch(n)
        {
            case 0:
                return "very low";
                break;
            case 1:
                return "low";
                break;
            case 2:
                return "moderate";
                break;
            case 3:
                return "high";
                break;
            case 4:
                return "very high";
                break;

        }
        return "moderate";
    }

    //% blockId=carbon_queryCarbonGenerationMix block="get carbon generation mix|for type %mix" weight=71
    //% shim=carbon::queryCarbonGenerationMix
    export function queryCarbonGenerationMix(mix : GenerationMixType): number 
    {
        if(mix == GenerationMixType.biomas){
            return Math.random(4) + 4;
        }
        if(mix == GenerationMixType.coal){
            return Math.random(3) + 1;
        }
        if(mix == GenerationMixType.imports){
            return Math.random(5) + 4;
        }
        if(mix == GenerationMixType.gas){
            return Math.random(43) + 20;
        }
        if(mix == GenerationMixType.nuclear){
            return Math.random(11) + 10;
        }
        if(mix == GenerationMixType.hydro){
            return Math.random(3) + 1;
        }
        if(mix == GenerationMixType.solar){
            return Math.random(11) + 10;
        }
        if(mix == GenerationMixType.wind){
            return Math.random(8) + 2;
        }
        return 0;
    }
}