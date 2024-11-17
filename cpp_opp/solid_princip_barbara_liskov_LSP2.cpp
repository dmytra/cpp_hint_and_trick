class Shape {
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
protected:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int area() const override { return width * height; }
};

class Square : public Shape {
    int side;
public:
    Square(int s) : side(s) {}
    void setSide(int s) { side = s; }
    int getSide() const { return side; }
    int area() const override { return side * side; }
};


/*
Какова суть принципа подстановки Барбары Лисков? 

Является одним из пяти принципов SOLID и был предложен Барбарой Лисков в 1987 году. Этот принцип гласит, что объекты базового (родительского) класса должны быть заменяемы объектами производного (дочернего) класса без нарушения правильности программы. Другими словами, если класс S является подтипом класса T, то объекты типа T должны быть заменяемы объектами типа S без изменения желаемых свойств программы.
*/

//https://t.me/easy_c_plus/547
