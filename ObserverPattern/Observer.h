#pragma once

#include "IObserver.h"

class Observer : public IObserver
{
	ISubject& subject;

	std::string message_from_subject;

	void printInfo()
	{
		std::cout << "New message is available --> " << message_from_subject << "\n";
	}
	Observer() = delete;

public:
	Observer(ISubject& subject) : subject(subject)
	{
		subject.attach(*this);
		
	}

	virtual ~Observer() {}

	void update(const std::string& message) override
	{
		this->message_from_subject = message;
		printInfo();
	}

	void removeMeFromTheList()
	{
		subject.detach(*this);
		std::cout << "Observer is removed from the list.\n";
	}
};
