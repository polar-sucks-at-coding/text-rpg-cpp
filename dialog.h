#pragma once
#include <string>
#include <vector>

class Dialogue_Option
{
    
    public:
        std::string text;
        std::string next_line_ID;
        void (*function)();
        bool active; //has a function that it runs 
        bool ends_dialogue;
        
        Dialogue_Option(const std::string& _text, const std::string& _next_line_id, bool _ends_dialogue, bool _active, void (*_function)()) :
            text{_text},
            next_line_ID{_next_line_id},
            function{_function},
            ends_dialogue{_ends_dialogue},
            active{_active}
        {}
};

class Dialogue_Line
{
    public:
        std::string text;
        std::vector<Dialogue_Option> options;
        std::string ID;

        Dialogue_Line(const std::string& _text, const std::string& _id) :
            text{_text},
            ID{_id}

        {}
        
        void addOption(const std::string& _text, const std::string& _next_line_id, bool _ends_dialogue = false, void (*_function)() = NULL);
        void outputLine();
};

class Dialogue
{
    public:
        std::vector<Dialogue_Line> lines;

        Dialogue_Line* getLineByID(const std::string& id);
        Dialogue_Line* getLastLine();
        std::string getIDByIndex(int index);
        int searchLine(const std::string& _id);
        void addLine(const std::string& _text, const std::string& _id);
        void display();
        void pickOption(const std::string& _id);
        void play(const std::string& id = "none");

        int current_line;
        bool active;
};