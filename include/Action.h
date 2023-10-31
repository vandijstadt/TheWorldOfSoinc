#ifndef ACTION_H
#define ACTION_H


class Action
{
    public:
        Action();
        virtual ~Action();
        Action(const Action& other);
        Action& operator=(const Action& other);

    protected:

    private:
};

#endif // ACTION_H
