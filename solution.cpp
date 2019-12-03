#include <iostream>
#include <math.h>

int find_all_squares(Pair<double,double>* points) {

}

// class Corner {
//     private:
//         // See if the destructor works on "Type const *"...
//         Pair<double,double> * eA;
//         Pair<double,double> * eB;
//         Pair<double,double> * base;

//     public:
//         Corner() : eA(nullptr), eB(nullptr), base(nullptr) {}
//         // If multiple objects are instantiated with the same pointer to a Pair object (Pair<double,double> const * const), then this may cause a problem when trying to change only ONE of those object's variables...
//         Corner(Pair<double,double> const * const & eA, Pair<double,double> const * const & eB, Pair<double,double> const * const base) : eA(nullptr), eB(nullptr), base(nullptr) {
//             if ((eA == eB) ||
//             (eA == base) ||
//             (eB == base) ||
//             ((eA->first == eB->first) && (eA->second == eB->second)) ||
//             ((eA->first == base->first) && (eA->second == base->second)) ||
//             ((eB->first == base->first) && (eB->second == base->second))) return;
//             this->eA = new Pair<double,double>(eA->first, eA->second);
//             this->eB = new Pair<double,double>(eB->first, eB->second);
//             this->base = new Pair<double,double>(base->first, base->second);
//         }
//         Corner(Corner const * const & other) : eA(nullptr), eB(nullptr), base(nullptr) {
//             if (other == nullptr) return;
//             if ((other->get_eA() == other->get_eB()) ||
//             (other->get_eA() == other->get_base()) ||
//             (other->get_eB() == other->get_base()) ||
//             ((other->get_eA()->first == other->get_eB()->first) && (other->get_eA()->second == other->get_eB()->second)) ||
//             ((other->get_eA()->first == other->get_base()->first) && (other->get_eA()->second == other->get_base()->second)) ||
//             ((other->get_eB()->first == other->get_base()->first) && (other->get_eB()->second == other->get_base()->second))) return;
//             eA = new Pair<double,double>(eA->first, eA->second);
//             eB = new Pair<double,double>(eB->first, eB->second);
//             base = new Pair<double,double>(base->first, base->second);
//         }
//         ~Corner() {
//             delete eA;
//             delete eB;
//             delete base;

//             eA = nullptr;
//             eB = nullptr;
//             base = nullptr;
//         }
//         Corner* const operator=(Corner const * const & other) {
//             this->~Corner();
//             return new Corner(other);
//         }
//         bool const operator==(Corner const & other) const {
//             return ((eA->first == other.get_eA()->first) && (eA->second == other.get_eA()->second) &&
//              (eB->first == other.get_eB()->first) && (eB->second == other.get_eB()->second) &&
//              (base->first == other.get_base()->first) && (base->second == other.get_base()->second))
//         }
//         bool const operator!=(Corner const & other) const {
//             return !operator==(other);
//         }
//         int const hash(int list_len) const {
//             if ((eA == nullptr) || (eB == nullptr) || (base == nullptr)) return -1;
//             return ((pow(eA->first,1)+pow(eA->second,3)+pow(eB->first,5)+pow(eB->second,7))%list_len);
//         }
//         bool const shapeable(Corner const * const other) const {
//             return ((this->eA == other->get_eA()) && (this->eB == other->get_eB()) && (this->eA != other->get_base()));
//         }
//         Pair<double,double> const * const get_eA() const {
//             return this->eA;
//         }
//         Pair<double,double> const * const get_eB() const {
//             return this->eB;
//         }
//         Pair<double,double> const * const get_base() const {
//             return this->base;
//         }
//         void set_eA(Pair<double,double> const * const & new_eA) {
//             if (new_eA == nullptr) return;
//             // this->eA->first = new_eA->first;
//             // this->eA->second = new_eA->second;
//         }
//         void set_eA(Pair<double,double> const * const & new_eB) {
//             if (new_eB == nullptr) return;
//             // this->eB->first = new_eB->first;
//             // this->eB->second = new_eB->second;
//         }
//         void set_base(Pair<double,double> const * const & new_base) {
//             if (new_base == nullptr) return;
//             // this->base->first = new_base->first;
//             // this->base->second = new_base->second;
//         }
// };

// TODOS:
// Check for consts

class Corner {
    private:
        // See if the destructor works on "Type const *"...
        Pair<double,double> * eA;
        Pair<double,double> * eB;
        Pair<double,double> * base;

