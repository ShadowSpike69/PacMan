class Ghost : public Renderable {
private:
    int x, y;
    bool isScared;
    std::string color;

public:
    Ghost();
    Ghost(int x, int y, const std::string& color);

    void draw() const override;
    void move();
    int getX() const;
    int getY() const;
    void resetPosition();

    void setX(int x);
    void setY(int y);
    void setScared(bool scared);
    void setColor(const std::string& color);

    void read(std::istream& in);
    void print(std::ostream& out) const;
};
