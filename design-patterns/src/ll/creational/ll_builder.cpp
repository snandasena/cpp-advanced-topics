//
// Created by sajith on 7/4/21.
//

#include <iostream>
#include <string>

using namespace std;

// Base Entree class
class Entree
{

protected:
    string _entree;

public:

    const string *GetEntree() const
    {
        return &_entree;
    }
};


// Derived Burger class
class Burger : public Entree
{
public:

    Burger()
    {
        cout << "\n Grill burger patty, add tomatoes and place them in a bun";
        _entree = "Hamburger";
    }
};


class Hotdog : public Entree
{

public:
    Hotdog()
    {
        cout << "\n Cook sausage and place it in a bun";
        _entree = "Hotdog";
    }
};

// Base Side Class
class Side
{
protected:
    string _side;

public:

    const string *GetSide() const
    {
        return &_side;
    }
};

class Fries : public Side
{
public:

    Fries()
    {
        cout << "\n Fry and season potatoes";
        _side = "Fires";
    }
};

class Salad : public Side
{
public:
    Salad()
    {
        cout << "\n Toss greens and dressing together";
        _side = "Salad";
    }
};

class Drink
{
protected:
    string _drink;
public:

    Drink()
    {
        cout << "\n Fill cup with soda" << endl;
        _drink = "Soda";
    }

    const string *GetDrink() const
    {
        return &_drink;
    }
};

// Complex MealCombo object that contains an Entree, a Sode, and a Drink object.
class MealCombo
{
private:
    Entree *_entree;
    Side *_side;
    Drink *_drink;
    string _bag;

public:

    MealCombo(const string &type)
    {
        _bag = type;
    }

    void SetEntree(Entree *e)
    {
        _entree = e;
    }

    void SetSide(Side *s)
    {
        _side = s;
    }

    void SetDrink(Drink *d)
    {
        _drink = d;
    }

    const string *GetBag()
    {
        _bag += ", " + *_entree->GetEntree()
                + ", " + *_side->GetSide()
                + ", " + *_drink->GetDrink();

        return &_bag;
    }

};


// base builder
class MealBuilder
{
protected:
    MealCombo *_meal{};

public:
    virtual ~MealBuilder()
    {
        delete _meal;
    }

    virtual void cookEntree() = 0;

    virtual void cookSide() = 0;

    virtual void fillDrink() = 0;

    MealCombo *GetMeal()
    {
        return _meal;
    }
};

class BurgerMeal : public MealBuilder
{
public:
    BurgerMeal()
    {
        _meal = new MealCombo("Burger");
    }

    void cookEntree() override
    {
        Burger *burger = new Burger;
        _meal->SetEntree(burger);
    }

    void cookSide() override
    {
        Side *side = new Fries;
        _meal->SetSide(side);
    }

    void fillDrink() override
    {
        Drink *drink = new Drink;
        _meal->SetDrink(drink);
    }
};


class HotdogMeal : public MealBuilder
{
public:
    HotdogMeal()
    {
        _meal = new MealCombo("Hotdog");
    }

    void cookEntree() override
    {
        Hotdog *hotdog = new Hotdog;
        _meal->SetEntree(hotdog);
    }

    void cookSide() override
    {
        Salad *salad = new Salad;
        _meal->SetSide(salad);
    }

    void fillDrink() override
    {
        Drink *drink = new Drink;
        _meal->SetDrink(drink);
    }
};

void ClientCode(MealBuilder *cook)
{
    cook->cookEntree();
    cook->cookSide();
    cook->fillDrink();

    MealCombo *meal = cook->GetMeal();
    cout << *meal->GetBag() << endl;
}

int main()
{

    cout << "Build Hotdog\n";
    MealBuilder *cook = new HotdogMeal;
    ClientCode(cook);
    delete cook;

    cout << "Build Burger\n";
    cook = new BurgerMeal;
    ClientCode(cook);

    delete cook;

    return 0;
}