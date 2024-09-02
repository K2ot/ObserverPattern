#pragma once
#include <iostream>
#include <vector>
#include <string>

// Interfejs obserwatora
class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void update(const std::string& message_from_subject) = 0;
};

class ISubject
{
    virtual void notify() = 0;
public:
    virtual ~ISubject() {}
    virtual void attach(IObserver& observer) = 0;
    virtual void detach(IObserver& observer) = 0;
};
