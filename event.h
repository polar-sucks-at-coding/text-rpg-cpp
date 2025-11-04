#ifndef EVENT_H
#define EVENT_H

enum EventID
{
    Intro
};

class Event
{

};

class Dialogue : Event
{
    void typeNPCDialogue();
    void createOptions();
};

class Fight : Event
{
    void createEnemies();
};

#endif