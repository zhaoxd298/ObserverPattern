#ifndef OBSERVER_H
#define OBSERVER_H


/**
* 观察者接口
*/
class Observer {
public:
	virtual ~Observer(){}
	virtual void update() = 0;
};




#endif
