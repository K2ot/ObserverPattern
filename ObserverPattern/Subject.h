#pragma once

#include "IObserver.h"
#include <algorithm>

class Subject : public ISubject
{
	std::vector<std::reference_wrapper<IObserver>> list_observer;
	std::string message;

	void notify() override
	{
		std::for_each(begin(list_observer), end(list_observer),
			[this](std::reference_wrapper<IObserver>& observer)
			{
				observer.get().update(message);
			});
	}

public:
	virtual ~Subject(){}

	void attach(IObserver& observer) override
	{
		list_observer.push_back(observer);
	}

	void detach(IObserver& observer) override
	{
		list_observer.erase(
			std::remove_if(begin(list_observer), end(list_observer),
				[&observer](std::reference_wrapper<IObserver>& o)
				{
					return &o.get() == &observer;
				}),
			list_observer.end()
		);
	}

	void createMessage(const std::string& message = "Empty")
	{
		this->message = message;
		notify();
	}
};
