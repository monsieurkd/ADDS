class IWork{
    public:
    virtual void work()=0;
};
//each class should have one action  which is performed by the object of that class.
//divine funciton to different class for percific inheritance, avoid redundant
class ISleep{
    public:

    virtual void sleep() =0;

};
class IRest{
    public:


    virtual void rest()= 0;
};
class Person: public IWork, public ISleep, public IRest {
    public:
    void work() override {};
};

class Computer:public  IWork{
    void work() override {};

};