/*Calling a member function from another member function using pointer to member,
This seems confusing but actually is just an application of the pointer to member syntax with
“this” object playing the role of the hidden this parameter. If you want a member function f of
Class A to call another member function g of class A through a pointer to member function, it
would look like this:*/
// source: http://umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf
class A {
void f();
void g();
};
void A::f()
{
// declare pmf as pointer to A member function,
// taking no args and returning void
void (A::*pmf)();
// set pmf to point to A's member function g
pmf = &A::g;
// call the member function pointed to by pmf points on this object
(this->*pmf)(); // calls A::g on this object
}
// using a typedef to preserve sanity - same as above with typedef
// A_pmf_t is a pointer-to-member-function of class A
typedef void (A::*A_pmf_t)();
void A::f()
{
A_pmf_t p = &A::g;
(this->*p)(); // calls A::g on this object
}
