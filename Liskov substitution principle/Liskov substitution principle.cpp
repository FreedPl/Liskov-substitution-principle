#include <iostream>

// Інтерфейс для об'єктів, які можуть літати
class IFlyable
{
public:
    virtual void fly() = 0;
};

// Базовий клас "Птах"
class Bird
{
public:
    virtual void eat()
    {
        std::cout << "Птах їсть\n";
    }
};

// Клас "Горобець", який успадковує "Птах" і реалізує "IFlyable"
class Sparrow : public Bird, public IFlyable
{
public:
    void fly() override
    {
        std::cout << "Горобець летить\n";
    }
};

// Клас "Пінгвін", який успадковує "Птах", але не реалізує "IFlyable"
class Penguin : public Bird
{
public:
    void swim()
    {
        std::cout << "Пінгвін плаває\n";
    }
};

void makeBirdFly(IFlyable& flyableBird)
{
    flyableBird.fly();
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    Sparrow sparrow;
    Penguin penguin;

    makeBirdFly(sparrow); // Тепер працює коректно

    penguin.eat();  // Пінгвін може їсти
    penguin.swim(); // Пінгвін може плавати

    return 0;
}
