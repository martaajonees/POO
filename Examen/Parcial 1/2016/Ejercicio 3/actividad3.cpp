class doble {
    public:
    doble(double t): d(t){}
    operator double() const { return d;}
    private:
    double d;
};
