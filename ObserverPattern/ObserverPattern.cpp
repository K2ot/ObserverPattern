#include <iostream>

#include "Subject.h"
#include "Observer.h"

int main()
{
    Subject subject;
    Observer observer1{ subject };
    Observer observer2{ subject };
    Observer observer3{ subject };

    subject.createMessage("Hello World!");

    observer3.removeMeFromTheList();

    subject.createMessage("The weather is hot today!");
    Observer observer4(subject);

    subject.createMessage("My new car is great!");

    observer4.removeMeFromTheList();
    observer2.removeMeFromTheList();

    return 0;
}
