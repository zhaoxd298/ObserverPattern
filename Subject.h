#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"


/**
* 主题(被观察者)接口
*/
class Subject {
public:	
	virtual ~Subject(){}
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObserver() = 0;
};


#endif