    public:
        Corner() : eA(nullptr), eB(nullptr), base(nullptr) {}
        // If multiple objects are instantiated with the same pointer to a Pair object (Pair<double,double> const * const), then this may cause a problem when trying to change only ONE of those object's variables...
        Corner(Pair<double,double> const * const & eA, Pair<double,double> const * const & eB, Pair<double,double> const * const base) : eA(nullptr), eB(nullptr), base(nullptr) {
            if ((eA == eB) ||
            (eA == base) ||
            (eB == base) ||
            ((eA->first == eB->first) && (eA->second == eB->second)) ||
            ((eA->first == base->first) && (eA->second == base->second)) ||
            ((eB->first == base->first) && (eB->second == base->second))) return;
            this->eA = eA;
            this->eB = eB;
            this->base = base;
        }
        Corner(Corner const * const & other) : eA(nullptr), eB(nullptr), base(nullptr) {
            if (other == nullptr) return;
            if ((other->get_eA() == other->get_eB()) ||
            (other->get_eA() == other->get_base()) ||
            (other->get_eB() == other->get_base()) ||
            ((other->get_eA()->first == other->get_eB()->first) && (other->get_eA()->second == other->get_eB()->second)) ||
            ((other->get_eA()->first == other->get_base()->first) && (other->get_eA()->second == other->get_base()->second)) ||
            ((other->get_eB()->first == other->get_base()->first) && (other->get_eB()->second == other->get_base()->second))) return;
            eA = other->get_eA();
            eB = other->get_eB();
            base = other->get_base();
        }
        ~Corner() {
            eA = nullptr;
            eB = nullptr;
            base = nullptr;
        }
        Corner* const operator=(Corner const & other) {
            this->~Corner();
            return new Corner(&other);
        }
        bool const operator==(Corner const & other) const {
            if ((eA == other.get_eA()) && (eB == other.get_eB()) && (base == other.get_base())) return true;
            return ((eA->first == other.get_eA()->first) && (eA->second == other.get_eA()->second) &&
            (eB->first == other.get_eB()->first) && (eB->second == other.get_eB()->second) &&
            (base->first == other.get_base()->first) && (base->second == other.get_base()->second));
        }
        bool const operator!=(Corner const & other) const {
            return !operator==(other);
        }
        int const hash(int hash_mod) const {
            if ((eA == nullptr) || (eB == nullptr) || (base == nullptr)) return -1;
            return ((pow(eA->first,1)+pow(eA->second,3)+pow(eB->first,5)+pow(eB->second,7))%hash_mod);
        }
        bool const shapeable(Corner const * const other) const {
            if ((eA == other->get_eA()) && (this->eB == other->get_eB()) && (this->eA != other->get_base())) return true;
            return ((eA->first == other->get_eA()->first) && (eA->second == other->get_eA()->second) &&
            (eB->first == other->get_eB()->first) && (eB->second == other->get_eB()->second) &&
            !((base->first == other->get_base()->first) && (base->second == other->get_base()->second)));
        }
        Pair<double,double> const * const & get_eA() const {
            return this->eA;
        }
        Pair<double,double> const * const & get_eB() const {
            return this->eB;
        }
        Pair<double,double> const * const & get_base() const {
            return this->base;
        }
        void set(Pair<double,double> const * const new_ptr, Pair<double,double> const * * const self_ptr) {
            if ((new_ptr == nullptr) || (self_ptr == nullptr)) return;
            *(self_ptr) = new_ptr;
        }
        void set_src(Pair<double,double> const * const & new_ptr, Pair<double,double> const * * const & self_ptr) {
            if ((new_ptr == nullptr) || (self_ptr == nullptr) || (*(self_ptr) == nullptr)) return;
            *(self_ptr)->first = new_ptr->first;
            *(self_ptr)->second = new_ptr->second;
        }
        // void set_eA(Pair<double,double> const * const & eA) {
        //     this->eA = eA;
        // }
        // void set_eB(Pair<double,double> const * const & eB) {
        //     this->eB = eB
        // }
        // void set_base(Pair<double,double> const * const & base) {
        //     this->base = base;
        // }
        // void set_src_eA(Pair<double,double> const * const & eA) {
        //     if (eA == nullptr) return;
        //     this->eA->first = eA->first;
        //     this->eA->second = eA->second;
        // }
        // void set_src_eB(Pair<double,double> const * const & eB) {
        //     if (new_eB == nullptr) return;
        //     this->eB->first = eB->first;
        //     this->eB->second = eB->second;
        // }
        // void set_src_base(Pair<double,double> const * const & base) {
        //     if (base == nullptr) return;
        //     this->base->first = base->first;
        //     this->base->second = base->second;
        // }
};

class Line {
    private:
        double* vector;
        double* offset;
        int dim;

    public:
        Line() : vector(nullptr), offset(nullptr), dim(0) {}
        Line(double const * const & vector, double const * const & offset, int const & dim) : vector(vector), offset(offset), dim(dim) {}
        Line(Line const * const & other) {
            this->dim = other->get_dim();
            for (int i=0; i<dim; i++) {
                *(vector+i) = *((other->get_vector())+i);
                *(offset+i) = *((other->get_offset())+i);
            }
        }
        ~Line() {
            for (int i=0; i<dim; i++) {
                
            }
        }
}