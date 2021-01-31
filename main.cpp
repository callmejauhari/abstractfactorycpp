#include <iostream>

using std::cout;
using std::endl;

class WoodFactory
{
public:
    virtual void identity() = 0;
};

class TuningFactory
{
public:
    virtual void identity() = 0;
};

class StringFactory
{
public:
    virtual void identity() = 0;
};

class GuitarFactory
{
protected:
    WoodFactory *woods;
    TuningFactory *tunings;
    StringFactory *strings;

public:
    virtual WoodFactory *createWood() = 0;
    virtual TuningFactory *createTuning() = 0;
    virtual StringFactory *createString() = 0;
    virtual void assembley()
    {
        if (woods != nullptr && tunings != nullptr && strings != nullptr)
        {
            woods->identity();
            strings->identity();
            tunings->identity();
            cout << "Asembled!" << endl;
        }
        else
        {
            cout << "Check your ingredient!" << endl;
        }
    }
};

class UnstableTuner : public TuningFactory
{
public:
    void identity() override
    {
        cout << "Unstable Tuner" << endl;
    }
};

class StableTuner : public TuningFactory
{
public:
    void identity() override
    {
        cout << "Stable Tuner" << endl;
    }
};

class UndurableString : public StringFactory
{
public:
    void identity() override
    {
        cout << "Undurable String" << endl;
    }
};

class DurableString : public StringFactory
{
public:
    void identity() override
    {
        cout << "Durable String" << endl;
    }
};

class SolidWood : public WoodFactory
{
public:
    void identity() override
    {
        cout << "Solid Wood" << endl;
    }
};

class LaminatedWood : public WoodFactory
{
public:
    void identity() override
    {
        cout << "Laminated Wood" << endl;
    }
};

class ExpensiveGuitarFactory : public GuitarFactory
{
public:
    WoodFactory *createWood() override
    {
        this->woods = new SolidWood;
        return woods;
    }
    StringFactory *createString() override
    {
        this->strings = new DurableString;
        return strings;
    }
    TuningFactory *createTuning() override
    {
        this->tunings = new StableTuner;
        return tunings;
    }
};

class CheapGuitarFactory : public GuitarFactory
{
    WoodFactory *createWood() override
    {
        this->woods = new LaminatedWood;
        return woods;
    }
    StringFactory *createString() override
    {
        this->strings = new UndurableString;
        return strings;
    }
    TuningFactory *createTuning() override
    {
        this->tunings = new UnstableTuner;
        return tunings;
    }
};

int main()
{
    GuitarFactory *gf = new ExpensiveGuitarFactory();
    WoodFactory *woods = gf->createWood();
    StringFactory *strings = gf->createString();
    TuningFactory *tunings = gf->createTuning();
    gf->assembley();
}