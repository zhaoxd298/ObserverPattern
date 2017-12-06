#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H

#include "WeatherData.h"
#include "Observer.h"
#include "Subject.h"
#include <iostream>

using std::cout;

/**
* 显示目前状况(观察者实例，有多个)
*/
class CurrentConditionsDisplay : public Observer {
private:
	float m_temperature;
	float m_humidity;
	Subject* m_weatherData;	

public:
	CurrentConditionsDisplay(Subject* weatherData)
	{
		this->m_weatherData = weatherData;
		weatherData->registerObserver(this);
	}
	void update()
	{
		WeatherData* weatherData = dynamic_cast<WeatherData*>(this->m_weatherData);
		if (weatherData) {
			this->m_temperature = weatherData->getTemperature();
			this->m_humidity = weatherData->getHumidity();

			display();
		}
	}
	void display()
	{
		cout << "corrent conditions:";
		cout << "temperature:" << m_temperature ;
		cout << " humidity:" << m_humidity << "%" << endl;
	}
};

#endif
