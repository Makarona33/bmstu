template<typename T>
class Element {
private:
    T value;
    Element* parent;

public:
    Element(T x) : value(x), parent(this) {}

    T getValue() const { return value; }

    Element* find() {
        if (parent != this)
            parent = parent->find();
        return parent;
    }

    bool equivalent(Element* elem) {
        return find() == elem->find();
    }

    void unionSets(Element* elem) {
        Element* root1 = find();
        Element* root2 = elem->find();
        if (root1 != root2)
            root2->parent = root1;
    }
};
