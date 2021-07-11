//
// Created by sajith on 7/9/21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Canvas
{

private:
    vector<string> _shapes;

public:
    void AddShape(const string &newshape)
    {
        _shapes.push_back(newshape);
    }

    void ClearAll()
    {
        _shapes.clear();
    }

    vector<string> GetShapes()
    {
        return _shapes;
    }
};


class Command
{
public:
    virtual  ~Command() = default;

    virtual void Execute() = 0;

};

class Button
{
private:
    Command *_command;

public:
    Button(Command *command) : _command(command) {};

    void Click()
    {
        _command->Execute();
    };
};

class AddShapeCommand : public Command
{
private:
    string _shapeName;
    Canvas *_canvas;

public:
    AddShapeCommand(const string shapeName, Canvas *canvas) : _shapeName(shapeName), _canvas(canvas) {}

    void Execute() override
    {
        _canvas->AddShape(_shapeName);
    }
};

class ClearCommand : public Command
{

private:
    Canvas *_canvas;

public:
    ClearCommand(Canvas *canvas) : _canvas(canvas)
    {

    }

    void Execute() override
    {
        _canvas->ClearAll();
    }
};

string vectorToString(const vector<std::string> &v)
{
    string result;
    for (auto iStr = v.begin(); iStr != v.end(); ++iStr)
    {
        if (iStr != v.end())
        {
            result += *iStr;
        } else
        {
            result += *iStr + ", ";
        }
    }

    return result;
}

int main()
{
    Canvas *canvas = new Canvas;
//    Button *addTriangle

    return 0;
}