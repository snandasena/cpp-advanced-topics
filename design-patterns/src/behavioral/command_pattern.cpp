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

    virtual void execute() = 0;

};


class Button
{

public:

    virtual ~Button() = default;

    virtual void Click() = 0;
};

class AddShapeCommand : public Command
{
private:
    string _shapeName;
    Canvas *_canvas;

public:
    AddShapeCommand(const string shapeName, Canvas *canvas) : _shapeName(shapeName), _canvas(canvas) {}

    void execute() override
    {
        _canvas->AddShape(_shapeName);
    }
};

class AddTriangleButton : public Button
{
private:
    Canvas *_canvas;
public:

    AddTriangleButton(Canvas *canvas) : _canvas(canvas)
    {

    }

    void Click() override
    {
        _canvas->AddShape("Triangle");
    }
};


class AddSquareButton : public Button
{
private:
    Canvas *_canvas;

public:
    AddSquareButton(Canvas *canvas) : _canvas(canvas) {}

    void Click() override
    {
        _canvas->AddShape("Square");
    }
};


class ClearButton : public Button
{
private:
    Canvas *_canvas;

public:
    ClearButton(Canvas *canvas) : _canvas(canvas) {}

    void Click() override
    {
        _canvas->ClearAll();
    }
};