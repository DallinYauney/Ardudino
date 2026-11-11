class ObstacleComponent {
    private:
    bool isEmpty;
    int dRow;
    int dCol;
    char characterCode;

    public:
    ObstacleComponent() {
        isEmpty = true;
        dRow = 0;
        dCol = 0;
        characterCode = 0;
    }
    
    ObstacleComponent(bool isEmpty, int dRow, int dCol, char characterCode) {
        isEmpty = isEmpty;
        dRow = dRow;
        dCol = dCol;
        characterCode = characterCode;
    }

    int getDRow() {
        return dRow;
    }

    int getDCol() {
        return dCol;
    }

    char getChar() {
        return characterCode;
    }

    bool getIsEmpty() {
        return isEmpty;
    }
};
