#include "chrono"
#include "thread"
#include "json.hpp"
#include "fstream"
#include <mutex>
#include <atomic>

//using json = nlohmann::json;

struct hvacStateMachine{
	uint8_t currentTemperature;
	std::string zone;
	bool autoAcStatus;
	bool defoggerStatus;
	//hvacDdsObj::hvacClimateFlowControl climateFlowControlObj;
	//hvacDdsObj::hvacFanSpeed fanSpeedObj;
	std::string climateFlowControlObj;
	std::string fanSpeedObj;
};

class hvac_simulator {
private:

	std::atomic<uint8_t> temperatureSetPoint;
	hvacStateMachine hvac_cache;
	std::atomic<uint8_t> isTemperatureThreadRunning;
	nlohmann::json mqttMessage;
	std::mutex hvacCache_lock;
	std::function<void (nlohmann::json)> functionObj1;
	std::function<void (nlohmann::json)> functionObj2;

	void updateMqttMessage_req(std::string Number,std::string Value);
	void temperatureChangeFn();
	void temperatureManager(nlohmann::json obj);
	void autoacManager(nlohmann::json obj);
	void defoggerManager(nlohmann::json obj);
	void climateFlowControlManager(nlohmann::json obj);
	void fanSpeedManager(nlohmann::json obj);
	void TemperatureManager_MQTT(nlohmann::json obj);
	void AutoacManager_MQTT(nlohmann::json obj);
	void DefoggerManager_MQTT(nlohmann::json obj);
	void ClimateFlowControlManager_MQTT(nlohmann::json obj);
	void FanSpeedManager_MQTT(nlohmann::json obj);

public:

	void set_RestApplicationCbk_HVAC_MQTT_CURRENT_STATUS(std::function<void (nlohmann::json)> argFunctionObj);
	void set_RestApplicationCbk_HVACRESPONSE(std::function<void (nlohmann::json)> argFunctionObj);
	void initialize_cache(hvacStateMachine* hvacCachePtr);
	void HVAC_MQTT_SET_STATUS_Listener(nlohmann::json obj);
	void HVACWRITE_Listener(nlohmann::json obj);
	void HVACREAD_Listener(nlohmann::json obj);
	hvac_simulator(std::function<void (nlohmann::json)> functionObj1, std::function<void (nlohmann::json)> functionObj2);
	~hvac_simulator();
};using namespace nlohmann;