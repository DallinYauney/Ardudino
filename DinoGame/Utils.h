#ifndef UTILS_H 
#define UTILS_H 
 
struct Position { 
   int row; 
   int col; 
 
   void set(int newRow, int newCol) { 
      row = newRow; 
      col = newCol; 
   }
    
   void next() { 
      col = (col + 1) % 40; 
   } 
 
   void setAfter(int newRow, int newCol) { 
      set(newRow, newCol); 
      next(); 
   } 
 
   bool hasNext() { 
      return col != 39; 
   } 
   
   void write_increment() { 
      next(); 
   } 
}; 
 
#endif