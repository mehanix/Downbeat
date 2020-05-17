#include <exception>
class ObjException : public std::exception
{
    const char *what() const throw()
    {
        return "bad object in piano array";
    }
};
