#ifndef UTILS_H
#define UTILS_H

// Pure abstract interface file (No data members, no implementation)
class IPositionable {
public:
   virtual ~IPositionable() {} // Virtual destructor for safe polymorphic deletion

   virtual void set(int newRow, int newCol) = 0; // "pure virtual function" indictor
   virtual void next() = 0;
   virtual int getRow() const = 0;
   virtual int getCol() const = 0;
};

#endif // since this programing is going to be implementing a loop
       //, we need to explicitly stop the loop
       //
