typedef int Item;

class List
{
private:
    enum { MAXLEN = 10 };
    Item items[MAXLEN];
    int top;
public:
    List() { top = 0; }
    void AddItem(Item item);
    bool IsEmpty() const;
    bool IsFull() const;
    void visit(void (*pf)(Item & item));
};