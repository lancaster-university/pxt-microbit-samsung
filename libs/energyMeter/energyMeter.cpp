#include "pxt.h"
#include "EnergymeterService.h"

EnergymeterService energymeterService(uBit.radio);

enum class ApplianceState
{
    on,
    off
};

enum class ApplianceType
{
    printer,
    laptop,
    screen,
    //% block="smart board"
    smart_board,
    computer,
    projector,
    television,
    //% block="cd player"
    cd_player,
    microwave,
    kettle,
    laminator,
    heater,
    lamp,
    speakers,
    other
};


namespace energymeter {

    int init() {
        return enableRadio();
    }

    //%
    void onPowerHandler(ApplianceState state, Action body){
        init();
        registerWithDal(MICROBIT_ID_ENERGY_MONITOR, (state == ApplianceState::on) ? MICROBIT_ENERGY_MONITOR_EVT_POWER_ON : MICROBIT_ENERGY_MONITOR_EVT_POWER_OFF, body);
    }

    //%
    void sendEnergyMeterReading(ApplianceType type, StringData* name)
    {
        init();
        energymeterService.sendEnergyLevel(ManagedString(name), uBit.energyMonitor.getEnergyUsage(), (int)type);
    }

    //%
    int getElectricalPowerStatus()
    {
        init();
        return (uBit.energyMonitor.isElectricalPowerOn()) ? 1 : 0;
    }

    //%
    int getEnergyUsage()
    {
        init();
        return (uBit.energyMonitor.getEnergyUsage()) ? 1 : 0;
    }

    //%
    void calibrateEnergyMeter()
    {
        init();
        uBit.energyMonitor.calibrate();
    }
};
