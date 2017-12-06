#ifndef __TEMPERATUREONLYDISPLAY_H__
#define __TEMPERATUREONLYDISPLAY_H__

#include "WeatherData.h"

#include "Observer.h"
#include "Subject.h"
#include <iostream>


using std::cout;
using std::endl;

class TemperatureOnlyDisplay : public Observer
{
public:
	TemperatureOnlyDisplay(Subject* wd)
	{
		m_weatherData = wd;
		wd->registerObserver(this);
	}
	
	void update()
	{
		WeatherData* weatherData = dynamic_cast<WeatherData*>(this->m_weatherData);
		temp = weatherData->getTemperature();
		display();
	}
	
	void display()
	{
		cout << "TemperatureOnlyDisplay displaying, ";
		cout << "Temperuture: " << temp << endl;
		cout << endl;
	}
private:
	Subject *m_weatherData;
	int temp;
	int humidity;
	int pressure;
};


#endif
