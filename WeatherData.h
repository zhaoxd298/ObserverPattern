#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "Observer.h"
#include "Subject.h"
#include <list>

using namespace std;

/**
* 气象站(被观察者实例，一般只有一个)
*/
class WeatherData : public Subject {
private:
	list<Observer*> m_observers;
	float m_temperature;
	float m_humidity;
	float m_pressure;

public:	
	WeatherData(){}
	void registerObserver(Observer* o)
	{
		m_observers.push_back(o);
	}
	void removeObserver(Observer* o)
	{
		// 从m_observers列表中删除o
		list<Observer*>::iterator i;
		for (i=m_observers.begin(); i!=m_observers.end(); i++) {
			if (*i == o) {
				m_observers.erase(i++);
			}
		}
	}
	void notifyObserver()
	{
		list<Observer*>::iterator i;
		Observer* observer;
		for (i=m_observers.begin(); i!=m_observers.end(); i++) {
			// 调用每一个观察者的update方法
			observer = *i;
			observer->update();
		}
	}
	float getTemperature()
	{
		return m_temperature;
	}
	float getHumidity()
	{
		return m_humidity;
	}
	float getPressure()
	{
		return m_pressure;
	}
	void measurementChanged()
	{
		notifyObserver();
	}
	void setMeasurements(float temp, float humidity, float pressure)
	{
		this->m_temperature = temp;
		this->m_humidity = humidity;
		this->m_pressure = pressure;
		measurementChanged();
	}


	// WeatherData的其他方法
};

#endif