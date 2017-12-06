#include <iostream>

#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "TemperatureOnlyDisplay.h"

using namespace std;


int main()
{
	WeatherData* weatherData = new WeatherData();
	CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(weatherData);
	TemperatureOnlyDisplay* temperatureDisplay = new TemperatureOnlyDisplay(weatherData);
	
	weatherData->setMeasurements(80, 65, 30.4);
	weatherData->removeObserver(currentDisplay);
	weatherData->setMeasurements(88, 55, 36.4);
	
	delete temperatureDisplay;
	delete currentDisplay;
	delete weatherData;

	return 0;
}