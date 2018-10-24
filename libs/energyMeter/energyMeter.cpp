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
    washing_machine,
    kettle,
    television
};


namespace energymeter {

    int init() {
        return enableRadio();
    }

    //
    void onPowerHandler(ApplianceState state, Action body){
        init();
        registerWithDal(MICROBIT_ID_ENERGY_MONITOR, (state == ApplianceState::on) ? MICROBIT_EVT_ELECTRICAL_POWER_EVT_ON : MICROBIT_EVT_ELECTRICAL_POWER_EVT_OFF, body);
    }

    //
    void sendEnergyMeterReading(StringData* name, ApplianceType type)
    {
        init();
        energymeterService.sendEnergyLevel(ManagedString(name), uBit.energyMonitor.getEnergyUsage(), (int)type);
    }

    //
    int getElectricalPowerStatus()
    {
        init();
        return (uBit.energyMonitor.isElectricalPowerOn()) ? 1 : 0;
    }

};
