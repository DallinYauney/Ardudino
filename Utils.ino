
/*
Basically the catch-all module for anything that might be useful more than once.
Must not import from other local files, so that any file is safe to import this.
*/

struct Position {
    int row;
    int col;

    /**
     * Write a character to the screen, and set the position to be one to the right.
     * 
     * Most of the time, this happens automatically, but if the cursor is at
     * column 40, the row will switch, and we have to set the cursor manually. 
     */
    void write_increment() {

    }

    bool hasNext() {
        return col != 39;
    }

    void next() {
        ++col %= 40;
    }

    void set(int row, int col) {
        row = row;
        col = col;
    }

    /**
     * Sets the position to the spot *after* the one given in arguments.
     */
    void setAfter(int row, int col) {
        set(row, col);
        next();
    }
};
