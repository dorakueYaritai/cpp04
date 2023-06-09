#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    setDefaultIdeas();
    #ifdef DEBUG
        std::cout << "Brain constructor called" << std::endl;
    #endif
}

Brain::~Brain()
{
    #ifdef DEBUG
        std::cout << "Brain destructor called" << std::endl;
    #endif
    if (ideas_)
    {
        delete [] ideas_;
    }
}

Brain::Brain(std::string *&ideas){
    if (ideas->size() == 100)
        this->ideas_ = ideas;
    else
        this->ideas_ = NULL;
}

Brain::Brain(const Brain &copy)
{
    #ifdef DEBUG
        std::cout << "Brain copy constructor called" << std::endl;
    #endif
    this->ideas_ = NULL;
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
    // std::cout << &copy << std::endl;
    // std::cout << &copy.ideas_ << std::endl;
    // std::cout << &copy.ideas_[0] << std::endl;
    #ifdef DEBUG
        std::cout << "Brain operator= called" << std::endl;
    #endif
    if (this != &copy){
        if (this->ideas_)
            delete [] this->ideas_;
        this->ideas_ = new std::string[100];
        // std::cout << this->ideas_[0] << std::endl;
        // std::cout << this->ideas_[1] << std::endl;
        // std::cout << copy.ideas_[0] << std::endl;
        for (int i = 0; i < 100; i++){
            this->ideas_[i] = copy.ideas_[i];
        }
    }
    return (*this);
}

void    Brain::setDefaultIdeas(void){
    this->ideas_ = new std::string[BRAIN_SIZE];
    for (int i = 0; i < BRAIN_SIZE; i++){
        this->ideas_[i] = '!' + (i % 20);
    }
}

void    Brain::printIdeas(void){
    for (int i = 0; i < BRAIN_SIZE; ++i){
        std::cout << this->ideas_[i];
    }
    std::cout << std::endl;
}
