class Rectangle {
protected:
    int width, height;
public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int area() const { return width * height; }
};

class Square : public Rectangle {
public:
    void setWidth(int w) override {
        width = w;
        height = w; // Изменяем и ширину, и высоту
    }

    void setHeight(int h) override {
        height = h;
        width = h; // Изменяем и высоту, и ширину
    }
};

/*
Какова суть принципа подстановки Барбары Лисков? 

Является одним из пяти принципов SOLID и был предложен Барбарой Лисков в 1987 году. Этот принцип гласит, что объекты базового (родительского) класса должны быть заменяемы объектами производного (дочернего) класса без нарушения правильности программы. Другими словами, если класс S является подтипом класса T, то объекты типа T должны быть заменяемы объектами типа S без изменения желаемых свойств программы.
*/

//https://t.me/easy_c_plus/547
