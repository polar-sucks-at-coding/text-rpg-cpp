#include <iostream>
#include <string>
#include <vector>
#include "dialog.h"
#include "utility.h"

void Dialogue_Line::addOption(const std::string& _text, const std::string& _next_line_id, bool _ends_dialogue, void (*_function)())
{
    bool active = false;
    if (_function != NULL) active = true;

    options.emplace_back(_text, _next_line_id, _ends_dialogue, active, _function);
}

void Dialogue_Line::outputLine()
{
    Utility::typeText(text);
    Utility::makeSpace();

    if (options.size() == 0) return;
    
    for (int i = 0; i < options.size(); i++){
        Utility::typeText(std::to_string(i +1 ), 0);
        Utility::typeText(") ", 0);
        Utility::typeText(options[i].text, 1);
    }
}

Dialogue_Line* Dialogue::getLineByID(const std::string& _id)
{
    for (int i = 0; i < lines.size(); i++){
        if (lines[i].ID == _id) return &(lines[i]);
    }
    return NULL;
}

Dialogue_Line* Dialogue::getLastLine()
{
    if (lines.size() > 0) 
        return &(lines.back());
    return NULL;
}

std::string Dialogue::getIDByIndex(int _index)
{
    if (_index >= lines.size()) return "bruh";
    return lines[_index].ID;
}

int Dialogue::searchLine(const std::string& _id)
{
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].ID == _id) return i;
    }
    return -1;
}

void Dialogue::addLine(const std::string& _text, const std::string& _id)
{
    lines.emplace_back(_text, _id);
}

void Dialogue::display()
{
    if (current_line >= lines.size()) return;
    lines[current_line].outputLine();
}

void Dialogue::pickOption(const std::string& _id)
{
    int line = searchLine(_id);
    if (line == -1){
        Utility::typeText("Invalid line"); return;
    }

    int option_count = lines[line].options.size();
    if (option_count == 0){
        active = false; return;
    }

    int option;
    
    while(1)
    {
        option = Utility::getPlayerChoice(option_count, 0);
        option--;

        Dialogue_Option* option_object = &(lines[line].options[option]);

        if (option_object->active) {option_object->function();}

        if (option_object->ends_dialogue) {active = false; break;}

        current_line = searchLine(option_object->next_line_ID);
        break;
    }
}

void Dialogue::play(const std::string& _id)
{
    current_line = searchLine(_id);
    active = true;

    while (active)
    {
        display();
        pickOption(getIDByIndex(current_line));
    }
}