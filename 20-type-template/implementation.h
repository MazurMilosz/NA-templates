#pragma once

template<typename T>
class container_wrapper
{
public:

    container_wrapper() = default;              //konstruktor dzieki default jest generowany domyslnie
    
   // container_wrapper( T arg ) : _value( arg )                              // robimy kopie obiektu typu T -> robimy za duzo nie powinnismy kopiowac typu zamieniamy na move
    container_wrapper( T arg ): _value( std::move( arg ) )
    {
    }
    
    container_wrapper( const container_wrapper &) = default;                //konstruktor kopiujacy

    container_wrapper( container_wrapper &&) = default;                     //move constructor
    container_wrapper & operator=( const container_wrapper &) = default;    //przypisuje do wrappera ten operator przypisania
    container_wrapper & operator=( container_wrapper &&) = default;         //przypisanie rvalue operatora   
    

    std::size_t size() const 
    {
        return _value.size();
    }
private:
    T _value; //rozpoczecie od _ tylko dla prywatnych pewna konwencja i uwazac jak sie uzywa

};

