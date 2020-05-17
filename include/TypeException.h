#include <exception>
class TypeException : public std::exception
{
    const char *what() const throw()
    {
        return "wrong object passed to checkPressed; not a button";
    }
};