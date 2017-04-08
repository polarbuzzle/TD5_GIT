
#ifndef ERREUR_H
#define ERREUR_H

#include <exception>

class OperationInvalide : public std::invalid_argument
{
public:
    OperationInvalide(const std::string& raison = "Exception division par zero impossible!");
};

OperationInvalide::OperationInvalide(const std::string& raison) : std::invalid_argument(raison){}

#endif // ERREUR_H



