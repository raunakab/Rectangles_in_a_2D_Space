class Line {
    private:
        double* vector;
        double* offset;
        int dim;

    public:
        Line() : vector(nullptr), offset(nullptr), dim(0) {}
        Line(double * const & vector, double * const & offset, int const & dim) : vector(nullptr), offset(nullptr), dim(dim) {
            if (vector == offset) return;
            this->vector = vector;
            this->offset = offset;
        }
        Line(Line const * const & other) {
            dim = other->get_dim();
            for (int i=0; i<dim; i++) {
                *(vector+i) = *(other->get_vector()+i);
                *(offset+i) = *(other->get_offset()+i);
            }
        }
        ~Line() {
            for (int i=0; i<dim; i++) {
                delete[] vector;
                delete[] offset;
                vector = nullptr;
                offset = nullptr;
            }
        }
        Line & operator=(Line const & other) {
            this->~Line();
            return *(new Line(&other));
        }
        bool operator==(Line const & other) {
            if (dim != other->get_dim()) return false;
            if ((vector == other->get_vector()) && (offset == other->get_offset())) return true;
            return (array_check(vector,other->get_vector()) && array_check(offset,other->get_offset()));
        }
};